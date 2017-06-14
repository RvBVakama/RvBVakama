#include "ObjectPool.h"
#include "Bombs.h"

ObjectPool::ObjectPool(int nMaxSize)
{
	m_nMaxSize = nMaxSize;
	for (int i = 0; i < nMaxSize; ++i)
	{
		m_pData.PushBack(new Bombs());
	}
}

ObjectPool::~ObjectPool()
{
	for (int i = 0; i < m_nMaxSize; ++i)
	{
		delete m_pData[i];
	}
}

Bombs* ObjectPool::Allocate()
{
	for(int i = 0; i < m_nMaxSize; ++i)
	{
		if (!m_pData[i]->GetActive())
		{
			m_pData[i]->SetActive(true);
			return m_pData[i];
		}
	}

	return nullptr;
}

void ObjectPool::Deallocate(Bombs* object)
{
	object->SetActive(false);
}
