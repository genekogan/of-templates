#pragma once

#include "ofMain.h"
#include "MantaStats.h"


struct MantaParameterMapping
{
    float min, max;
    ofParameter<float> parameter;
    MantaParameterMapping(ofParameter<float> & parameter_);
};


class MantaSuperColliderController : public MantaStats
{
public:
    MantaSuperColliderController();

    void mapPadToParameter(int row, int col, ofParameter<float> & parameter);
    void mapSliderToParameter(int index, ofParameter<float> & parameter);
    void mapButtonToParameter(int index, ofParameter<float> & parameter);
    
private:
    
    void PadEvent(ofxMantaEvent & evt);
    void SliderEvent(ofxMantaEvent & evt);
    void ButtonEvent(ofxMantaEvent & evt);
    void PadVelocityEvent(ofxMantaEvent & evt);
    void ButtonVelocityEvent(ofxMantaEvent & evt);
    
    map<int, MantaParameterMapping*> padMap;
    map<int, MantaParameterMapping*> sliderMap;
    map<int, MantaParameterMapping*> buttonMap;
};