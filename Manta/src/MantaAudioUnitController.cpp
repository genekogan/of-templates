#include "MantaAudioUnitController.h"

MantaParameterMapping::MantaParameterMapping(ofParameter<float> & parameter_)
{
    this->parameter.makeReferenceTo(parameter_);
    this->min = parameter.getMin();
    this->max = parameter.getMax();
}

void MantaAudioUnitController::mapPadToParameter(int row, int column, ofParameter<float> & parameter)
{
    MantaParameterMapping *newMapping = new MantaParameterMapping(parameter);
    padMap[row * 8 + column] = newMapping;
    setPadLedState(row, column, Manta::Red);
}

void MantaAudioUnitController::mapSliderToParameter(int index, ofParameter<float> & parameter)
{
    MantaParameterMapping *newMapping = new MantaParameterMapping(parameter);
    sliderMap[index] = newMapping;
}

void MantaAudioUnitController::mapButtonToParameter(int index, ofParameter<float> & parameter)
{
    MantaParameterMapping *newMapping = new MantaParameterMapping(parameter);
    buttonMap[index] = newMapping;
}

MantaAudioUnitController::MantaAudioUnitController() : MantaStats()
{
    setupTheory();
    ofAddListener(padEvent, this, &MantaAudioUnitController::PadEvent);
    ofAddListener(sliderEvent, this, &MantaAudioUnitController::SliderEvent);
    ofAddListener(buttonEvent, this, &MantaAudioUnitController::ButtonEvent);
    ofAddListener(padVelocityEvent, this, &MantaAudioUnitController::PadVelocityEvent);
    ofAddListener(buttonVelocityEvent, this, &MantaAudioUnitController::ButtonVelocityEvent);
}

void MantaAudioUnitController::setAudioUnit(ofxAudioUnitSampler *audioUnit)
{
    this->audioUnit = audioUnit;
}

void MantaAudioUnitController::mapSelectionToMidiNotes()
{
    clearMidiMapping();
    vector<int> selection = getPadSelection();
    for (auto s : selection) {
        setMidiMapping(s);
    }
}

void MantaAudioUnitController::clearMidiMapping()
{
    midiMap.clear();
    markAllPads(Manta::Off);
}

void MantaAudioUnitController::resetMidiMapping()
{
    map<int, int>::iterator it = midiMap.begin();
    for (; it != midiMap.end(); ++it) {
        setMidiMapping(it->first);
    }
}

void MantaAudioUnitController::setMidiMapping(int idx)
{
    int row = floor(idx / 8);
    int col = idx % 8;
    int degree = (2 * row - (int)(row / 2) + col) % 7;
    int octave1 = octave + floor((2 * row - floor(row / 2) + col) / 7);
    midiMap[idx] = getNoteAtScaleDegree(key, degree, mode, octave1);
    setPadLedState(row, col, Manta::Red);

}

void MantaAudioUnitController::PadEvent(ofxMantaEvent & evt)
{
    if (padMap.count(evt.id) != 0) {
        padMap[evt.id]->parameter.set(ofMap(evt.value, 0, MANTA_MAX_PAD_VALUE, padMap[evt.id]->min, padMap[evt.id]->max));
    }
}

void MantaAudioUnitController::SliderEvent(ofxMantaEvent & evt)
{
    if (sliderMap.count(evt.id) != 0 && evt.value > -1) {
        sliderMap[evt.id]->parameter.set(ofMap(evt.value, 0, MANTA_MAX_SLIDER_VALUE, sliderMap[evt.id]->min, sliderMap[evt.id]->max));
    }
}

void MantaAudioUnitController::ButtonEvent(ofxMantaEvent & evt)
{
    if (buttonMap.count(evt.id) != 0) {
        buttonMap[evt.id]->parameter.set(ofMap(evt.value, 0, MANTA_MAX_BUTTON_VALUE, buttonMap[evt.id]->min, buttonMap[evt.id]->max));
    }
}

void MantaAudioUnitController::PadVelocityEvent(ofxMantaEvent & evt)
{
    if (midiMap.count(evt.id) != 0)
    {
        int note = midiMap[evt.id];
        if (evt.value == -1) {
            audioUnit->midiNoteOff(note, evt.value);
        }
        else {
            audioUnit->midiNoteOn(note, evt.value);
        }
    }
}

void MantaAudioUnitController::ButtonVelocityEvent(ofxMantaEvent & evt)
{
    
}

void MantaAudioUnitController::setupTheory()
{
    int major_[7] = {0, 2, 4, 5, 7, 9, 11};
    int minorN_[7] = {0, 2, 3, 5, 7, 8, 10};
    int minorH_[7] = {0, 2, 3, 5, 7, 8, 11};
    int minorM_[7] = {0, 2, 3, 5, 7, 9, 11};
    for (auto m : major_)   major.push_back(m);
    for (auto m : minorN_)   minorN.push_back(m);
    for (auto m : minorH_)   minorH.push_back(m);
    for (auto m : minorM_)   minorM.push_back(m);
    key = 0;
    mode = 0;
    octave = 5;
}

void MantaAudioUnitController::getChord(int chord[], int root, int octave)
{
    for (int i=0; i<3; i++) {
        chord[i] = (octave + floor((root + 2 * i) / 7)) * 12 + major[(root + 2 * i) % 7];
    }
}

int MantaAudioUnitController::getNoteAtScaleDegree(int root, int degree, int mode, int octave)
{
    if      (mode < 7) {
        return (octave + floor((mode + degree) / 7)) * 12 + root + major[(mode + degree) % 7] - major[mode];
    }
    else if (mode == 7) {
        return (octave + floor(degree / 7)) * 12 + root + minorN[degree % 7];
    }
    else if (mode == 8) {
        return (octave + floor(degree / 7)) * 12 + root + minorH[degree % 7];
    }
    else if (mode == 9) {
        return (octave + floor(degree / 7)) * 12 + root + minorM[degree % 7];
    }
}
