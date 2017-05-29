#include "Menu.h"



Menu::Menu()
{
	m_pLogo = nullptr;
	m_pPlayButton = nullptr;
}

Menu::~Menu()
{
	delete m_pLogo;
	delete m_pPlayButton;
}

void Menu::OnEnter()
{

}

void Menu::OnUpdate(float deltaTime)
{

	m_pLogo = new Texture("./textures/spikeup.png");
	m_pPlayButton = new Texture("./textures/spikedown.png");
}

void Menu::OnExit()
{
	if (m_pLogo)
	{
		delete m_pLogo;
		m_pLogo = nullptr;
	}

	if (m_pPlayButton)
	{
		delete m_pPlayButton;
		m_pPlayButton = nullptr;
	}
}

void Menu::OnDraw(Renderer2D* renderer2d)
{

}