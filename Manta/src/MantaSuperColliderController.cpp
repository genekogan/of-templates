#include "MantaSuperColliderController.h"

/*
 map to parameters / triggers / volume
 */

MantaParameterMapping::MantaParameterMapping(ofParameter<float> & parameter_)
{
    this->parameter.makeReferenceTo(parameter_);
    this->min = parameter.getMin();
    this->max = parameter.getMax();
}

void MantaSuperColliderController::mapPadToParameter(int row, int column, ofParameter<float> & parameter)
{
    padMap[row * 8 + column] = new MantaParameterMapping(parameter);
    setPadLedState(row, column, Manta::Red);
}

void MantaSuperColliderController::mapSliderToParameter(int index, ofParameter<float> & parameter)
{
    sliderMap[index] = new MantaParameterMapping(parameter);
}

void MantaSuperColliderController::mapButtonToParameter(int index, ofParameter<float> & parameter)
{
    buttonMap[index] = new MantaParameterMapping(parameter);
}

MantaSuperColliderController::MantaSuperColliderController() : MantaStats()
{
    ofAddListener(padEvent, this, &MantaSuperColliderController::PadEvent);
    ofAddListener(sliderEvent, this, &MantaSuperColliderController::SliderEvent);
    ofAddListener(buttonEvent, this, &MantaSuperColliderController::ButtonEvent);
    ofAddListener(padVelocityEvent, this, &MantaSuperColliderController::PadVelocityEvent);
    ofAddListener(buttonVelocityEvent, this, &MantaSuperColliderController::ButtonVelocityEvent);
}

void MantaSuperColliderController::PadEvent(ofxMantaEvent & evt)
{
    if (padMap.count(evt.id) != 0) {
        padMap[evt.id]->parameter.set(ofMap(evt.value, 0, MANTA_MAX_PAD_VALUE, padMap[evt.id]->min, padMap[evt.id]->max));
    }
}

void MantaSuperColliderController::SliderEvent(ofxMantaEvent & evt)
{
    if (sliderMap.count(evt.id) != 0 && evt.value > -1) {
        sliderMap[evt.id]->parameter.set(ofMap(evt.value, 0, MANTA_MAX_SLIDER_VALUE, sliderMap[evt.id]->min, sliderMap[evt.id]->max));
    }
}

void MantaSuperColliderController::ButtonEvent(ofxMantaEvent & evt)
{
    if (buttonMap.count(evt.id) != 0) {
        buttonMap[evt.id]->parameter.set(ofMap(evt.value, 0, MANTA_MAX_BUTTON_VALUE, buttonMap[evt.id]->min, buttonMap[evt.id]->max));
    }
}

void MantaSuperColliderController::PadVelocityEvent(ofxMantaEvent & evt)
{

}

void MantaSuperColliderController::ButtonVelocityEvent(ofxMantaEvent & evt)
{
    
}
