#pragma once

#include "ofMain.h"
#include "ofxManta.h"
#include "MantaStats.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    MantaStats manta;
    
    ofParameter<float> padRef;
    ofParameter<float> sliderRef;
    ofParameter<float> buttonRef;
    
    ofParameter<float> numPads;
    ofParameter<float> padSum, padAverage;
    ofParameter<float> centroidX, centroidY;
    ofParameter<float> weightedCentroidX, weightedCentroidY;
    ofParameter<float> averageInterFingerDistance;
    ofParameter<float> perimeter, area;
    ofParameter<float> padWidth, padHeight, whRatio;
    
    // velocity statistics
    ofParameter<float> numPadsVelocity;
    ofParameter<float> padSumVelocity, padAverageVelocity;
    ofParameter<float> centroidVelocityX, centroidVelocityY;
    ofParameter<float> weightedCentroidVelocityX, weightedCentroidVelocityY;
    ofParameter<float> averageInterFingerDistanceVelocity;
    ofParameter<float> perimeterVelocity, areaVelocity;
    ofParameter<float> widthVelocity, heightVelocity, whRatioVelocity;

};
