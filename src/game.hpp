
#pragma once

#include "ofMain.h"
#include "shape.hpp"

#define CANVAS_WIDTH	10  //画面幅
#define CANVAS_HEIGHT	20  //画面高さ

#define NUM_PATTERNS	7
/*[1..6]*/

class Shape;

class Tetris{
    
public:
    
    Tetris();
    ~Tetris(){};
    
    void update();
    void draw();
    

    void deleteFullLines();   //列完成したらdropdown
    
    void setColorForTile(int tile); //色
    

    void dropDown(int line);	//列が完成したら消して一行下げる
    void checkForLines();       //列が完成してるか確認
    void checkTopLines();       //一番上まで積まれてるか
    
    int getClearedLines(){ return clearedLines;	};
    
    
    int board[CANVAS_WIDTH][CANVAS_HEIGHT];
    
    bool completeLineMap[CANVAS_HEIGHT];
    bool gameover;
    float time;
    
    Shape * shape;
    
    int clearedLines;
    int countdown;
};