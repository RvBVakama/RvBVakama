#include "Agent.h"

Agent::Agent()
{	
};

Agent::~Agent()
{
};

void Agent::Update(float deltaTime)
{
	for (auto& behaviour : m_behaviours)
		behaviour->Update(this, deltaTime);
};
