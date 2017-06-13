//--------------------------------------------------------------------------------------
// Class for Splash
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
class Splash : public BaseState
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	Splash();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~Splash();

	//optional extra to reinitialize anything you need to
	void OnEnter();

	//--------------------------------------------------------------------------------------
	// Does nothing/might be used at later development.
	//
	// Param:
	//		deltaTime: It's not used.
	//--------------------------------------------------------------------------------------
	void OnUpdate(float deltaTime, StateMachine* stateMachine);

	//--------------------------------------------------------------------------------------
	// Draws the Splash texture.
	//
	// Param:
	//		m_2dRenderer: Passes in the renderer to allow for drawing trxtures.
	//--------------------------------------------------------------------------------------
	void OnDraw(Renderer2D* m_2dRenderer);

	//optional extra to deinitialize anything you need to
	void OnExit();

private:
	//the Laoding Screen texture
	aie::Texture* m_splash;
	float m_fTimer;
};
