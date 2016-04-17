#pragma once

#include "StructureItem.h"
#include "PriorityQueue_List.h"
#include "PriorityQueue_ArrayList.h"

namespace DS
{
	template<typename T>
	class PriorityQueue_ArrayList_Sorted :
		public PriorityQueue_ArrayList<T>
	{
	public:
		PriorityQueue_ArrayList_Sorted();
		PriorityQueue_ArrayList_Sorted(const PriorityQueue_ArrayList_Sorted<T>& other);

		Structure* clone() const override;
    PriorityQueue_ArrayList_Sorted<T>& operator=(
		const PriorityQueue_ArrayList_Sorted<T>& other);

		void push(const int priority, const T& data) override;
		T pop() override;
	protected:
		int indexOfHighestPriority() const override;
	};

	template<typename T>
	PriorityQueue_ArrayList_Sorted<T>::PriorityQueue_ArrayList_Sorted() 
	{
    throw -1;
	}

	template<typename T>
	PriorityQueue_ArrayList_Sorted<T>::PriorityQueue_ArrayList_Sorted(
		const PriorityQueue_ArrayList_Sorted<T>& other) 
	{
    throw -1;
	}

	template<typename T>
	Structure* PriorityQueue_ArrayList_Sorted<T>::clone() const
	{
		return new PriorityQueue_ArrayList_Sorted<T>(*this);
	}
  
	template<typename T>
	PriorityQueue_ArrayList_Sorted<T>& PriorityQueue_ArrayList_Sorted<T>::operator=(
		const PriorityQueue_ArrayList_Sorted<T>& other)
	{
		PriorityQueue_List<T>::operator=(other);
		return *this;
	}

	template<typename T>
	void PriorityQueue_ArrayList_Sorted<T>::push(const int priority, const T& data)
	{
		int startIndex(0);
		int stopIndex(static_cast<int>(list_->size()));
		
		while (startIndex < stopIndex)
		{
			int index(startIndex + ((stopIndex - startIndex) >> 1));
			
			if (priority < (*list_)[index]->getPriority())
			{
				startIndex = index + 1;
			}
			else
			{
				stopIndex = index;
			}

			list_->insert(new PriorityItem<T>(priority, data), stopIndex());
		}
	}

	template<typename T>
	T PriorityQueue_ArrayList_Sorted<T>::pop()
	{
		// TODO Re-write this stolen piece of code.
		PriorityItem<T>* pom = list_->removeAt(indexOfHighestPriority());
		T data = pom->getData();
		delete pom;
		return data;
	}

	template<typename T>
	inline int PriorityQueue_ArrayList_Sorted<T>::indexOfHighestPriority() const
	{
		return static_cast<int>(list_->size()) - 1;
	}
}