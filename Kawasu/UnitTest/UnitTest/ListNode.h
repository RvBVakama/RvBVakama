#pragma once
#include "ListNode.h"

template <typename T>
class ListNode
{
public:
	ListNode() {};
	~ListNode() {};
	
	T data;
	ListNode* next;
	ListNode* prev;
};