#include "GameController.h"

#include "Renderer.h"
#include "TTFont.h"

#include "InputController.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Controller.h"

#include "AudioController.h"
#include "SoundEffect.h"

#include "WavDraw.h"

GameController::GameController() {
	
	
	m_sdlEvent = {};
	m_renderer = nullptr;
	m_fArial20 = nullptr;
	m_quit = false;
	m_input = nullptr;
	
	m_audio = nullptr;
	m_wavDraw = nullptr;
	m_zoomY = 5;
	
}

GameController::~GameController() {

	ShutDown();
}


void GameController::Initialize() {

	AssetController::Instance().Initialize(10000000); //10MB
	m_renderer = &Renderer::Instance();

	m_renderer->Initialize();
	m_fArial20 = new TTFont();
	m_fArial20->Initialize(20);

	m_input = &InputController::Instance();
	m_audio = &AudioController::Instance();
	m_wavDraw = new WavDraw();

	m_effects.push_back(m_audio->LoadEffect("../Assets/Audio/Effects/Whoosh.wav"));
}

void GameController::ShutDown() {

	delete m_fArial20;
	delete m_wavDraw;
}

void GameController::HandleInput(SDL_Event _event) {
	
	string temp;
	if (_event.type == SDL_QUIT ||
		(m_input->KB()->KeyUp(_event, SDLK_ESCAPE))) {

		m_quit = true;
	}
	else if (m_input->KB()->KeyUp(_event, SDLK_w)) {

		m_zoomY += 0.5f;
	}
	else if (m_input->KB()->KeyUp(_event, SDLK_s)) {

		m_zoomY -= 0.5f;
	}

	m_input->MS()->ProcessButtons(_event);
}


void GameController::RunGame() {

	Initialize();

	while (!m_quit) {

		m_renderer->SetDrawColor(Color(255, 255, 255, 255));
		m_renderer->ClearScreen();
		
		//Checks for Events in one frame
		while (SDL_PollEvent(&m_sdlEvent) != 0) {
			
			HandleInput(m_sdlEvent);
		}

		m_wavDraw->DrawWave(m_effects[0]->GetData(), m_renderer, m_zoomY);


		SDL_RenderPresent(m_renderer->GetRenderer());
	}
}
