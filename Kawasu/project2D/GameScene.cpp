#include "GameScene.h"
#include "Input.h"
#include "StateMachine.h"
#include "Define.h"

using namespace aie;

//--------------------------------------------------------------------------------------
// Default Constructor
//--------------------------------------------------------------------------------------
GameScene::GameScene()
{
	m_BG = new Texture("./textures/bg.png");
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
GameScene::~GameScene()
{
	delete m_BG;
}

void GameScene::OnEnter()
{
}

//--------------------------------------------------------------------------------------
// Does nothing/might be used at later development.
//
// Param:
//		deltaTime: It's not used.
//--------------------------------------------------------------------------------------
void GameScene::OnUpdate(float deltaTime, StateMachine* stateMachine)
{
	Input* input = Input::getInstance();

	if (input->wasKeyPressed(aie::INPUT_KEY_ESCAPE))
		stateMachine->SetState(E_MENUPAUSE);
}

//--------------------------------------------------------------------------------------
// Draws the GameScene texture.
//
// Param:
//		m_2dRenderer: Passes in the renderer to allow for drawing trxtures.
//--------------------------------------------------------------------------------------
void GameScene::OnDraw(Renderer2D * m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_BG, SCREENX / 2, SCREENY / 2, 0, 0, 0, 100);
}

void GameScene::OnExit()
{
}
