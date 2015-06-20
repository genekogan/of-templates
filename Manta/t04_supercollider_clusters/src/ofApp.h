#pragma once

#include "ofMain.h"
#include "ofxSuperCollider.h"
#include "SuperCollider.h"
#include "MantaSuperColliderController.h"

/*
 SynthDef(\fmsynth, {
	arg carrierF, modF, modA;
	Out.ar(0, SinOsc.ar(SinOsc.kr(modF, 0, modA, carrierF))!2);
 }).add;
*/





class ofApp : public ofBaseApp
{
    
public:
    ~ofApp();
    void setup();
    void update();
    void draw();
    void stop();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    
    void padVelocityEvent(ofxMantaEvent & evt);
    MantaSuperColliderController manta;

    SuperCollider sc3;
    SuperColliderSynth *reverb;
    map<int, SuperColliderSynth*> synths;
    ofxSCGroup *group;
    ofxSCBus *bus;
    
    int drawView;
};
