#include "Bombs.h"
#include "CollisionManager.h"
#include "Input.h"
#include <iostream>
#include "Define.h"
#include "ResourceManager.h"
#include "Texture.h"

//-------------------------------------------------------------------------------------------------
// Default Constructor.
// Adds the bombs to the collision manager, sets the texture up and sets the bCanKill bool to true.
//-------------------------------------------------------------------------------------------------
Bombs::Bombs()
{
	CollisionManager::GetInstance()->AddObject(this);

	//sets the correct texture based on the input filename
	m_BombTexture = ResourceManager<Texture>::GetInstance()->LoadResource("./textures/bomb.png");

	UpdateTransforms();

	//Can kill players
	bCanKill = true;
}

//-------------------------------------------------------------------------------------------------
// Alternative Constructor.
// Adds the bombs to the collision manager, asks the user for the collision
// bounds and position, sets the texture up and sets the bCanKill bool to true.
// 
// Param:
//		pos: The position of the bombs.
//		TL: Top left pixel to set the collision area.
//		BR:	Bottom right pixel to set the collision area.
//-------------------------------------------------------------------------------------------------
Bombs::Bombs(Vector2 pos, Vector2 TL, Vector2 BR)
{
	//Settings the collision area
	m_Collider.m_TL = Vector2(TL); //-18, -24
	m_Collider.m_BR = Vector2(BR); //-18, -24

	CollisionManager::GetInstance()->AddObject(this);

	//sets the correct texture based on the input filename
	m_BombTexture = ResourceManager<Texture>::GetInstance()->LoadResource("./textures/bomb.png");

	//creating a matrix 3d to store the position of the platform in
	Matrix3 temppos;

	//putting the position values into the matrix
	temppos.SetPos(pos);

	//updating the players position by multiplying the current player matrix(localTransform)
	//by the temppose matrix
	localTransform = localTransform * temppos;

	UpdateTransforms();

	//Can kill players
	bCanKill = true;
}

//-------------------------------------------------------------------------------------------------
// Default Destructor
//-------------------------------------------------------------------------------------------------
Bombs::~Bombs()
{
	//delete m_BombTexture;
}

//-------------------------------------------------------------------------------------------------
// Set the bomb's position.
// 
// Param:
//		pos: The position of the borders.
//		TL: Top left pixel to set the collision area.
//		BR:	Bottom right pixel to set the collision area.
//-------------------------------------------------------------------------------------------------
void Bombs::setPos(Vector2 pos, Vector2 TL, Vector2 BR)
{
	//Settings the collision area
	m_Collider.m_TL = Vector2(TL); //-18, -24
	m_Collider.m_BR = Vector2(BR); //-18, -24

	//creating a matrix 3d to store the position of the platform in
	Matrix3 temppos;

	//putting the position values into the matrix
	temppos.SetPos(pos);

	//updating the players position by multiplying the current player matrix(localTransform)
	//by the temppose matrix
	localTransform = localTransform * temppos;

	UpdateTransforms();

}

//-------------------------------------------------------------------------------------------------
// Prints "Death" if the bomb touches a bat.
//
// Param:
//		deltaTime: this makes it possible to keep time.
//-------------------------------------------------------------------------------------------------
void Bombs::Update(float deltaTime)
{
	CollisionManager* pCollision = CollisionManager::GetInstance();

	//debug to see if the colliders are working
	Entity* colliding = pCollision->TestCollision(this);
	if (colliding)
	{
		std::cout << "Death" << std::endl;
	}
}

//-------------------------------------------------------------------------------------------------
// Draws the bombs each frame.
//
// Param:
//		m_2dRenderer: this makes it possible to render.
//-------------------------------------------------------------------------------------------------
void Bombs::Draw(Renderer2D * m_2dRenderer)
{
	//drawing the texture
	m_2dRenderer->drawSpriteTransformed3x3(m_BombTexture, globalTransform, 0, 0, 99);
}