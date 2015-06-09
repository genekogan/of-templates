#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    kinect.setup(12345);
    renderer.setup(kinect.getSkeletons());
    
    drawView = 1;
    
    synth.setup('aumu', 'Kaiv', 'MLbs');
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
}

//--------------------------------------------------------------
void ofApp::update(){
    kinect.update();

    if (kinect.hasSkeletons()) {
        float rv = ofClamp(ofMap(kinect.getNearestSkeleton()->getHandRight().y(),
                                 -20, 300, 0, 1), 0, 1);
        synth.getParameter("output_reverb").set(rv);
        
        
        float co = ofClamp(ofMap(kinect.getNearestSkeleton()->getHandLeft().y(),
                                 -20, 300, 0, 1), 0, 20000);
        synth.getParameter("filter_cutoff").set(co);
    }
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
    else if (drawView == 3) {
        kinect.drawDebug();
        renderer.draw();
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
    else if (key=='3') {
        drawView = 3;
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
