#include "Agent.h"
#include "stateAgent.h"

Agent::Agent()
{
	//stateAgent* m_pStateAgent = new stateAgent;
};

Agent::~Agent()
{
};

void Agent::Update(float deltaTime)
{
	for (auto& behaviour : m_behaviours)
		behaviour->Update(this, deltaTime);
}

void Agent::Draw(Renderer2D* m_pRenderer2D)
{

};
