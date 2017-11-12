

#include "shape.hpp"

Shape::Shape( Tetris* board){
    ofSeedRandom( ofGetElapsedTimeMillis() );
    tetris = board;
    regenerate();
}


void Shape::regenerate(){
    
    x = CANVAS_WIDTH / 2 - MAX_SHAPE_SIZE / 2;   //中心からスタート
    y = -MAX_SHAPE_SIZE;                        //画面上からスタート
    
    int color = ofRandom(1, NUM_PATTERNS);
    int tiles = ofRandom(8);
    
    for (int i = 0; i < MAX_SHAPE_SIZE; i++){
         for (int j = 0; j < MAX_SHAPE_SIZE; j++){
             shape[i][j] = NULL;
         }
    }
    
    
    if(tiles == 0){
        //短長方形
        shape[1][0] = color;
        shape[1][1] = color;
        
    }else if(tiles == 1){
        //長長方形
        shape[1][0] = color;
        shape[1][1] = color;
        shape[1][2] = color;
      
    }else if(tiles == 2){
        //正方形
        shape[0][0] = color;
        shape[0][1] = color;
        shape[1][0] = color;
        shape[1][1] = color;

    }else if(tiles == 3){
        //S字
        shape[0][0] = color;
        shape[0][1] = color;
        shape[1][1] = color;
        shape[1][2] = color;
     
    }else if(tiles == 4){
        //Z字
        shape[1][0] = color;
        shape[1][1] = color;
        shape[0][1] = color;
        shape[0][2] = color;
        
    }else if(tiles == 5){
        //L字
        shape[0][0] = color;
        shape[0][1] = color;
        shape[0][2] = color;
        shape[1][2] = color;
        
    }else if(tiles == 6){
        //J字
        shape[1][0] = color;
        shape[1][1] = color;
        shape[1][2] = color;
        shape[0][2] = color;
        
    }else if(tiles == 7){
        //T字
        shape[0][0] = color;
        shape[1][0] = color;
        shape[2][0] = color;
        shape[1][1] = color;
        shape[1][2] = color;
    }

    fresh = true;
    
    
}


bool Shape::testCollision(){
    

    int collide = false;//着地判定
    
    for (int i = 0; i < MAX_SHAPE_SIZE; i++){
        for (int j = 0; j < MAX_SHAPE_SIZE; j++){
            
            int xx = i+x;//ブロックごとの座標
            int yy = j+y;
            
            if ( xx >= 0 && xx < CANVAS_WIDTH && yy >= 0 && yy < CANVAS_HEIGHT){
                
                if ( tetris->board[xx][yy] == 0 || shape[i][j] == 0){
                    //まだ着地していない   collide == false;
                }else{
                    collide = true;
                    break;
                }
            }
            
            if ( shape[i][j] != 0 && yy >= CANVAS_HEIGHT)
                collide = true;
            
            if ( shape[i][j] != 0 && xx < 0)
                collide = true;
            
            if ( shape[i][j] != 0 && xx >= CANVAS_WIDTH)
                collide = true;
            
            
        }
    }
    
    return collide;	//collision
}


void Shape::printOnBoard(){
    
    for (int i = 0; i < MAX_SHAPE_SIZE; i++){
        for (int j = 0; j < MAX_SHAPE_SIZE; j++){
            if (tetris->board[i+x][j+y] == 0)
                tetris->board[i+x][j+y] = shape[i][j];//着地した場合boardに入れる
        }
    }
}


void Shape::rotateLeft(){
    
    int t[MAX_SHAPE_SIZE][MAX_SHAPE_SIZE];
    
    for (int i = 0; i < MAX_SHAPE_SIZE; i++){
        for (int j = 0; j < MAX_SHAPE_SIZE; j++){
            t[i][j] = shape[MAX_SHAPE_SIZE -j -1][i];//変化後をtに一時入れておく
        }
    }
    
    for (int i = 0; i < MAX_SHAPE_SIZE; i++){
        for (int j = 0; j < MAX_SHAPE_SIZE; j++){
            shape[i][j]= t[i][j];//tをshapeに入れなおす
        }
    }
}


void Shape::rotateRight(){
    
    
    
    int t[MAX_SHAPE_SIZE][MAX_SHAPE_SIZE];
    
    for (int i = 0; i < MAX_SHAPE_SIZE; i++){
        for (int j = 0; j < MAX_SHAPE_SIZE; j++){
            t[i][j] = shape[j][MAX_SHAPE_SIZE -i -1];//変化後をtに一時入れておく
        }
    }
    
    for (int i = 0; i < MAX_SHAPE_SIZE; i++){
        for (int j = 0; j < MAX_SHAPE_SIZE; j++){
            shape[i][j]= t[i][j];//tをshapeに入れなおす
        }
    }	
}

void Shape::moveLeft(){
    
    fresh = false;
    
    x--;
    
    if( testCollision() == true )
        x++;//貫通したら手前に戻して移動させない
}


void Shape::moveRight(){
    
    fresh = false;
    
    x++;
    
    if( testCollision() == true )
        x--;//貫通したら手前に戻して移動させない
}


void Shape::moveDown(){
    
    fresh = false;
    y++;
    
    if( testCollision() == true ){
        y--;//貫通したら手前に戻して着地
      
        printOnBoard();//boardに入れる
        
        tetris->deleteFullLines();//列が完成されたか確認
        regenerate();//新たにshape生成
        
    } 
}

void Shape::dropDown(){
    
    fresh = false;
    while (fresh == false)//着地するまで落下
        moveDown();
    
}

