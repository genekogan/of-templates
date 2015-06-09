#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    manta.setup();

    // set smoothing for manta stats (default=0.1)
    manta.setVelocityLerpRate(0.1);

    // manta values are stored as ofParameters, so you can keep a persistent reference to them
    padRef.makeReferenceTo(manta.getPad(0, 0));     // get pad, row/column (0, 0)
    sliderRef.makeReferenceTo(manta.getSlider(0));  // get first slider
    buttonRef.makeReferenceTo(manta.getButton(0));  // get first button
   
    // get other values
    numPads.makeReferenceTo(manta.getNumPads());
    padSum.makeReferenceTo(manta.getPadSum());
    padAverage.makeReferenceTo(manta.getPadAverage());
    centroidX.makeReferenceTo(manta.getCentroidX());
    centroidY.makeReferenceTo(manta.getCentroidY());
    weightedCentroidX.makeReferenceTo(manta.getWeightedCentroidX());
    weightedCentroidY.makeReferenceTo(manta.getWeightedCentroidY());
    averageInterFingerDistance.makeReferenceTo(manta.getAverageInterFingerDistance());
    perimeter.makeReferenceTo(manta.getPerimeter());
    area.makeReferenceTo(manta.getArea());
    padWidth.makeReferenceTo(manta.getWidth());
    padHeight.makeReferenceTo(manta.getHeight());
    whRatio.makeReferenceTo(manta.getWidthHeightRatio());

    // get other values (velocity)
    numPadsVelocity.makeReferenceTo(manta.getNumPadsVelocity());
    padSumVelocity.makeReferenceTo(manta.getPadSumVelocity());
    padAverageVelocity.makeReferenceTo(manta.getPadAverageVelocity());
    centroidVelocityX.makeReferenceTo(manta.getCentroidVelocityX());
    centroidVelocityY.makeReferenceTo(manta.getCentroidVelocityY());
    weightedCentroidVelocityX.makeReferenceTo(manta.getWeightedCentroidVelocityX());
    weightedCentroidVelocityY.makeReferenceTo(manta.getWeightedCentroidVelocityY());
    averageInterFingerDistanceVelocity.makeReferenceTo(manta.getAverageInterFingerDistanceVelocity());
    perimeterVelocity.makeReferenceTo(manta.getPerimeterVelocity());
    areaVelocity.makeReferenceTo(manta.getAreaVelocity());
    widthVelocity.makeReferenceTo(manta.getWidthVelocity());
    heightVelocity.makeReferenceTo(manta.getHeightVelocity());
    whRatioVelocity.makeReferenceTo(manta.getWidthHeightRatioVelocity());
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    manta.draw(20, 50, 400);
    manta.drawStats(450, 50, 400);
    
    ofSetColor(0);
    
    ofDrawBitmapString(padRef.getName()+" = "+ofToString(padRef), 20, 450);
    ofDrawBitmapString(sliderRef.getName()+" = "+ofToString(sliderRef), 20, 470);
    ofDrawBitmapString(buttonRef.getName()+" = "+ofToString(buttonRef), 20, 490);

    ofDrawBitmapString(numPads.getName()+" = "+ofToString(numPads), 320, 450);
    ofDrawBitmapString(padSum.getName()+" = "+ofToString(padSum), 320, 470);
    ofDrawBitmapString(padAverage.getName()+" = "+ofToString(padAverage), 320, 490);
    ofDrawBitmapString(centroidX.getName()+" = "+ofToString(centroidX), 320, 510);
    ofDrawBitmapString(centroidY.getName()+" = "+ofToString(centroidY), 320, 530);
    ofDrawBitmapString(weightedCentroidX.getName()+" = "+ofToString(weightedCentroidX), 320, 550);
    ofDrawBitmapString(weightedCentroidY.getName()+" = "+ofToString(weightedCentroidY), 320, 570);
    ofDrawBitmapString(averageInterFingerDistance.getName()+" = "+ofToString(averageInterFingerDistance), 320, 590);
    ofDrawBitmapString(perimeter.getName()+" = "+ofToString(perimeter), 320, 610);
    ofDrawBitmapString(area.getName()+" = "+ofToString(area), 320, 630);
    ofDrawBitmapString(padWidth.getName()+" = "+ofToString(padWidth), 320, 650);
    ofDrawBitmapString(padHeight.getName()+" = "+ofToString(padHeight), 320, 670);
    ofDrawBitmapString(whRatio.getName()+" = "+ofToString(whRatio), 320, 690);
    
    ofDrawBitmapString(numPadsVelocity.getName()+" = "+ofToString(numPadsVelocity), 620, 450);
    ofDrawBitmapString(padSumVelocity.getName()+" = "+ofToString(padSumVelocity), 620, 470);
    ofDrawBitmapString(padAverageVelocity.getName()+" = "+ofToString(padAverageVelocity), 620, 490);
    ofDrawBitmapString(centroidVelocityX.getName()+" = "+ofToString(centroidVelocityX), 620, 510);
    ofDrawBitmapString(centroidVelocityY.getName()+" = "+ofToString(centroidVelocityY), 620, 530);
    ofDrawBitmapString(weightedCentroidVelocityX.getName()+" = "+ofToString(weightedCentroidVelocityX), 620, 550);
    ofDrawBitmapString(weightedCentroidVelocityY.getName()+" = "+ofToString(weightedCentroidVelocityY), 620, 570);
    ofDrawBitmapString(averageInterFingerDistanceVelocity.getName()+" = "+ofToString(averageInterFingerDistanceVelocity), 620, 590);
    ofDrawBitmapString(perimeterVelocity.getName()+" = "+ofToString(perimeterVelocity), 620, 610);
    ofDrawBitmapString(areaVelocity.getName()+" = "+ofToString(areaVelocity), 620, 630);
    ofDrawBitmapString(widthVelocity.getName()+" = "+ofToString(widthVelocity), 620, 650);
    ofDrawBitmapString(heightVelocity.getName()+" = "+ofToString(heightVelocity), 620, 670);
    ofDrawBitmapString(whRatioVelocity.getName()+" = "+ofToString(whRatioVelocity), 620, 690);
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
