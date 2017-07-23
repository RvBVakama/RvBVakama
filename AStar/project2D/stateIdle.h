#pragma once
#include "BaseState.h"

class StateMachine;

class stateIdle : public BaseState
{
public:
	stateIdle();
	~stateIdle();

	void OnEnter();
	void OnUpdate(float deltaTime, StateMachine* stateMachine);
	void OnDraw(Renderer2D* renderer2d);
	void OnExit();
};

