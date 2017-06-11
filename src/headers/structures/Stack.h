#pragma once

#include "LinkedList.h"

namespace DS
{
	template<typename T>
	class Stack
	{
	public:
		Stack();
		Stack(const Stack& other);
		~Stack();

		Stack& operator=(const Stack& other);

		size_t size() const;
		bool isEmpty() const;
		void clear();

		void push(const T& data);
		T pop();
		T& peek();
		const T& peek() const;

	private:
		LinkedList<T>* list_;
	};

	template<typename T>
	Stack<T>::Stack() :
		list_(new LinkedList<T>())
	{
	}

	template<typename T>
	Stack<T>::Stack(const Stack& other) :
		list_(new LinkedList<T>(*other.list_))
	{
	}

	template<typename T>
	Stack<T>::~Stack()
	{
		delete list_;
	}

	template<typename T>
	Stack<T>& Stack<T>::operator=(const Stack& other)
	{
		if (this != &other)
		{
			*list_ = *other.list_;
		}

		return *this;
	}

	template<typename T>
	size_t Stack<T>::size() const
	{
		return list_->size();
	}

	template<typename T>
	bool Stack<T>::isEmpty() const
	{
		return list_->size() == 0;
	}

	template<typename T>
	void Stack<T>::clear()
	{
		list_->clear();
	}

	template<typename T>
	void Stack<T>::push(const T& data)
	{
		list_->insert(data, 0);
	}

	template<typename T>
	T Stack<T>::pop()
	{
		// TODO Check for size? (the same goes for peek()).
		T data = (*list_)[0];
		list_->removeAt(0);

		return data;
	}

	template<typename T>
	T& Stack<T>::peek()
	{
		return list_->getLinkedItemAt(0)->getData();
	}

	template<typename T>
	const T& Stack<T>::peek() const
	{
		return list_->getLinkedItemAt(0)->getData();
	}
}