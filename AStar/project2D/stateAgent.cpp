#include "stateAgent.h"
#include "StateMachine.h"
#include "statePatrol.h"
#include "stateIdle.h"
#include "Define.h"

stateAgent::stateAgent()
{
	m_pStateMachine = new StateMachine();
	_ASSERT(m_pStateMachine);

	/*m_pStatePatrol = new statePatrol();
	_ASSERT(m_pStatePatrol);*/

	m_pStateIdle = new stateIdle();
	_ASSERT(m_pStateIdle);

	// Registering all possible states
	m_pStateMachine->RegisterState(E_STATEPATROL, m_pStatePatrol);
	m_pStateMachine->RegisterState(E_STATEIDLE, m_pStateIdle);
}

stateAgent::~stateAgent()
{
	delete m_pStateMachine;
	delete m_pStateIdle;
	delete m_pStatePatrol;
}

void stateAgent::Update(float deltaTime)
{

}