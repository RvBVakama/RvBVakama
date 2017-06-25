//--------------------------------------------------------------------------------------
// Class for the GameScene
//--------------------------------------------------------------------------------------
#pragma once

#include "Texture.h"
#include "Renderer2d.h"
#include "DynamicArray.h"
#include "BaseState.h"

class ObjectPool;
//class DynamicArray;
class Bombs;

using namespace aie;

//--------------------------------------------------------------------------------------
// Player object
// Stores data used by the player, handles rendering and input.
// Inherits from Entity.
//--------------------------------------------------------------------------------------
class GameScene : public BaseState
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
	// OnEnter is ran whenever a state is pushed.
	//--------------------------------------------------------------------------------------
	void OnEnter();

	//--------------------------------------------------------------------------------------
	// Does nothing/might be used at later development.
	//
	// Param:
	//		deltaTime: It's not used.
	//--------------------------------------------------------------------------------------
	void OnUpdate(float deltaTime, StateMachine* stateMachine);
	
	//--------------------------------------------------------------------------------------
	// Draws the GameScene texture.
	//
	// Param:
	//		m_2dRenderer: Passes in the renderer to allow for drawing trxtures.
	//--------------------------------------------------------------------------------------
	void OnDraw(Renderer2D* m_2dRenderer);

	//--------------------------------------------------------------------------------------
	// OnExit is ran whenever the stack has more than 0 states.
	//--------------------------------------------------------------------------------------
	void OnExit();

	bool bDrawLowerState;

private:
	//the GameScene texture
	aie::Texture* m_BG;
	ObjectPool* m_BombPool;
	DynamicArray<Bombs*> m_BombArray;
	Bombs* m_Bomb;

	bool bBombSpawned;
	bool bTrue;
	bool bTrue2;
};
