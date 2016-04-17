#pragma once

#include "List.h"
#include "PriorityQueue.h"

namespace DS
{
	template<typename T>
	class PriorityQueue_List :
		public PriorityQueue<T>
	{
	public:
		virtual ~PriorityQueue_List();

		Structure& operator=(const Structure& other) override;
		PriorityQueue<T>& operator=(const PriorityQueue<T>& other) override;
		PriorityQueue_List<T>& operator=(const PriorityQueue_List<T>& other);

		size_t size() const override;
		bool isEmpty() const override;
		void clear() override;

		T& peek() override;
		const T& peek() const override;
		int peekPriority() const override;
	protected:
		List<PriorityItem<T>*>* list_;

		PriorityQueue_List(List<PriorityItem<T>*>* list);
		virtual int indexOfHighestPriority() const;
	};

	template<typename T>
	PriorityQueue_List<T>::PriorityQueue_List(List<PriorityItem<T>*>* list) :
		list_(list)
	{
	}

	template<typename T>
	PriorityQueue_List<T>::~PriorityQueue_List()
	{
		for (PriorityItem<T>* pi : *list_)
		{
			delete pi;
		}

		delete list_;
		list_ = nullptr;
	}

	template<typename T>
	Structure& PriorityQueue_List<T>::operator=(const Structure& other)
	{
		return (*this) = dynamic_cast<const PriorityQueue_List&>(other);
	}

	template<typename T>
	PriorityQueue<T>& PriorityQueue_List<T>::operator=(const PriorityQueue<T>& other)
	{
		return (*this) = dynamic_cast<const PriorityQueue_List&>(other);
	}

	template<typename T>
	PriorityQueue_List<T>& PriorityQueue_List<T>::operator=(const PriorityQueue_List<T>& other)
	{
		clear();

		for (PriorityItem<T>* pi : *other.list_)
		{
			list_->add(new PriorityItem<T>(*pi));
		}

		return *this;
	}

	template<typename T>
	size_t PriorityQueue_List<T>::size() const
	{
		return list_->size();
	}

	template<typename T>
	bool PriorityQueue_List<T>::isEmpty() const
	{
		return size() == 0;
	}

	template<typename T>
	void PriorityQueue_List<T>::clear()
	{
		for (PriorityItem<T>* pi : *list_)
		{
			delete pi;
		}

		list_->clear();
	}

	template<typename T>
	int PriorityQueue_List<T>::indexOfHighestPriority() const
	{
		int highestPriority((*list_)[0]->getPriority());
		int resIndex(0);
		int currIndex(0);

		for (PriorityItem<T>* item : *list_)
		{
			int tmpPriority(item->getPriority());

			if (tmpPriority < highestPriority)
			{
				highestPriority = tmpPriority;
				resIndex = currIndex;
			}

			currIndex++;
		}

		return resIndex;
	}

	template<typename T>
	T & PriorityQueue_List<T>::peek()
	{
		return (*list_)[indexOfHighestPriority()]->getData();
	}

	template<typename T>
	const T & PriorityQueue_List<T>::peek() const
	{
		return (*list_)[indexOfHighestPriority()]->getData();
	}

	template<typename T>
	int PriorityQueue_List<T>::peekPriority() const
	{
		return (*list_)[indexOfHighestPriority()]->getPriority();
	}

}