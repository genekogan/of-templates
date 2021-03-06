#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    synth.setup("Aalto", 'aumu', 'Aalt', 'MLbs');
    synth.showUI();

    synth.getSynth().connectTo(mixer, 0);
    mixer.connectTo(output);
    output.start();
        
    p.makeReferenceTo(synth.getParameter("output_reverb"));
}

//--------------------------------------------------------------
void ofApp::update(){

    if (ofGetKeyPressed()) {
        //p.set((float) ofGetMouseX() / ofGetWidth());
    }
    
    cout << p.getName() << " = " << p << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0);
    synth.draw(5, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key=='1')   synth.savePreset("myPreset1");
    if (key=='2')   synth.loadPreset("myPreset1");
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
