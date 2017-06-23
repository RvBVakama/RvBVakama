#include "StateMachine.h"
#include <crtdbg.h>
#include "Define.h"

StateMachine::StateMachine()
{
	bDrawLowerState = false;
}

StateMachine::~StateMachine()
{
	//for (int i = 0; i < m_StateList.Size(); ++i)
	//{
	//	delete m_StateList[i];
	//}
	
	m_StateList.Clear();
}

int StateMachine::Update(float fDetaTime)
{
	_ASSERT(m_StateList.Size() >= 0);
	if (m_StateList.Size() < 0)
		return STATELIST_NEGATIVESIZE;

	_ASSERT(m_Stack.Size() >= 0);
	if (m_Stack.Size() < 0)
		return STACK_NEGATIVESIZE;
	
	m_Stack.Top()->OnUpdate(fDetaTime, this);

	return SUCCESS;
}

int StateMachine::Draw(Renderer2D * m_2dRenderer)
{
	_ASSERT(m_StateList.Size() >= 0);
	if (m_StateList.Size() < 0)
		return STATELIST_NEGATIVESIZE;

	m_Stack.Top()->OnDraw(m_2dRenderer);

	if (bDrawLowerState)
		Draw2ndFromTop(m_2dRenderer);

	return SUCCESS;
}

int StateMachine::Draw2ndFromTop(Renderer2D * m_2dRenderer)
{
	_ASSERT(m_StateList.Size() >= 0);
	if (m_StateList.Size() < 0)
		return STATELIST_NEGATIVESIZE;

	m_Stack.SecondFromTop()->OnDraw(m_2dRenderer);

	return SUCCESS;
}

int StateMachine::PushState(int nStateIndex)
{
	_ASSERT(nStateIndex < m_StateList.Size());
	if (nStateIndex >= m_StateList.Size())
		return INVALID_STATE;
	if (m_Stack.Size() > 0)
		m_Stack.Top()->OnExit();
	
	m_Stack.Push(m_StateList[nStateIndex]);

	m_Stack.Top()->OnEnter();

	return SUCCESS;
}

void StateMachine::RegisterState(int nStateIndex, BaseState* pState)
{
	int nResult = m_StateList.Insert(nStateIndex, pState);
	_ASSERT(nResult == 0);
}

void StateMachine::PopState()
{
	if (m_Stack.Size() > 0)
		m_Stack.Pop();
}
