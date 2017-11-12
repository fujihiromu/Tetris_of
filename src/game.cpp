

#include "game.hpp"



Tetris::Tetris(){
    
  
    shape = new Shape(this);
}




void Tetris::deleteFullLines(){
    
    checkForLines();
    for (int j=0; j<CANVAS_HEIGHT; j++)
        if (completeLineMap[j] == true)
            dropDown(j);
    
}

void Tetris::dropDown(int line){
    
    clearedLines++;
    for (int j = line; j >= 1; j--){
        for (int i = 0; i<CANVAS_WIDTH; i++){
            board[i][j] = board[i][j-1];
        }
    }
    
    for (int i = 0; i<CANVAS_WIDTH; i++)
        board[i][0] = 0;
    
}




void Tetris::checkForLines(){
    

    
    for (int j=0; j<CANVAS_HEIGHT; j++){
        bool complete = true;
        for (int i=0; i<CANVAS_WIDTH; i++){
            if ( board[i][j] == 0 )
                complete = false;//隙間があるとfalse
        }
        completeLineMap[j] = complete;//列が埋まっているかどうか代入
    }
}


void Tetris::checkTopLines(){
    for(int i=0; i<CANVAS_WIDTH;i++){
        if( board[i][0]!=0)gameover=true;
    }
}



void Tetris::draw(){
    
    int s = 20;
    ofSetColor(200);
    ofNoFill();
    ofRect( 0, 0, s * CANVAS_WIDTH, s * CANVAS_HEIGHT ); //枠
    
    ofFill();
    
    for (int i=0; i<CANVAS_WIDTH; i++){
        for (int j=0; j<CANVAS_HEIGHT; j++){
            
            setColorForTile( board[i][j] );
            if ( board[i][j] != 0){
                ofRect( i * s, j * s, s, s); //着地タイルを描画
            }
        }
    }
    
    for (int i = 0; i < MAX_SHAPE_SIZE; i++){
        for (int j = 0; j < MAX_SHAPE_SIZE; j++){
            
            if (shape->shape[i][j] != 0){
                setColorForTile( shape->shape[i][j] );
                ofRect(s * shape->x + s * i, s * shape->y + s * j, s, s);//落下中タイル描画
            }
        }
    }
}


void Tetris::update(){
    
    time += 1.0f / ofGetFrameRate();
    
    float dropRate = 1.0f;
    
    if ( time > dropRate ){
        shape->moveDown();  //1秒ごとに落下
        time = 0.0f;
        countdown++;//1秒づつ増えるカウントダウン
    }
    checkTopLines();
}


void Tetris::setColorForTile(int tile){
    
    switch (tile){
            
        case 1:
            glColor3f(0,1,0);
            break;
            
        case 2:
            glColor3f(0,0,1);
            break;
            
        case 3:
            glColor3f(1,1,0);
            break;
            
        case 4:
            glColor3f(1,0,0);
            break;
            
        case 5:
            glColor3f(1,0,1);
            break;
            
        case 6:
            glColor3f(0,1,1);
            break;
            
    }
}
