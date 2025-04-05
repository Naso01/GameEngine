#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "StandardIncludes.h"
#include "AudioController.h"


class Renderer;
class TTFont;

class InputController;

class Timing;

class PhysicsController;


class GameController : public Singleton<GameController>
{
public:
	//Contructors/Destructors
	GameController();
	virtual ~GameController();

	//Methods
	void RunGame();
	void Initialize();
	void HandleInput(SDL_Event _event);
	void ShutDown();

private:
	//Members
	SDL_Event m_sdlEvent;
	Renderer* m_renderer;
	TTFont* m_fArial20;

	bool m_quit;

	InputController* m_input;
	
	Timing* m_timing;
	PhysicsController* m_physics;

};

#endif //GAMECONTROLLER_H