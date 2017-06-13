#pragma once

#include "Texture.h"
#include "Renderer2d.h"
#include "BaseState.h"
#include "Vector2.h"
#include "Input.h"

using namespace aie;

class MenuPause : public BaseState
{
	enum MenuSelector
	{
		E_RESUME,
		E_DONATE,
		E_EXIT,
		E_NONE
	};

public:
	MenuPause();
	~MenuPause();

	//optional extra to reinitialize anything you need to
	void OnEnter();

	void OnUpdate(float deltaTime, StateMachine* StateMachine);

	void OnDraw(Renderer2D* m_2dRenderer);

	//optional extra to deinitialize anything you need to
	void OnExit();
	
private:
	Vector2 m_pos;
	Texture* m_MenuPause;
	Texture* m_MenuSelect;
	MenuSelector nMenuNo;
};
