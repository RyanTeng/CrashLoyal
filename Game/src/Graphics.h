#pragma once

#include "Building.h"
#include "Mob.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "Singleton.h"

class Graphics : public Singleton<Graphics> {
	/**
	 * Houses the logic for drawing the game to the screen.
	 * Acts as a StringBuilder but for images drawn the the canvas.
	 */

public:
	Graphics();
	virtual ~Graphics();  //SDL_DestroyRenderer(gRenderer);

	void drawMob(Mob* m);
	void drawText(const char* textToDraw, SDL_Rect messageRect, SDL_Color color);
	void drawBuilding(Building* b);

	void resetFrame();

	void drawWinScreen(int winningSide);
	
	void render();

	SDL_Renderer* getRenderer() { return gRenderer; };

private: 

	void drawMob(Mob* m, Vec2 centerPixel);

	void drawSquare(float centerX, float centerY, float size);
	int healthToAlpha(const Entity* e);

	void drawGrid();
	void drawBG();
	void drawUIBG();

	void drawUIButtons(std::vector<Mob*> mobsToDraw);

	SDL_Renderer* gRenderer;
	SDL_Window* gWindow;
	TTF_Font* sans;
};