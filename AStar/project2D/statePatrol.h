#pragma once
#include "BaseState.h"
#include "Agent.h"
#include "Vector2.h"
#include "Entity.h"
#include "Renderer2D.h"
#include "AStar.h"
#include "GridNode.h"

class StateMachine;

class statePatrol : public BaseState
{
public:
	statePatrol();
	~statePatrol();

	void OnEnter();
	void OnUpdate(float fDeltaTime);
	void OnDraw(Renderer2D* m_pRenderer2D);
	void OnExit();

private:
	Vector2				m_v2Pos;
	AStar*				m_pAStar;

	//GridNode**			m_ppGrid;

	vector<AStarNode*> m_path;

	unsigned int m_nNextNode;
	int nTime;
};
