#pragma once

#include "ofMain.h"
#include "ofxAudioUnit.h"


class AudioUnitInstrumentParameter
{
public:
    AudioUnitInstrumentParameter(ofxAudioUnitSampler *synth, AudioUnitParameterInfo parameter, int index);
    ofParameter<float> & getParameter() {return value;}
    void setValue(float v);
    
private:
    void parameterChanged(float & v);
    
    int index;
    ofParameter<float> value;
    ofxAudioUnitSampler *synth;
};


class AudioUnitInstrument
{
public:
    
    void setup(OSType type, OSType subType, OSType manufacturer);
    void draw(int x_, int y_);
    void showUI() {synth.showUI();}
    
    ofxAudioUnitSampler & getSynth() {return synth;}
    ofParameter<float> & getParameter(string name);
    
private:
    
    static void audioUnitParameterChanged(void * context, void * object, const AudioUnitEvent * event, UInt64 hostTime, AudioUnitParameterValue value);
    
    map<int, AudioUnitInstrumentParameter*> parameters;
    ofxAudioUnitSampler synth;
    AUEventListenerRef auEventListener;
};


