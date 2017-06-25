#pragma once

#include "Texture.h"
#include "Renderer2d.h"
#include "BaseState.h"
#include "Vector2.h"
#include "Input.h"

using namespace aie;

class MenuPause : public BaseState
{
public:
	MenuPause();
	~MenuPause();

	//optional extra to reinitialize anything you need to
	void OnEnter();

	void OnUpdate(float deltaTime, StateMachine* stateMachine);

	void OnDraw(Renderer2D* m_2dRenderer);

	//--------------------------------------------------------------------------------------
	// OnExit is ran whenever the stack has more than 0 states.
	//--------------------------------------------------------------------------------------
	void OnExit();
	
private:
	enum MenuSelector
	{
		E_RESUME,
		E_DONATE,
		E_EXIT,
		E_NONE
	};
	MenuSelector nMenuNo;

	Vector2 m_pos;
	Texture* m_MenuPause;
	Texture* m_MenuSelect;
};
