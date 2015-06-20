#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    drawView = 1;
    
    synth.setup("Aalto", 'aumu', 'Aalt', 'MLbs');
    synth.showUI();
    
    synth.getSynth().connectTo(mixer, 0);
    mixer.connectTo(output);
    output.start();
    
    manta.setup();
    manta.addAudioUnit(&synth);
    
    // instead of manually assigning mappings, key, and mode, load from file
    manta.loadPreset("presetTest");
    
    
    return;
    // map sliders to reverb and cutoff parameters
    manta.mapPadToParameter(3, 4, synth, "filter_cutoff");
    manta.mapButtonToParameter(2, synth, "output_reverb");

    manta.mapSliderToParameter(0, synth, "output_reverb");
    manta.mapSliderToParameter(1, synth, "filter_cutoff");

    // map all pads to midi notes
    manta.mapAllPadsToMidiNotes();
    
    // changing key/mode
    manta.setKey(0);    // 0=C
    manta.setMode(0);   // 0=ionian ... 6=locrian, 7=natural min., 8=harmonic, 9=melodic
    
    // save all parameter and midi mappings, key, and mode
    //manta.savePreset("presetTest");
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (drawView == 1) {
        manta.draw(20, 50, 400);
        manta.drawStats(450, 50, 400);
    }
    else if (drawView == 2) {
        ofSetColor(0);
        synth.draw(5, 20);
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
    else if (key=='a') {
        manta.setKey(-12);
    }
    else if (key=='s') {
        manta.savePreset("presetTest");
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
