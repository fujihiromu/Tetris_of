#pragma once

#include "game.hpp"

#define MAX_SHAPE_SIZE		3

class Tetris;

class Shape{
    
public:
    
    Shape( Tetris* board );
    
    void update(){};
    
    void regenerate();//ブロックの形を生成
    void moveLeft();
    void moveRight();
    void moveDown();
    void dropDown();
    
    void rotateRight();
    void rotateLeft();
    
    
    bool testCollision();//着地判定
    void printOnBoard();//着地したshapeをboardに
    
    int x, y;//座標
    int shape[MAX_SHAPE_SIZE][MAX_SHAPE_SIZE];
    
   
    bool fresh;//操作したshapeか
    Tetris * tetris;
    

    
};