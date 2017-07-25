#pragma once
#include "Agent.h"
#include "Renderer2D.h"

using namespace aie;

class AIStateMachine;
class statePatrol;
class stateIdle;

class stateAgent : public Agent
{
public:
	stateAgent();
	~stateAgent();

	void Update(float deltaTime);
	void Draw(Renderer2D* m_pRenderer2D);

private:
	AIStateMachine*		m_pAIStateMachine;
	statePatrol*		m_pStatePatrol;
	stateIdle*			m_pStateIdle;
};
