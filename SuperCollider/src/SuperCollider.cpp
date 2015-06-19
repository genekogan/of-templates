#include "SuperCollider.h"


SuperColliderSynthParameter::SuperColliderSynthParameter(ofxSCSynth *synth, string name, float min, float max)
{
    this->synth = synth;
    parameter.set(name, 0.5*(min+max), min, max);
    parameter.addListener(this, &SuperColliderSynthParameter::parameterChanged);
}

void SuperColliderSynthParameter::parameterChanged(float & v)
{
    synth->set(parameter.getName(), parameter);
}

SuperColliderSynth::SuperColliderSynth(string name)
{
    synth = new ofxSCSynth(name);
}

void SuperColliderSynth::set(string arg, double value)
{
    synth->set(arg, value);
}

string SuperColliderSynth::getInfo()
{
    string s = getName() + "\n============\n";
    vector<SuperColliderSynthParameter*>::iterator it = parameters.begin();
    for (; it != parameters.end(); ++it) {
        s += " -> " + (*it)->getParameter().getName() + " {"+ofToString((*it)->getParameter().getMin())+", "+ofToString((*it)->getParameter().getMax())+"}\n";
    }
    return s;
}

SuperColliderSynth::~SuperColliderSynth()
{
    free();
}

ofParameter<float> & SuperColliderSynth::addParameter(string name, float min, float max)
{
    SuperColliderSynthParameter *newParameter = new SuperColliderSynthParameter(synth, name, min, max);
    parameters.push_back(newParameter);
    return newParameter->getParameter();
}

SuperColliderSynth * SuperCollider::addSynth(string name)
{
    SuperColliderSynth *newSynth = new SuperColliderSynth(name);
    synths.push_back(newSynth);
    return newSynth;
}

SuperCollider::~SuperCollider()
{
    vector<SuperColliderSynth*>::iterator it = synths.begin();
    while (it != synths.end()) {
        delete (*it);
        synths.erase(it);
    }
}

void SuperCollider::draw()
{
    string s = "Synths\n\n";
    vector<SuperColliderSynth*>::iterator it = synths.begin();
    for (; it != synths.end(); ++it) {
        s += (*it)->getInfo() + "\n";
    }
    ofDrawBitmapString(s, 50, 50);
}