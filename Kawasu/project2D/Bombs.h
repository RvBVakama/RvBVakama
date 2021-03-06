//--------------------------------------------------------------------------------------
// Class for Bombs
//--------------------------------------------------------------------------------------
#pragma once

#include "Texture.h"
#include "Renderer2d.h"
#include "Entity.h"

//using aie namespace
using namespace aie;

//--------------------------------------------------------------------------------------
// Spikes object
// Lots of spikes that surround the gamespace, these kill the player if they're touched.
// Inherits from Entity.
//--------------------------------------------------------------------------------------
class Bombs : public Entity
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor
	// -------------------------------------------------------------------------------------
	Bombs();
	
	//--------------------------------------------------------------------------------------
	// Default Constructor
	// 
	// Param:
	//		pos: The position of the borders.
	//		TL: Top left pixel to set the collision area.
	//		BR:	Bottom right pixel to set the collision area.
	//--------------------------------------------------------------------------------------
	Bombs(Vector2 pos, Vector2 TL, Vector2 BR);
	
	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~Bombs();

	//--------------------------------------------------------------------------------------
	// Set the bomb's position
// 
// Param:
//		pos: The position of the borders.
//		TL: Top left pixel to set the collision area.
//		BR:	Bottom right pixel to set the collision area.
	//--------------------------------------------------------------------------------------
	void setPos(Vector2 pos, Vector2 TL, Vector2 BR);

	//--------------------------------------------------------------------------------------
	// Prints "Crash" if something touches the spike.
	//
	// Param:
	//		deltaTime: this makes it possible to keep time.
	//--------------------------------------------------------------------------------------
	void Update(float deltaTime);

	//--------------------------------------------------------------------------------------
	// Draws the Spikes each frame.
	//
	// Param:
	//		m_2dRenderer: this makes it possible to render.
	//--------------------------------------------------------------------------------------
	void Draw(Renderer2D* m_2dRenderer);

private:
	//Textures for the different spike directions
	aie::Texture* m_BombTexture;
};