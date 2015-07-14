#pragma once

#include "ofMain.h"
#include "ofxSuperCollider.h"


class SuperColliderSynthParameter
{
public:
    SuperColliderSynthParameter(ofxSCSynth *synth, string name, float min, float max);
    void parameterChanged(float & v);
    ofParameter<float> & getParameter() {return parameter;}
private:
    ofxSCSynth *synth;
    ofParameter<float> parameter;
};


class SuperColliderSynth
{
public:
    SuperColliderSynth(string name);
    ~SuperColliderSynth();
    
    string getName() {return synth->getName();}
    string getInfo();
    vector<SuperColliderSynthParameter*> & getParameters() {return parameters;}
    ofxSCSynth * getSynth() {return synth;}
    
    ofParameter<float> & addParameter(string name, float min, float max);
    void set(string arg, double value);

    void create() {synth->create();}
    void addToHead() {synth->addToHead();}
    void addToTail() {synth->addToTail();}
    void grain() {synth->grain();}
    void free() {synth->free();}
    
private:
    ofxSCSynth *synth;
    vector<SuperColliderSynthParameter*> parameters;
};


class SuperCollider
{
public:
    ~SuperCollider();
    void draw();
    SuperColliderSynth * addSynth(string name);
    
    
//    float choose(vector<float> )
    
    
private:
    vector<SuperColliderSynth*> synths;
};
