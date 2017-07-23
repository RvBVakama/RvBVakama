#include "Agent.h"
#include "StateMachine.h"

Agent::Agent()
{	
	m_StateMachine = new StateMachine();
 	_ASSERT(m_StateMachine);
};

Agent::~Agent()
{
};

void Agent::Update(float deltaTime)
{
	for (auto& behaviour : m_behaviours)
		behaviour->Update(this, deltaTime);
};
