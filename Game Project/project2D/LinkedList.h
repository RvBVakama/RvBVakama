#pragma once
#include "ListNode.h"

template <typename T>
class LinkedList
{
public:
	LinkedList() {};
	~LinkedList() {};

	void PushBack(T data)
	{
	}
	
	ListNode<T>* start;
	ListNode<T>* end;
};