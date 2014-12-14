/*
 *  ColourLoveEvent.h
 *  Vectagram
 *
 *  Created by Andreas Borg on 06/10/2012
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _ColourLoveEvent
#define _ColourLoveEvent

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ColourCallTypes.h"
#include "ColourLovePalette.h"

class ColourLoveEvent : public ofEventArgs {
	
  public:
	
	ColourLoveEvent(){};
    ColourCallType type;
    string   message;
    ofxXmlSettings xml;
	vector<ColourLovePalette> palettes; 
    static ofEvent <ColourLoveEvent> events;
	
};

#endif
