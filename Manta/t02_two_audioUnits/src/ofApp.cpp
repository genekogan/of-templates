#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    drawView = 1;
    
    aalto.setup("Aalto", 'aumu', 'Aalt', 'MLbs');
    aalto.showUI();

    kaivo.setup("Kaivo", 'aumu', 'Kaiv', 'MLbs');
    kaivo.showUI();

    aalto.getSynth().connectTo(mixer, 0);
    kaivo.getSynth().connectTo(mixer, 1);
    mixer.connectTo(output);
    output.start();
    
    manta.setup();
    
    // instead of manually assigning mappings, key, and mode, load from file
    //manta.loadPreset("presetTest");
    
    // map sliders to reverb and cutoff parameters
    manta.mapSliderToParameter(0, aalto, "output_reverb");
    manta.mapSliderToParameter(1, kaivo, "body_pitch");
    
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
        aalto.draw(5, 20);
    }
    else if (drawView == 3) {
        ofSetColor(0);
        kaivo.draw(5, 20);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key=='z') {
        manta.mapSelectionToMidiNotes(aalto);
    }
    else if (key=='x') {
        manta.mapSelectionToMidiNotes(kaivo);
    }
    else if (key=='1') {
        drawView = 1;
    }
    else if (key=='2') {
        drawView = 2;
    }
    else if (key=='3') {
        drawView = 3;
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
