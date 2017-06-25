#include "Splash.h"
#include "Define.h"
#include "StateMachine.h"
#include "ResourceManager.h"
#include "Texture.h"

//--------------------------------------------------------------------------------------
// Default Constructor, Sets the splash texture and gives the timer a default value, 0.0
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
}

//--------------------------------------------------------------------------------------
// OnEnter is ran whenever a state is pushed.
//--------------------------------------------------------------------------------------
void Splash::OnEnter()
{
}

//---------------------------------------------------------------------------------------
// Sets deltaTime (seconds) to the stopwatch timer then checks if the timer has reached
// the randTime set above and if it has it pushes the GameScene state and thus enters the
// game.
//
// Param:
//		deltaTime: Used with m_nTimer to keep a stopwatch timer to allow 
//				   for a random loading time for the loading screen.
//---------------------------------------------------------------------------------------
void Splash::OnUpdate(float deltaTime, StateMachine* stateMachine)
{
	m_fTimer += deltaTime;
	if (m_fTimer > 3.0f)
	{
		int nResult = stateMachine->PushState(E_TITLEMENU);
		_ASSERT(nResult == SUCCESS);
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

//--------------------------------------------------------------------------------------
// OnExit is ran whenever the stack has more than 0 states.
//--------------------------------------------------------------------------------------
void Splash::OnExit()
{
}

