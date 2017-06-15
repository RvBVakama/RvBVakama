#include "Menu.h"
#include "StateMachine.h"
#include "Define.h"
#include "Input.h"

Menu::Menu()
{
	m_titleMenu = new Texture("./textures/titleMenu.png");
	m_buttonBeginUP = new Texture("./textures/buttonBeginUP.png");
	m_buttonBeginDOWN = new Texture("./textures/buttonBeginDOWN.png");
	m_buttonExitUP = new Texture("./textures/buttonExitUP.png");
	m_buttonExitDOWN = new Texture("./textures/buttonExitDOWN.png");

	m_pos.x = SCREENX / 2;
	m_pos.y = SCREENY / 2;
}

Menu::~Menu()
{
	delete m_titleMenu;
	delete m_buttonBeginUP;
	delete m_buttonBeginDOWN;
	delete m_buttonExitUP;
	delete m_buttonExitDOWN;
}

void Menu::OnEnter()
{
}

void Menu::OnUpdate(float deltaTime, StateMachine* stateMachine)
{
	aie::Input* input = aie::Input::getInstance();

	int fMouseX = input->getMouseX();
	int fMouseY = input->getMouseY();

	nMenuNo = E_NONE;

	if (fMouseX > 290 && fMouseX < 746 && fMouseY > 330 && fMouseY < 469)
	{
		// if mouse button is pressed at all it always thinks it is up even after clicking off
		if (input->isMouseButtonDown(INPUT_MOUSE_BUTTON_LEFT))
			nMenuNo = E_BEGIN;

		if (input->isMouseButtonUp(INPUT_MOUSE_BUTTON_LEFT))
			stateMachine->PushState(E_GAMESCENE);

		printf("resume");
	}

	if (fMouseX > 364 && fMouseX < 672 && fMouseY > 83 && fMouseY < 177)
	{
		if (input->isMouseButtonDown(INPUT_MOUSE_BUTTON_LEFT))
			nMenuNo = E_EXIT;
		printf("exit");
		//quit
	}

	if (input->wasKeyPressed(aie::INPUT_KEY_ESCAPE))
	{
		//quit
	}
}

void Menu::OnDraw(Renderer2D * m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_titleMenu, m_pos.x, m_pos.y, 0, 0, 0, 1);
	m_2dRenderer->drawSprite(m_buttonBeginUP, m_pos.x, m_pos.y, 0, 0, 0, 0);
	m_2dRenderer->drawSprite(m_buttonExitUP, m_pos.x, m_pos.y - 270, 0, 0, 0, 0);

	switch (nMenuNo)
	{
	case E_BEGIN:
		m_2dRenderer->drawSprite(m_buttonBeginDOWN, m_pos.x, m_pos.y, 0, 0, 0, 0);
		printf("tex");
		break;
	case E_EXIT:
		m_2dRenderer->drawSprite(m_buttonExitDOWN, m_pos.x, m_pos.y - 270, 0, 0, 0, 0);
		printf("tex");
		break;

	default:
		break;
	}
}

void Menu::OnExit()
{
}
