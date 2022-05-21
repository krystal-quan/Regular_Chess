#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include "VarAndFunc.h"
#include "random.h"
#include "Timer.h"
#include "DrawBoard.h"


void printBoard(int cBP[][11])
{
    for (int i=0;i<11;i++) {
                        for (int j=0l;j<11;j++) std::cout << cBP[i][j] << " ";
                        std::cout << std::endl;
                    }
                    std::cout << std::endl;
}

bool canCheckKing(int cBP[][11], int xpos, int ypos)
{
    int typeOfPiece = cBP[xpos][ypos]%6;
    int kingFind = (abs((cBP[xpos][ypos]-1)/6-1)*6+1);
    switch(typeOfPiece)  {
    case 3:
        for(int i=1;i<=4;i++) {
            if (xpos-i<0) break;
            else if (cBP[xpos-i][ypos]!=0 && cBP[xpos-i][ypos]!=kingFind) break;
            else if (cBP[xpos-i][ypos]==kingFind) return true;
        }
        for(int i=1;i<=4;i++) {
            if (xpos+i>=11) break;
            else if (cBP[xpos+i][ypos]!=0 && cBP[xpos+i][ypos]!=kingFind) break;
            else if (cBP[xpos+i][ypos]==kingFind) return true;
        }
        for(int i=1;i<=4;i++) {
            if (ypos-i<0) break;
            else if (cBP[xpos][ypos-i]!=0 && cBP[xpos][ypos-i]!=kingFind) break;
            else if (cBP[xpos][ypos-i]==kingFind) return true;
        }
        for(int i=1;i<=4;i++) {
            if (ypos+i>=11) break;
            else if (cBP[xpos][ypos+i]!=0 && cBP[xpos][ypos+i]!=kingFind) break;
            else if (cBP[xpos][ypos+i]==kingFind) return true;
        }
        return false;
        break;
    case 5:
        for(int i=1;i<=3;i++) {
           if (xpos-i<0||ypos-i<0) break;
           else if (cBP[xpos-i][ypos-i]!=0 && cBP[xpos-i][ypos-i]!=kingFind) break;
           else if (cBP[xpos-i][ypos-i]==kingFind) return true;
        }
        for(int i=1;i<=3;i++) {
           if (xpos-i<0||ypos+i>=11) break;
           else if (cBP[xpos-i][ypos+i]!=0 && cBP[xpos-i][ypos+i]!=kingFind) break;
           else if (cBP[xpos-i][ypos+i]==kingFind) return true;
        }
        for(int i=1;i<=3;i++) {
           if (xpos+i>=11||ypos-i<0) break;
           else if (cBP[xpos+i][ypos-i]!=0 && cBP[xpos+i][ypos-i]!=kingFind) break;
           else if (cBP[xpos+i][ypos-i]==kingFind) return true;
        }
        for(int i=1;i<=3;i++) {
           if (xpos+i>=11||ypos-i>=11) break;
           else if (cBP[xpos+i][ypos+i]!=0 && cBP[xpos+i][ypos+i]!=kingFind) break;
           else if (cBP[xpos+i][ypos+i]==kingFind) return true;
        }
        return false;
        break;
    case 2:
        for(int i=1;i<=2;i++) {
           if (xpos-i<0||ypos-i<0) break;
           else if (cBP[xpos-i][ypos-i]!=0 && cBP[xpos-i][ypos-i]!=kingFind) break;
           else if (cBP[xpos-i][ypos-i]==(abs((cBP[xpos][ypos]-1)/6-1)*6+1)) return true;
        }
        for(int i=1;i<=2;i++) {
           if (xpos-i<0||ypos+i>=11) break;
           else if (cBP[xpos-i][ypos+i]!=0 && cBP[xpos-i][ypos+i]!=kingFind) break;
           else if (cBP[xpos-i][ypos+i]==(abs((cBP[xpos][ypos]-1)/6-1)*6+1)) return true;
        }
        for(int i=1;i<=2;i++) {
           if (xpos+i>=11||ypos-i<0) break;
           else if (cBP[xpos+i][ypos-i]!=0 && cBP[xpos+i][ypos-i]!=kingFind) break;
           else if (cBP[xpos+i][ypos-i]==kingFind) return true;
        }
        for(int i=1;i<=2;i++) {
           if (xpos+i>=11||ypos-i>=11) break;
           else if (cBP[xpos+i][ypos+i]!=0 && cBP[xpos+i][ypos+i]!=kingFind) break;
           else if (cBP[xpos+i][ypos+i]==kingFind) return true;
        }
        for(int i=1;i<=3;i++) {
            if (xpos-i<0) break;
            else if (cBP[xpos-i][ypos]!=0 && cBP[xpos-i][ypos]!=kingFind) break;
            else if (cBP[xpos-i][ypos]==kingFind) return true;
        }
        for(int i=1;i<=3;i++) {
            if (xpos+i>=11) break;
            else if (cBP[xpos+i][ypos]!=0 && cBP[xpos+i][ypos]!=kingFind) break;
            else if (cBP[xpos+i][ypos]==kingFind) return true;
        }
        for(int i=1;i<=3;i++) {
            if (ypos-i<0) break;
            else if (cBP[xpos][ypos-i]!=0 && cBP[xpos][ypos-i]!=kingFind) break;
            else if (cBP[xpos][ypos-i]==kingFind) return true;
        }
        for(int i=1;i<=3;i++) {
            if (ypos+i>=11) break;
            else if (cBP[xpos][ypos+i]!=0 && cBP[xpos][ypos+i]!=kingFind) break;
            else if (cBP[xpos][ypos+i]==kingFind) return true;
        }
        return false;
        break;
    case 4:
        if (xpos-2>=0) {
            if (ypos-1>=0) if (cBP[xpos-2][ypos-1]==kingFind) return true;
            if (ypos+1<11) if (cBP[xpos-2][ypos+1]==kingFind) return true;
        }
        if (ypos-2>=0) {
            if (xpos-1>=0) if (cBP[xpos-1][ypos-2]==kingFind) return true;
            if (xpos+1<11) if (cBP[xpos+1][ypos-2]==kingFind) return true;
        }
        if (xpos+2<11) {
            if (ypos-1>=0) if (cBP[xpos+2][ypos-1]==kingFind) return true;
            if (ypos+1<11) if (cBP[xpos+2][ypos+1]==kingFind) return true;
        }
        if (ypos+2<11) {
            if (xpos-1>=0) if (cBP[xpos-1][ypos+2]==kingFind) return true;
            if (xpos+1<11) if (cBP[xpos+1][ypos+2]==kingFind) return true;
        }
        return false;
        break;
    }
    return false;
}

bool isChecked(int cBPa[][11],int side = 0, int xpos = -1, int ypos = -1, int xnew = -1, int ynew = -1)
{
    int cBP[11][11];
    for (int i=0;i<11;i++) for (int j=0;j<11;j++) cBP[i][j]=boardStatus[i][j];
    if (xpos!=-1) {
        cBP[xnew][ynew] = cBP[xpos][ypos];
        cBP[xpos][ypos] = 0;
        //printBoard();
    }
    for (int i=0;i<11;i++) for (int j=0;j<11;j++) {
        if (cBP[i][j]!=0&&((cBP[i][j]-1)/6!=side)&&cBP[i][j]%6!=1&&cBP[i][j]%6!=0) {
            if (canCheckKing(cBP, i, j)==true) return true;
        }
    }
    return false;
}

void checkMove(int cBP[][11], int xpos, int ypos)
{
    int side = (cBP[xpos][ypos]-1)/6;
    int type = (cBP[xpos][ypos])%6;
    switch(type) {
    case 2:
        if (mustMoveKing == false) {
        for(int i=1;i<=2;i++) {
           if (xpos-i<0||ypos-i<0||cBP[xpos-i][ypos-i]==-1) break;
           else if (cBP[xpos-i][ypos-i]!=0)
           {
               if ((cBP[xpos-i][ypos-i]-1)/6==side) break;
               else {
                    if (isChecked(cBP, side, xpos, ypos, xpos-i, ypos-i) == false) {
                            boardTarget[xpos-i][ypos-i] = 3;
                            sideCanMove = true;
                            break;
                    }
                    else break;
               }
           }
           else if (cBP[xpos-i][ypos-i]==0)
           {
               if (isChecked(cBP, side, xpos, ypos, xpos-i, ypos-i) == false) {boardTarget[xpos-i][ypos-i] = 2;sideCanMove = true;}
           }
        }
        for(int i=1;i<=2;i++) {
           if (xpos+i>=11||ypos+i>=11||cBP[xpos+i][ypos+i]==-1) break;
           else if (cBP[xpos+i][ypos+i]!=0)
           {
               if ((cBP[xpos+i][ypos+i]-1)/6==side) break;
               else {
                    if (isChecked(cBP, side, xpos, ypos, xpos+i, ypos+i) == false) {
                            boardTarget[xpos+i][ypos+i] = 3;
                            sideCanMove = true;
                            break;
                    }
                    else break;
               }
           }
           else if (cBP[xpos+i][ypos+i]==0)
           {
               if (isChecked(cBP, side, xpos, ypos, xpos+i, ypos+i) == false) {boardTarget[xpos+i][ypos+i] = 2;sideCanMove = true;}
           }
        }
        for(int i=1;i<=2;i++) {
           if (xpos+i>=11||ypos-i<0||cBP[xpos+i][ypos-i]==-1) break;
           else if (cBP[xpos+i][ypos-i]!=0)
           {
               if ((cBP[xpos+i][ypos-i]-1)/6==side) break;
               else {
                    if (isChecked(cBP, side, xpos, ypos, xpos+i, ypos-i) == false) {
                            boardTarget[xpos+i][ypos-i] = 3;
                            sideCanMove = true;
                            break;
                    }
                    else break;
               }
           }
           else if (cBP[xpos+i][ypos-i]==0)
           {
               if (isChecked(cBP, side, xpos, ypos, xpos+i, ypos-i) == false) {boardTarget[xpos+i][ypos-i] = 2;sideCanMove = true;}
           }
        }
        for(int i=1;i<=2;i++) {
           if (xpos-i<0||ypos+i>=11||cBP[xpos-i][ypos+i]==-1) break;
           else if (cBP[xpos-i][ypos+i]!=0)
           {
               if ((cBP[xpos-i][ypos+i]-1)/6==side) break;
               else {
                    if (isChecked(cBP, side, xpos, ypos, xpos-i, ypos+i) == false) {
                            boardTarget[xpos-i][ypos+i] = 3;
                            sideCanMove = true;
                            break;
                    }
                    else break;
               }
           }
           else if (cBP[xpos-i][ypos+i]==0)
           {
               if (isChecked(cBP, side, xpos, ypos, xpos-i, ypos+i) == false) {boardTarget[xpos-i][ypos+i] = 2;sideCanMove = true;}
           }
        }
        for(int i=1;i<=3;i++) {
           if (ypos-i<0||cBP[xpos][ypos-i]==-1) break;
           else if (cBP[xpos][ypos-i]!=0)
           {
               if ((cBP[xpos][ypos-i]-1)/6==side) break;
               else {
                    if (isChecked(cBP, side, xpos, ypos, xpos, ypos-i) == false) {
                            boardTarget[xpos][ypos-i] = 3;
                            sideCanMove = true;
                            break;
                    }
                    else break;
               }
           }
           else if (cBP[xpos][ypos-i]==0)
           {
               if (isChecked(cBP, side, xpos, ypos, xpos, ypos-i) == false) {boardTarget[xpos][ypos-i] = 2;sideCanMove = true;}
           }
        }
        for(int i=1;i<=3;i++) {
           if (xpos-i<0||cBP[xpos-i][ypos]==-1) break;
           else if (cBP[xpos-i][ypos]!=0)
           {
               if ((cBP[xpos-i][ypos]-1)/6==side) break;
               else {
                    if (isChecked(cBP, side, xpos, ypos, xpos-i, ypos) == false) {
                            boardTarget[xpos-i][ypos] = 3;
                            sideCanMove = true;
                            break;
                    }
                    else break;
               }
           }
           else if (cBP[xpos-i][ypos]==0)
           {
               if (isChecked(cBP, side, xpos, ypos, xpos-i, ypos) == false) {boardTarget[xpos-i][ypos] = 2;sideCanMove = true;}
           }
        }
        for(int i=1;i<=3;i++) {
           if (xpos+i>=11||cBP[xpos+i][ypos]==-1) break;
           else if (cBP[xpos+i][ypos]!=0)
           {
               if ((cBP[xpos+i][ypos]-1)/6==side) break;
               else {
                    if (isChecked(cBP, side, xpos, ypos, xpos+i, ypos) == false) {
                            boardTarget[xpos+i][ypos] = 3;
                            sideCanMove = true;
                            break;
                    }
                    else break;
               }
           }
           else if (cBP[xpos+i][ypos]==0)
           {
               if (isChecked(cBP, side, xpos, ypos, xpos+i, ypos) == false) {boardTarget[xpos+i][ypos] = 2;sideCanMove = true;}
           }
        }
        for(int i=1;i<=3;i++) {
           if (ypos+i>=11||cBP[xpos][ypos+i]==-1) break;
           else if (cBP[xpos][ypos+i]!=0)
           {
               if ((cBP[xpos][ypos+i]-1)/6==side) break;
               else {
                    if (isChecked(cBP, side, xpos, ypos, xpos, ypos+i) == false) {
                            boardTarget[xpos][ypos+i] = 3;
                            sideCanMove = true;
                            break;
                    }
                    else break;
               }
           }
           else if (cBP[xpos][ypos+i]==0)
           {
               if (isChecked(cBP, side, xpos, ypos, xpos, ypos+i) == false) {boardTarget[xpos][ypos+i] = 2;sideCanMove = true;}
           }
        }
        }
        break;
    case 3:
        if (mustMoveKing == false) {
        for(int i=1;i<=4;i++) {
           if (ypos-i<0||cBP[xpos][ypos-i]==-1) break;
           else if (cBP[xpos][ypos-i]!=0)
           {
               if ((cBP[xpos][ypos-i]-1)/6==side) break;
               else {
                    if (isChecked(cBP, side, xpos, ypos, xpos, ypos-i) == false) {
                            boardTarget[xpos][ypos-i] = 3;
                            sideCanMove = true;
                            break;
                    }
                    else break;
               }
           }
           else if (cBP[xpos][ypos-i]==0)
           {
               if (isChecked(cBP, side, xpos, ypos, xpos, ypos-i) == false) {boardTarget[xpos][ypos-i] = 2;sideCanMove = true;}
           }
        }
        for(int i=1;i<=4;i++) {
           if (xpos-i<0||cBP[xpos-i][ypos]==-1) break;
           else if (cBP[xpos-i][ypos]!=0)
           {
               if ((cBP[xpos-i][ypos]-1)/6==side) break;
               else {
                    if (isChecked(cBP, side, xpos, ypos, xpos-i, ypos) == false) {
                            boardTarget[xpos-i][ypos] = 3;
                            sideCanMove = true;
                            break;
                    }
                    else break;
               }
           }
           else if (cBP[xpos-i][ypos]==0)
           {
               if (isChecked(cBP, side, xpos, ypos, xpos-i, ypos) == false) {boardTarget[xpos-i][ypos] = 2;sideCanMove = true;}
           }
        }
        for(int i=1;i<=4;i++) {
           if (xpos+i>=11||cBP[xpos+i][ypos]==-1) break;
           else if (cBP[xpos+i][ypos]!=0)
           {
               if ((cBP[xpos+i][ypos]-1)/6==side) break;
               else {
                    if (isChecked(cBP, side, xpos, ypos, xpos+i, ypos) == false) {
                            boardTarget[xpos+i][ypos] = 3;
                            sideCanMove = true;
                            break;
                    }
                    else break;
               }
           }
           else if (cBP[xpos+i][ypos]==0)
           {
               if (isChecked(cBP, side, xpos, ypos, xpos+i, ypos) == false) {boardTarget[xpos+i][ypos] = 2;sideCanMove = true;}
           }
        }
        for(int i=1;i<=4;i++) {
           if (ypos+i>=11||cBP[xpos][ypos+i]==-1) break;
           else if (cBP[xpos][ypos+i]!=0)
           {
               if ((cBP[xpos][ypos+i]-1)/6==side) break;
               else {
                    if (isChecked(cBP, side, xpos, ypos, xpos, ypos+i) == false) {
                            boardTarget[xpos][ypos+i] = 3;
                            sideCanMove = true;
                            break;
                    }
                    else break;
               }
           }
           else if (cBP[xpos][ypos+i]==0)
           {
               if (isChecked(cBP, side, xpos, ypos, xpos, ypos+i) == false) {boardTarget[xpos][ypos+i] = 2;sideCanMove = true;}
           }
        }
        }
        break;
    case 5:
        if (mustMoveKing == false) {
        for(int i=1;i<=3;i++) {
           if (xpos-i<0||ypos-i<0||cBP[xpos-i][ypos-i]==-1) break;
           else if (cBP[xpos-i][ypos-i]!=0)
           {
               if ((cBP[xpos-i][ypos-i]-1)/6==side) break;
               else {
                    if (isChecked(cBP, side, xpos, ypos, xpos-i, ypos-i) == false) {
                            boardTarget[xpos-i][ypos-i] = 3;
                            sideCanMove = true;
                            break;
                    }
                    else break;
               }
           }
           else if (cBP[xpos-i][ypos-i]==0)
           {
               if (isChecked(cBP, side, xpos, ypos, xpos-i, ypos-i) == false) {boardTarget[xpos-i][ypos-i] = 2;sideCanMove = true;}
           }
        }
        for(int i=1;i<=3;i++) {
           if (xpos+i>=11||ypos+i>=11||cBP[xpos+i][ypos+i]==-1) break;
           else if (cBP[xpos+i][ypos+i]!=0)
           {
               if ((cBP[xpos+i][ypos+i]-1)/6==side) break;
               else {
                    if (isChecked(cBP, side, xpos, ypos, xpos+i, ypos+i) == false) {
                            boardTarget[xpos+i][ypos+i] = 3;
                            sideCanMove = true;
                            break;
                    }
                    else break;
               }
           }
           else if (cBP[xpos+i][ypos+i]==0)
           {
               if (isChecked(cBP, side, xpos, ypos, xpos+i, ypos+i) == false) {boardTarget[xpos+i][ypos+i] = 2;sideCanMove = true;}
           }
        }
        for(int i=1;i<=3;i++) {
           if (xpos+i>=11||ypos-i<0||cBP[xpos+i][ypos-i]==-1) break;
           else if (cBP[xpos+i][ypos-i]!=0)
           {
               if ((cBP[xpos+i][ypos-i]-1)/6==side) break;
               else {
                    if (isChecked(cBP, side, xpos, ypos, xpos+i, ypos-i) == false) {
                            boardTarget[xpos+i][ypos-i] = 3;
                            sideCanMove = true;
                            break;
                    }
                    else break;
               }
           }
           else if (cBP[xpos+i][ypos-i]==0)
           {
               if (isChecked(cBP, side, xpos, ypos, xpos+i, ypos-i) == false) {boardTarget[xpos+i][ypos-i] = 2;sideCanMove = true;}
           }
        }
        for(int i=1;i<=3;i++) {
           if (xpos-i<0||ypos+i>=11||cBP[xpos-i][ypos+i]==-1) break;
           else if (cBP[xpos-i][ypos+i]!=0)
           {
               if ((cBP[xpos-i][ypos+i]-1)/6==side) break;
               else {
                    if (isChecked(cBP, side, xpos, ypos, xpos-i, ypos+i) == false) {
                            boardTarget[xpos-i][ypos+i] = 3;
                            sideCanMove = true;
                            break;
                    }
                    else break;
               }
           }
           else if (cBP[xpos-i][ypos+i]==0)
           {
               if (isChecked(cBP, side, xpos, ypos, xpos-i, ypos+i) == false) {boardTarget[xpos-i][ypos+i] = 2;sideCanMove = true;}
           }
        }
        }
        break;
    case 4:
        if (mustMoveKing == false) {
        if (xpos-2>=0) {
            if (ypos-1>=0&&cBP[xpos-2][ypos-1]!=-1&&((cBP[xpos-2][ypos-1]-1)/6!=side||cBP[xpos-2][ypos-1]==0)&&isChecked(cBP, side, xpos, ypos, xpos-2, ypos-1)==false) {sideCanMove = true;if (cBP[xpos-2][ypos-1]==0) boardTarget[xpos-2][ypos-1]=2; else boardTarget[xpos-2][ypos-1]=3;}
            if (ypos+1<11&&cBP[xpos-2][ypos+1]!=-1&&((cBP[xpos-2][ypos+1]-1)/6!=side||cBP[xpos-2][ypos+1]==0)&&isChecked(cBP, side, xpos, ypos, xpos-2, ypos+1)==false) {sideCanMove = true;if (cBP[xpos-2][ypos+1]==0) boardTarget[xpos-2][ypos+1]=2; else boardTarget[xpos-2][ypos+1]=3;}
        }
        if (ypos-2>=0) {
            if (xpos-1>=0&&cBP[xpos-1][ypos-2]!=-1&&((cBP[xpos-1][ypos-2]-1)/6!=side||cBP[xpos-1][ypos-2]==0)&&isChecked(cBP, side, xpos, ypos, xpos-1, ypos-2)==false) {sideCanMove = true;if (cBP[xpos-1][ypos-2]==0) boardTarget[xpos-1][ypos-2]=2; else boardTarget[xpos-1][ypos-2]=3;}
            if (xpos+1<11&&cBP[xpos+1][ypos-2]!=-1&&((cBP[xpos+1][ypos-2]-1)/6!=side||cBP[xpos+1][ypos-2]==0)&&isChecked(cBP, side, xpos, ypos, xpos+1, ypos-2)==false) {sideCanMove = true;if (cBP[xpos+1][ypos-2]==0) boardTarget[xpos+1][ypos-2]=2; else boardTarget[xpos+1][ypos-2]=3;}
        }
        if (xpos+2<11) {
            if (ypos-1>=0&&cBP[xpos+2][ypos-1]!=-1&&((cBP[xpos+2][ypos-1]-1)/6!=side||cBP[xpos+2][ypos-1]==0)&&isChecked(cBP, side, xpos, ypos, xpos+2, ypos-1)==false) {sideCanMove = true;if (cBP[xpos+2][ypos-1]==0) boardTarget[xpos+2][ypos-1]=2; else boardTarget[xpos+2][ypos-1]=3;}
            if (ypos+1<11&&cBP[xpos+2][ypos+1]!=-1&&((cBP[xpos+2][ypos+1]-1)/6!=side||cBP[xpos+2][ypos+1]==0)&&isChecked(cBP, side, xpos, ypos, xpos+2, ypos+1)==false) {sideCanMove = true;if (cBP[xpos+2][ypos+1]==0) boardTarget[xpos+2][ypos+1]=2; else boardTarget[xpos+2][ypos+1]=3;}
        }
        if (ypos+2<11) {
            if (xpos-1>=0&&cBP[xpos-1][ypos+2]!=-1&&((cBP[xpos-1][ypos+2]-1)/6!=side||cBP[xpos-1][ypos+2]==0)&&isChecked(cBP, side, xpos, ypos, xpos-1, ypos+2)==false) {sideCanMove = true;if (cBP[xpos-1][ypos+2]==0) boardTarget[xpos-1][ypos+2]=2; else boardTarget[xpos-1][ypos+2]=3;}
            if (xpos+1<11&&cBP[xpos+1][ypos+2]!=-1&&((cBP[xpos+1][ypos+2]-1)/6!=side||cBP[xpos+1][ypos+2]==0)&&isChecked(cBP, side, xpos, ypos, xpos+1, ypos+2)==false) {sideCanMove = true;if (cBP[xpos+1][ypos+2]==0) boardTarget[xpos+1][ypos+2]=2; else boardTarget[xpos+1][ypos+2]=3;}
        }
        }
        break;
    case 1:
        if (mustMoveKing == true) {
                //std::cout << "This used";
            if (xpos-1>=0&&ypos-1>=0&&cBP[xpos-1][ypos-1]!=-1&&isChecked(cBP, side, xpos, ypos, xpos-1, ypos-1)==false){
                if (boardStatus[xpos-1][ypos-1]==0) boardTarget[xpos-1][ypos-1]=2;
                else if ((boardStatus[xpos-1][ypos-1]-1)/6==side) boardTarget[xpos-1][ypos-1]=4;
                else boardTarget[xpos-1][ypos-1]=3;
                sideCanMove = true;
            }
            if (xpos-1>=0&&cBP[xpos-1][ypos]!=-1&&isChecked(cBP, side, xpos, ypos, xpos-1, ypos)==false){
                if (boardStatus[xpos-1][ypos]==0) boardTarget[xpos-1][ypos]=2;
                else if ((boardStatus[xpos-1][ypos]-1)/6==side) boardTarget[xpos-1][ypos]=4;
                else boardTarget[xpos-1][ypos]=3;
                sideCanMove = true;
            }
            if (ypos-1>=0&&cBP[xpos][ypos-1]!=-1&&isChecked(cBP, side, xpos, ypos, xpos, ypos-1)==false){
                if (boardStatus[xpos][ypos-1]==0) boardTarget[xpos][ypos-1]=2;
                else if ((boardStatus[xpos][ypos-1]-1)/6==side) boardTarget[xpos][ypos-1]=4;
                else boardTarget[xpos][ypos-1]=3;
                sideCanMove = true;
            }
            if (xpos+1<11&&ypos+1<11&&cBP[xpos+1][ypos+1]!=-1&&isChecked(cBP, side, xpos, ypos, xpos+1, ypos+1)==false){
                if (boardStatus[xpos+1][ypos+1]==0) boardTarget[xpos+1][ypos+1]=2;
                else if ((boardStatus[xpos+1][ypos+1]-1)/6==side) boardTarget[xpos+1][ypos+1]=4;
                else boardTarget[xpos+1][ypos+1]=3;
                sideCanMove = true;
            }
            if (xpos+1<11&&cBP[xpos+1][ypos]!=-1&&isChecked(cBP, side, xpos, ypos, xpos+1, ypos)==false){
                if (boardStatus[xpos+1][ypos]==0) boardTarget[xpos+1][ypos]=2;
                else if ((boardStatus[xpos+1][ypos]-1)/6==side) boardTarget[xpos+1][ypos]=4;
                else boardTarget[xpos+1][ypos]=3;
                sideCanMove = true;
            }
            if (ypos+1<11&&cBP[xpos][ypos+1]!=-1&&isChecked(cBP, side, xpos, ypos, xpos, ypos+1)==false){
                if (boardStatus[xpos][ypos+1]==0) boardTarget[xpos][ypos+1]=2;
                else if ((boardStatus[xpos][ypos+1]-1)/6==side) boardTarget[xpos][ypos+1]=4;
                else boardTarget[xpos][ypos+1]=3;
                sideCanMove = true;
            }
            if (xpos-1>=0&&ypos+1<11&&cBP[xpos-1][ypos+1]!=-1&&isChecked(cBP, side, xpos, ypos, xpos-1, ypos+1)==false){
                if (boardStatus[xpos-1][ypos+1]==0) boardTarget[xpos-1][ypos+1]=2;
                else if ((boardStatus[xpos-1][ypos+1]-1)/6==side) boardTarget[xpos-1][ypos+1]=4;
                else boardTarget[xpos-1][ypos+1]=3;
                sideCanMove = true;
            }
            if (xpos+1<11&&ypos-1>=0&&cBP[xpos+1][ypos-1]!=-1&&isChecked(cBP, side, xpos, ypos, xpos+1, ypos-1)==false){
                if (boardStatus[xpos+1][ypos-1]==0) boardTarget[xpos+1][ypos-1]=2;
                else if ((boardStatus[xpos+1][ypos-1]-1)/6==side) boardTarget[xpos+1][ypos-1]=4;
                else boardTarget[xpos+1][ypos-1]=3;
                sideCanMove = true;
            }
        }
        else {
            if (xpos-1>=0&&ypos-1>=0&&cBP[xpos-1][ypos-1]!=-1&&isChecked(cBP, side, xpos, ypos, xpos-1, ypos-1)==false&&((boardStatus[xpos-1][ypos-1]-1)/6!=side||boardStatus[xpos-1][ypos-1]==0)){
                if (boardStatus[xpos-1][ypos-1]==0) boardTarget[xpos-1][ypos-1]=2;
                else boardTarget[xpos-1][ypos-1]=3;
                sideCanMove = true;
            }
            if (xpos-1>=0&&cBP[xpos-1][ypos]!=-1&&isChecked(cBP, side, xpos, ypos, xpos-1, ypos)==false&&((boardStatus[xpos-1][ypos]-1)/6!=side||boardStatus[xpos-1][ypos]==0)){
                if (boardStatus[xpos-1][ypos]==0) boardTarget[xpos-1][ypos]=2;
                else boardTarget[xpos-1][ypos]=3;
                sideCanMove = true;
            }
            if (ypos-1>=0&&cBP[xpos][ypos-1]!=-1&&isChecked(cBP, side, xpos, ypos, xpos, ypos-1)==false&&((boardStatus[xpos][ypos-1]-1)/6!=side||boardStatus[xpos][ypos-1]==0)){
                if (boardStatus[xpos][ypos-1]==0) boardTarget[xpos][ypos-1]=2;
                else boardTarget[xpos][ypos-1]=3;
                sideCanMove = true;
            }
            if (xpos+1<11&&ypos+1<11&&cBP[xpos+1][ypos+1]!=-1&&isChecked(cBP, side, xpos, ypos, xpos+1, ypos+1)==false&&((boardStatus[xpos+1][ypos+1]-1)/6!=side||boardStatus[xpos+1][ypos+1]==0)){
                if (boardStatus[xpos+1][ypos+1]==0) boardTarget[xpos+1][ypos+1]=2;
                else boardTarget[xpos+1][ypos+1]=3;
                sideCanMove = true;
            }
            if (xpos+1<11&&cBP[xpos+1][ypos]!=-1&&isChecked(cBP, side, xpos, ypos, xpos+1, ypos)==false&&((boardStatus[xpos+1][ypos]-1)/6!=side||boardStatus[xpos+1][ypos]==0)){
                if (boardStatus[xpos+1][ypos]==0) boardTarget[xpos+1][ypos]=2;
                else boardTarget[xpos+1][ypos]=3;
                sideCanMove = true;
            }
            if (ypos+1<11&&cBP[xpos][ypos+1]!=-1&&isChecked(cBP, side, xpos, ypos, xpos, ypos+1)==false&&((boardStatus[xpos][ypos+1]-1)/6!=side||boardStatus[xpos][ypos+1]==0)){
                if (boardStatus[xpos][ypos+1]==0) boardTarget[xpos][ypos+1]=2;
                else boardTarget[xpos][ypos+1]=3;
                sideCanMove = true;
            }
            if (xpos-1>=0&&ypos+1<11&&cBP[xpos-1][ypos+1]!=-1&&isChecked(cBP, side, xpos, ypos, xpos-1, ypos+1)==false&&((boardStatus[xpos-1][ypos+1]-1)/6!=side||boardStatus[xpos-1][ypos+1]==0)){
                if (boardStatus[xpos-1][ypos+1]==0) boardTarget[xpos-1][ypos+1]=2;
                else boardTarget[xpos-1][ypos+1]=3;
                sideCanMove = true;
            }
            if (xpos+1<11&&ypos-1>=0&&cBP[xpos+1][ypos-1]!=-1&&isChecked(cBP, side, xpos, ypos, xpos+1, ypos-1)==false&&((boardStatus[xpos+1][ypos-1]-1)/6!=side||boardStatus[xpos+1][ypos-1]==0)){
                if (boardStatus[xpos+1][ypos-1]==0) boardTarget[xpos+1][ypos-1]=2;
                else boardTarget[xpos+1][ypos-1]=3;
                sideCanMove = true;
            }
        }
        break;
    }
}



void resetTarget()
{
    for (int i=0;i<11;i++) for (int j=0;j<11;j++) if (boardTarget[i][j]!=5) boardTarget[i][j]=0;
}

void makeDangerRed(int x, int y)
{
    for (int i=0;i<11;i++) {
        if (boardStatus[y][i]!=-1) boardInDanger[y][i] = 1;
        if (boardStatus[i][x]!=-1) boardInDanger[i][x] = 1;
    }
    //printBoard(boardTarget);
    //printBoard(boardInDanger);
}

void createDanger()
{
    int xDiff = (randomChosen-1)%4;
    int yDiff = (randomChosen-1)/4;
    int xDanger, yDanger;
    int round = (step-2)/4;
    switch((step-2)%4) {
    case 1:
        if (xDiff>=2) xDanger = xPlay;
        else xDanger = xPlay + 11-3*round-1;
        if (yDiff>=2) yDanger = yPlay;
        else yDanger = yPlay + 11-3*round-1;
        break;
    case 2:
        if (xDiff==0) xDanger = xPlay + 11-3*round-2;
        else if (xDiff==1) xDanger = xPlay;
        else if (xDiff==2) xDanger = xPlay + 11-3*round-1;
        else xDanger = xPlay+1;
        if (yDiff==0) yDanger = yPlay + 11-3*round-2;
        else if (yDiff==1) yDanger = yPlay;
        else if (yDiff==2) yDanger = yPlay + 11-3*round-1;
        else yDanger = yPlay+1;
        break;
    case 3:
        if (xDiff==0) xDanger = xPlay + 11-3*round-3;
        else if (xDiff==1) xDanger = xPlay + 11-3*round-2;
        else if (xDiff==2) xDanger = xPlay + 1;
        else xDanger = xPlay+2;
        if (yDiff==0) yDanger = yPlay + 11-3*round-3;
        else if (yDiff==1) yDanger = yPlay + 11-3*round-2;
        else if (yDiff==2) yDanger = yPlay + 1;
        else yDanger = yPlay+2;
        break;
    }
    //std::cout << (step-2)%4 << " " << xDanger << " " << yDanger << std::endl << xDiff << " " << yDiff << std::endl;
    makeDangerRed(xDanger, yDanger);
    printBoard(boardInDanger);
}
void resetDanger();
void drawFlower();
void checkStep() {
    if (turnCountdown<=0) {
        switch(step) {
        case 0:
            step++;
            turnCountdown += 14;
            break;
        case 1:
            step++;
            turnCountdown += 10;
            randomChosen = borderRandom(mt);
            break;
        case 2:
        case 6:
        case 10:
            step++;
            turnCountdown += 2;
            createDanger();
            break;
        case 3:
        case 7:
        case 11:
            step++;
            drawFlower();
            resetDanger();
            turnCountdown += 2;
            createDanger();
            break;
        case 4:
        case 8:
        case 12:
            step++;
            drawFlower();
            resetDanger();
            turnCountdown += 2;
            createDanger();
            break;
        case 5:
            step++;
            drawFlower();
            resetDanger();
            turnCountdown += 8;
            xPlay = xPlay + (randomChosen-1)%4;
            yPlay = yPlay + (randomChosen-1)/4;
            randomChosen = borderRandom(mt);
            break;
        case 9:
            step++;
            drawFlower();
            resetDanger();
            turnCountdown += 6;
            xPlay = xPlay + (randomChosen-1)%4;
            yPlay = yPlay + (randomChosen-1)/4;
            randomChosen = borderRandom(mt);
            break;
        case 13:
            step++;
            drawFlower();
            resetDanger();
            turnCountdown += 10;
            xPlay = xPlay + (randomChosen-1)%4;
            yPlay = yPlay + (randomChosen-1)/4;
            break;
        }
    }
}

void processClock()
{
    //if (gameStarted == true&&turnCountdown==14) playTime.start();
    if (movePlayed==true) {
        movePlayed = false;
        playTime.stop();
        playTime.start();
        player1RememTime = player1TimeLeft;
        player2RememTime = player2TimeLeft;
        player1TurnTime = 30000;
        player2TurnTime = 30000;
    }
    Uint32 timeGetTick = playTime.getTick();
    if (currentTurnSide==0) {
        if (timeGetTick>=defaultPlayTime) {
            player1TurnTime = minTime;
            player1TimeLeft = player1RememTime + defaultPlayTime - timeGetTick;
        }
        else player1TurnTime = defaultPlayTime - timeGetTick;
        //std::cout << player2TimeLeft << std::endl;
    }
    else if (currentTurnSide==1) {
        if (timeGetTick>=defaultPlayTime) {
            player2TurnTime = minTime;
            player2TimeLeft = player2RememTime + defaultPlayTime - timeGetTick;
        }
        else player2TurnTime = defaultPlayTime - timeGetTick;
    }

}

void checkChecked()
{
    for (int i=0;i<11;i++) for (int j=0;j<1;j++) if(boardTarget[i][j]==5) boardTarget[i][j]=0;
    if (isChecked(boardStatus, currentTurnSide)==true) {
        sideChecked = true;
        //std::cout << "Checkmate Did!";
        for (int i=0;i<11;i++) for (int j=0;j<11;j++) {
            if (boardStatus[i][j]== currentTurnSide*6+1) boardTarget[i][j]=5;
        }
    }
    printBoard(boardTarget);
}

void resetDanger()
{
    for (int i=0;i<11;i++) for (int j=0;j<11;j++) boardInDanger[i][j] = 0;
}

void checkMustMove()
{
    for (int i=0;i<11;i++) for (int j=0;j<11;j++) if (boardInDanger[i][j]==1 && boardStatus[i][j]==currentTurnSide*6+1) {mustMoveKing = true;
    //boardTarget[i][j] = 5;
    }
}

void drawFlower()
{
    playTime.pause();
    for (int i=1;i<=50;i++) {
        borderTexture.setTextureSize(i,i);
        for (int j=0;j<11;j++) for (int k=0;k<11;k++) {
            if (boardInDanger[j][k]==1) {
                double temp = i;
                double angle = 5.0*temp;
                borderTexture.renderTexture(75+k*55-(50-i)/2, 82+j*55-(50-i)/2, nullptr, angle);
            }
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(30);
    }
    for (int i=0;i<11;i++) for (int j=0;j<11;j++) if (boardInDanger[i][j]==1) boardStatus[i][j] = -1;
    playTime.resume();
}

void checkKingAlive()
{
    king1Alive = false;
    king2Alive = false;
    for (int i=0;i<11;i++) for (int j=0;j<11;j++){
        if (boardStatus[i][j]==1) king1Alive = true;
        else if (boardStatus[i][j]==7) king2Alive = true;
    }
    if (king1Alive==false||king2Alive==false) {
            gameOver = true;
            //playTime.stop();
            if (king1Alive==false&&king2Alive==false) winner = -1;
            else if (king1Alive==false) winner = 1;
            else winner = 0;
    }
}

void checkSideCanMove()
{
    for (int i=0;i<11;i++) for (int j=0;j<11;j++) if (boardStatus[i][j]>0&&(boardStatus[i][j]-1)/6==currentTurnSide) {
        checkMove(boardStatus, i, j);
    }
    resetTarget();
}

void checkCanPlay()
{
    if (sideCanMove == false) {
        if (sideChecked==true) {
            gameOver = true;
            winner = abs(currentTurnSide-1);
        }
        else {
            gameOver = true;
            winner = -1;
        }
    }
}
#endif // GAMELOGIC_H
