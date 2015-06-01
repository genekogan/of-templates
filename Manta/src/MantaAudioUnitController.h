#pragma once

#include "ofMain.h"
#include "ofxAudioUnit.h"
#include "MantaStats.h"


struct MantaParameterMapping
{
    float min, max;
    ofParameter<float> parameter;
    MantaParameterMapping(ofParameter<float> & parameter_);
};


class MantaAudioUnitController : public MantaStats
{
public:
    MantaAudioUnitController();
    void setAudioUnit(ofxAudioUnitSampler *audioUnit);

    void mapPadToParameter(int row, int col, ofParameter<float> & parameter);
    void mapSliderToParameter(int index, ofParameter<float> & parameter);
    void mapButtonToParameter(int index, ofParameter<float> & parameter);

    void mapSelectionToMidiNotes();
    void clearMidiMapping();

private:
    
    void PadEvent(ofxMantaEvent & evt);
    void SliderEvent(ofxMantaEvent & evt);
    void ButtonEvent(ofxMantaEvent & evt);
    void PadVelocityEvent(ofxMantaEvent & evt);
    void ButtonVelocityEvent(ofxMantaEvent & evt);

    void resetMidiMapping();
    void setMidiMapping(int idx);
    
    void setupTheory();
    void getChord(int chord[], int root, int octave=0);
    int getNoteAtScaleDegree(int root, int degree, int mode, int octave);
    
    ofxAudioUnitSampler *audioUnit;
    
    map<int, MantaParameterMapping*> padMap;
    map<int, MantaParameterMapping*> sliderMap;
    map<int, MantaParameterMapping*> buttonMap;
    map<int, int> midiMap;

    vector<int> major, minorM, minorH, minorN;
    int mode;
    int key;
    int octave;
};