/*
 *  ofxColourLovers.cpp
 *  Vectagram
 *
 *  Created by Andreas Borg on 05/10/2012
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxColourLovers.h"


ofxColourLovers::ofxColourLovers(){
    ofAddListener(http.newResponseEvent,this,&ofxColourLovers::newResponse);
};

ofxColourLovers::~ofxColourLovers(){
    if(getSingleton().http.isThreadRunning()){
        getSingleton().http.stop();
    }
};

ofxColourLovers & ofxColourLovers::getSingleton(){
    static ofxColourLovers singleton;
    return singleton;

};



