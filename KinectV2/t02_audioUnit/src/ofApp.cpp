#include "ofApp.h"

void ofApp::setup(){
    smallFont.loadFont("selena.otf", 16); //http://openfontlibrary.org/en/font/selena
    largeFont.loadFont("selena.otf", 48);
    
    ofSetLineWidth(8);
    ofSetFrameRate(60);
    
    //The Kinect here is just an OSC receiver and parser
    //It just needs a port number and font for the debug text
    kinect.setup(12345, smallFont);
    
    //Here we get a pointer to the list of skeletons it has parsed
    //from OSC
    skeletons = kinect.getSkeletons();
    
    //We could inspect the skeletons and draw them here in ofApp
    //but for now let's pass the list to a default renderer class
    renderer.setup(skeletons, largeFont);
    
    
    
    
    drawView = 1;
    
    synth.setup('aumu', 'Aalt', 'MLbs');
    synth.showUI();
    
    synth.getSynth().connectTo(mixer, 0);
    mixer.connectTo(output);
    output.start();
    
    
    p.makeReferenceTo(synth.getParameter("output_reverb"));
    q.makeReferenceTo(synth.getParameter("delay_drive"));

    

}

void ofApp::update(){
    //Each frame check for new Kinect OSC messages
    kinect.update();
    
    if (kinect.getSkeletons()->size() > 0) {
        cout << kinect.getNearestSkeleton()->getHead().z() << endl;
        p = ofMap(kinect.getNearestSkeleton()->getHead().z(), 20, -10, 0, 1);
        q = ofMap(kinect.getNearestSkeleton()->getHead().z(), 20, -10, 0, 1);
    }
}

void ofApp::draw(){
    
    ofBackground(ofColor::darkGray);
    
    //Print out strings with the values from the network
    kinect.drawDebug();
    
    //We passed the skeleton list pointer to the renderer earlier,
    //now we tell it to draw them
    renderer.draw();
    
    //If you want to stop using the default renderer and start
    //drawing your own graphics, uncomment this for a starting point:
    /*for(int i = 0; i < skeletons->size(); i++) {
     ofSetColor(ofColor::fromHsb(ofGetFrameNum() % 255, 255, 255));
     Joint handLeft = skeletons->at(i).getHandLeft();
     ofCircle(handLeft.x(), handLeft.y(), 60);
     Joint handRight = skeletons->at(i).getHandRight();
     ofCircle(handRight.x(), handRight.y(), 60);
     }*/
    
    //Print out commands and text
    string commands = "COMMANDS\n\n";
    commands.append("d = debug\n");
    commands.append("j = joints\n");
    commands.append("b = bones\n");
    commands.append("h = hands\n");
    commands.append("r = ranges\n");
    
    ofSetColor(ofColor::white);
    smallFont.drawString(commands, 20, 40);
    largeFont.drawString("fps:\n" + ofToString(ofGetFrameRate()), 20, ofGetHeight() - 100);
}

void ofApp::keyPressed(int key){
    if(key == 'd') kinect.toggleDebug();
    if(key == 'j') renderer.toggleJoints();
    if(key == 'b') renderer.toggleBones();
    if(key == 'h') renderer.toggleHands();
    if(key == 'r') renderer.toggleRanges();
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
