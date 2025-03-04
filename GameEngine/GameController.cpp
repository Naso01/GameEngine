#include "GameController.h"
#include "Renderer.h"
#include "RenderTarget.h"
#include "SpriteSheet.h"
#include "TTFont.h"
#include "Timing.h"

GameController::GameController() {

	m_sdlEvent = {};
}

GameController::~GameController() { }


void GameController::RunGame() {

	AssetController::Instance().Initialize(10000000); // Allocate 10MB
	Renderer* r = &Renderer::Instance();
	Timing* t = &Timing::Instance();
	r->Initialize(800, 600);

	TTFont* font = new TTFont();
	font->Initialize(20);

	SpriteSheet::Pool = new ObjectPool<SpriteSheet>();
	SpriteAnim::Pool = new ObjectPool<SpriteAnim>();
	SpriteSheet* sheet = SpriteSheet::Pool->GetResource();
	sheet->Load("../Assets/Textures/Warrior.tga");
	sheet->SetSize(17, 6, 69, 44); //size of SpriteSheet
	sheet->AddAnimation(EN_AN_IDLE, 0, 6, 6.0f);
	sheet->AddAnimation(EN_AN_RUN, 6, 8, 6.0f);

	Point ws = r->GetWindowSize();
	RenderTarget* rt = new RenderTarget();
	rt->Create(ws.X, ws.Y);

	while (m_sdlEvent.type != SDL_QUIT) {

		t->Tick();
		rt->Start();//Render Target -> Texture Buffer

		SDL_PollEvent(&m_sdlEvent);
		r->SetDrawColor(Color(255, 255, 255, 255));
		r->ClearScreen();
		r->RenderTexture(sheet, sheet->Update(EN_AN_IDLE, t->GetDeltaTime()), Rect(0, 0, 69 * 3, 44 * 3));
		r->RenderTexture(sheet, sheet->Update(EN_AN_RUN, t->GetDeltaTime()), Rect(0, 150, 69 * 3, 150 + 44 * 3));
		
		string s = "Frame number: " + to_string(sheet->GetCurrentClip(EN_AN_IDLE));
		font->Write(r->GetRenderer(), s.c_str(), SDL_Color{0, 255, 0}, SDL_Point{250,  50});

		s = "Frame number: " + to_string(sheet->GetCurrentClip(EN_AN_RUN));
		font->Write(r->GetRenderer(), s.c_str(), SDL_Color{ 0, 255, 0 }, SDL_Point{ 250,  200 });

		string fps = "Frames per Second: " + to_string(t->GetFPS());
		font->Write(r->GetRenderer(),fps.c_str(), SDL_Color{0, 0, 255}, SDL_Point{0, 0});

		rt->Stop(); //Render Target -> Back Buffer
		r->SetDrawColor(Color(0, 0, 0, 255));
		r->ClearScreen();
		rt->Render(t->GetDeltaTime());

		SDL_RenderPresent(r->GetRenderer()); // Display all Textures from Back Buffer to Front Buffer

		t->CapFPS();
	}

	delete rt;
	delete SpriteAnim::Pool;
	delete SpriteSheet::Pool;

	font->Shutdown();
	r->Shutdown();
}