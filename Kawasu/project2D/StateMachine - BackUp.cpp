#include "StateMachine.h"
#include <assert.h>
#include <crtdbg.h>

StateMachine::StateMachine()
{
}

StateMachine::~StateMachine()
{
	for (int i = 0; i < m_StateList.Size(); ++i)
	{
		delete m_StateList[i];
	}
}

void StateMachine::Update(float fDetaTime)
{
	if (m_StateList.Size() <= 0)
		return;

	if (m_Stack.Size() < 0)
		return;

	m_Stack.Top()->OnUpdate(fDetaTime, this);
}

void StateMachine::Draw(Renderer2D * m_2dRenderer)
{

	if (m_StateList.Size() < 0)
		return;

	m_Stack.Top()->OnDraw(m_2dRenderer);
}

void StateMachine::PushState(int nStateIndex)
{
	_ASSERT(nStateIndex < m_StateList.Size());
	//assert(nStateIndex < m_StateList.Size());
	if (nStateIndex >= m_StateList.Size())
		return;

	if (m_Stack.Size() > 0)
		m_Stack.Top()->OnExit();

	m_Stack.Push(m_StateList[nStateIndex]);

	m_Stack.Top()->OnEnter();
}

void StateMachine::RegisterState(int nStateIndex, BaseState* pState)
{
	m_StateList.Insert(nStateIndex, pState);
}

void StateMachine::PopState()
{

}