#pragma once
#include "BaseState.h"

class StateMachine;

class statePatrol : public BaseState
{
public:
	statePatrol();
	~statePatrol();

	void OnEnter();
	void OnUpdate(float deltaTime, StateMachine* stateMachine);
	void OnDraw(Renderer2D* renderer2d);
	void OnExit();
};

