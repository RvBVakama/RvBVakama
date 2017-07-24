#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"

struct GridNode;
class AStar;
class StateMachine;
class Agent;
class DecisionTree;
class Player;

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

private:
	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	aie::Audio*			m_audio;
	GridNode**			m_ppGrid;
	Agent*				m_pAgent;
	StateMachine*		m_pStateMachine;
	Player*				m_pPlayer;
	DecisionTree*		m_pDecisionTree;

	float m_cameraX, m_cameraY;
};