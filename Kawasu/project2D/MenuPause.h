#pragma once

#include "Texture.h"
#include "Renderer2d.h"
#include "Entity.h"
#include "Input.h"

using namespace aie;

class MenuPause : public Entity
{
	enum MenuSelector
	{
		E_RESUME,
		E_DONATE,
		E_EXIT
	};

public:
	MenuPause();
	~MenuPause();

	void Update(float deltaTime);

	void Draw(Renderer2D* m_2dRenderer);
	
private:
	Vector2 m_pos;
	Texture* m_MenuPause;
	Texture* m_MenuSelect;
	MenuSelector nMenuNo;
};
