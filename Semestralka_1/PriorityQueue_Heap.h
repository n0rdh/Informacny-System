#pragma once

#include "DSRoutines.h"
#include "StructureItem.h"
#include "PriorityQueue_ArrayList.h"

namespace DS
{
	template<typename T>
	class PriorityQueue_Heap :
		public PriorityQueue_ArrayList<T>
	{
	public:
		PriorityQueue_Heap();
		PriorityQueue_Heap(const PriorityQueue_Heap<T>& other);

		Structure* clone() const override;
		PriorityQueue_Heap<T>& operator=(const PriorityQueue_Heap<T>& other);

		void push(const int priority, const T& data) override;
		T pop() override;
	protected:
		int indexOfHighestPriority() const override;
	private:
		static int getParentIndex(const int index);
		int getGreaterSonIndex(const int index);
	};

	template<typename T>
	PriorityQueue_Heap<T>::PriorityQueue_Heap() :
		PriorityQueue_ArrayList<T>()
	{
	}

	template<typename T>
	PriorityQueue_Heap<T>::PriorityQueue_Heap(const PriorityQueue_Heap<T>& other) :
		PriorityQueue_ArrayList<T>(other)
	{
	}

	template<typename T>
	Structure* PriorityQueue_Heap<T>::clone() const
	{
		return new PriorityQueue_Heap<T>(*this);
	}

	template<typename T>
	PriorityQueue_Heap<T>& PriorityQueue_Heap<T>::operator=(const PriorityQueue_Heap<T>& other)
	{
		return PriorityQueue_List<T>::operator=(other);
	}

	template<typename T>
	void PriorityQueue_Heap<T>::push(const int priority, const T& data)
	{
		PriorityItem<T>* newItem = new PriorityItem<T>(priority, data);
		list_->add(newItem);
		int currIndex(list_->size() - 1);
		int parentIndex(getParentIndex(currIndex));

		while ((currIndex > 0) &&
			((*list_)[parentIndex]->getPriority() >
				(*list_)[currIndex]->getPriority()))
		{
			DSRoutines::swap<PriorityItem<T>*>((*list_)[parentIndex], (*list_)[currIndex]);
			currIndex = parentIndex;
			parentIndex = getParentIndex(currIndex);
		}
	}

	template<typename T>
	T PriorityQueue_Heap<T>::pop()
	{
		int lastIndex(list_->size() - 1);

		PriorityItem<T>* deleted = (*list_)[0];
		(*list_)[0] = (*list_)[lastIndex];
		list_->removeAt(lastIndex);

		if (list_->size() > 0)
		{
			int currIndex(0);
			int sonIndex = getGreaterSonIndex(currIndex);

			while ((sonIndex != -1) && ((*list_)[sonIndex]->getPriority() <
				(*list_)[currIndex]->getPriority()))
			{
				DSRoutines::swap<PriorityItem<T>*>((*list_)[sonIndex], (*list_)[currIndex]);
				currIndex = sonIndex;
				sonIndex = getGreaterSonIndex(currIndex);
			}
		}

		T data = deleted->getData();
		delete deleted;

		return data;
	}

	template<typename T>
	int PriorityQueue_Heap<T>::getParentIndex(const int index)
	{
		return ((index + 1) >> 1) - 1;
	}

	template<typename T>
	int PriorityQueue_Heap<T>::getGreaterSonIndex(const int index)
	{
		int indexTmp(index + 1);
		int left((indexTmp << 1) - 1);
		int right(indexTmp << 1);

		PriorityItem<T>* leftSon = (left < static_cast<int>(size())) ?
			(*list_)[left] : nullptr;
		PriorityItem<T>* rightSon = (right < static_cast<int>(size())) ?
			(*list_)[right] : nullptr;

		if ((leftSon == nullptr) && (rightSon == nullptr))
		{
			return -1;
		}

		return (rightSon == nullptr) ||
			(leftSon->getPriority() < rightSon->getPriority()) ? left : right;
	}

	template<typename T>
	int PriorityQueue_Heap<T>::indexOfHighestPriority() const
	{
		return 0;
	}
}
