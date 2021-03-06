#include "GameScene.h"
#include "Input.h"
#include "StateMachine.h"
#include "Define.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "ObjectPool.h"
#include "Bombs.h"

using namespace aie;

//--------------------------------------------------------------------------------------
// Default Constructor
// Sets the texture, creates a object pool that holds 1024 bomb objects.
// Sets some bools to safe initial values.
//--------------------------------------------------------------------------------------
GameScene::GameScene()
{
	m_BG = ResourceManager<Texture>::GetInstance()->LoadResource("./textures/bg.png");

	m_BombPool = new ObjectPool(1024);
	_ASSERT(m_BombPool);

	bBombSpawned = true;

	bDrawLowerState = false;

	bTrue = true;
	bTrue2 = false;
}

//--------------------------------------------------------------------------------------
// Default Destructor / Deletes things.
//--------------------------------------------------------------------------------------
GameScene::~GameScene()
{
	delete m_BombPool;
}

//--------------------------------------------------------------------------------------
// OnEnter is ran whenever a state is pushed.
//--------------------------------------------------------------------------------------
void GameScene::OnEnter()
{
}

//--------------------------------------------------------------------------------------
// Does nothing/might be used at later development.
//
// Param:
//		deltaTime: Passed into bombArray's update function which currently does nothing.
//--------------------------------------------------------------------------------------
void GameScene::OnUpdate(float deltaTime, StateMachine* stateMachine)
{
	if (bBombSpawned)
	{
		m_Bomb = m_BombPool->Allocate();

		m_Bomb->setPos(Vector2(518, 588), Vector2(-18, -24), Vector2(18, 24));

		m_BombArray.PushBack(m_Bomb);

		bBombSpawned = false;
	}

	for (int i = 0; i < m_BombArray.Size(); ++i)
		m_BombArray[i]->Update(deltaTime);

	Input* input = Input::getInstance();

	if (input->wasKeyPressed(aie::INPUT_KEY_ESCAPE))
	{
		int nResult = stateMachine->PushState(E_MENUPAUSE);
		_ASSERT(nResult == SUCCESS);

		stateMachine->bDrawLowerState = true;
	}
}

//--------------------------------------------------------------------------------------
// Draws the GameScene texture.
//
// Param:
//		m_2dRenderer: Passes in the renderer to allow for drawing textures.
//--------------------------------------------------------------------------------------
void GameScene::OnDraw(Renderer2D * m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_BG, SCREENX / 2, SCREENY / 2, 0, 0, 0, 100);
	
	for (int i = 0; i < m_BombArray.Size(); ++i)
		m_BombArray[i]->Draw(m_2dRenderer);
}

//--------------------------------------------------------------------------------------
// OnExit is ran whenever the stack has more than 0 states.
//--------------------------------------------------------------------------------------
void GameScene::OnExit()
{
}
