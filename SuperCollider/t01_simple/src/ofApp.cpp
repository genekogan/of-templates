#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    bus = new ofxSCBus(RATE_AUDIO, 2);

    reverb = sc3.addSynth("reverb_ef");
    reverb->set("inBus", bus->index);
    reverb->set("outBus", 0);
    reverb->create();
    
    group = new ofxSCGroup();
    group->addBefore(*reverb->getSynth());
    
    synth = sc3.addSynth("filtSaw");
    synth->set("freq", 2);
    synth->set("detune", 0);
    synth->set("minBpfHz", 0.01);
    synth->set("maxBpfHz", 0.35565588200778);
    synth->set("minRq", 0.003);
    synth->set("maxRq", 0.064535484606211);
    synth->set("minCf", 308);
    synth->set("maxCf", 228.8);
    synth->set("amp", 0.15074007600918);
    synth->set("atk", 0.36477118781107);
    synth->set("rel", 0.8);
    synth->set("spread", 5.1201859720906);
    synth->set("busOut", bus->index);

    synth->getSynth()->addToHead(*group);

    mix.makeReferenceTo(reverb->addParameter("mix", 0, 1));
    freq.makeReferenceTo(synth->addParameter("freq", 0, 20));
}

//--------------------------------------------------------------
void ofApp::update(){
    mix.set(ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 1));
    freq.set(ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, 20));
}

//--------------------------------------------------------------
void ofApp::draw(){
    sc3.draw();
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
