#pragma once
#include "BaseState.h"
#include "Texture.h"
using namespace aie;

class Menu : public BaseState
{
public:
	Menu();
	~Menu();

	void OnEnter();
	void OnUpdate(float deltaTime);
	void OnDraw(Renderer2D* renderer2d);
	void OnExit();

private:
	Texture* m_pLogo;
	Texture* m_pPlayButton;
};

