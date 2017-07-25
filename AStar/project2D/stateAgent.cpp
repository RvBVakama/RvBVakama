#include "stateAgent.h"
#include "AIStateMachine.h"
#include "statePatrol.h"
#include "stateIdle.h"
#include "Define.h"
#include "Renderer2D.h"

stateAgent::stateAgent()
{
	m_pAIStateMachine = new AIStateMachine();
	_ASSERT(m_pAIStateMachine);

	m_pStatePatrol = new statePatrol();
	_ASSERT(m_pStatePatrol);

	m_pStateIdle = new stateIdle();
	_ASSERT(m_pStateIdle);

	// Registering all possible states
	m_pAIStateMachine->RegisterState(E_STATEPATROL, m_pStatePatrol);
	m_pAIStateMachine->RegisterState(E_STATEIDLE, m_pStateIdle);

	m_pAIStateMachine->PushState(E_STATEPATROL);
}

stateAgent::~stateAgent()
{
	delete m_pAIStateMachine;
	delete m_pStateIdle;
	delete m_pStatePatrol;
}

void stateAgent::Update(float deltaTime)
{
	m_pAIStateMachine->Update(deltaTime);
	m_pStatePatrol->OnUpdate(deltaTime);
}

void stateAgent::Draw(Renderer2D* m_pRenderer2D)
{
	m_pStatePatrol->OnDraw(m_pRenderer2D);
}
