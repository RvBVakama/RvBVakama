#include "Loading.h"
#include "Define.h"
#include "StateMachine.h"
#include "ResourceManager.h"
#include "Texture.h" 
//--------------------------------------------------------------------------------------
// Default Constructor
//--------------------------------------------------------------------------------------
Loading::Loading()
{
	m_Loading = ResourceManager<Texture>::GetInstance()->LoadResource("./textures/loading.png");
	randTime = (float)(rand()%200) / 100 + 1.0f;
	m_nTimer = 0.0f;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Loading::~Loading()
{
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
		int nResult = stateMachine->PushState(E_GAMESCENE);
		_ASSERT(nResult == SUCCESS);
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

