#pragma once
#include "Agent.h"
#include "Renderer2D.h"
#include <vector>
#include "AStarNode.h"

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
	void Draw(Renderer2D* pRenderer2D);


private:
	vector<AStarNode*> m_path;
	
	AIStateMachine*		m_pAIStateMachine;
	statePatrol*		m_pStatePatrol;
	stateIdle*			m_pStateIdle;
};
