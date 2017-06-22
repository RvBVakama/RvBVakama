#pragma once
#include "ListNode.h"
#include <crtdbg.h>

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
		return *this;
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
	bool operator==(ListNode<T>* other)
	{
		if (current == other)
			return true;
		else
			return false;
	}

	//->
	T value()
	{
		return current->data;
	}

	//++
	void operator++()
	{
		current = current->next;
	}

	//--
	void operator--()
	{
		current = current->prev;
	}
};

template <typename T>
class LinkedList
{
public:

	LinkedList()
	{
		start = new ListNode<T>();
		_ASSERT(start);
		end = new ListNode<T>();
		_ASSERT(end);

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
		_ASSERT(node);
		node->data = data;
		node->next = start->next;
		start->next->prev = node;
		start->next = node;
		node->prev = start;
	}

	void PushBack(T data)
	{
		ListNode<T>* node = new ListNode<T>();
		_ASSERT(node);
		node->data = data;
		node->prev = end->prev;
		end->prev->next = node;
		end->prev = node;
		node->next = end;
	}

	void insert(ListNode<T>* node)
	{
		ListNode<T>* firstNode = node;
		ListNode<T>* lastNode = node->next;
		ListNode<T>* newNode = new ListNode<T>*;
		_ASSERT(newNode);

		firstNode = newNode->prev;
		LastNode = newNode->next;

		//delete node;
	}

	ListNode<T>* Begin()
	{
		return start->next;
	}

	ListNode<T>* End()
	{
		return end;
	}

	ListNode<T>* first()
	{
		_ASSERT(start->next != end)
		return start->next->data;
	}

	ListNode<T>* Last()
	{
		_ASSERT(end->prev != start)
			return end->prev->data;
	}

	int Count()
	{
		int m_count = 0;

		ListNode<T>* current = start->next;

		while (current != end)
		{
			++current;
			++m_count;
		}

		return m_count;
	}

	ListNode<T>* Delete(ListNode<T>* node)
	{
		ListNode<T>* prevNode = node->prev;
		ListNode<T>* nextNode = node->next;

		prevNode->next = nextNode;
		nextNode->prev = prevNode;

		delete node;

		return nextNode;
	}

	void Erase(Iter<T> & target)
	{
		target.current = Delete(target.current);
	}

	void Remove(T value)
	{
		ListNode<T>* current = start->next;

		while (current != end)
		{
			if (current.data == value)
			{
				current = Delete(current);
			}

			else
			{
			++current;
			}
		}
	}

	void PopBack()
	{
		_ASSERT(end->prev != start);
		Delete(end->prev);
	}

	void PopFront()
	{
		_ASSERT(start->next != end);
		Delete(start->next);
	}

	void Clear()
	{
		ListNode<T>* current = start->next;

		while (current != end)
		{
			current = Delete(current);
			++current;
		}
	}

private:
	ListNode<T>* start;
	ListNode<T>* end;
	int m_Iterator;
};
