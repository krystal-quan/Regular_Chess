#ifndef DRAWBOARD_H
#define DRAWBOARD_H
#include "Texture.h"
#include "Button.h"
#include "Timer.h"
#include "gameLogic.h"


void startDrawBoard()
    {
        gameAllBackground.renderTexture(0,0);
        boardBackground.renderTexture(0,0);
        for (int i=0;i<11;i++)
            for (int j=0;j<11;j++)
        {
            if ((i+j)%2==0) pinkTexture.renderTexture(75+i*55, 82+j*55);
            else brownTexture.renderTexture(75+i*55, 82+j*55);
        }
        player1Board.renderTexture(750,75);
        player2Board.renderTexture(750,500);
    }
void drawPieceFollowCursor()
{
    if (currentChoosing!=0&&mouseDown == true) {
        SDL_Rect cursorSqr;
        cursorSqr.h=50;
        cursorSqr.w=50;
        cursorSqr.x=((currentChoosing-1)%6)*50;
        cursorSqr.y=(currentChoosing-1)/6*50;
        pieceTexture.renderTexture(xMouse-25, yMouse-25,&cursorSqr);
    }
}

void drawBoardPieces()
{
    pieceTexture.loadTextureFromFile("pieces1.png", 0, 0, 255);
    pieceTexture.setTextureSize(50,50);
    SDL_Rect tempPiece;
    tempPiece.w=50;
    tempPiece.h=50;
    for (int i=0;i<11;i++) for (int j=0;j<11;j++) {
        switch (boardStatus[i][j]) {
        case -1:
            borderTexture.renderTexture(75+j*55, 82+i*55);
            break;
        case 1:
            tempPiece.x=0;
            tempPiece.y=0;
            pieceTexture.renderTexture(75+j*55, 82+i*55,&tempPiece);
            break;
        case 2:
            tempPiece.x=50;
            tempPiece.y=0;
            pieceTexture.renderTexture(75+j*55, 82+i*55,&tempPiece);
            break;
        case 3:
            tempPiece.x=100;
            tempPiece.y=0;
            pieceTexture.renderTexture(75+j*55, 82+i*55,&tempPiece);
            break;
        case 4:
            tempPiece.x=150;
            tempPiece.y=0;
            pieceTexture.renderTexture(75+j*55, 82+i*55,&tempPiece);
            break;
        case 5:
            tempPiece.x=200;
            tempPiece.y=0;
            pieceTexture.renderTexture(75+j*55, 82+i*55,&tempPiece);
            break;
        case 6:
            tempPiece.x=250;
            tempPiece.y=0;
            pieceTexture.renderTexture(75+j*55, 82+i*55,&tempPiece);
            break;
        case 7:
            tempPiece.x=0;
            tempPiece.y=50;
            pieceTexture.renderTexture(75+j*55, 82+i*55,&tempPiece);
            break;
        case 8:
            tempPiece.x=50;
            tempPiece.y=50;
            pieceTexture.renderTexture(75+j*55, 82+i*55,&tempPiece);
            break;
        case 9:
            tempPiece.x=100;
            tempPiece.y=50;
            pieceTexture.renderTexture(75+j*55, 82+i*55,&tempPiece);
            break;
        case 10:
            tempPiece.x=150;
            tempPiece.y=50;
            pieceTexture.renderTexture(75+j*55, 82+i*55,&tempPiece);
            break;
        case 11:
            tempPiece.x=200;
            tempPiece.y=50;
            pieceTexture.renderTexture(75+j*55, 82+i*55,&tempPiece);
            break;
        case 12:
            tempPiece.x=250;
            tempPiece.y=50;
            pieceTexture.renderTexture(75+j*55, 82+i*55,&tempPiece);
            break;
        case 13:
            if (mouseDown == false) {
                tempPiece.x=((currentChoosing-1)%6)*50;
                tempPiece.y=(currentChoosing-1)/6*50;
                pieceTexture.renderTexture(75+j*55, 82+i*55,&tempPiece);
            }
        }
    }
    currentPointing.renderTexture(xPoint*55+75, yPoint*55+82);
    pause_button.renderButton();
}

void DrawBoardTarget()
{
    for (int i=0;i<11;i++) for (int j=0;j<11;j++) {
        switch (boardTarget[i][j]) {
        case 1:
            currentChoosed.renderTexture(75+j*55, 82+i*55);
            break;
        case 2:
            emptyMove.renderTexture(75+j*55, 82+i*55);
            break;
        case 3:
            eatingMove.renderTexture(75+j*55, 82+i*55);
            break;
        case 4:
            mustEatingMove.renderTexture(75+j*55, 82+i*55);
            break;
        case 5:
            beingChecked.renderTexture(75+j*55, 82+i*55);
            break;
        }

    }
}

void displayTime()
{
    clockDisplay.loadTextureFromText("00:26", clockLeft_font,{198,35,53});
    clockDisplay.setTextureSize(100,50);
    clockDisplay.renderTexture(800,200);
}

std::string timeToString(Uint32 timePlay)
{
    int mil = timePlay%1000;
    int sec = timePlay/1000;
    int mie = sec/60;
    std::string ans = "";
    ans = ans + std::to_string(mie) + ":";
    if (sec%60<10) ans = ans + "0";
    ans = ans + std::to_string(sec%60) + ":";
    if (mil<100) ans = ans + "0";
    if (mil<10) ans = ans + "0";
    ans = ans + std::to_string(mil);
    return ans;
}

std::string mix(int x, int y)
{
    return std::to_string(x) + " - " + std::to_string(y);
}

void drawClock()
{
    player1Name.renderTexture(842, 270);
    player2Name.renderTexture(845, 515);
    player1Color.renderTexture(785, 270);
    player2Color.renderTexture(787, 512);
    clockTimeLeft.loadTextureFromText(timeToString(player1TimeLeft),clockLeft_font, {0, 0, 0});
    if (player1TimeLeft<=15000) clockTimeLeft.loadTextureFromText(timeToString(player1TimeLeft), clockLeft_font, {255, 0, 0});
    clockTimeLeft.setTextureSize(220, 75);
    clockTimeLeft.renderTexture(790, 100);
    clockTurnTime.loadTextureFromText(timeToString(player1TurnTime),clockTurn_font, {0, 0, 0});
    if (player1TurnTime<=10000) clockTurnTime.loadTextureFromText(timeToString(player1TurnTime), clockTurn_font, {255, 0, 0});
    clockTurnTime.setTextureSize(195, 45);
    clockTurnTime.renderTexture(820, 195);
    clockTimeLeft.loadTextureFromText(timeToString(player2TimeLeft),clockLeft_font, {0, 0, 0});
    if (player2TimeLeft<=15000) clockTimeLeft.loadTextureFromText(timeToString(player2TimeLeft), clockLeft_font, {255, 0, 0});
    clockTimeLeft.setTextureSize(220, 75);
    clockTimeLeft.renderTexture(785, 645);
    clockTurnTime.loadTextureFromText(timeToString(player2TurnTime),clockTurn_font, {0, 0, 0});
    if (player2TurnTime<=10000) clockTurnTime.loadTextureFromText(timeToString(player2TurnTime), clockTurn_font, {255, 0, 0});
    clockTurnTime.setTextureSize(195, 45);
    clockTurnTime.renderTexture(820, 575);

    noteBoard.renderTexture(750,340);
}
std::string displayTurn()
{
    std::string ans = "";
    if (turnCountdown<10) ans = "0" + ans;
    ans = ans + std::to_string(turnCountdown);
    return ans;
}

void displayCoor()
{
    tempVar.loadTextureFromText(displayTurn(), clockLeft_font, {198,35,53});
    tempVar.setTextureSize(70,50);
    tempVar.renderTexture(865,410);
}

void drawDiscription()
{
    switch(step){
    case 0:
        noteDis.loadTextureFromText("Move to Start Game", note_font, {0, 0, 0});
        break;
    case 1:
        noteDis.loadTextureFromText("Playzone appear in:", note_font, {0, 0, 0});
        break;
    case 2:
    case 6:
    case 10:
        noteDis.loadTextureFromText("Playzone start small in", note_font, {0, 0, 0});
    case 3:
    case 4:
    case 5:
    case 7:
    case 8:
    case 9:
    case 11:
    case 12:
    case 13:
        noteDis.loadTextureFromText("Playzone smallize in", note_font, {0, 0, 0});
        break;
    case 14:
        noteDis.loadTextureFromText("Final Battle!!!", note_font,{0, 0, 0});
    }
    noteDis.setTextureSize(270, 50);
    noteDis.renderTexture(785, 363);
}

void drawBorder()
{
    int round = (step + 2)/4;
    int dimension = 11-3*round;
    if (randomChosen!=-1) {
        int posx = (randomChosen-1)%4;
        int posy = (randomChosen-1)/4;
        SDL_Rect temp;
        temp.x = 75+xPlay*55+posx*55-5;
        temp.y = 82+yPlay*55+posy*55-5;
        temp.h = 5;
        temp.w = 55*dimension+5;
        SDL_RenderFillRect(renderer, &temp);
        temp.h = 55*dimension+5;
        temp.w = 5;
        SDL_RenderFillRect(renderer, &temp);
        temp.x = 75+xPlay*55+posx*55+55*dimension-5;
        SDL_RenderFillRect(renderer,&temp);
        temp.x = 75+xPlay*55+posx*55-5;
        temp.y = 82+yPlay*55+posy*55+55*dimension-5;
        temp.h = 5;
        temp.w = 55*dimension+5;
        SDL_RenderFillRect(renderer,&temp);
    }
}

void drawDanger()
{
    int timeStep = playTime.getTick()%2000;
    timeStep = timeStep/4;
    int alpha;
    if (timeStep<=250) alpha = timeStep;
    else alpha = 500 - timeStep;
    beingDanger.setTextureAlpha(alpha);
    for (int i=0;i<11;i++) for (int j=0;j<11;j++) if (boardInDanger[i][j]==1) {
        //std::cout << i << " "<< j << std::endl;
        beingDanger.renderTexture(75+j*55, 82+i*55);
        //std::cout << "drawDanger() activated!\n";
    }
    //std::cout << alpha << std::endl;
}


#endif // DRAWBOARD_H
