#pragma once
#include "Renderer2D.h"
#include "DynamicArray.h"
#include "BaseState.h"
using namespace aie;

class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	void Update(float fDetaTime);
	void Draw(Renderer2D* m_2dRenderer);
	void SetState(int nStateIndex);
	void AddState(int nStateIndex, BaseState* pState);


private:
	DynamicArray<BaseState*> m_StateList;
	int m_nCurrentState;
};

