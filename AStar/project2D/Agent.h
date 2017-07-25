#pragma once
#include "IBehaviour.h"
#include "Vector2.h"
#include "Renderer2D.h"
#include <vector>

class stateAgent;

using namespace aie;

class Agent
{
public:
	Agent();

	~Agent();

	virtual void Update(float deltaTime);
	virtual void Draw(Renderer2D* m_pRenderer2D);

protected:
	std::vector<IBehaviour *> m_behaviours;

	stateAgent* m_pStateAgent;

	Vector2 m_force;
	Vector2 m_acceleration;
	Vector2 m_velocity;
	Vector2 m_position;
};
