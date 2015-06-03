#include "ofApp.h"

void ofApp::setup(){
    kinect.setup(12345);
    renderer.setup(kinect.getSkeletons());
    
    drawView = 1;
    
    synth.setup('aumu', 'Aalt', 'MLbs');
    synth.showUI();
    
    synth.getSynth().connectTo(mixer, 0);
    mixer.connectTo(output);
    output.start();
}

void ofApp::update(){
    kinect.update();
    
    if (!isMapped && kinect.hasSkeletons())
    {
        isMapped = true;
        
        skeleton = kinect.getNearestSkeleton();
        
        mapper.addCorrespondencePair(skeleton->getHead().getPositionZ(), &synth.getParameter("output_reverb"));
//        mapper.addCorrespondencePair(skeleton->getHead().getPositionY(), &synth.getParameter("delay_drive"));
    }
    
    if (isMapped && kinect.hasSkeletons()) {
        mapper.update();
    }
}

void ofApp::draw(){
    ofBackground(ofColor::darkGray);
    
    if (drawView == 1) {
        kinect.drawDebug();
        renderer.draw();
    }
    else if (drawView == 2) {
        ofSetColor(0);
        synth.draw(5, 20);
    }
    else if (drawView == 3) {
        mapper.draw();
    }

}

void ofApp::keyPressed(int key){
    if(key == '1') kinect.toggleDebug();
    if(key == '2') renderer.toggleJoints();
    if(key == '3') renderer.toggleBones();
    if(key == '4') renderer.toggleHands();
    if(key == '5') renderer.toggleRanges();
    if(key == 'z') drawView = 1;
    if(key == 'x') drawView = 2;
    if(key == 'c') drawView = 3;
}

void ofApp::keyReleased(int key){
    
}

void ofApp::mouseMoved(int x, int y ){
    
}

void ofApp::mouseDragged(int x, int y, int button){
    
}

void ofApp::mousePressed(int x, int y, int button){
    
}

void ofApp::mouseReleased(int x, int y, int button){
    
}

void ofApp::windowResized(int w, int h){
    
}

void ofApp::gotMessage(ofMessage msg){
    
}

void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
