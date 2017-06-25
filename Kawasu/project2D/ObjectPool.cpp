#include "ObjectPool.h"
#include "Bombs.h"

//--------------------------------------------------------------------------------------------
// Default Constructor / Creates data for the object pool via a for loop.
//--------------------------------------------------------------------------------------------
ObjectPool::ObjectPool(int nMaxSize)
{
	m_nMaxSize = nMaxSize;
	for (int i = 0; i < nMaxSize; ++i)
	{
		m_pData.PushBack(new Bombs());
	}
}

//--------------------------------------------------------------------------------------------
// Default Destructor / Deletes data in the object pool via a for loop.
//--------------------------------------------------------------------------------------------
ObjectPool::~ObjectPool()
{
	for (int i = 0; i < m_nMaxSize; ++i)
	{
		delete m_pData[i];
	}
}

//--------------------------------------------------------------------------------------------
// Allocates ram to each object in the object pool via for loop based on the size of the pool.
//
// Return:
//		Returns nullptr.
//--------------------------------------------------------------------------------------------
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

//--------------------------------------------------------------------------------------------
// Deallocates ram from the passed in object, deactivating it.
// 
// Param:
//		object: The object to be deallocated.
//--------------------------------------------------------------------------------------------
void ObjectPool::Deallocate(Bombs* object)
{
	object->SetActive(false);
}
