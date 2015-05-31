#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    manta.setup();
    
    // manta values are stored as ofParameters, so you can keep a persistent reference to them
    padRef.makeReferenceTo(manta.getPad(0, 0));
    sliderRef.makeReferenceTo(manta.getSlider(0));
    buttonRef.makeReferenceTo(manta.getButton(0));
   
    // get other values
    
    
    // map to osc
    
    
    // map to midi
    
    
    // get area of convex hull
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    manta.draw(20, 50, 400);
    manta.drawStats(450, 50, 400);

    ofSetColor(0);
    ofDrawBitmapString("value of "+padRef.getName()+" = "+ofToString(padRef), 20, 450);
    ofDrawBitmapString("value of "+sliderRef.getName()+" = "+ofToString(sliderRef), 20, 470);
    ofDrawBitmapString("value of "+buttonRef.getName()+" = "+ofToString(buttonRef), 20, 490);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
