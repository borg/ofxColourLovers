/*
 *  ColourLovePalette.cpp
 *  mural
 *
 *  Created by Andreas Borg on 15/10/2012
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "ColourLovePalette.h"

//extern int stringToHex(string hex);
//extern void hexToColor(ofColor &col,string hex);


ColourLovePalette::ColourLovePalette(){};
ColourLovePalette::~ColourLovePalette(){};


void ColourLovePalette::draw(int x,int y,int w,int h){
    
    ofPushStyle();
    float _w = (float)w/(float)colours.size();
    float currX = x;
    for(int i=0;i<colours.size();i++){
        ofSetColor(colours[i]);
        ofRect(currX,y,w*colorWidths[i],h);
        currX +=w*colorWidths[i];
    }
    
   /* 
    currX+=10;
    for(int i=0;i<sortedColours.size();i++){
        ofSetColor(sortedColours[i]);
        ofRect(currX,y,_w,h);
        currX +=_w;
    }
    */
    
    ofPopStyle();
};


void ColourLovePalette::sortByWidth(){
    vector<SortColour> tempSort;
    for(int i = 0;i<colours.size();i++){
        SortColour sp;
        sp.uid =i;
        sp.w = colorWidths[i];
        tempSort.push_back(sp);
    }
    
    sort(tempSort.begin(),tempSort.end(),ColourLovePalette::sortSizes);
    
    for(int i = 0;i<tempSort.size();i++){
        sortedColours.push_back(colours[tempSort[i].uid]);
    }

}


void ColourLovePalette::save(string fileName){
    xml.saveFile(fileName);
};


void ColourLovePalette::load(string fileName){
    ofxXmlSettings tmp;
    tmp.loadFile(fileName);
    tmp.pushTag("palette");
    parseXML(tmp);

};


void ColourLovePalette::parseXML(ofxXmlSettings &x){
    
    //rebuild local version of tag...no apparent easy way of copy/cloning tags
    
    xml.addTag("palette");
    xml.pushTag("palette");

    
    id = x.getValue("id","");
    xml.addValue("id",id);
    
    title = x.getValue("title","");
    xml.addValue("title",title);
    
    userName = x.getValue("userName","");
    xml.addValue("userName",userName);
    
    numViews = x.getValue("numViews",0);
    xml.addValue("numViews",numViews);
    
    numVotes = x.getValue("numVotes",0);
    xml.addValue("numVotes",numVotes);
    
    numComments =x.getValue("numComments",0);
    xml.addValue("numComments",numComments);
    
    numHearts = x.getValue("numHearts",0);
    xml.addValue("numHearts",numHearts);
    
    rank = x.getValue("rank",0);
    xml.addValue("rank",rank);
    
    dateCreated = x.getValue("dateCreated","");
    xml.addValue("dateCreated",dateCreated);
    
    description = x.getValue("description","");
    xml.addValue("description",description);
    
    url = x.getValue("url","");                
    xml.addValue("url",url);
    
    imageUrl = x.getValue("imageUrl",""); 
    xml.addValue("imageUrl",imageUrl);
    
    badgeUrl = x.getValue("badgeUrl",""); 
    xml.addValue("badgeUrl",badgeUrl);
    
    apiUrl = x.getValue("apiUrl",""); 
    xml.addValue("apiUrl",apiUrl);
    

    
    xml.addTag("colors");
    xml.pushTag("colors");
    
    
    x.pushTag("colors");
    
    string hex;
    int numCols = x.getNumTags("hex");
    if(numCols>0){
        for(int c=0;c<numCols;c++){
            ofColor col;
            hex = x.getValue("hex","FFFFFF",c); 
            
            xml.addValue("hex",hex);
            
            hexToColor(col,hex);
            
            
            
            colours.push_back(col);
        }
    }
    //colors
    xml.popTag();
    x.popTag();
    
    
    string ws = x.getValue("colorWidths","0.2,0.2,0.2,0.2,0.2"); 
    xml.addValue("colorWidths",ws);
    
    vector<string> wv = ofSplitString(ws,",");
    
    for(int v =0;v<wv.size();v++){
        colorWidths.push_back(ofToFloat(wv[v]));
    }
    
    
    
    //palette
   xml.popTag();

    sortByWidth();

}

