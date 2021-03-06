#include "ofApp.h"

//--------------------------------------------------------------

void ofApp::setup()
{
    drawView = 1;
    
    synth = sc3.addSynth("fmsynth");
    synth->create();
    
    cf.makeReferenceTo(synth->addParameter("carrierF", 200, 800));
    mf.makeReferenceTo(synth->addParameter("modF", 0, 20));
    ma.makeReferenceTo(synth->addParameter("modA", 0, 200));

    manta.setup();
    manta.mapPadToParameter(0, 0, cf);
    manta.mapPadToParameter(0, 1, mf);
    manta.mapPadToParameter(0, 2, ma);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
ofApp::~ofApp(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (drawView == 1) {
        manta.draw(20, 50, 400);
        manta.drawStats(450, 50, 400);
    }
    else if (drawView == 2) {
        sc3.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key=='1') {
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

