#pragma once
#include <memory.h>
#include <crtdbg.h>
template <typename T>
class DynamicArray
{
public:
	DynamicArray(int initialSize = 0)
	{
		int nCapacity = initialSize;
		if (nCapacity <= 0)
			nCapacity = 1;

		m_pData = new T[nCapacity];
		_ASSERT(m_pData);
		m_nCapacity = nCapacity;
		m_nUsed = 0;
		memset(&m_NullValue, 0, sizeof(T));
	}

	~DynamicArray()
	{
		delete m_pData;
	}

	DynamicArray(const DynamicArray& other)
	{
		m_nCapacity = other.m_nCapacity;
		m_nUsed = other.m_nUsed;

		m_pData = new T[m_nCapacity];
		_ASSERT(m_pData);
		memcpy(m_pData, other.m_pData, sizeof(T) * m_nCapacity);
	}

	void PushBack(T value)
	{
		if (m_nUsed >= m_nCapacity)
			Resize();
		m_pData[m_nUsed] = value;
		++m_nUsed;
	}

	void PushFront(T value)
	{
		Insert(0, value);
	}

	void Insert(int index, T value)
	{
		_ASSERT(index <= m_nUsed);

		if (index > m_nUsed)
			return;

		if (m_nUsed >= m_nCapacity)
			Resize();

		//memcpy(m_pData + index + 1, m_pData + index, sizeof(T) * (m_nUsed - index));

		for (int i = m_nUsed - 1; i >= index; --i)
		{
			m_pData[i + 1] = m_pData[i];
		}

		m_pData[index] = value;
		++m_nUsed;
	}

	T PopBack()
	{
		_ASSERT(m_nUsed > 0);

		if (m_nUsed <= 0)
			return 0;

		--m_nUsed;
		return m_pData[m_nUsed];
	}

	T Remove(int index)
	{
		_ASSERT(index <= m_nUsed);

		if (index >= m_nUsed)
			return 0;
		//Back value that we are removing from array
		T value = m_pData[index];

		//shuffle all other values across to fill removed space
		for (int i = index; i < m_nUsed; ++i)
		{
			m_pData[i] = m_pData[i + 1];
		}
		--m_nUsed;

		//return removed value
		return value;
	}

	T PopFront()
	{
		return Remove(0);
	}

	void Clear()
	{
		m_nUsed = 0;
	}

	void Shrink()
	{
		int nCapacity = m_nUsed;
		_ASSERT(nCapacity > 0);
		if (nCapacity <= 0)
			nCapacity = 1;

		T* newData = new T[m_nUsed];
		_ASSERT(newData);
		memcpy(newData, m_pData, sizeof(T) * m_nUsed);
		delete m_pData;
		m_pData = newData;
		m_nCapacity = m_nUsed;
	}

	T& operator[](const int index)
	{
		_ASSERT(index < m_nUsed);
		if (index >= m_nUsed)
			return m_NullValue;

		return m_pData[index];
	}

	int Size()
	{
		return m_nUsed;
	}
	int Capacity()
	{
		return m_nCapacity;
	}

private:

	DynamicArray& operator= (const DynamicArray& other) = default;
	DynamicArray(DynamicArray&& other) = default;
	DynamicArray& operator= (DynamicArray&& other) = default;

	void Resize()
	{
		//Creates new array that is twice as big
		T* newData = new T[m_nCapacity * 2];
		_ASSERT(newData);
		//copy old data acriss ubit new attay
		memcpy(newData, m_pData, sizeof(T) * m_nCapacity);

		//Delete old array
		delete m_pData;

		//Make sure our pointers still work
		m_pData = newData;

		m_nCapacity = m_nCapacity * 2;
	}

	int m_nCapacity;
	int m_nUsed;
	T* m_pData;
	T m_NullValue;
};