#include "AudioUnitInstrument.h"


AudioUnitInstrumentParameter::AudioUnitInstrumentParameter(ofxAudioUnitSampler *synth, AudioUnitParameterInfo parameter, int index)
{
    this->synth = synth;
    this->index = index;
    value.set(parameter.name, parameter.defaultValue, parameter.minValue, parameter.maxValue);
    value.addListener(this, &AudioUnitInstrumentParameter::parameterChanged);
}

void AudioUnitInstrumentParameter::parameterChanged(float & v)
{
    synth->setParameter(index, 0, value);
}

void AudioUnitInstrumentParameter::setValue(float v)
{
    value.set(v);
}

void AudioUnitInstrument::setup(OSType type, OSType subType, OSType manufacturer)
{
    synth = ofxAudioUnitSampler(type, subType, manufacturer);
    AUEventListenerCreate(&AudioUnitInstrument::audioUnitParameterChanged,
                          this, CFRunLoopGetCurrent(), kCFRunLoopDefaultMode,
                          0.005, // minimum callback interval (seconds)
                          0.005, // callback granularity (for rate-limiting)
                          &auEventListener);
}

void AudioUnitInstrument::audioUnitParameterChanged(void *context, void *object, const AudioUnitEvent *event, UInt64 hostTime, AudioUnitParameterValue parameterValue)
{
    ((AudioUnitInstrument *) context)->parameters[event->mArgument.mParameter.mParameterID]->setValue(parameterValue);
}


void AudioUnitInstrument::draw(int x_, int y_)
{
    int x = x_;
    int y = y_;
    int clumpId = -1;
    vector<AudioUnitParameterInfo> params = synth.getParameterList();
    for (int p = 0; p < params.size(); p++) {
        if (params[p].clumpID != clumpId) {
            clumpId = params[p].clumpID;
            string s = ofToString("Group "+ofToString(clumpId));
            y += 8;
            ofDrawBitmapString(s, x, y);
            y += 15;
        }
        string s = ofToString(params[p].name) + " (" + ofToString(params[p].minValue) + "," + ofToString(params[p].maxValue) + ")";
        ofDrawBitmapString(s, x + 8, y);
        y += 15;
        if (y > 560) {
            x += 240;
            y = 20;
        }
    }
}

ofParameter<float> & AudioUnitInstrument::getParameter(string name)
{
    vector<AudioUnitParameterInfo> params = synth.getParameterList();
    for (int p = 0; p < params.size(); p++)
    {
        if (name == params[p].name)
        {
            AudioUnitParameter param = {synth, p, kAudioUnitScope_Global, 0};
            AUListenerAddParameter(auEventListener, this, &param);
            parameters[p] = new AudioUnitInstrumentParameter(&synth, params[p], p);
            return parameters[p]->getParameter();
        }
    }
    // if we got here, no such parameter exists
    ofLog(OF_LOG_ERROR, "No parameter called "+name+" found");
    return;
}

