#pragma once
#include "ListNode.h"

template <typename T>
class Iter
{
	ListNode<T>* current;

public:

	//=
	Iter& operator=(ListNode<T>* other)
	{
		//LinkedList<int> other1;
		current = other;
		return this;
	}

	//!=
	bool operator!=(ListNode<T>* other)
	{
		if (current != other)
			return true;
		else
			return false;
	}

	//==
	bool operator!=(ListNode<T>* other)
	{
		if (current == other)
			return true;
		else
			return false;
	}

	//->
	Iter& operator->(ListNode<T>* other)
	{
		current

	}

	//++
	//Iter operator ++ (Iter & other)
	//{
	//	return
	//}

	////--
	//Iter operator -- (Iter & other)
	//{
	//	return
	//}

	////*
	//Iter operator * (Iter & other)
	//{
	//	return
	//}
};

template <typename T>
class LinkedList
{
public:

	LinkedList()
	{
		start = new ListNode<T>();
		end = new ListNode<T>();

		start->next = end;
		end->prev = start;

		start->prev = nullptr;
		end->next = nullptr;
	}

	~LinkedList()
	{
		delete end;
		delete start;	
	}

	void PushFront(T data)
	{
		ListNode<T>* node = new ListNode<T>();
		node->data = data;
		node->next = start->next;
		start->next->prev = node;
		start->next = node;
		node->prev = start;
	}

	void PushBack(T data)
	{
		ListNode<T>* node = new ListNode<T>();
		node->data = data;
		node->prev = end->prev;
		end->prev->next = node;
		end->prev = node;
		node->next = end;
	}

	/*Iter insert(m_Iterator, T data)
	{

	}*/

	ListNode<T>* Begin()
	{
		return start->next;
	}

	ListNode<T>* End()
	{
		return end->prev;
	}

	ListNode<T>* first()
	{
		
	}

	/*Last()
	{

	}

	Count()
	{

	}

	Erase()
	{

	}

	Remove()
	{

	}

	PopBack()
	{

	}

	PopFront()
	{

	}

	Empty()
	{

	}

	Clear()
	{

	}*/

private:
	ListNode<T>* start;
	ListNode<T>* end;
	int m_Iterator;
};
