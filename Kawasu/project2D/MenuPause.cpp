#include "MenuPause.h"
#include "StateMachine.h"
#include "Define.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "Loading.h"

//-------------------------------------------------------------------------------------------------------
// Default Constructor
// Applies all the textures to their respective button objects and sets up the pos.x and pos.y values.
//-------------------------------------------------------------------------------------------------------
MenuPause::MenuPause()
{
	m_MenuPause = ResourceManager<Texture>::GetInstance()->LoadResource("./textures/pause.png");
	m_MenuSelect = ResourceManager<Texture>::GetInstance()->LoadResource("./textures/selector.png");
	
	m_pos.x = SCREENX / 2;
	m_pos.y = SCREENY / 2;
}

//-------------------------------------------------------------------------------------------------------
// Default Destructor
//-------------------------------------------------------------------------------------------------------
MenuPause::~MenuPause()
{
}

//-------------------------------------------------------------------------------------------------------
// OnEnter is ran whenever a state is pushed.
//-------------------------------------------------------------------------------------------------------
void MenuPause::OnEnter()
{
}

//-------------------------------------------------------------------------------------------------------
// This update function checks for mouse location and input and based on if the mouse button was pressed
// the games will either resume the game, load donation information or exit to the menu screen.
// 
// Param:
//		deltaTime: Not currently used.
//		stateMachine: Used to access the State Machine to be able to push the next state.
//-------------------------------------------------------------------------------------------------------
void MenuPause::OnUpdate(float deltaTime, StateMachine* stateMachine)
{
	aie::Input* input = aie::Input::getInstance();

	int fMouseX = input->getMouseX();
	int fMouseY = input->getMouseY();

	nMenuNo = E_NONE;

	if (fMouseX > 320 && fMouseX < 726 && fMouseY > 466 && fMouseY < 540)
	{
		nMenuNo = E_RESUME;

		if (input->wasMouseButtonPressed(INPUT_MOUSE_BUTTON_LEFT))
		{
			stateMachine->PopState();
			stateMachine->bDrawLowerState = false;			
		}

		printf("resume");
	}
	
	if (fMouseX > 310 && fMouseX < 730 && fMouseY > 346 && fMouseY < 466)
	{
		nMenuNo = E_DONATE;
		printf("donate");
	}

	if (fMouseX > 380 && fMouseX < 658 && fMouseY > 256 && fMouseY < 332)
	{
		nMenuNo = E_EXIT;
		printf("exit");

		if (input->wasMouseButtonPressed(INPUT_MOUSE_BUTTON_LEFT))
		{
			stateMachine->PopState();
			stateMachine->PopState();
			stateMachine->PopState();
			stateMachine->bDrawLowerState = false;
		}
	}
	
	if (input->wasKeyPressed(aie::INPUT_KEY_ESCAPE))
	{
			stateMachine->PopState();
			stateMachine->bDrawLowerState = false;
	}
}

//-------------------------------------------------------------------------------------------------------
// This draw function draws each button on the pause menu and on mouse hover draws a little selector icon
// 
// Param:
//		m_2drenderer: Allows access to the Renderer2D class which allows us to render textures onscreen
//-------------------------------------------------------------------------------------------------------
void MenuPause::OnDraw(Renderer2D * m_2dRenderer)
{
	_ASSERT(m_2dRenderer);
	m_2dRenderer->drawSprite(m_MenuPause, m_pos.x, m_pos.y, 0, 0, 0, 1);

	switch (nMenuNo)
	{
	case E_RESUME:
		m_2dRenderer->drawSprite(m_MenuSelect, m_pos.x, m_pos.y - (-112), 0, 0, 0, 0);
		printf("tex");
		break;
	case E_DONATE:
		m_2dRenderer->drawSprite(m_MenuSelect, m_pos.x, m_pos.y, 0, 0, 0, 0);
		printf("tex");
		break;
	case E_EXIT:
		m_2dRenderer->drawSprite(m_MenuSelect, m_pos.x, m_pos.y - 123, 0, 0, 0, 0);
		printf("tex");
		break;

	default:
		break;
	}
}
//-------------------------------------------------------------------------------------------------------
// OnExit is ran whenever the stack has more than 0 states.
//-------------------------------------------------------------------------------------------------------
void MenuPause::OnExit()
{
}
