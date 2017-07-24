#pragma once
#include "BaseState.h"

class StateMachine;

class stateIdle : public BaseState
{
public:
	stateIdle();
	~stateIdle();

	void OnEnter();
	void OnUpdate(float fDeltaTime);
	void OnDraw(Renderer2D* renderer2d);
	void OnExit();
};

