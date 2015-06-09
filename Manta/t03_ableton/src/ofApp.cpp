#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    drawView = 1;
    
    live.setup(this, &ofApp::abletonLoaded);
    manta.setup();

    manta.mapAllPadsToMidiNotes();
    
    // changing key/mode
    manta.setKey(0);    // 0=C
    manta.setMode(0);   // 0=ionian ... 6=locrian, 7=natural min., 8=harmonic, 9=melodic
}

//--------------------------------------------------------------
void ofApp::abletonLoaded() {
    manta.mapSliderToParameter(0, *live.getTrack(1)->getDevice("Vocoder")->getParameter("Dry/Wet")->getParameter());
}

//--------------------------------------------------------------
void ofApp::update(){
    live.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (drawView == 1) {
        manta.draw(20, 50, 400);
        manta.drawStats(450, 50, 400);
    }
    else if (drawView == 2) {
        live.drawDebugView();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key=='z') {
        manta.mapSelectionToMidiNotes();
    }
    else if (key=='1') {
        drawView = 1;
    }
    else if (key=='2') {
        drawView = 2;
    }
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
