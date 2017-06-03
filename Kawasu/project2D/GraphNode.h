#pragma once
#include "DynamicArray.h"
#include "Renderer2D.h"
#include "Stack.h"

template <typename T>
class GraphNode
{
public:
	GraphNode() {}

	GraphNode(T data)
	{
		m_Data = data;
	}

	~GraphNode() {}

	void AddConnection(GraphNode<T>* other)
	{
		for (int i = 0; i < m_Edges.Size(); ++i)
			if (m_Edges[i] == other)
			{
				m_Edges.Remove(i);
				return;
			}
	}

	/*void SetTraversed(bool bTraversed)
	{
		m_bTraveresd = bTraversed;
	}

	void GetTraveresd()
	{
		return m_bTraveresd;
	}*/


private:
	DynamicArray<GraphNode<T>*> m_Edges;
		T m_Data;
};
