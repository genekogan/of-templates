#include "MantaAbletonController.h"

MantaParameterMapping::MantaParameterMapping(ofParameter<float> & parameter_)
{
    this->parameter.makeReferenceTo(parameter_);
    this->min = parameter.getMin();
    this->max = parameter.getMax();
}

void MantaAbletonController::mapPadToParameter(int row, int column, ofParameter<float> & parameter)
{
    padMap[row * 8 + column] = new MantaParameterMapping(parameter);
    setPadLedState(row, column, Manta::Red);
}

void MantaAbletonController::mapSliderToParameter(int index, ofParameter<float> & parameter)
{
    sliderMap[index] = new MantaParameterMapping(parameter);
}

void MantaAbletonController::mapButtonToParameter(int index, ofParameter<float> & parameter)
{
    buttonMap[index] = new MantaParameterMapping(parameter);
}

MantaAbletonController::MantaAbletonController() : MantaStats()
{
    setupTheory();
    ofAddListener(padEvent, this, &MantaAbletonController::PadEvent);
    ofAddListener(sliderEvent, this, &MantaAbletonController::SliderEvent);
    ofAddListener(buttonEvent, this, &MantaAbletonController::ButtonEvent);
    ofAddListener(padVelocityEvent, this, &MantaAbletonController::PadVelocityEvent);
    ofAddListener(buttonVelocityEvent, this, &MantaAbletonController::ButtonVelocityEvent);
    
    midiOut.listPorts(); // via instance
    midiOut.openPort(0); // by number
    //midiOut.openPort("IAC Driver IAC Bus 1"); // by name
    //midiOut.openVirtualPort("IAC Driver IAC Bus 1"); // open a virtual port
}

MantaAbletonController::~MantaAbletonController()
{
    midiOut.closePort();
}

void MantaAbletonController::mapSelectionToMidiNotes()
{
    clearMidiMapping();
    vector<int> selection = getPadSelection();
    for (auto s : selection) {
        setMidiMapping(s);
    }
}

void MantaAbletonController::mapAllPadsToMidiNotes()
{
    clearMidiMapping();
    for (int r = 0; r < 6; r++) {
        for (int c = 0; c < 8; c++) {
            addPadToSelection(r, c);
        }
    }
    mapSelectionToMidiNotes();
}

void MantaAbletonController::clearMidiMapping()
{
    midiMap.clear();
    markAllPads(Manta::Off);
}

void MantaAbletonController::resetMidiMapping()
{
    map<int, int>::iterator it = midiMap.begin();
    for (; it != midiMap.end(); ++it) {
        setMidiMapping(it->first);
    }
}

void MantaAbletonController::setMidiMapping(int idx)
{
    int row = floor(idx / 8);
    int col = idx % 8;
    int degree = (2 * row - (int)(row / 2) + col) % 7;
    int octave1 = octave + floor((2 * row - floor(row / 2) + col) / 7);
    midiMap[idx] = getNoteAtScaleDegree(key, degree, mode, octave1);
    setPadLedState(row, col, Manta::Red);
}

void MantaAbletonController::setKey(int key)
{
    this->key = key;
    resetMidiMapping();
}

void MantaAbletonController::setMode(int mode)
{
    this->mode = mode;
    resetMidiMapping();
}

void MantaAbletonController::PadEvent(ofxMantaEvent & evt)
{
    if (padMap.count(evt.id) != 0) {
        padMap[evt.id]->parameter.set(ofMap(evt.value, 0, MANTA_MAX_PAD_VALUE, padMap[evt.id]->min, padMap[evt.id]->max));
    }
}

void MantaAbletonController::SliderEvent(ofxMantaEvent & evt)
{
    if (sliderMap.count(evt.id) != 0 && evt.value > -1) {
        sliderMap[evt.id]->parameter.set(ofMap(evt.value, 0, MANTA_MAX_SLIDER_VALUE, sliderMap[evt.id]->min, sliderMap[evt.id]->max));
    }
}

void MantaAbletonController::ButtonEvent(ofxMantaEvent & evt)
{
    if (buttonMap.count(evt.id) != 0) {
        buttonMap[evt.id]->parameter.set(ofMap(evt.value, 0, MANTA_MAX_BUTTON_VALUE, buttonMap[evt.id]->min, buttonMap[evt.id]->max));
    }
}

void MantaAbletonController::PadVelocityEvent(ofxMantaEvent & evt)
{
    if (midiMap.count(evt.id) != 0)
    {
        int note = midiMap[evt.id];
        if (evt.value == 0) {
            midiOut.sendNoteOff(1, note);
        }
        else {
            midiOut.sendNoteOn(1, note);
        }
    }
}

void MantaAbletonController::ButtonVelocityEvent(ofxMantaEvent & evt)
{
    
}

void MantaAbletonController::setupTheory()
{
    int major_[7]  = {0, 2, 4, 5, 7, 9, 11};
    int minorN_[7] = {0, 2, 3, 5, 7, 8, 10};
    int minorH_[7] = {0, 2, 3, 5, 7, 8, 11};
    int minorM_[7] = {0, 2, 3, 5, 7, 9, 11};
    for (auto m : major_)   major.push_back(m);
    for (auto m : minorN_)  minorN.push_back(m);
    for (auto m : minorH_)  minorH.push_back(m);
    for (auto m : minorM_)  minorM.push_back(m);
    key = 0;
    mode = 0;
    octave = 5;
}

void MantaAbletonController::getChord(int chord[], int root, int octave)
{
    for (int i=0; i<3; i++) {
        chord[i] = (octave + floor((root + 2 * i) / 7)) * 12 + major[(root + 2 * i) % 7];
    }
}

int MantaAbletonController::getNoteAtScaleDegree(int root, int degree, int mode, int octave)
{
    if      (mode  < 7) {
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
