#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define PORT 12345

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
	
    
    ofVideoPlayer player;
    ofxOscReceiver receiver;
    float position;
		
};
