#include "Splash.h"
#include "Define.h"
#include "StateMachine.h"
#include "ResourceManager.h"
#include "Texture.h"

//--------------------------------------------------------------------------------------
// Default Constructor
//--------------------------------------------------------------------------------------
Splash::Splash()
{
	m_splash = ResourceManager<Texture>::GetInstance()->LoadResource("./textures/splash.png");
	m_fTimer = 0.0f;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Splash::~Splash()
{
	delete m_splash;
}

void Splash::OnEnter()
{
}

//--------------------------------------------------------------------------------------
// Does nothing/might be used at later development.
//
// Param:
//		deltaTime: It's not used.
//--------------------------------------------------------------------------------------
void Splash::OnUpdate(float deltaTime, StateMachine* stateMachine)
{
	m_fTimer += deltaTime;
	if (m_fTimer > 3.0f)
	{
		stateMachine->PushState(E_TITLEMENU);
	}
}

//--------------------------------------------------------------------------------------
// Draws the Splash Screen texture.
//
// Param:
//		m_2dRenderer: Passes in the renderer to allow for drawing trxtures.
//--------------------------------------------------------------------------------------
void Splash::OnDraw(Renderer2D * m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_splash, SCREENX / 2, SCREENY / 2, 0, 0, 0, 1);
}

void Splash::OnExit()
{
}

