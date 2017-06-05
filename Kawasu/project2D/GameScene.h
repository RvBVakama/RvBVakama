//--------------------------------------------------------------------------------------
// Class for the GameScene
//--------------------------------------------------------------------------------------
#pragma once

#include "Texture.h"
#include "Renderer2d.h"
#include "Entity.h"

using namespace aie;

//--------------------------------------------------------------------------------------
// Player object
// Stores data used by the player, handles rendering and input.
// Inherits from Entity.
//--------------------------------------------------------------------------------------
class GameScene : public Entity
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	GameScene();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~GameScene();

	//--------------------------------------------------------------------------------------
	// Does nothing/might be used at later development.
	//
	// Param:
	//		deltaTime: It's not used.
	//--------------------------------------------------------------------------------------
	void Update(float deltaTime);
	
	//--------------------------------------------------------------------------------------
	// Draws the GameScene texture.
	//
	// Param:
	//		m_2dRenderer: Passes in the renderer to allow for drawing trxtures.
	//--------------------------------------------------------------------------------------
	void Draw(Renderer2D* m_2dRenderer);

private:
	//the GameScene texture
	aie::Texture* m_gameSceneTexture;
};

