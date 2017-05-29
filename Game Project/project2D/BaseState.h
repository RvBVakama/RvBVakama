#pragma once
#include "Renderer2D.h"

using namespace aie;

class BaseState
{
public:
	BaseState();
	~BaseState();

	virtual void OnEnter() = 0;
	virtual void OnUpdate(float deltaTime) = 0;
	virtual void OnDraw(Renderer2D* renderer2d) = 0;
	virtual void OnExit() = 0;
};

