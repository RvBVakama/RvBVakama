#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"

class StateMachine;
class MenuPause;
class GameScene;
class Loading;
class Menu;
class Splash;
class ObjectPool;
class Bombs;

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

private:
	MenuPause* m_MenuPause;
	GameScene* m_BG;
	Loading* m_Loading;
	Menu* m_titleMenu;
	Splash* m_Splash;
	ObjectPool* m_BombObj;
	Bombs* m_Bomb;

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	aie::Font*			m_font;
	aie::Audio*			m_audio;
	StateMachine*		m_StateMachine;

	float m_cameraX, m_cameraY;
};