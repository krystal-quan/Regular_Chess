#ifndef TEXTURE_H
#define TEXTURE_H
#include "VarAndFunc.h"
class Texture {
	SDL_Texture* currentTexture;
	int width, height;
public:
	Texture() {
		currentTexture = nullptr;
		width = height = 0;
	}
	void free() {
		SDL_DestroyTexture(currentTexture);
		currentTexture = nullptr;
		width = height = 0;
	}
	void loadTextureFromFile(std::string path, Uint8 r = 1, Uint8 g = 1, Uint8 b = 1) {
		free();
		SDL_Surface* loadedImage = IMG_Load(path.c_str());
		SDL_SetColorKey(loadedImage, SDL_TRUE, SDL_MapRGB(loadedImage->format, r, g, b));
		currentTexture = SDL_CreateTextureFromSurface(renderer, loadedImage);
		SDL_FreeSurface(loadedImage);
		loadedImage = nullptr;
	}
	void loadTextureFromText(std::string textureText, TTF_Font* font, SDL_Color text_color = {255,255,255}) {
		free();
		SDL_Surface* loadedText = TTF_RenderText_Solid(font, textureText.c_str(), text_color);
		currentTexture = SDL_CreateTextureFromSurface(renderer, loadedText);
		width = loadedText->w;
		height = loadedText->h;
		SDL_FreeSurface(loadedText);
		loadedText = nullptr;
	}
	void setTextureSize(int w, int h) {
		width = w;
		height = h;
	}
	void setTextureColor(Uint8 red, Uint8 green, Uint8 blue) {
		SDL_SetTextureColorMod(currentTexture, red, green, blue);
	}
	void setTextureBlendMode(SDL_BlendMode blending) {
		SDL_SetTextureBlendMode(currentTexture, blending);
	}
	void setTextureAlpha(Uint8 alpha) {
		SDL_SetTextureAlphaMod(currentTexture, alpha);
	}
	void renderTexture(int x, int y, SDL_Rect* clip = nullptr, double angle = 0.0, SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE) {
		SDL_Rect renderQuad{x,y,width,height};
		SDL_RenderCopyEx(renderer, currentTexture, clip, &renderQuad, angle, center, flip);
	}
	int textureWidth() { return width; }
	int textureHeight() { return height; }
};

Texture pieceTexture;
Texture boardBackground;

Texture gameAllBackground;
Texture player1Board, player2Board;

Texture pinkTexture, brownTexture, borderTexture;
Texture beingDanger;
Texture currentPointing;
Texture currentChoosed, emptyMove, eatingMove, mustEatingMove, beingChecked;

Texture clockDisplay;

Texture tempVar;

Texture player1Name, player2Name, clockTimeLeft, clockTurnTime;
Texture player1Color, player2Color;

//Pause
Texture pauseTexture;
Texture pauseBackground;

Texture endBackground;
Texture conclusion;

Texture noteBoard;
Texture noteDis;

#endif // TEXTURE_H
