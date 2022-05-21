#ifndef VARANDFUNC_H
#define VARANDFUNC_H
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include<iostream>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<deque>
#include<vector>
#include<string>
#include<sstream>
SDL_Window* window;
SDL_Renderer* renderer;

const int SCREEN_WIDTH = 1100;
const int SCREEN_HEIGHT = 750;

const Uint32 minTime = 0;
const Uint32 defaultPlayTime = 30000;

enum menuOption {
    PLAY,
    PAUSE,
    END,
};
Uint8 option = PLAY;

bool touch_pause = false, touch_continue = false, locked_button = false;


int boardStatus[11][11] = { 1, 5, 4, 0, 0, 0, 0, 0, 0, 0, 0,
                            4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            5, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0,
                            3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9,
                            0, 0, 0, 0, 0, 0, 0, 0, 8, 0,11,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 9,10,
                            0, 0, 0, 0, 0, 0, 0, 0,10,11, 7 };

int boardTarget[11][11] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
/*
1 - Current Choosing
2 - Move Without Eating
3 - Move And Eat
4 - Move And Eat Allies (King Only)
5 - Being Checkmated
-1 - Border

*/
int boardInDanger[11][11] ={    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };


TTF_Font* menu_font = nullptr;
TTF_Font* clockLeft_font = nullptr;
TTF_Font* name_font = nullptr;
TTF_Font* clockTurn_font = nullptr;
TTF_Font* pause_font = nullptr;
TTF_Font* end_font = nullptr;
TTF_Font* note_font = nullptr;



//Ingame
int randomChosen = -1;
int turnCountdown = 0;
int step = 0;

int currentTurnSide = 0;
bool mustMoveKing = false;

bool isTargeted = false;
int xTargeted = 0, yTargeted = 0;
bool mouseDown = false;
bool mouseMoved = false;
bool secondTargeted = false;
bool movePlayed = false;
bool gameOver = false;
bool sideCanMove = false;

int winner = -2;

bool king1Alive = true;
bool king2Alive = true;

bool sideChecked = false;

int currentChoosing = 0;

int xMouse = 0, yMouse=0;
int xPoint = 0, yPoint = 0;
int xPlay = 0, yPlay = 0;

Uint32 player1TimeLeft = 60000;
Uint32 player2TimeLeft = 60000;
Uint32 player1TurnTime = 30000;
Uint32 player2TurnTime = 30000;

Uint32 player1RememTime = player1TimeLeft;
Uint32 player2RememTime = player2TimeLeft;

Mix_Chunk* touch_button = nullptr;
Mix_Chunk* click_button = nullptr;

Mix_Music* play_music = nullptr;



#endif // VARANDFUNC_H
