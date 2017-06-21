#pragma once
#include "DynamicArray.h"

template <typename T>
class Stack
{
public:

	Stack()
	{
		//m_pData = new DynamicArray<T>(initialiseSize);
	}
	
	~Stack()
	{
		//delete m_pData;
	}

	bool IsEmpty()
	{
		return (m_pData.Size() == 0);
	}

	int Size()
	{
		return m_pData.Size();
	}

	void Push(T value)
	{
		m_pData.PushBack(value);
	}

	T Pop()
	{
		return m_pData.PopBack();
	}

	T Top()
	{
		int nTop = m_pData.Size() - 1;
		return m_pData[nTop];
	}

	T SecondFromTop()
	{
		int nTop2 = m_pData.Size() - 2;
		return m_pData[nTop2];
	}

	DynamicArray<T> m_pData;
};
