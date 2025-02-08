#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "StandardIncludes.h"

class GameController : public Singleton<GameController>
{
public:
	//Contructors/Destructors
	GameController();
	virtual ~GameController();

	//Methods
	void RunGame();

private:
	//Members
	SDL_Event m_sdlEvent;

};

#endif //GAMECONTROLLER_H