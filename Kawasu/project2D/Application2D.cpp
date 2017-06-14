#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "MenuPause.h"
#include "GameScene.h"
#include "Loading.h"
#include "Splash.h"
#include "StateMachine.h"
#include "Define.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	m_texture = new aie::Texture("./textures/numbered_grid.tga");

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_audio = new aie::Audio("./audio/powerup.wav");

	m_StateMachine = new StateMachine();

	m_BG = new GameScene();

	m_MenuPause = new MenuPause();

	m_Loading = new Loading();

	m_Splash = new Splash();

	m_StateMachine->RegisterState(E_GAMESCENE, m_BG);
	m_StateMachine->RegisterState(E_MENUPAUSE, m_MenuPause);
	m_StateMachine->RegisterState(E_LOADING, m_Loading);
	m_StateMachine->RegisterState(E_SPLASH, m_Splash);

	m_StateMachine->PushState(E_SPLASH);

	m_cameraX = 0;
	m_cameraY = 0;
	
	return true;
}

void Application2D::shutdown() {
	
	delete m_Splash;
	delete m_Loading;
	delete m_BG;
	delete m_MenuPause;
	delete m_audio;
	delete m_font;
	delete m_texture;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// use arrow keys to move camera
	if (input->isKeyDown(aie::INPUT_KEY_UP))
		m_cameraY += 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		m_cameraY -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		m_cameraX -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		m_cameraX += 500.0f * deltaTime;
	
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