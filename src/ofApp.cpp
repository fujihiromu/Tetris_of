#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    myfont.load("Arial Bold.ttf", 13);
    
    firsttime=100;//制限時間
    mode=1;//スタート画面
}

//--------------------------------------------------------------
void ofApp::update(){
    if(firsttime-game.countdown<1||game.gameover == true)mode=0;//ゲームオーバー、タイムオーバー判定
   
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(10, 10);
   

    
    if(mode==0){
        //ゲームオーバー、タイムオーバー
        
        ofSetColor(255, 0, 0);
        if(firsttime - game.countdown<1)myfont.drawString("Time over !!", 45, 200);
        if(game.gameover == true)myfont.drawString("Game over !!", 40, 200);
        
        ofSetColor(0, 255, 255);
        myfont.drawString("Score: "+ ofToString(game.getClearedLines()), 55,240);
        
    }else if(mode==1){
        //スタート画面
        
        ofSetColor(255, 255, 0);
        myfont.drawString("Prease push space key", 2, 200);

    }else{
        //プレイ中
        
        game.update();
        

        
        
        ofSetColor(255,255,255);
        ofDrawBitmapString("Score: "+ ofToString(game.getClearedLines()), 10,40);
        ofDrawBitmapString("Time: "+ ofToString(firsttime - game.countdown), 10,20);
        
        
        game.draw();
 
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == OF_KEY_LEFT)
        game.shape->moveLeft();
    
    if (key == OF_KEY_RIGHT)
        game.shape->moveRight();
    
    if (key == OF_KEY_UP)
        game.shape->dropDown();
    
    if (key == OF_KEY_DOWN)
        game.shape->moveDown();
    
  
    
    if (key == 's')
        game.shape->rotateRight();
    
    if (key == 'a')
        game.shape->rotateLeft();
    
    if (key == ' ' && mode==1)//スタート画面のときゲームスタート
        mode=2;
        
    
        
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
