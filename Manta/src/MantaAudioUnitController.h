#pragma once

#include "ofMain.h"
#include "ofxAudioUnit.h"
#include "AudioUnitInstrument.h"
#include "MantaStats.h"


struct MantaParameterMapping
{
    float min, max;
    ofParameter<float> parameter;
    string synthName;
    MantaParameterMapping(AudioUnitInstrument & synth, string parameterName);
};


class MantaAudioUnitController : public MantaStats
{
public:
    MantaAudioUnitController();
    void addAudioUnit(AudioUnitInstrument *audioUnit);

    void mapPadToParameter(int row, int col, AudioUnitInstrument & synth, string parameterName);
    void mapSliderToParameter(int index, AudioUnitInstrument & synth, string parameterName);
    void mapButtonToParameter(int index, AudioUnitInstrument & synth, string parameterName);

    void mapSelectionToMidiNotes();
    void mapAllPadsToMidiNotes();
    void clearMidiMapping();
    
    void setKey(int key);
    void setMode(int mode);

    void savePreset(string name);
    void loadPreset(string name);
    
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
    
    map<string, AudioUnitInstrument*> synths;
    
    map<int, MantaParameterMapping*> padMap;
    map<int, MantaParameterMapping*> sliderMap;
    map<int, MantaParameterMapping*> buttonMap;
    map<int, int> midiMap;

    vector<int> major, minorM, minorH, minorN;
    int mode;
    int key;
    int octave;
};