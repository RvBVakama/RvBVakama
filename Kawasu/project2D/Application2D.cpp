#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "MenuPause.h"
#include "GameScene.h"
#include "Loading.h"
#include "Menu.h"
#include "Splash.h"
#include "StateMachine.h"
#include "ResourceManager.h"
#include "CollisionManager.h"
#include "Define.h"
#include "ObjectPool.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() 
{
	m_2dRenderer = new aie::Renderer2D();
	_ASSERT(m_2dRenderer);

	CollisionManager::Create();

	CollisionManager* pPtr = CollisionManager::GetInstance();

	m_font = new aie::Font("./font/consolas.ttf", 32);
	_ASSERT(m_font);

	m_audio = new aie::Audio("./audio/powerup.wav");
	_ASSERT(m_audio);

	m_StateMachine = new StateMachine();
	_ASSERT(m_StateMachine);

	ResourceManager<Texture>::Create();

	m_BG = new GameScene();
	_ASSERT(m_BG);

	m_MenuPause = new MenuPause();
	_ASSERT(m_MenuPause);

	m_Loading = new Loading();
	_ASSERT(m_Loading);

	m_titleMenu = new Menu();
	_ASSERT(m_titleMenu);

	m_Splash = new Splash();
	_ASSERT(m_Splash);

	m_StateMachine->RegisterState(E_SPLASH, m_Splash);
	m_StateMachine->RegisterState(E_TITLEMENU, m_titleMenu);
	m_StateMachine->RegisterState(E_LOADING, m_Loading);
	m_StateMachine->RegisterState(E_GAMESCENE, m_BG);
	m_StateMachine->RegisterState(E_MENUPAUSE, m_MenuPause);

	m_StateMachine->PushState(E_SPLASH);

	m_cameraX = 0;
	m_cameraY = 0;
	return true;
}

void Application2D::shutdown() {
	
	delete m_Splash;
	delete m_titleMenu;
	delete m_Loading;
	delete m_MenuPause;
	delete m_BG;
	ResourceManager<Texture>::Destroy();
	delete m_StateMachine;
	delete m_audio;
	delete m_font;
	CollisionManager::Destroy();
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// example of audio
	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
		m_audio->play();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_END))
		quit();

	m_StateMachine->Update(deltaTime);
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	m_2dRenderer->begin();

	m_StateMachine->Draw(m_2dRenderer);
	
	m_2dRenderer->end();
}