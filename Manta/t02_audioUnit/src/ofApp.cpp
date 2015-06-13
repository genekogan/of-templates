#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    drawView = 1;
    
    synth.setup('aumu', 'Aalt', 'MLbs');
    synth.showUI();
    
    synth.getSynth().connectTo(mixer, 0);
    mixer.connectTo(output);
    output.start();
    
    manta.setup();
    manta.setAudioUnit(&synth.getSynth());
    
    // map sliders to reverb and cutoff parameters
    manta.mapSliderToParameter(0, synth.getParameter("output_reverb"));
    manta.mapSliderToParameter(1, synth.getParameter("filter_cutoff"));

    // map all pads to midi notes
    manta.mapAllPadsToMidiNotes();
    
    // changing key/mode
    manta.setKey(0);    // 0=C
    manta.setMode(0);   // 0=ionian ... 6=locrian, 7=natural min., 8=harmonic, 9=melodic
    
    
    // AUDIO UNIT
    // AUDIO UNIT PRESET FILE
    //
    // MIDI
    //  - KEY
    //  - MODE
    //
    // PARAM MAPPINGS
    //  - PADS
    //    - min, max range
    //  - SLIDERS
    //  - BUTTONS
    //  - STATS
    //    *** add map()toParameter method to regular example
    //
    // PAD MIDI MAPPING
    //  - which pads
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
    
    else if (key=='a')  manta.setKey(-12);
    else if (key=='s')  manta.setKey(-24);
    else if (key=='d')  manta.setKey(-36);
    else if (key=='f')  manta.setKey(-48);
    else if (key=='g')  manta.setKey(-60);
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
