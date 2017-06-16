#include "Loading.h"
#include "Define.h"
#include "StateMachine.h"

//--------------------------------------------------------------------------------------
// Default Constructor
//--------------------------------------------------------------------------------------
Loading::Loading()
{
	m_Loading = new Texture("./textures/loading.png");
	randTime = 1.0f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (5.0f - 1.0f)));
	m_nTimer = 0.0f;
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
	m_nTimer += deltaTime;

	if (m_nTimer > randTime)
	{
		stateMachine->PushState(E_GAMESCENE);
	}
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

