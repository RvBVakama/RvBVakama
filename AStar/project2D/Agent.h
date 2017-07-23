#pragma once

#include "IBehaviour.h"
#include "Vector2.h"
#include <vector>

class StateMachine;

class Agent
{
public:
	Agent();

	~Agent();

	virtual void Update(float deltaTime);

protected:
	
	std::vector<IBehaviour *> m_behaviours;

	Vector2 m_force;
	Vector2 m_acceleration;
	Vector2 m_velocity;
	Vector2 m_position;

private:
	StateMachine*		m_StateMachine;
};
