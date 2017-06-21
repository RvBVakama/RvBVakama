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
//#include "Texture.h"
#include "ObjectPool.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() 
{
	m_2dRenderer = new aie::Renderer2D();

	CollisionManager::Create();

	CollisionManager* pPtr = CollisionManager::GetInstance();

	m_texture = new aie::Texture("./textures/numbered_grid.tga");

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_audio = new aie::Audio("./audio/powerup.wav");

	m_StateMachine = new StateMachine();

	ResourceManager<Texture>::Create();

	m_BG = new GameScene();

	m_MenuPause = new MenuPause();

	m_Loading = new Loading();

	m_titleMenu = new Menu();

	m_Splash = new Splash();

	m_BombObj = new ObjectPool(1024);

	m_Bomb = m_BombObj->Allocate();

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
	
	delete m_Bomb;
	delete m_Splash;
	delete m_titleMenu;
	delete m_Loading;
	delete m_MenuPause;
	delete m_BG;
	ResourceManager<Texture>::Destroy();
	delete m_StateMachine;
	delete m_audio;
	delete m_font;
	delete m_texture;
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