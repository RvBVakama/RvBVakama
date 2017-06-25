#pragma once

#define SCREENX 1036
#define SCREENY 800

//------------------------------------------------
// List of states that are used in the game
//------------------------------------------------
enum STATES
{
	E_SPLASH,
	E_TITLEMENU,
	E_LOADING,
	E_GAMESCENE,
	E_MENUPAUSE
};

//------------------------------------------------
// Error Debug Codes
//------------------------------------------------
#define SUCCESS 0
#define OUT_OF_BOUNDS 1
#define INVALID_STATE 2
#define STATELIST_NEGATIVE_SIZE 3
#define STACK_NEGATIVE_SIZE 4
