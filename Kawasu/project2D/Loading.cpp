#include "Loading.h"
#include "Define.h"

//--------------------------------------------------------------------------------------
// Default Constructor
//--------------------------------------------------------------------------------------
Loading::Loading()
{
	m_Loading = new Texture("./textures/loading.png");
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Loading::~Loading()
{
	delete m_Loading;
}

void Loading::OnEnter()
{
}

//--------------------------------------------------------------------------------------
// Does nothing/might be used at later development.
//
// Param:
//		deltaTime: It's not used.
//--------------------------------------------------------------------------------------
void Loading::OnUpdate(float deltaTime, StateMachine* stateMachine)
{
}

//--------------------------------------------------------------------------------------
// Draws the Loading Screen texture.
//
// Param:
//		m_2dRenderer: Passes in the renderer to allow for drawing trxtures.
//--------------------------------------------------------------------------------------
void Loading::OnDraw(Renderer2D * m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_Loading, SCREENX / 2, SCREENY / 2, 0, 0, 0, 1);
}

void Loading::OnExit()
{
}

