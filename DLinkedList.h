#pragma once
#include<iostream>
#include"ExceptionList.h"

template <typename T>
struct Node
{
	T value;
	Node* prev;
	Node* next;

	Node(const T& value) :value{ value }, prev{ NULL }, next{ NULL }
	{

	}

	Node(const T& value, Node* prev) :value{ value }, prev{ prev }, next{ NULL }
	{

	}
};

template<typename T>
class DLinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
	unsigned int size;

	void _addFirst(const T& value);
	Node<T>* _getByIndex(unsigned int index) const;
	void _remove(Node<T>* node);

public:
	DLinkedList() :head{ NULL }, tail{ NULL }, size{ 0 }
	{

	}

	DLinkedList(const DLinkedList& list);
	DLinkedList(DLinkedList&& list) noexcept;

	void copy(const DLinkedList& list);

	bool isEmpty() const;

	void add(const T& value);

	void edit(const T& newValue, unsigned int index);

	unsigned int find(const T& value) const;

	void remove(unsigned int index);
	void remove(const T& value);

	void print(std::ostream& out = std::cout) const;

	void clear();

	unsigned int getSize() const;

	T& getByIndex(unsigned int index) const;
	T& getByIndex() const;

	T operator[] (unsigned int index) const;
	T& operator[] (unsigned int index);

	const DLinkedList<T>& operator+=(const DLinkedList<T>& list_1);
	DLinkedList<T>& operator = (const DLinkedList& list);

	template<typename U>
	friend DLinkedList<U> operator + (const DLinkedList<U> list_1, const DLinkedList<U> list_2);

	~DLinkedList();
};

template<typename T>
inline void DLinkedList<T>::_addFirst(const T& value)
{
	this->head = new Node<T>(value);
	this->tail = this->head;
}

template<typename T>
inline Node<T>* DLinkedList<T>::_getByIndex(unsigned int index) const
{
	if (index >= this->size)
		throw ExceptionList("Index out of range\n");

	unsigned int count = 0;

	Node<T>* curr = this->head;

	while (count++ != index)
	{
		curr = curr->next;
	}

	return curr;
}

template<typename T>
inline void DLinkedList<T>::_remove(Node<T>* node)
{
	Node<T>* next = node->next;

	if (node == this->head)
	{
		if (this->head == this->tail)
		{
			this->head = this->tail = NULL;
		}
		else
		{
			this->head->next->prev = NULL;
			this->head = this->head->next;
		}
	}
	else if (node == this->tail)
	{
		this->tail->prev->next = NULL;
		this->tail = this->tail->prev;
	}
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}

	delete node;

	this->size--;
}

template<typename T>
inline DLinkedList<T>::DLinkedList(const DLinkedList& list) :head{ NULL }, tail{ NULL }, size{ 0 }
{
	this->copy(list);
}

template<typename T>
inline DLinkedList<T>::DLinkedList(DLinkedList&& list) noexcept :head{ list.head }, tail{ list.tail }, size{ list.size }
{
	list.head = NULL;
}

template<typename T>
inline void DLinkedList<T>::copy(const DLinkedList& list)
{
	this->clear();
	unsigned int size = list.getSize();

	for (unsigned int i = 0; i < size; i++)
	{
		this->add(list.getByIndex(i));
	}
}

template<typename T>
inline bool DLinkedList<T>::isEmpty() const
{
	return (this->size == 0);
}

template<typename T>
inline void DLinkedList<T>::add(const T& value)
{
	if (this->head == NULL)
		this->_addFirst(value);

	else
	{
		this->tail->next = new Node<T>(value, this->tail);
		this->tail = this->tail->next;
	}

	this->size++;
}

template<typename T>
inline void DLinkedList<T>::edit(const T& newValue, unsigned int index)
{
	this->_getByIndex(index)->value = newValue;
}

template<typename T>
inline unsigned int DLinkedList<T>::find(const T& value) const
{
	Node<T>* curr = this->head;
	unsigned int index = 0;

	while (curr != NULL)
	{
		if (curr->value == value)
			return index;

		index++;
		curr = curr->next;
	}
	return -1;
}

template<typename T>
inline void DLinkedList<T>::remove(unsigned int index)
{
	Node<T>* curr = this->_getByIndex(index);

	this->_remove(curr);
}

template<typename T>
inline void DLinkedList<T>::remove(const T& value)
{
	Node<T>* curr = this->head;
	while (curr != NULL && curr->value != value)
	{
		curr = curr->next;
	}

	if (curr == NULL)
		throw ExceptionList("Cannot find an element to remove\n");

	this->_remove(curr);
}

template<typename T>
inline void DLinkedList<T>::print(std::ostream& out) const
{
	Node<T>* curr = this->head;

	while (curr != NULL)
	{
		out << curr->value << "\n";
		curr = curr->next;
	}
}

template<typename T>
inline void DLinkedList<T>::clear()
{
	while (this->head != NULL)
	{
		Node<T>* curr = this->head;
		this->head = this->head->next;
		delete curr;
	}
}

template<typename T>
inline unsigned int DLinkedList<T>::getSize() const
{
	return this->size;
}

template<typename T>
inline T& DLinkedList<T>::getByIndex(unsigned int index) const
{
	return this->_getByIndex(index)->value;
}

template<typename T>
inline T& DLinkedList<T>::getByIndex() const
{
	return this->getByIndex(this->size - 1);
}

template<typename T>
inline T DLinkedList<T>::operator[](unsigned int index) const
{
	return this->getByIndex(index);
}

template<typename T>
inline T& DLinkedList<T>::operator[](unsigned int index)
{
	return this->getByIndex(index);
}

template<typename T>
inline const DLinkedList<T>& DLinkedList<T>::operator+=(const DLinkedList<T>& list_1)
{
	unsigned int size = list_1.getSize();

	for (unsigned int i = 0; i < size; i++)
	{
		this->add(list_1.getByIndex(i));
	}

	return *this;
}

template<typename T>
inline DLinkedList<T>& DLinkedList<T>::operator=(const DLinkedList& list)
{
	this->copy(list);
	return *this;
}

template<typename T>
inline DLinkedList<T>::~DLinkedList()
{
	this->clear();
}

template<typename U>
inline DLinkedList<U> operator+(const DLinkedList<U> list_1, const DLinkedList<U> list_2)
{
	DLinkedList<U> list(list_1);

	unsigned size = list_2.getSize();

	for (unsigned int i = 0; i < size; i++)
	{
		list.add(list_2.getByIndex(i));
	}

	return list;
}
