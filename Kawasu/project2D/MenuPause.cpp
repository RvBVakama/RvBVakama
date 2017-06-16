#include "MenuPause.h"
#include "StateMachine.h"
#include "Define.h"

MenuPause::MenuPause()
{
	m_MenuPause = new Texture("./textures/pause.png");
	m_MenuSelect = new Texture("./textures/selector.png");
	
	m_pos.x = SCREENX / 2;
	m_pos.y = SCREENY / 2;
}

MenuPause::~MenuPause()
{
	delete m_MenuSelect;
	delete m_MenuPause;
}

void MenuPause::OnEnter()
{
}

void MenuPause::OnUpdate(float deltaTime, StateMachine* stateMachine)
{
	aie::Input* input = aie::Input::getInstance();

	int fMouseX = input->getMouseX();
	int fMouseY = input->getMouseY();

	nMenuNo = E_NONE;

	if (fMouseX > 320 && fMouseX < 726 && fMouseY > 466 && fMouseY < 540)
	{
		nMenuNo = E_RESUME;

		if (input->wasMouseButtonPressed(INPUT_MOUSE_BUTTON_LEFT))
				stateMachine->PushState(E_GAMESCENE);

		printf("resume");
	}
	
	if (fMouseX > 310 && fMouseX < 730 && fMouseY > 346 && fMouseY < 466)
	{
		nMenuNo = E_DONATE;
		printf("donate");
	}

	if (fMouseX > 380 && fMouseX < 658 && fMouseY > 256 && fMouseY < 332)
	{
		nMenuNo = E_EXIT;
		printf("exit");
		//quit
	}
	
	if (input->wasKeyPressed(aie::INPUT_KEY_ESCAPE))
	{
			stateMachine->PushState(E_GAMESCENE);
	}
}

void MenuPause::OnDraw(Renderer2D * m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_MenuPause, m_pos.x, m_pos.y, 0, 0, 0, 1);

	switch (nMenuNo)
	{
	case E_RESUME:
		m_2dRenderer->drawSprite(m_MenuSelect, m_pos.x, m_pos.y - (-112), 0, 0, 0, 0);
		printf("tex");
		break;
	case E_DONATE:
		m_2dRenderer->drawSprite(m_MenuSelect, m_pos.x, m_pos.y, 0, 0, 0, 0);
		printf("tex");
		break;
	case E_EXIT:
		m_2dRenderer->drawSprite(m_MenuSelect, m_pos.x, m_pos.y - 123, 0, 0, 0, 0);
		printf("tex");
		break;

	default:
		break;
	}
}

void MenuPause::OnExit()
{
}
