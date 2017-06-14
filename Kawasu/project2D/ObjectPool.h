#pragma once
#include "DynamicArray.h"

class Entity;
class Bombs;

class ObjectPool
{
public:
	ObjectPool(int nMaxSize);
	~ObjectPool();

	Bombs* Allocate();
	void Deallocate(Bombs* object);

private:
	DynamicArray<Bombs*> m_pData;
	int m_nMaxSize;
};
