#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 18

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleScenePaoPao;
class ModuleSceneSoundBeach;
class ModuleWelcomeScreen;
class ModulePlayer;
class ModuleFadeToBlack;
class ModulePlayerSelection;
class ModuleMusic;
class ModuleFFIntro;
class ModuleFFIntro2;
class ModuleParticles;
class ModuleCollision;
class ModuleEnemy;
class ModuleFonts;
class ModuleTime;

class Module;

class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleScenePaoPao* scene_paopao;
	ModuleSceneSoundBeach* scene_soundbeach;
	ModuleWelcomeScreen* scene_welcome;
	ModulePlayer* player;
	ModuleFadeToBlack* fade;
	ModulePlayerSelection* playerselection;
	ModuleMusic* audio;
	ModuleFFIntro* scene_intro;
	ModuleFFIntro2* scene_intro2;
	ModuleParticles* particles;
	ModuleCollision* collision;
	ModuleEnemy* enemy;
	ModuleFonts* fonts;
	ModuleTime* timer;
	


public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__