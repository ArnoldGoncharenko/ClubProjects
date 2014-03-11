#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <math.h>
#include "Rect.h"

int main(int argc, char* argv[]){

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* gameWindow = NULL;
	gameWindow = SDL_CreateWindow("GameWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1440, 900, SDL_WINDOW_SHOWN);
	SDL_Renderer* gameRenderer = NULL;
	gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED);
	SDL_Event* gameEvent = new SDL_Event();

	bool gameOn = true;
	SDL_Texture* game_MapPlayer = NULL;
	SDL_Texture* game_NPCPlayer = NULL;
	SDL_Texture* colBoxMain = NULL;
	SDL_Texture* colBox = NULL;
	SDL_Texture* Village1 = NULL;
	SDL_Texture* Menu = NULL;
	SDL_Texture* Button = NULL;
	SDL_Texture* ButtonExit = NULL;
	Village1 = IMG_LoadTexture(gameRenderer, "village1.png");
	game_MapPlayer = IMG_LoadTexture(gameRenderer, "playermap.png");
	game_NPCPlayer = IMG_LoadTexture(gameRenderer, "playermap.png");
	colBoxMain = IMG_LoadTexture(gameRenderer, "colboxmain_2.png");
	colBox = IMG_LoadTexture(gameRenderer, "collisionTestBox.png");
	Menu = IMG_LoadTexture(gameRenderer, "mainMenu.png");
	Button = IMG_LoadTexture(gameRenderer, "Button.png");
	ButtonExit = IMG_LoadTexture(gameRenderer, "exitButton.png");

	newRect testRect;

	SDL_Rect Village_1 = testRect.createNewRect(0,0,900,1440);

	SDL_Rect map_player;
	map_player.x = 600;
	map_player.y = 300;
	map_player.h = 11;
	map_player.w = 11;

	SDL_Rect map_NPC;
	map_NPC.x = 300;
	map_NPC.y = 600;
	map_NPC.h = 11;
	map_NPC.w = 11;

	SDL_Rect Collision;
	Collision.x = 0;
	Collision.y = 475;
	Collision.h = 450;
	Collision.w = 1440;

	SDL_Rect CollisionTriangle;
	CollisionTriangle.x = 0;
	CollisionTriangle.y = 475;
	CollisionTriangle.h = 18;
	CollisionTriangle.w = 51;

	SDL_Rect mainMenu;
	mainMenu.x = 0;
	mainMenu.y = 0;
	mainMenu.h = 900;
	mainMenu.w = 1440;

	SDL_Rect mainMenuButton;
	mainMenuButton.x = 300;
	mainMenuButton.y = 400;
	mainMenuButton.h = 200;
	mainMenuButton.w = 150;

	SDL_Rect mainMenuButtonExit;
	mainMenuButtonExit.x = 400;
	mainMenuButtonExit.y = 300;
	mainMenuButtonExit.h = 200;
	mainMenuButtonExit.w = 150;

	bool moveRight = false;
	bool moveLeft = false;
	bool moveDown = false;
	bool moveUp = false;
	int randomValue = rand() % 101; 

	int timeCheck = SDL_GetTicks();

	short TriangleTestCollison = 0;
	TriangleTestCollison = pow(CollisionTriangle.h, 2.0) + pow(CollisionTriangle.w, 2.0);
	TriangleTestCollison = sqrt(TriangleTestCollison);
	
	bool inside = true;
	bool quitMenu = false;
	bool gameMenu = false;
	bool attack = false;

	int x, y;

	while (quitMenu != true)
	{
			if (gameEvent->type == SDL_MOUSEBUTTONDOWN)
			{
				if (gameEvent->button.button == SDL_BUTTON_LEFT)
				{
					x = gameEvent->motion.x;
					y = gameEvent->motion.y;

					if ((x > mainMenuButton.x) && (x < mainMenuButton.x + mainMenuButton.w) && (y > mainMenuButton.y) && (y < mainMenuButton.y + mainMenuButton.h))
					{
						quitMenu = true;
					}

					else if ((x > mainMenuButtonExit.x) && (x < mainMenuButtonExit.x + mainMenuButtonExit.w) && (y > mainMenuButtonExit.y) && (y < mainMenuButtonExit.y + mainMenuButtonExit.h))
					{
						quitMenu = true;
						inside = false;
					}
				}
			}

			SDL_PollEvent(gameEvent);
			SDL_RenderClear(gameRenderer);
			SDL_RenderCopy(gameRenderer, Menu, NULL, &mainMenu);
			SDL_RenderCopy(gameRenderer, Button, NULL, &mainMenuButton);
			SDL_RenderCopy(gameRenderer, ButtonExit, NULL, &mainMenuButtonExit);
			SDL_RenderPresent(gameRenderer);
	}
	
	while (gameOn && gameEvent->type != SDL_QUIT && inside != false)
	{

		switch (gameEvent->type)
		{
		case SDL_KEYDOWN:

			switch (gameEvent->key.keysym.sym)
			{
			case SDLK_a:
				moveLeft = true;
				break;
			case SDLK_s:
				moveDown = true;
				break;
			case SDLK_w:
				moveUp = true;
				break;
			case SDLK_d:
				moveRight = true;
				break;
			case SDLK_ESCAPE:
				gameMenu = true;
				break;
			case SDLK_SPACE:
				attack = true;
				break;
			default:
				break;
			}

			break;

		case SDL_KEYUP:
			switch (gameEvent->key.keysym.sym)
			{
			case SDLK_a:
				moveLeft = false;
				break;
			case SDLK_s:
				moveDown = false;
				break;
			case SDLK_w:
				moveUp = false;
				break;
			case SDLK_d:
				moveRight = false;
				break;
			case SDLK_SPACE:
				attack = false;
				break;
			default:
				break;
			}

			break;
		default:
			break;
		}

		if (timeCheck + 5 < SDL_GetTicks())
		{
			if (moveUp)
			{
				map_player.y--;
			}

			if (moveDown)
			{
				map_player.y++;
			}

			if (moveLeft)
			{
				map_player.x--;
			}

			if (moveRight)
			{
				map_player.x++;
			}

			if (gameMenu)
			{
				while (gameMenu == true)
				{
					if (gameEvent->type == SDL_MOUSEBUTTONDOWN)
					{
						if (gameEvent->button.button == SDL_BUTTON_LEFT)
						{
							x = gameEvent->motion.x;
							y = gameEvent->motion.y;

							if ((x > mainMenuButton.x) && (x < mainMenuButton.x + mainMenuButton.w) && (y > mainMenuButton.y) && (y < mainMenuButton.y + mainMenuButton.h))
							{
								gameMenu = false;
							}

							else if ((x > mainMenuButtonExit.x) && (x < mainMenuButtonExit.x + mainMenuButtonExit.w) && (y > mainMenuButtonExit.y) && (y < mainMenuButtonExit.y + mainMenuButtonExit.h))
							{
								gameMenu = false;
								inside = false;
							}
						}
					}

					SDL_PollEvent(gameEvent);
					SDL_RenderClear(gameRenderer);
					SDL_RenderCopy(gameRenderer, Menu, NULL, &mainMenu);
					SDL_RenderCopy(gameRenderer, Button, NULL, &mainMenuButton);
					SDL_RenderCopy(gameRenderer, ButtonExit, NULL, &mainMenuButtonExit);
					SDL_RenderPresent(gameRenderer);
				}
			}

			randomValue = rand() % 1001;
			if (randomValue < 5)
			{
				map_NPC.x++;
			}
			if (randomValue > 5 && randomValue < 15)
			{
				map_NPC.x--;
			}
			if (randomValue > 25 && randomValue < 35)
			{
				//map_NPC.y++;
			}
			if (randomValue > 45 && randomValue < 50)
			{
				//map_NPC.y--;
			}

			if (attack)
			{
				cout << "trying to attack";
				if (map_NPC.x <= map_player.x && map_player.x <= map_NPC.x+11 && map_NPC.y <= map_player.y && map_player.y <= map_NPC.y+11)
				{
					cout << "OMG YOU HIT THE ENEMY ROFL LOL WHAT";
				}
			}

			timeCheck = SDL_GetTicks();
		}

		if (map_player.y >= 475)
		{
			map_player.y--;
		}

		if (map_NPC.y >= 475)
		{
			map_NPC.y--;
		}

		SDL_PollEvent(gameEvent);
		SDL_RenderClear(gameRenderer);
		SDL_RenderCopy(gameRenderer, Village1, NULL, &Village_1);
		SDL_RenderCopy(gameRenderer, game_MapPlayer, NULL, &map_player);
		SDL_RenderCopy(gameRenderer, game_NPCPlayer, NULL, &map_NPC);
		SDL_RenderCopy(gameRenderer, colBoxMain, NULL, &Collision);
		SDL_RenderCopy(gameRenderer, colBoxMain, NULL, &CollisionTriangle);
		SDL_RenderPresent(gameRenderer);

	}

	SDL_DestroyWindow(gameWindow);
	SDL_DestroyRenderer(gameRenderer);
	delete gameEvent;
	return 0;
}