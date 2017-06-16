#pragma once
#include "DynamicArray.h"
#include <string.h>

template<typename T>
class ResourceManager
{
public:
	
	T* LoadResource (char* szFilename)
	{
		// Check if resource is already loaded
		// if so return it
		for (int i = 0; i < m_ResourceList.Size(); ++i)
		{
			if (strcmp(m_ResourceList[i]->m_szFilename, szFilename) == 0)
			{
				return m_ResourceList[i]->m_Data;
			}
		}

		// Resource is not loaded, so load it
		Resource<T>* pResource = new Resource<T>(szFilename);
		m_ResourceList.PushBack(pResource);
		return pResource->m_Data;
	}

	void UnloadAllResources()
	{
		for (int i = 0; i < m_ResourceList.Size(); ++i)
		{
			delete m_ResourceList[i];
		}

		m_Resource.Clear();
	}

	static void Create()
	{
		if (!m_pInstance)
			m_pInstance = new ResourceManager<T>();
	}

	static void Destroy()
	{
		delete m_pInstance;
	}

	static ResourceManager<T>* GetInstance()
	{
		return m_pInstance;
	}

	std::shared_ptr<T> get(const std::string filename, Targs ... args)
	{
		std::map<std::string, std::shared_ptr<T>>::iterator it = m_map.find(filename);
		if (it == m_map.end())
		{
			std::shared_ptr<T> resource(new T(filename.c_str(), args...));
			it = m_map.insert(it, std::pair< std::string, std::shared_ptr<T> >(filename, resource));
		}

		return (*it).second;
	}
	
	void collectGarbage()
	{
		for (std::map<std::string, std::shared_ptr<T>>::iterator it = m_map.begin(); it != m_map.end(); )
		{
			if (it->second.use_count() == 1)
				m_map.erase(it++);
			else
				++it;
		}
	}

private:
	ResourceManager() {}
	~ResourceManager()
	{
		UnloadAllResources();
	}
	std::map<std::string, std::shared_ptr<T>> m_map;
	static ResourceManager<T>* m_pInstance;
};

template<typename T>
ResourceManager<T>* ResourceManager<T>::m_pInstance = nullptr;
