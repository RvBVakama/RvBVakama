#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"

struct GridNode;
class AStar;
class StateMachine;
class statePatrol;
class stateIdle;
class Agent;

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();
	int nTime;

private:
	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	aie::Audio*			m_audio;
	GridNode**			m_ppGrid;
	AStar*				m_pAStar;
	Agent*				m_pAgent;
	StateMachine*		m_StateMachine;
	statePatrol*		m_StatePatrol;
	stateIdle*			m_StateIdle;

	float m_cameraX, m_cameraY;
};