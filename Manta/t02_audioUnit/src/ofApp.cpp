#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    synth.setup('aumu', 'Aalt', 'MLbs');
    synth.showUI();
    
    synth.getSynth().connectTo(mixer, 0);
    mixer.connectTo(output);
    output.start();
    
    manta.setup();
    manta.setAudioUnit(&synth.getSynth());
    
    manta.mapPadToParameter(0, 0, synth.getParameter("output_reverb"));

    // changing key/mode
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    manta.draw(20, 50, 400);
    manta.drawStats(450, 50, 400);

    ofSetColor(0);
    synth.draw(5, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key=='z') {
        manta.mapSelectionToMidiNotes();
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
