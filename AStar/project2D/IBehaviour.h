#pragma once

class Agent;

class IBehaviour
{
public:
	IBehaviour();
	~IBehaviour();

	virtual bool Update(Agent* agent, float deltaTime) = 0;
};
