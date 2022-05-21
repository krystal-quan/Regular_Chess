#ifndef BUTTON_H
#define BUTTON_H
#include "Texture.h"

enum buttonStatus {
    MOUSE_OUT,
    MOUSE_IN,
    MOUSE_DOWN,
    MOUSE_UP,
};

class Button
{
    int posX,posY,currentStatus;
    Texture buttonTexture;
    public:
        Button() {
		posX = posY = 0;
		currentStatus = MOUSE_OUT;
        }
        void setPosition(int x, int y) {
            posX = x;
            posY = y;
        }
        void handleEvent(SDL_Event* e) {
            if(e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                if(x < posX || x > posX + buttonTexture.textureWidth() || y < posY || y > posY + buttonTexture.textureHeight()) currentStatus = MOUSE_OUT;
                else switch(e->type) {
                    case SDL_MOUSEMOTION: currentStatus = MOUSE_IN; return;
                    case SDL_MOUSEBUTTONDOWN: currentStatus = MOUSE_DOWN; return;
                }
            }
        }
        void textureFromFile(std::string path, Uint8 r = 1, Uint8 g = 1, Uint8 b = 1) {
            buttonTexture.loadTextureFromFile(path, r, g, b);
        }
        void textureFromText(std::string text, TTF_Font* font, SDL_Color color = {255,255,255}) {
            buttonTexture.loadTextureFromText(text, font, color);
        }
        void setButtonSize(int w, int h) {
            buttonTexture.setTextureSize(w, h);
        }
        void setButtonColor(Uint8 r, Uint8 g, Uint8 b) {
            buttonTexture.setTextureColor(r, g, b);
        }
        void renderButton(SDL_Rect* clip = nullptr) {
            buttonTexture.renderTexture(posX, posY, clip);
        }
        int getCurrentStatus() {
            return currentStatus;
        }
        int buttonWidth() {
            return buttonTexture.textureWidth();
        }
        int buttonHeight() {
            return buttonTexture.textureHeight();
        }
        void setButtonStatus(int state) {
            currentStatus = state;
        }
        void reset() {
            currentStatus = MOUSE_OUT;
            setButtonColor(255, 255, 255);
            }
        void free() {
            buttonTexture.free();
        }
};

Button pause_button;
Button continue_button;

#endif // BUTTON_H
