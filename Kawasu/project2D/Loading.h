//--------------------------------------------------------------------------------------
// Class for Loading
//--------------------------------------------------------------------------------------
#pragma once

#include "Texture.h"
#include "Renderer2d.h"
#include "BaseState.h"

using namespace aie;

//--------------------------------------------------------------------------------------
// Player object
// Stores data used by the player, handles rendering and input.
// Inherits from Entity.
//--------------------------------------------------------------------------------------
class Loading : public BaseState
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	Loading();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~Loading();

	//optional extra to reinitialize anything you need to
	void OnEnter();

	//--------------------------------------------------------------------------------------
	// Does nothing/might be used at later development.
	//
	// Param:
	//		deltaTime: It's not used.
	//--------------------------------------------------------------------------------------
	void OnUpdate(float deltaTime, StateMachine* StateMachine);

	//--------------------------------------------------------------------------------------
	// Draws the Loading texture.
	//
	// Param:
	//		m_2dRenderer: Passes in the renderer to allow for drawing trxtures.
	//--------------------------------------------------------------------------------------
	void OnDraw(Renderer2D* m_2dRenderer);

	//optional extra to deinitialize anything you need to
	void OnExit();

private:
	//the Laoding Screen texture
	aie::Texture* m_Loading;
	int m_nTimer;
};
