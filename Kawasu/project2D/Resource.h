#pragma once
#include <stdlib.h>

template<typename T>
class Resource
{
public:
	Resource(char* szFilename)
	{
		int length = strlen(szFilename) + 1;
		m_szFilename = new char[length];
		strcpy_s(m_szFilename, length, szFilename);
		
		m_Data = new T(szFilename);
	}

	~Resource()
	{
		delete[] m_szFilename;
	}

	void Clear()
	{

	}

	char* m_szFilename;
	T* m_Data;
};