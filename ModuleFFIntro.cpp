#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "SDL\include\SDL.h"
#include "ModuleMusic.h"
#include "Application.h"



#include "ModuleFFIntro.h"
#include "ModuleFFIntro2.h"
#include "ModulePlayerSelection.h"
#include "ModuleScenePaoPao.h"
#include "ModuleWelcomeScreen.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleFFIntro::ModuleFFIntro()
{

	//Intro Background

	introwin.x = 0;
	introwin.y = 0;
	introwin.w = 314;
	introwin.h = 192;


	//Start Animation
	
	start.PushBack({ 590, 260, 146, 21 });
	start.PushBack({ 0, 498, 236, 44 });
	start.speed = 0.04f;

	//Player Animation

	/*positionplayer.x = -40;
	positionplayer.y = 225;*/
	
	player.PushBack({ 340, 34, 61, 127 });
	player.PushBack({ 411, 35, 62, 127 });
	player.PushBack({ 485, 38, 61, 124 });
	player.PushBack({ 554, 38, 61, 124 });
	player.speed = 0.04f;

	//Rock

	/*positionrock.x = -40;
	positionrock.y = 244; */

	rock.x = 647;
	rock.y = 129;
	rock.w = 117;
	rock.h = 31;

	
}

ModuleFFIntro::~ModuleFFIntro()
{}

// Load assets
bool ModuleFFIntro::Start()
{
	LOG("Loading image assets");
	bool ret = true;
	graphics = App->textures->Load("Source/UI/Intro/intro2.png");
	introsong = App->audio->LoadMusic("Source/Sound/Music/Opening.ogg");
	App->audio->PlayMusic(introsong);
	return ret;

}

bool ModuleFFIntro::CleanUp()
{
	SDL_DestroyTexture(graphics);
	return true;
}

// Update: draw background
update_status ModuleFFIntro::Update()
{
	
	// Drawing background - Intro Background
	
	App->render->Blit(graphics, 0, 0, &introwin, 0.75f);

	//Drawing Rock

	App->render->Blit(graphics, -2, 161, &rock, 0.75f);

	// Player animation

	App->render->Blit(graphics, 50, 58, &(player.GetCurrentFrame()), 0.75f);

	//Start animation

	App->render->Blit(graphics, 72, 140, &(start.GetCurrentFrame()), 0.75f);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1)
	{
		App->fade->FadeToBlack(App->scene_intro, App->scene_intro2, 1.5);

	}

	return UPDATE_CONTINUE;
}