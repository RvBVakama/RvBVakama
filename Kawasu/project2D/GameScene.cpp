#include "GameScene.h"

//--------------------------------------------------------------------------------------
// Default Constructor
//--------------------------------------------------------------------------------------
GameScene::GameScene()
{
	m_gameSceneTexture = new Texture("./textures/gameScene.png");
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
GameScene::~GameScene()
{
	delete m_gameSceneTexture;
}

//--------------------------------------------------------------------------------------
// Does nothing/might be used at later development.
//
// Param:
//		deltaTime: It's not used.
//--------------------------------------------------------------------------------------
void GameScene::Update(float deltaTime)
{
}

//--------------------------------------------------------------------------------------
// Draws the GameScene texture.
//
// Param:
//		m_2dRenderer: Passes in the renderer to allow for drawing trxtures.
//--------------------------------------------------------------------------------------
void GameScene::Draw(Renderer2D * m_2dRenderer)
{
	m_2dRenderer->drawSpriteTransformed3x3(m_gameSceneTexture, globalTransform);
}