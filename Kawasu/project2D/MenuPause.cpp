#include "MenuPause.h"
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

void MenuPause::Update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	int fMouseX = input->getMouseX();
	int fMouseY = input->getMouseY();

	if (fMouseX > -290 && fMouseX < 290 && fMouseY > 100 && fMouseY < 150)
	{
		nMenuNo = E_RESUME;
	}
	
	if (fMouseX > -290 && fMouseX < 290 && fMouseY > 100 && fMouseY < 150)
	{
		nMenuNo = E_DONATE;
	}

	if (fMouseX > -290 && fMouseX < 290 && fMouseY > 100 && fMouseY < 150)
	{
		nMenuNo = E_EXIT;
	}

}

void MenuPause::Draw(Renderer2D * m_2dRenderer)
{
//	m_2dRenderer->drawSpriteTransformed3x3(m_MenuPause, globalTransform);
	m_2dRenderer->drawSprite(m_MenuPause, m_pos.x, m_pos.y);

	switch (nMenuNo)
	{
	case E_RESUME:
		m_2dRenderer->drawSpriteTransformed3x3(m_MenuSelect, globalTransform, 0, 0, -2);
		printf("resume");
		break;
	case E_DONATE:
		m_2dRenderer->drawSpriteTransformed3x3(m_MenuSelect, globalTransform, 0, 0, -2);
		printf("donate");
		break;
	case E_EXIT:
		m_2dRenderer->drawSpriteTransformed3x3(m_MenuSelect, globalTransform, 0, 0, -2);
		printf("exit");
		break;

	default:
		break;
	}
}