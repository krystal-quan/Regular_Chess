#ifndef LOADMEDIA_H
#define LOADMEDIA_H
#include "Button.h"
void loadMedia()
{
    //font
    menu_font = TTF_OpenFont("font/samurai.ttf", 120);
    clockLeft_font = TTF_OpenFont("font/clock1.ttf",75);
    name_font = TTF_OpenFont("font/name.ttf", 35);
    clockTurn_font = TTF_OpenFont("font/clock1.ttf",45);
    pause_font = TTF_OpenFont("font/blossoms.ttf",150);
    end_font = TTF_OpenFont("font/samurai.ttf",200);
    note_font = TTF_OpenFont("font/clock1.ttf", 35);

    //clock
    player1Color.loadTextureFromFile("player1color.png", 0, 0, 0);
    player1Color.setTextureSize(45,40);
    //player1Color.setTextureAlpha(64);
    //player1Color.setTextureBlendMode(SDL_BLENDMODE_BLEND);
    player2Color.loadTextureFromFile("player2color.png", 0, 0, 0);
    player2Color.setTextureSize(45,40);
    player2Color.setTextureBlendMode(SDL_BLENDMODE_BLEND);
    player1Name.loadTextureFromText("Player 1", name_font, {0, 0, 0});
    player1Name.setTextureSize(175, 35);
    player2Name.loadTextureFromText("Player 2", name_font, {0, 0, 0});
    player2Name.setTextureSize(175, 35);
    //Board
    boardBackground.loadTextureFromFile("sakura-frames.png",0,0,255);
    boardBackground.setTextureSize(750,750);
    player1Board.loadTextureFromFile("Player1.png");
    player1Board.setTextureSize(285,240);
    player2Board.loadTextureFromFile("Player2.png");
    player2Board.setTextureSize(285,240);
    currentChoosed.loadTextureFromFile("yellow.jpg");
    currentChoosed.setTextureSize(50,50);
    //currentChoosed.setTextureBlendMode(SDL_BLENDMODE_BLEND);
    //currentChoosed.setTextureAlpha(128);
    emptyMove.loadTextureFromFile("silver.png");
    emptyMove.setTextureSize(50,50);
    //emptyMove.setTextureBlendMode(SDL_BLENDMODE_BLEND);
    //emptyMove.setTextureAlpha(128);
    eatingMove.loadTextureFromFile("orange.png");
    eatingMove.setTextureSize(50,50);
    //eatingMove.setTextureBlendMode(SDL_BLENDMODE_BLEND);
    //eatingMove.setTextureAlpha(128);
    mustEatingMove.loadTextureFromFile("purple.png");
    mustEatingMove.setTextureSize(50,50);
    //mustEatingMove.setTextureBlendMode(SDL_BLENDMODE_BLEND);
    //mustEatingMove.setTextureAlpha(128);
    beingChecked.loadTextureFromFile("darkpink.png");
    beingChecked.setTextureSize(50,50);
    //beingChecked.setTextureBlendMode(SDL_BLENDMODE_BLEND);
    //beingChecked.setTextureAlpha(128);

    beingDanger.loadTextureFromFile("red.png");
    beingDanger.setTextureSize(50,50);

    pinkTexture.loadTextureFromFile("pink.png");
    pinkTexture.setTextureSize(50,50);
    brownTexture.loadTextureFromFile("brown.png");
    brownTexture.setTextureSize(50,50);
    borderTexture.loadTextureFromFile("border.png");
    borderTexture.setTextureSize(50,50);
    gameAllBackground.loadTextureFromFile("screen-11.png",0,0,255);
    gameAllBackground.setTextureSize(1100,750);
    currentPointing.loadTextureFromFile("Pointing.png");
    currentPointing.setTextureSize(50,50);

    pause_button.textureFromFile("pause_button.png", 0, 0, 255);
    pause_button.setButtonSize(75,75);
    pause_button.setPosition(SCREEN_WIDTH-75,0);

    touch_button = Mix_LoadWAV("sound/touch_button.wav");
    Mix_VolumeChunk(touch_button, 50);
    click_button = Mix_LoadWAV("sound/click_button.wav");
    Mix_VolumeChunk(click_button, 50);
    //play_music = Mix_LoadMUS("sound/play.wav");
    //Mix_VolumeMusic(50);

    continue_button.textureFromText("Continue", menu_font, {0, 0, 0});
    continue_button.setButtonSize(300, 150);
    continue_button.setPosition(SCREEN_WIDTH/2-150, SCREEN_HEIGHT/2-75);

    pauseTexture.loadTextureFromText("PAUSED", pause_font, {255, 0, 0});
    pauseTexture.setTextureSize(300, 120);
    pauseBackground.loadTextureFromFile("pausefont.png");
    pauseBackground.setTextureSize(SCREEN_WIDTH, SCREEN_HEIGHT);

    endBackground.loadTextureFromFile("endbackground.jpg");
    endBackground.setTextureSize(SCREEN_WIDTH,SCREEN_HEIGHT);

    noteBoard.loadTextureFromFile("note_board.png");
    noteBoard.setTextureSize(330, 140);


}

void closeMedia()
{

}



#endif // LOADMEDIA_H
