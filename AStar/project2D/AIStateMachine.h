#pragma once
#include "Renderer2D.h"
#include "DynamicArray.h"
#include "BaseState.h"
#include "Stack.h"

using namespace aie;

class AIStateMachine
{
public:
	AIStateMachine();
	~AIStateMachine();

	int Update(float fDetaTime);
	int Draw(Renderer2D* m_2dRenderer);
	int PushState(int nStateIndex);
	void RegisterState(int nStateIndex, BaseState* pState);
	void PopState();
	bool bDrawLowerState;

private:
	DynamicArray<BaseState*> m_StateList;
	BaseState* m_CurrentState;
};
