#pragma once
#include "BaseState.h"
#include "Texture.h"
#include "Vector2.h"

using namespace aie;

class Menu : public BaseState
{
public:
	Menu();
	~Menu();

	void OnEnter();
	void OnUpdate(float deltaTime, StateMachine* StateMachine);
	void OnDraw(Renderer2D* renderer2d);
	void OnExit();

private:
	enum MenuSelector
	{
		E_BEGIN,
		E_EXIT,
		E_NONE
	};
	MenuSelector nMenuNo;

	Texture* 	m_titleMenu;
	Texture* 	m_buttonBeginUP;
	Texture* 	m_buttonBeginDOWN;
	Texture* 	m_buttonExitUP;
	Texture* 	m_buttonExitDOWN;
	Vector2 m_pos;
};