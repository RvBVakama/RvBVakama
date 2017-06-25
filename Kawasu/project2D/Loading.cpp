#include "Loading.h"
#include "Define.h"
#include "StateMachine.h"
#include "ResourceManager.h"
#include "Texture.h" 
//---------------------------------------------------------------------------------------
// Default Constructor / Sets the loading texture.
//---------------------------------------------------------------------------------------
Loading::Loading()
{
	m_Loading = ResourceManager<Texture>::GetInstance()->LoadResource("./textures/loading.png");
}

//---------------------------------------------------------------------------------------
// Default Destructor
//---------------------------------------------------------------------------------------
Loading::~Loading()
{
}

//---------------------------------------------------------------------------------------
// OnEnter is ran whenever a state is pushed.
// Sets a random value between 1.0 and 3.0 using randTime and sets a timer to 0.0 seconds
//---------------------------------------------------------------------------------------
void Loading::OnEnter()
{
	randTime = (float)(rand() % 200) / 100 + 1.0f;
	m_nTimer = 0.0f;
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
void Loading::OnUpdate(float deltaTime, StateMachine* stateMachine)
{
	m_nTimer += deltaTime;

	if (m_nTimer > randTime)
	{
		int nResult = stateMachine->PushState(E_GAMESCENE);
		_ASSERT(nResult == SUCCESS);
	}
}

//---------------------------------------------------------------------------------------
// Draws the Loading Screen texture.
//
// Param:
//		m_2dRenderer: Passes in the renderer to allow for drawing textures.
//---------------------------------------------------------------------------------------
void Loading::OnDraw(Renderer2D * m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_Loading, SCREENX / 2, SCREENY / 2, 0, 0, 0, 1);
}

//---------------------------------------------------------------------------------------
// OnExit is ran whenever the stack has more than 0 states.
//---------------------------------------------------------------------------------------
void Loading::OnExit()
{
}

