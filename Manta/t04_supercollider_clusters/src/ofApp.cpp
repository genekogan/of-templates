#include "ofApp.h"

//--------------------------------------------------------------

void ofApp::setup()
{
    drawView = 1;
    
    bus = new ofxSCBus(RATE_AUDIO, 2);
    
    reverb = sc3.addSynth("reverb_ef");
    reverb->set("inBus", bus->index);
    reverb->set("outBus", 0);
    reverb->create();
    
    group = new ofxSCGroup();
    group->addBefore(*reverb->getSynth());
    
   
    manta.setup();
    manta.addPadVelocityListener(this, &ofApp::padVelocityEvent);
}

//--------------------------------------------------------------
void ofApp::padVelocityEvent(ofxMantaEvent & evt) {
    if (evt.value == 0) {
        synths[evt.id]->set("gate", -2);
    }
    else {
        if (synths.count(evt.id) == 0) {
            SuperColliderSynth *synth = sc3.addSynth("filtSaw");
            synths[evt.id] = synth;
            synths[evt.id]->getSynth()->addToHead(*group);
        }
        
        synths[evt.id]->set("freq", ofRandom(4));
        synths[evt.id]->set("detune", 0);
        synths[evt.id]->set("minBpfHz", ofRandom(0.05));
        synths[evt.id]->set("maxBpfHz", ofRandom(1));
        synths[evt.id]->set("minRq", 0.003);
        synths[evt.id]->set("maxRq", ofRandom(0.01)); //0.064535484606211);
        synths[evt.id]->set("minCf", ofRandom(205,308));
        synths[evt.id]->set("maxCf", ofRandom(300, 400));
        synths[evt.id]->set("amp", 0.15074007600918);
        synths[evt.id]->set("atk", 0.36477118781107);
        synths[evt.id]->set("rel", 0.8);
        synths[evt.id]->set("spread", 5.1201859720906);
        synths[evt.id]->set("busOut", bus->index);
        
        
    }
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

