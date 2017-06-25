#include "Menu.h"
#include "StateMachine.h"
#include "Define.h"
#include "Input.h"
#include "ResourceManager.h"
#include "Texture.h"

//-----------------------------------------------------------------------------------------------------
// Default Constructor
// Applies all the textures to their respective button objects and sets up the pos.x and pos.y values.
//-----------------------------------------------------------------------------------------------------
Menu::Menu()
{
	m_titleMenu = ResourceManager<Texture>::GetInstance()->LoadResource("./textures/titleMenu.png");
	m_buttonBeginUP = ResourceManager<Texture>::GetInstance()->LoadResource("./textures/buttonBeginUP.png");
	m_buttonBeginDOWN = ResourceManager<Texture>::GetInstance()->LoadResource("./textures/buttonBeginDOWN.png");
	m_buttonExitUP = ResourceManager<Texture>::GetInstance()->LoadResource("./textures/buttonExitUP.png");
	m_buttonExitDOWN = ResourceManager<Texture>::GetInstance()->LoadResource("./textures/buttonExitDOWN.png");

	m_pos.x = SCREENX / 2;
	m_pos.y = SCREENY / 2;
}

//-----------------------------------------------------------------------------------------------------
// Default Destructor
//-----------------------------------------------------------------------------------------------------
Menu::~Menu()
{
}

//-----------------------------------------------------------------------------------------------------
// OnEnter is ran whenever a state is pushed.
//-----------------------------------------------------------------------------------------------------
void Menu::OnEnter()
{
}

//-----------------------------------------------------------------------------------------------------
// This update function checks for mouse location and input and based on if the mouse button is down or
// up the code enters different if statements to determine if the game should be started or exited.
// 
// Param:
//		deltaTime: Not currently used.
//		stateMachine: Used to access the State Machine to be able to push the next state.
//-----------------------------------------------------------------------------------------------------
void Menu::OnUpdate(float deltaTime, StateMachine* stateMachine)
{
	aie::Input* input = aie::Input::getInstance();

	int fMouseX = input->getMouseX();
	int fMouseY = input->getMouseY();

	nMenuNo = E_NONE;

	if (fMouseX > 290 && fMouseX < 746 && fMouseY > 330 && fMouseY < 469)
	{
		// if mouse button is pressed at all it always thinks it is up even after clicking off
		if (input->isMouseButtonDown(INPUT_MOUSE_BUTTON_LEFT))
			nMenuNo = E_BEGIN;

		if (input->isMouseButtonUp(INPUT_MOUSE_BUTTON_LEFT))
		{
			int nResult = stateMachine->PushState(E_LOADING);
			_ASSERT(nResult == SUCCESS);
		}
	}

	if (fMouseX > 364 && fMouseX < 672 && fMouseY > 83 && fMouseY < 177)
	{
		if (input->isMouseButtonDown(INPUT_MOUSE_BUTTON_LEFT))
			nMenuNo = E_EXIT;
		printf("exit");
		//quit
	}

	if (input->wasKeyPressed(aie::INPUT_KEY_ESCAPE))
	{
		//quit
	}
}

//-----------------------------------------------------------------------------------------------------
// This draw function draws each button and also changes the texture of a button on mouse hover 
// and click to a depressed texture of the button based on a couple if statements.
// 
// Param:
//		m_2drenderer: Allows access to the Renderer2D class which allows us to render textures onscreen
//-----------------------------------------------------------------------------------------------------
void Menu::OnDraw(Renderer2D * m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_titleMenu, m_pos.x, m_pos.y, 0, 0, 0, 1);
	m_2dRenderer->drawSprite(m_buttonBeginUP, m_pos.x, m_pos.y, 0, 0, 0, 0);
	m_2dRenderer->drawSprite(m_buttonExitUP, m_pos.x, m_pos.y - 270, 0, 0, 0, 0);

	switch (nMenuNo)
	{
	case E_BEGIN:
		m_2dRenderer->drawSprite(m_buttonBeginDOWN, m_pos.x, m_pos.y, 0, 0, 0, 0);
		printf("tex");
		break;
	case E_EXIT:
		m_2dRenderer->drawSprite(m_buttonExitDOWN, m_pos.x, m_pos.y - 270, 0, 0, 0, 0);
		printf("tex");
		break;

	default:
		break;
	}
}

//-----------------------------------------------------------------------------------------------------
// OnExit is ran whenever the stack has more than 0 states.
//-----------------------------------------------------------------------------------------------------
void Menu::OnExit()
{
}
