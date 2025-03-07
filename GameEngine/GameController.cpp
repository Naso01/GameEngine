#include "GameController.h"
#include "Renderer.h"
#include "RenderTarget.h"
#include "SpriteSheet.h"
#include "TTFont.h"
#include "Timing.h"
#include <sstream>

GameController::GameController() {

	m_sdlEvent = {};
}

GameController::~GameController() { }


void GameController::RunGame() {

	AssetController::Instance().Initialize(10000000); //Allocate 10MB
	Renderer* r = &Renderer::Instance();
	Timing* t = &Timing::Instance();
	r->Initialize();
	r->EnumerateDisplayModes();
	//cout << r->GetResolution(800, 600).w << r->GetResolution(800, 600).h << endl;
	r->ChangeDisplayMode((r->GetResolution(800, 600))); // 800x600
	
	TTFont* font = new TTFont();
	font->Initialize(20);

	SpriteSheet::Pool = new ObjectPool<SpriteSheet>();
	SpriteAnim::Pool = new ObjectPool<SpriteAnim>();
	SpriteSheet* sheet = SpriteSheet::Pool->GetResource();
	sheet->Load("../Assets/Textures/Warrior.tga");
	sheet->SetSize(17, 6, 69, 44);
	sheet->AddAnimation(EN_AN_IDLE, 0, 6, 6.0f);
	sheet->AddAnimation(EN_AN_RUN, 6, 8, 6.0f);

	while (m_sdlEvent.type != SDL_QUIT) {

		t->Tick();
		
		//SDL_PollEvent(&m_sdlEvent);

		r->SetDrawColor(Color(255, 255, 255, 255));
		r->ClearScreen();
		r->RenderTexture(sheet, sheet->Update(EN_AN_RUN, t->GetDeltaTime()), Rect(0, 150, 69 * 3, 150 + 44 * 3));
 
		string fps = "Frames per Second: " + to_string(t->GetFPS());
		font->Write(r->GetRenderer(),fps.c_str(), SDL_Color{0, 0, 255}, SDL_Point{0, 0});
		string s = "Frame number: " + to_string(sheet->GetCurrentClip(EN_AN_RUN));
		font->Write(r->GetRenderer(), s.c_str(), SDL_Color{ 0, 255, 0 }, SDL_Point{ 250, 200 });
		/*
		vector<SDL_DisplayMode> modes = r->GetResolutions();
		
		for (int count = 0; count < modes.size(); count++) {

			stringstream s;
			s << modes[count].w << "x" << modes[count].h << " " << modes[count].refresh_rate << "hz";
			font->Write(r->GetRenderer(), s.str().c_str(), SDL_Color{ 255, 128, 0 }, SDL_Point{ 500, 20 + count * 20 });
		}
*/
		SDL_RenderPresent(r->GetRenderer()); // Display all Textures from Back Buffer to Front Buffer

		t->CapFPS();
	}

	delete SpriteAnim::Pool;
	delete SpriteSheet::Pool;

	font->Shutdown();
	r->Shutdown();
}