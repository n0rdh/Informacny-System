#pragma once

#include "List.h"
#include "Array.h"
#include "Iterator.h"
#include "DSRoutines.h"

namespace DS
{
	template<typename T>
	bool functionEqual(const T& a, const T& b)
	{
		return a == b;
	}

	template<typename T>
	class ArrayList :
		public List<T>
	{
	protected:
		class ArrayListIterator :
			public StructureIterator<T>
		{		
		public:
			ArrayListIterator(int index, const ArrayList<T>* arrayList);

			bool operator!=(const StructureIterator<T>& other) const override;
			const T& operator*() const override;
			StructureIterator<T>& operator++() override;

			StructureIterator<T>* clone() const override;
		private:
			int index_;
			const ArrayList<T>* arrList_;
		};

	public:
		ArrayList(const size_t initialCapacity = 10,
			const EqualityFunction<T>& equalityFunction = functionEqual);
		ArrayList(const ArrayList<T>& other);
		~ArrayList() override;

		Structure* clone() const override;
		Structure& operator=(const Structure& other) override;
		List<T>& operator=(const List<T>& other) override;
		ArrayList<T>& operator=(const ArrayList<T>& other);

		size_t size() const override;
		T& operator[](const int index) override;
		const T& operator[](const int index) const override;

		void add(const T& data) override;
		void insert(const T& data, const int index) override;
		bool tryRemove(const T& data) override;
		T& removeAt(const int index) override;
		int getIndexOf(const T& data) override;
		void clear() override;

		void shrinkToFit();

		Iterator<T> begin() const override;
		Iterator<T> end() const override;
	private:
		static const int RESIZE_ARR_COEF = 20;

		size_t size_;
		size_t minCapacity_;
		Array<T>* array_;

		void ensureCapacity();
		void changeCapacity(size_t newCapacity);
	};

	template<typename T>
	ArrayList<T>::ArrayList(const size_t initialCapacity,
		const EqualityFunction<T>& equalityFunction) :
		List<T>(equalityFunction),
		size_(0),
		array_(new Array<T>(initialCapacity)),
		minCapacity_(initialCapacity)
	{
	}

	template<typename T>
	ArrayList<T>::ArrayList(const ArrayList<T>& other) :
		List<T>(other),
		array_(new Array<T>(*other.array_)),
		size_(other.size_),
		minCapacity_(other.minCapacity_)
	{
	}

	template<typename T>
	ArrayList<T>::~ArrayList()
	{
		delete array_;
	}

	template<typename T>
	Structure* ArrayList<T>::clone() const
	{
		return new ArrayList<T>(*this);
	}

	template<typename T>
	Structure& ArrayList<T>::operator=(const Structure & other)
	{
		return (*this) = dynamic_cast<const ArrayList&>(other);
	}

	template<typename T>
	List<T>& ArrayList<T>::operator=(const List<T>& other)
	{
		return (*this) = dynamic_cast<const ArrayList&>(other);
	}

	template<typename T>
	ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& other)
	{
		if (this != &other)
		{
			delete array_;
			array_ = new Array<T>(*other.array_);
			size_ = other.size_;
			minCapacity_ = other.minCapacity_;
		}

		return *this;
	}

	template<typename T>
	size_t ArrayList<T>::size() const
	{
		return size_;
	}

	template<typename T>
	T& ArrayList<T>::operator[](const int index)
	{
		DSRoutines::rangeCheck(index, size_, true,
			&std::string("index out of range"));

		return (*array_)[index];
	}

	template<typename T>
	const T& ArrayList<T>::operator[](const int index) const
	{
		DSRoutines::rangeCheck(index, size_, true,
			&std::string("index out of range"));

		return (*array_)[index];
	}

	template<typename T>
	void ArrayList<T>::add(const T& data)
	{
		ensureCapacity();

		(*array_)[size_] = data;
		size_++;
	}

	template<typename T>
	void ArrayList<T>::insert(const T& data, const int index)
	{
		ensureCapacity();

		DSRoutines::rangeCheck(index, size_, true,
			&std::string("index out of range"));

		Array<T>::copy(*array_, index, *array_, index + 1, size_ - index);
		(*array_)[index] = data;
		size_++;
	}

	template<typename T>
	bool ArrayList<T>::tryRemove(const T& data)
	{
		int index(getIndexOf(data));

		if (index >= 0)
		{
			removeAt(index);

			return true;
		}

		return false;
	}

	template<typename T>
	T& ArrayList<T>::removeAt(const int index)
	{
		DSRoutines::rangeCheck(index, size_, true,
			&std::string("index out of range"));

		T& item = (*array_)[index];
		Array<T>::copy(*array_, index + 1, *array_, index, size_ - index);
		size_--;

		return item;
	}

	template<typename T>
	int ArrayList<T>::getIndexOf(const T& data)
	{
		for (unsigned i(0); i < size_; i++)
		{
			if (equalityFunction_((*array_)[i], data))
			{
				return i;
			}
		}

		return -1;
	}

	template<typename T>
	void ArrayList<T>::clear()
	{
		size_ = 0;
	}

	template<typename T>
	void ArrayList<T>::shrinkToFit()
	{
		changeCapacity((size_ > minCapacity_) ? size_ : minCapacity_);
	}

	template<typename T>
	Iterator<T> ArrayList<T>::begin() const
	{
		return Iterator<T>(ArrayListIterator(0, this));
	}

	template<typename T>
	Iterator<T> ArrayList<T>::end() const
	{
		return Iterator<T>(ArrayListIterator(size_, this));
	}

	template<typename T>
	inline void ArrayList<T>::ensureCapacity()
	{
		if (size_ == array_->size())
		{
			changeCapacity(array_->size() + RESIZE_ARR_COEF);
		}
	}

	template<typename T>
	void ArrayList<T>::changeCapacity(size_t newCapacity)
	{
		if (newCapacity != array_->size())
		{
			Array<T>* newArr = new Array<T>(newCapacity);
			if (size_ > newCapacity)
			{
				size_ = newCapacity;
			}

			Array<T>::copy(*array_, 0, *newArr, 0, size_);

			delete array_;
			array_ = newArr;
		}
	}

	template<typename T>
	ArrayList<T>::ArrayListIterator::ArrayListIterator(int index, const ArrayList<T>* arrayList)
		: index_(index), arrList_(arrayList)
	{
	}

	template<typename T>
	bool ArrayList<T>::ArrayListIterator::operator!=(
		const StructureIterator<T>& other) const
	{
		const ArrayListIterator& ali = 
			dynamic_cast<const ArrayListIterator&>(other);

		return (index_ != ali.index_) || (arrList_ != ali.arrList_);
	}

	template<typename T>
	const T& ArrayList<T>::ArrayListIterator::operator*() const
	{
		return (*arrList_)[index_];
	}

	template<typename T>
	StructureIterator<T>& ArrayList<T>::ArrayListIterator::operator++()
	{
		index_++;

		return *this;
	}

	template<typename T>
	StructureIterator<T>* ArrayList<T>::ArrayListIterator::clone() const
	{
		return new ArrayListIterator(index_, arrList_);
	}

}