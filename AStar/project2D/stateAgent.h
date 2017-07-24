#pragma once
#include "Agent.h"

class StateMachine;
class statePatrol;
class stateIdle;

class stateAgent : public Agent
{
	public:
		stateAgent();
		~stateAgent();
	
		void Update(float deltaTime);

	private:
		StateMachine*		m_pStateMachine;
		statePatrol*		m_pStatePatrol;
		stateIdle*			m_pStateIdle;
};

