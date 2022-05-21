#include <iostream>
#include <SDL.h>
#include "DrawBoard.h"
#include "VarAndFunc.h"
#include "initgame.h"
#include "LoadMedia.h"
#include "gameLogic.h"

int main(int argc, char* argv[])
{
    init();
    loadMedia();
    SDL_Event e;

    bool quit = false;

    while(!quit) switch(option){
    case PLAY:
        /*
        if (!Mix_PlayingMusic()) {
            Mix_FreeMusic(play_music);
            Mix_PlayMusic(play_music, 1);
        }
        */
        SDL_SetRenderDrawColor(renderer, 0,0,255,128);
        SDL_RenderClear(renderer);
        //checkStep();
        startDrawBoard();
        drawBorder();
        drawClock();
        drawDiscription();
        drawDanger();
        DrawBoardTarget();
        drawBoardPieces();
        drawPieceFollowCursor();
        //displayClock();
        displayCoor();
        //drawDanger();
        SDL_RenderPresent(renderer);
        while(SDL_PollEvent(&e)!=0)
        {
            pause_button.handleEvent(&e);
            switch(pause_button.getCurrentStatus()) {
            case MOUSE_OUT:
                touch_pause = false;
                break;
            case MOUSE_IN:
                touch_pause = true;
                break;
            case MOUSE_DOWN:
                option = PAUSE;
                playTime.pause();
                //Mix_PauseMusic();
                pause_button.reset();
                Mix_PlayChannel(1, click_button, 0);
                break;
            }
            if (touch_pause) {
                if (!locked_button) {
                    locked_button = true;
                    Mix_PlayChannel(1, touch_button,0);
                }
            }
            else locked_button = false;
            //if (option==PLAY) {
            switch(e.type) {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_MOUSEMOTION:
                SDL_GetMouseState(&xMouse, &yMouse);
                if (xMouse>=75&&yMouse>=82&&xMouse<(75+11*55)&&yMouse<(82+11*55)&&(xMouse-75)%55<50&&(yMouse-82)%55<50&&mouseDown==false) {
                    xPoint = (xMouse-75)/55;
                    yPoint = (yMouse-82)/55;
                }
                if (mouseDown==true) mouseMoved = true;
                break;
            case SDL_KEYDOWN:
                if (mouseDown==false) {
                switch(e.key.keysym.sym) {
                case SDLK_a:
                case SDLK_LEFT:
                    xPoint = std::max(xPoint-1,0);
                    break;
                case SDLK_d:
                case SDLK_RIGHT:
                    xPoint = std::min(xPoint+1,10);
                    break;
                case SDLK_w:
                case SDLK_UP:
                    yPoint = std::max(yPoint-1,0);
                    break;
                case SDLK_s:
                case SDLK_DOWN:
                    yPoint = std::min(yPoint+1,10);
                    break;
                case SDLK_RETURN:
                    if (boardStatus[yPoint][xPoint]!=-1)
                    {
                        //std::cout <<"Passed condition 1\n";
                        if (boardStatus[yPoint][xPoint]!=0)
                        {
                        if ((boardStatus[yPoint][xPoint]-1)/6==currentTurnSide) {
                            //std::cout<<"Passed condition 2\n";
                            if (isTargeted == false) {
                                isTargeted = true;
                                //currentChoosing = boardStatus[yPoint][xPoint];
                                xTargeted = xPoint;
                                yTargeted = yPoint;
                                boardTarget[yPoint][xPoint] = 1;
                                checkMove(boardStatus, yPoint, xPoint);
                                //std::cout <<"If 2.1 runned\n";
                            }
                            else {
                                //std::cout <<"Condition 3 used\n";
                                if (boardTarget[yPoint][xPoint]==1) {
                                    isTargeted = false;
                                    secondTargeted = false;
                                    //boardStatus[yPoint][xPoint] = currentChoosing;
                                    //currentChoosing = 0;
                                    resetTarget();
                                    mouseMoved = false;
                                    //std::cout <<"If 3.1 runned\n";
                                }
                                else {
                                    //boardStatus[yTargeted][xTargeted] = currentChoosing;
                                    resetTarget();
                                    //currentChoosing = boardStatus[yPoint][xPoint];
                                    xTargeted = xPoint;
                                    yTargeted = yPoint;
                                    boardTarget[yPoint][xPoint] = 1;
                                    checkMove(boardStatus, yPoint, xPoint);
                                    //std::cout <<"If 3.3 runned\n";
                                }
                            }
                        }
                        else {
                            if (boardTarget[yPoint][xPoint] >= 2 && boardTarget[yPoint][xPoint]<=4&&boardStatus[yPoint][xPoint]!=-1)
                                {
                                    mustMoveKing = false;
                                    sideCanMove = false;
                                    sideChecked = false;
                                    if (isChecked(boardStatus, currentTurnSide)==true) turnCountdown--;
                                    boardStatus[yPoint][xPoint] = boardStatus[yTargeted][xTargeted];
                                    boardStatus[yTargeted][xTargeted] = 0;
                                    secondTargeted = false;
                                    isTargeted = false;
                                    resetTarget();
                                    mouseMoved = false;
                                    xTargeted = 0;
                                    yTargeted = 0;
                                    currentTurnSide = abs(currentTurnSide-1);
                                    turnCountdown--;
                                    movePlayed = true;
                                    checkChecked();
                                    checkStep();
                                    checkMustMove();
                                    checkSideCanMove();
                                    checkKingAlive();
                                    if (gameOver==false) checkCanPlay();
                                }
                        }
                        }
                        else {
                            //std::cout <<"Condition 2 failed\n";
                            //boardStatus[yTargeted][xTargeted] = currentChoosing;
                            if (isTargeted == true) {
                                if (boardTarget[yPoint][xPoint] >= 2 && boardTarget[yPoint][xPoint]<=4&&boardStatus[yPoint][xPoint]!=-1)
                                {
                                    mustMoveKing = false;
                                    sideCanMove = false;
                                    sideChecked = false;
                                    if (isChecked(boardStatus, currentTurnSide)==true) turnCountdown--;
                                    boardStatus[yPoint][xPoint] = boardStatus[yTargeted][xTargeted];
                                    boardStatus[yTargeted][xTargeted] = 0;
                                    secondTargeted = false;
                                    isTargeted = false;
                                    resetTarget();
                                    mouseMoved = false;
                                    xTargeted = 0;
                                    yTargeted = 0;
                                    currentTurnSide = abs(currentTurnSide-1);
                                    turnCountdown--;
                                    movePlayed = true;
                                    checkChecked();
                                    checkStep();
                                    checkMustMove();
                                    checkSideCanMove();
                                    checkKingAlive();
                                    if (gameOver==false) checkCanPlay();
                                }
                                else {
                                isTargeted = false;
                                resetTarget();
                                xTargeted = 0;
                                yTargeted = 0;
                                }
                                //std::cout <<"Failed 2.1 used\n";
                            }
                        }
                    }
                    else {
                        if (isTargeted == true) {
                            isTargeted = false;
                            resetTarget();
                            xTargeted = 0;
                            yTargeted = 0;
                            //std::cout <<"Failed 2.2 used\n";
                        }
                    }
                    //printBoard(boardStatus);
                    //std::cout << xPoint << " " << yPoint << std::endl;
                    //printBoard(boardTarget);
                    break;
                }
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                mouseDown = true;
                SDL_GetMouseState(&xMouse, &yMouse);
                if (xMouse>=75&&yMouse>=82&&xMouse<(75+11*55)&&yMouse<(82+11*55)&&(xMouse-75)%55<50&&(yMouse-82)%55<50) {
                    xPoint = (xMouse-75)/55;
                    yPoint = (yMouse-82)/55;
                    if (boardStatus[yPoint][xPoint]!=-1)
                    {
                        if (boardStatus[yPoint][xPoint]!=0&&(boardStatus[yPoint][xPoint]-1)/6==currentTurnSide)
                        {
                            if (isTargeted == false) {
                                isTargeted = true;
                                currentChoosing = boardStatus[yPoint][xPoint];
                                xTargeted = xPoint;
                                yTargeted = yPoint;
                                boardTarget[yPoint][xPoint] = 1;
                                checkMove(boardStatus, yPoint, xPoint);
                                boardStatus[yPoint][xPoint] = 13;
                            }
                            else {
                                if (boardTarget[yPoint][xPoint]==1) {
                                    secondTargeted = true;
                                    currentChoosing = boardStatus[yPoint][xPoint];
                                    boardStatus[yPoint][xPoint] = 13;
                                }
                                else {
                                    resetTarget();
                                    currentChoosing = boardStatus[yPoint][xPoint];
                                    xTargeted = xPoint;
                                    yTargeted = yPoint;
                                    boardTarget[yPoint][xPoint] = 1;
                                    checkMove(boardStatus, yPoint, xPoint);
                                    boardStatus[yPoint][xPoint] = 13;
                                }
                            }
                        }
                        else {
                            if (isTargeted == true) {
                                isTargeted = false;
                                resetTarget();
                                xTargeted = 0;
                                yTargeted = 0;
                            }
                            e.type = SDL_MOUSEBUTTONUP;
                            SDL_PushEvent(&e);
                        }
                    }
                }
                else {
                    if (isTargeted == true) {
                        isTargeted = false;
                        resetTarget();
                        xTargeted = 0;
                        yTargeted = 0;
                    }
                    e.type = SDL_MOUSEBUTTONUP;
                    SDL_PushEvent(&e);
                }
                break;
            case SDL_MOUSEBUTTONUP:
                mouseDown = false;
                if (currentChoosing==0) {

                }
                else {
                    if (mouseMoved == false) {
                        if (secondTargeted == true) {
                            isTargeted = false;
                            secondTargeted = false;
                            boardStatus[yPoint][xPoint] = currentChoosing;
                            currentChoosing = 0;
                            resetTarget();
                        }
                        else {
                            boardStatus[yPoint][xPoint] = currentChoosing;
                            currentChoosing = 0;
                        }
                    }
                    else {
                        if (xMouse>=75&&yMouse>=82&&xMouse<(75+11*55)&&yMouse<(82+11*55)&&(xMouse-75)%55<50&&(yMouse-82)%55<50)
                        {
                            xPoint = (xMouse-75)/55;
                            yPoint = (yMouse-82)/55;
                            if (boardTarget[yPoint][xPoint] >= 2 && boardTarget[yPoint][xPoint]<=4&&boardStatus[yPoint][xPoint]!=-1)
                            {
                                mustMoveKing = false;
                                sideCanMove = false;
                                //sideChecked = false;
                                if (sideChecked==true) turnCountdown--;
                                sideChecked = false;
                                boardStatus[yTargeted][xTargeted] = 0;
                                boardStatus[yPoint][xPoint] = currentChoosing;
                                secondTargeted = false;
                                isTargeted = false;
                                currentChoosing = 0;
                                resetTarget();
                                mouseMoved = false;
                                xTargeted = 0;
                                yTargeted = 0;
                                currentTurnSide = abs(currentTurnSide-1);
                                turnCountdown--;
                                movePlayed = true;
                                checkChecked();
                                checkStep();
                                checkMustMove();
                                checkSideCanMove();
                                checkKingAlive();
                                if (gameOver==false) checkCanPlay();
                            }
                            else {
                                boardStatus[yTargeted][xTargeted] = currentChoosing;
                                currentChoosing = 0;
                                secondTargeted = false;
                                mouseMoved = false;
                            }
                        }
                        else {
                            boardStatus[yTargeted][xTargeted] = currentChoosing;
                            currentChoosing = 0;
                            secondTargeted = false;
                            mouseMoved = false;
                        }
                    }
                }
                break;
            }
            //}

        }
        processClock();
        if (player1TimeLeft<=50||player2TimeLeft<=50) {
            gameOver = true;
            winner = abs(currentTurnSide-1);
        }
        if (gameOver == true) {
            option = END;
            //Mix_PauseMusic();
            playTime.stop();
            SDL_Delay(3000);
        }
        break;
    case PAUSE:
        pauseBackground.renderTexture(0, 0);
        pauseTexture.renderTexture(400, 150);
        continue_button.renderButton();
        SDL_RenderPresent(renderer);
        while(SDL_PollEvent(&e)!=0) {
            if (e.type == SDL_QUIT) {
                quit = true;
                break;
            }
            continue_button.handleEvent(&e);
            switch(continue_button.getCurrentStatus()) {
            case MOUSE_OUT:
                touch_continue = false;
                continue_button.setButtonColor(0, 0, 0);
                break;
            case MOUSE_IN:
                touch_continue = true;
                continue_button.setButtonColor(255, 0 ,0);
                break;
            case MOUSE_DOWN:
                option = PLAY;
                playTime.resume();
                Mix_ResumeMusic();
                continue_button.reset();
                Mix_PlayChannel(1, click_button, 0);
                break;
            }
            if (touch_continue) {
                if (!locked_button) {
                    locked_button = true;
                    Mix_PlayChannel(1, touch_button, 0);
                }
            }
        }
        break;
    case END:
        endBackground.renderTexture(0, 0);
        if (winner == 1) conclusion.loadTextureFromText("Player 2 Win!!!", menu_font, {0, 0, 0});
        else if (winner == 0) conclusion.loadTextureFromText("Player 1 Win!!!", menu_font, {0, 0, 0});
        else conclusion.loadTextureFromText("Game End In Draw", menu_font, {0, 0 ,0});
        conclusion.setTextureSize(500, 250);
        conclusion.renderTexture(SCREEN_WIDTH/2-250, SCREEN_HEIGHT/2-125);
        SDL_RenderPresent(renderer);
        while(SDL_PollEvent(&e)!=0) {
            if (e.type==SDL_QUIT){
                quit = true;
                break;
            }
        }

    }

    return 0;
}
