#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    
    cout << "listening for osc messages on port " << PORT << "\n";

    receiver.setup( PORT );
    
    player.loadMovie("movies/macbook4s-demo.mov");
    player.play();
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    player.update();
    
    
    while( receiver.hasWaitingMessages() ){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage( &m );
        
        
        //get movie position
        
        if ( m.getAddress() == "/movie/position" )
        {
            position = m.getArgAsFloat(0);
            
        }
        // Set the position
        player.setPosition(position);
        
            cout << "position: " << position << endl;
        
    }
    

}

//--------------------------------------------------------------
void testApp::draw(){

    player.draw(0, 0);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key=='f'){
        ofToggleFullscreen();
    }
}