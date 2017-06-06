#include "MenuPause.h"



MenuPause::MenuPause()
{
	m_MenuPause = new Texture("./textures/pause.png");
}

MenuPause::~MenuPause()
{
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
	m_2dRenderer->drawSpriteTransformed3x3(m_MenuPause, globalTransform, 0, 0, -1);
	
	switch (nMenuNo)
	{
	case E_RESUME:

		break;
	case E_DONATE:

		break;
	case E_EXIT:

		break;

	default:
		break;
	}
}