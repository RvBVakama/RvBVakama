#pragma once
#include "DynamicArray.h"
#include "GraphNode.h"
#include <iostream>

template <typename T>
class Graph
{
public:
	Graph() {}
	~Graph() {}

	void Insert(GraphNode<T>* node)
	{
		m_Nodes.PushBack(node);
	}

	void Remove(GraphNode<T>* node)
	{

	}

	void Remove(T data)
	{

	}

	void DrawGraph(aie::Renderer2D* m_2dRenderer)
	{
		Stack<GraphNode<T>*> stack;

		stack.Push(m_Nodes[0]);

		while (!stack.IsEmpty())
		{
			GraphNode<T>* current = stack.Pop();
			current->m_Traveresed = true;
			
			std::cout << current->m_Data << std::endl;
			
			for (int i = 0; i< current->m_Edges.Size(); ++i)
			{
				if(!current->m_Edges[i]->m_bTraversed)
				stack.Push(current->m_Edges[i]);
			}
		}
	}

private:
	DynamicArray<GraphNode<T>*> m_Nodes;

};