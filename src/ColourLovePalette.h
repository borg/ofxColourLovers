/*
 *  ColourLovePalette.h
 *  mural
 *
 *  Created by Andreas Borg on 15/10/2012
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 http://www.colourlovers.com/api/palettes/top/?lover=andreasborg&showPaletteWidths=1
 
 
 id
 title
 userName
 numViews
 numVotes
 numComments
 numHearts
 rank
 dateCreated
 colours [hex#1,hex#2...]
 colorWidths
 description
 url
 imageUrl
 badgeUrl
 apiUrl
 
 
 */

#ifndef _ColourLovePalette
#define _ColourLovePalette

#include "ofMain.h"
#include "ofxXmlSettings.h"
//#include "ofxColourLovers.h"

typedef struct SortColour{
    int uid;
    float w;
}SortColour;





class ColourLovePalette {
	
  public:
	
	ColourLovePalette();
    ~ColourLovePalette();
	
    string id;
    string title;
    string userName;
    int numViews;
    int numVotes;
    int numComments;
    int numHearts;
    int rank;
    string dateCreated;//kept as string (2012-10-09 14:06:00)...you will need to parse with some fancy function if you need this (there are some, eg. ofxDateTime)
    vector<ofColor> colours;
    vector<float> colorWidths;
    vector<ofColor> sortedColours;
    string description;
    string url;
    string imageUrl;
    string badgeUrl;
    string apiUrl;
    
    void draw(int x,int y,int w,int h);
    void sortByWidth();// arranges colours according to prominence and stores in sortedColours
	
    
    void save(string fileName);
    void load(string fileName);
    
    void parseXML(ofxXmlSettings &x);
    
    private:
    ofxXmlSettings xml;
    
    static bool sortSizes (SortColour i,SortColour j){
        return (i.w>j.w);
    };
    
    
    static int stringToHex(string hex){
        int aHex;
        stringstream convert ( hex );
        convert>> std::hex >> aHex;
        return aHex;
    }
    
    
    
    static void hexToColor(ofColor &col,string hex){
        string r = hex.substr(0,2);
        int ri = stringToHex(r);
        string g = hex.substr(2,2);
        int gi = stringToHex(g);
        string b = hex.substr(4,2);
        int bi = stringToHex(b);
        col.set(ri,gi,bi);
        
    }
};

#endif
