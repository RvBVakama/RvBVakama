#pragma once
#include "Renderer2D.h"
#include "DynamicArray.h"
#include "BaseState.h"
#include "Stack.h"

using namespace aie;

class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	void Update(float fDetaTime);
	void Draw(Renderer2D* m_2dRenderer);
	void PushState(int nStateIndex);
	void RegisterState(int nStateIndex, BaseState* pState);
	void PopState();
	
private:
	DynamicArray<BaseState*> m_StateList;
	Stack<BaseState*> m_Stack;
};
