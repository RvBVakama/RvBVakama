#pragma once
#include "BaseState.h"

class Game : public BaseState
{
public:
	Game();
	~Game();

	void OnEnter();
	void OnUpdate(float deltaTime, StateMachine* StateMachine);
	void OnDraw(Renderer2D* renderer2d);
	void OnExit();

};

