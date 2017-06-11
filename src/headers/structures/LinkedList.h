#pragma once

#include "List.h"
#include "DSRoutines.h"
#include "StructureItem.h"

namespace DS
{
	template<typename T>
	class LinkedList :
		public List<T>
	{
	protected:
		class LinkedListIterator :
			public StructureIterator<T>
		{
		public:
			LinkedListIterator(const LinkedItem<T>* item);

			bool operator!=(const StructureIterator<T>& other) const override;
			const T& operator*() const override;
			const StructureIterator<T>& operator++() override;

			StructureIterator<T>* clone() const override;
		private:
			const LinkedItem<T>* item_;
		};

	public:
		static bool defaultEqFunc(T& a, T& b);

		LinkedList(const EqualityFunction<T>& equalityFunction =
			reinterpret_cast<EqualityFunction<T>>(defaultEqFunc));
		LinkedList(const LinkedList<T>& other);
		~LinkedList() override;

		Structure* clone() const override;
		Structure& operator=(const Structure& other) override;
		List<T>& operator=(const List<T>& other) override;
		LinkedList<T>& operator=(const LinkedList<T>& other);

		size_t size() const override;
		T& operator[](const int index) override;
		const T& operator[](const int index) const override;

		void add(const T& data) override;
		void insert(const T& data, const int index) override;
		bool tryRemove(const T& data) override;
		T& removeAt(const int index) override;
		int getIndexOf(const T& data) override;
		void clear() override;

		Iterator<T> begin() const override;
		Iterator<T> end() const override;
	private:
		LinkedItem<T>* first_;
		LinkedItem<T>* last_;
		size_t size_;

		DS::LinkedItem<T>* getLinkedItemAt(const int index) const;
	};

	template<typename T>
	bool LinkedList<T>::defaultEqFunc(T& a, T& b)
	{
		return a == b;
	}

	template<typename T>
	LinkedList<T>::LinkedList(const EqualityFunction<T>& equalityFunction) :
		List<T>(equalityFunction),
		first_(nullptr),
		last_(nullptr),
		size_(0)
	{
	}

	template<typename T>
	LinkedList<T>::LinkedList(const LinkedList<T>& other) :
		LinkedList(other.equalityFunction_)
	{
		(*this) = other;
	}

	template<typename T>
	LinkedList<T>::~LinkedList()
	{
		clear();
	}

	template<typename T>
	Structure* LinkedList<T>::clone() const
	{
		return new LinkedList<T>(*this);
	}

	template<typename T>
	Structure& LinkedList<T>::operator=(const Structure& other)
	{
		return (*this) = dynamic_cast<const LinkedList<T>&>(other);
	}

	template<typename T>
	List<T>& LinkedList<T>::operator=(const List<T>& other)
	{
		return (*this) = dynamic_cast<const LinkedList<T>&>(other);
	}

	template<typename T>
	LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
	{
		List<T>::operator=(other);

		if (this != &other)
		{
			clear();

			for (T data : other)
			{
				add(data);
			}
		}

		return *this;
	}

	template<typename T>
	size_t LinkedList<T>::size() const
	{
		return size_;
	}

	template<typename T>
	T& LinkedList<T>::operator[](const int index)
	{
		return getLinkedItemAt(index)->getData();
	}

	template<typename T>
	const T& LinkedList<T>::operator[](const int index) const
	{
		return getLinkedItemAt(index)->getData();
	}

	template<typename T>
	void LinkedList<T>::add(const T& data)
	{
		LinkedItem<T>* newItem = new LinkedItem<T>(data);
		
		if (size_ == 0)
		{
			first_ = last_ = newItem;
		}
		else
		{
			last_->setNext(newItem);
			last_ = newItem;
		}

		size_++;
	}

	template<typename T>
	void LinkedList<T>::insert(const T& data, const int index)
	{
		DSRoutines::rangeCheck(index, size_ + 1, true,
			&std::string("index out of range"));

		if (index == size_)
		{
			add(data);
		}
		else
		{
			LinkedItem<T>* newItem = new LinkedItem<T>(data);

			if (index == 0)
			{
				newItem->setNext(first_);
				first_ = newItem;
			}
			else
			{
				LinkedItem<T>* prevItem = getLinkedItemAt(index - 1);

				newItem->setNext(prevItem->getNext());
				prevItem->setNext(newItem);
			}

			size_++;
		}
	}

	template<typename T>
	bool LinkedList<T>::tryRemove(const T& data)
	{
		int index(getIndexOf(data));

		if (index == -1)
		{
			return false;
		}

		removeAt(index);

		return true;
	}

	template<typename T>
	T& LinkedList<T>::removeAt(const int index)
	{
		DSRoutines::rangeCheck(index, size_, true,
			&std::string("index out of range"));

		LinkedItem<T>* deleted;

		if (index == 0)
		{
			deleted = first_;
			first_ = first_->getNext();

			if (deleted == last_)
			{
				last_ = nullptr;
			}
		}
		else
		{
			LinkedItem<T>* prevItem = getLinkedItemAt(index - 1);
			deleted = prevItem->getNext();
			prevItem->setNext(deleted->getNext());

			if (last_ == deleted)
			{
				last_ = prevItem;
			}
		}

		size_--;
		T data = deleted->getData();
		delete deleted;

		return data;
	}

	template<typename T>
	int LinkedList<T>::getIndexOf(const T& data)
	{
		LinkedItem<T>* currItem = first_;
		int i(0);

		while (currItem != nullptr)
		{
			if (equalityFunction_(currItem->getData(), data))
			{
				return i;
			}

			currItem = currItem->getNext();
			i++;
		}

		return -1;
	}

	template<typename T>
	void LinkedList<T>::clear()
	{
		LinkedItem<T>* currItem = first_;

		while (currItem != nullptr)
		{
			LinkedItem<T>* nextItem = currItem->getNext();
			delete currItem;
			currItem = nextItem;
		}

		first_ = last_ = nullptr;
		size_ = 0;
	}

	template<typename T>
	Iterator<T> LinkedList<T>::begin() const
	{
		return Iterator<T>(LinkedList<T>::LinkedListIterator(first_));
	}

	template<typename T>
	Iterator<T> LinkedList<T>::end() const
	{
		return Iterator<T>(LinkedList<T>::LinkedListIterator(nullptr));
	}

	template<typename T>
	LinkedItem<T>* LinkedList<T>::getLinkedItemAt(const int index) const
	{
		DSRoutines::rangeCheck(index, size_, true,
			&std::string("index out of range"));

		LinkedItem<T>* currItem = first_;

		for (int i(0); i < index; i++)
		{
			currItem = currItem->getNext();
		}

		return currItem;
	}
  
	template<typename T>
	LinkedList<T>::LinkedListIterator::LinkedListIterator(const LinkedItem<T>* item)
		: item_(item)
	{
	}

	template<typename T>
	bool LinkedList<T>::LinkedListIterator::operator!=(const StructureIterator<T>& other) const
	{
		const LinkedListIterator& lli = dynamic_cast<const LinkedListIterator&>(other);

		return item_ != lli.item_;
	}

	template<typename T>
	const T& LinkedList<T>::LinkedListIterator::operator*() const
	{
		return item_->getData();
	}

	template<typename T>
	const StructureIterator<T>& LinkedList<T>::LinkedListIterator::operator++()
	{
		item_ = item_->getNext();

		return *this;
	}

	template<typename T>
	StructureIterator<T>* LinkedList<T>::LinkedListIterator::clone() const
	{
		return new LinkedListIterator(item_);
	}
}