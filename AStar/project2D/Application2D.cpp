#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "StateMachine.h"
#include "ResourceManager.h"
#include "CollisionManager.h"
#include "Define.h"
#include "GridNode.h"
#include "AStarNode.h"
#include "DecisionTree.h"
#include "Agent.h"
#include "stateAgent.h"
#include "statePatrol.h"
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------
// Default Constructor
// ---------------------------------------------------------------------------------
Application2D::Application2D() {

}

// ---------------------------------------------------------------------------------
// Default Destructor
// ---------------------------------------------------------------------------------
Application2D::~Application2D() {

}
// ---------------------------------------------------------------------------------
// Creates the renderer, collision manager, my resource manager and my state
// manager then registers all possible states and pushes my spash screen state.
// 
// Return:
// 		Returns true.
// ---------------------------------------------------------------------------------
bool Application2D::startup()
{
	// Creating everything
	m_2dRenderer = new aie::Renderer2D();
	_ASSERT(m_2dRenderer);

	CollisionManager::Create();

	CollisionManager* pPtr = CollisionManager::GetInstance();

	ResourceManager<Texture>::Create();

	m_pDecisionTree = new DecisionTree;
	
	m_pAgent = new Agent;

	m_pStateAgent = new stateAgent;

	m_pStateMachine = new StateMachine();
	_ASSERT(m_pStateMachine);


	m_cameraX = -15;
	m_cameraY = -15;

	m_ppGrid = new GridNode*[GRID_SIZE * GRID_SIZE];

	for (int x = 0; x < GRID_SIZE; ++x)
	{
		for (int y = 0; y < GRID_SIZE; ++y)
		{
			// Calculate the index of the node from the x and y.
			int index = (y * GRID_SIZE) + x;
			
			// Calculate position of node in game world.
			Vector2 pos((float)x * NODE_SIZE, (float)y * NODE_SIZE);

			// Create the node.
			m_ppGrid[index] = new GridNode(pos, index ,x, y);

			if (x % 3 == 0 && y != 15)
			{
				m_ppGrid[index]->m_bBlocked = true;
			}
		}
	}

	// Connect up adjacent nodes.
	for (int x = 0; x < GRID_SIZE; ++x)
	{
		for (int y = 0; y < GRID_SIZE; ++y)
		{
			int index = (y * GRID_SIZE) + x;

			GridNode* currentNode = m_ppGrid[index];
			
			// Adjacent nodes
			// ---------
			//	-  3  -
			//	0  C  2
			//	-  1  -
			// ---------
			for (int a = 0; a < 4; ++a)
			{
				// Work out which are the adjacent nodes
				int localX = x;
				int localY = y;
				
				if (a % 2 == 0) // Check if number is even
					localX += a - 1;
				else
					localY += a - 2;

				if (localX < 0 || localX >= GRID_SIZE)
					continue;

				if (localY < 0 || localY >= GRID_SIZE)
					continue;

				int localIndex = (localY * GRID_SIZE) + localX;
				//int i = ((y + (a - 2)) * GRID_SIZE) + (x + (a-1));
				GridNode* adjNode = m_ppGrid[localIndex];
			
			// Connect adjacency
				AStarEdge* pEdge = new AStarEdge();
				pEdge->m_pEndNode = adjNode;
				pEdge->m_nCost = ADJACENT_COST;

				currentNode->m_AdjacentList.push_back(pEdge);
			}

			// Diagonal nodes.
			for (int d = 0; d < 4; ++d)
			{
				// Work out which are the adjacent nodes
				int localX = x;
				int localY = y;
				
				if (d % 2 == 0)
				{
					localX += d - 1;
					localY += d - 1;
				}

				else
				{
					localX += d - 2;
					localY -= d - 2;
				}

				if (localX < 0 || localX >= GRID_SIZE)
					continue;

				if (localY < 0 || localY >= GRID_SIZE)
					continue;

				int localIndex = (localY * GRID_SIZE) + localX;
				//int i = ((y + (a - 2)) * GRID_SIZE) + (x + (a-1));
				GridNode* adjNode = m_ppGrid[localIndex];
			
				// Connect adjacency
				AStarEdge* pEdge = new AStarEdge();
				pEdge->m_pEndNode = adjNode;
				pEdge->m_nCost = DIAGONAL_COST;

				currentNode->m_AdjacentList.push_back(pEdge);
			}

		}
	}

	statePatrol::InstStatePatrol(m_ppGrid);
	
	return true;
}

// ---------------------------------------------------------------------------------
// Deletes and destroys all managers, states etc... to prevent memory leaks.
// ---------------------------------------------------------------------------------
void Application2D::shutdown() {

	delete m_pDecisionTree;
	delete m_pAgent;

	for (int i = 0; i < GRID_SIZE * GRID_SIZE; ++i)
	{
		delete m_ppGrid[i];
	}

	delete[] m_ppGrid;

	ResourceManager<Texture>::Destroy();
	CollisionManager::Destroy();
	delete m_2dRenderer;
}

// ---------------------------------------------------------------------------------
// Updates the state machine and checks if the user has clicked the end key and
// ends the game.
// 
// Param:
// 		deltaTime: delta time simply is seconds as a float value. It is passed into 
// the state machine's update function.
// ---------------------------------------------------------------------------------
void Application2D::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();
	
	// Updating the Agent
	m_pAgent->Update(deltaTime);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_END))
		quit();

	//statePatrol::InstStatePatrol()->OnUpdate(deltaTime);

	//m_pPlayer->Update(deltaTime);

	m_pDecisionTree->Update(nullptr, deltaTime);

}

// ---------------------------------------------------------------------------------
// Clears the screen then begins the 2d renderer then draws the state machine
// by passing in the 2d renderer, finally ending the 2d renderer.
// ---------------------------------------------------------------------------------
void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	m_2dRenderer->begin();

	for (int i = 0; i < GRID_SIZE * GRID_SIZE; ++i)
	{
			if (m_ppGrid[i]->m_bBlocked)
				m_2dRenderer->setRenderColour(0x003366FF);
			else
				m_2dRenderer->setRenderColour(0xB2E076FF);
		
		float x = m_ppGrid[i]->m_v2Pos.x;
		float y = m_ppGrid[i]->m_v2Pos.y;
		m_2dRenderer->drawBox(x, y, NODE_SIZE - GRID_SPACING, NODE_SIZE - GRID_SPACING);
	
		for (size_t a = 0; a < m_ppGrid[i]->m_AdjacentList.size(); ++a)
		{

			GridNode* otherNode = ((GridNode*)m_ppGrid[i]->m_AdjacentList[a]->m_pEndNode);

			float otherX = otherNode->m_v2Pos.x;
			float otherY = otherNode->m_v2Pos.y;
			//m_2dRenderer->setRenderColour(0xFF0000FF);
			//m_2dRenderer->drawLine(x, y, otherX, otherY, EDGE_THICKNESS);
			//m_2dRenderer->setRenderColour(0xFFFFFFFF);
		}

	}


	aie::Input* input = aie::Input::getInstance();

	int fMouseX = input->getMouseX();
	int fMouseY = input->getMouseY();

	//m_pPlayer->Draw(m_2dRenderer);

	////Draw Path
	//vector<AStarNode*> path;

	//if (nTime < 900)
	//	m_pAStar->CalculatePath(m_ppGrid[1], m_ppGrid[nTime], &path);

	//for (size_t i = 0; i < path.size(); ++i)
	//{
	//	GridNode* pNode = (GridNode*)path[i];

	//	m_2dRenderer->setRenderColour(0x00FF00FF);
	//	m_2dRenderer->drawBox(pNode->m_v2Pos.x, pNode->m_v2Pos.y, NODE_SIZE / 0.9f, NODE_SIZE / 0.9f);
	//	m_2dRenderer->setRenderColour(0xFFFFFFFF);
	//}

	// m_pStateMachine->Draw(m_2dRenderer);

	m_2dRenderer->end();
}
