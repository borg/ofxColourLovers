/*
 *  ofxColourLovers.h
 *  This is a selective goodies version of the ColourLovers API
    http://www.colourlovers.com/api
 *
 *  Created by Andreas Borg on 05/10/2012
 *  Copyright 2012 http://crea.tion.to
 *
 *  https://github.com/borg/ofxColourLovers
 */

#ifndef _ofxColourLovers
#define _ofxColourLovers

#include "ofMain.h"
#include "ofxHttpUtils.h"
#include "ofxXmlSettings.h"
#include "ColourCallTypes.h"

#include "ColourLoveEvent.h"

//http://www.colourlovers.com/api

#define CL_url "http://www.colourlovers.com/api/palettes/top/?showPaletteWidths=1"
//http://www.colourlovers.com/api/palettes/top/?lover=andreasborg&showPaletteWidths=1


#define CL_purl "http://www.colourlovers.com/api/palette/"

/*
 These string to hex conversions aren't trivial.
 */
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



class ofxColourLovers{
	
  public:
	
    ofxColourLovers();
    ~ofxColourLovers();
    /*
     orderCol	=	X   [Where X can be: dateCreated, score, name, numVotes, or numViews]
     sortBy	=	X   [Where X can be: ASC or DESC. Default ASC]
     */
    
   static  void getTopPalettes(int numResults=20, int resultOffset=0, string orderCol = "numVotes", string sortBy="DESC"){
        
        
        getSingleton().callType = CL_GET_TOP_PALETTES;
       
       ofxHttpForm form;//submitting form
       form.name ="getTopPalettes";
       form.method = OFX_HTTP_POST;
        string url = CL_url;
        url+="&numResults="+ofToString(numResults) +"&resultOffset="+ofToString(resultOffset)+"&orderCol="+orderCol+"&sortBy="+sortBy;
       form.action = url;

       
       
      
       
       
        
       //form.clearFormFields();//clear out old send data
        
        /*
         for(int i=0;i<form1.elements.size();i++){
         string v = form1.elements[i]->getValue();
         //  isEmpty = ((v=="0" || v =="") && isEmpty);//only test if not already proved wrong
         form.addFormField(form1.elements[i]->name,v);
         // ofLog()<<form1.elements[i]->name<< v <<endl;
         }*/
        
        
        
        ofLog()<<"submitting getTopPalettes"<<endl;
        //status = PENDING;
       getSingleton().http.addForm(form);
       if(!getSingleton().http.isThreadRunning()){
           getSingleton().http.start();            
       }

       //getSingleton().http.submitForm(form);
        
        
    }
    
    static  void getTopPalettesForLover(string lover, int numResults=20, int resultOffset=0, string orderCol = "numVotes", string sortBy="DESC"){
        
        
        getSingleton().callType = CL_GET_TOP_PALETTES_FOR_LOVER;
        
        
        
        ofxHttpForm form;//submitting form
        form.name ="getTopPalettesForLover";
        form.method = OFX_HTTP_POST;
        string url = CL_url;
        url+="&lover="+lover+"&numResults="+ofToString(numResults)+"&resultOffset="+ofToString(resultOffset)+"&orderCol="+orderCol+"&sortBy="+sortBy;
        form.action = url;
        
        
        //form.clearFormFields();//clear out old send data
        
        /*
         for(int i=0;i<form1.elements.size();i++){
         string v = form1.elements[i]->getValue();
         //  isEmpty = ((v=="0" || v =="") && isEmpty);//only test if not already proved wrong
         form.addFormField(form1.elements[i]->name,v);
         // ofLog()<<form1.elements[i]->name<< v <<endl;
         }*/
        
        
        
        ofLog()<<"submitting getTopPalettesForLover: "<<lover<<endl;
        //status = PENDING;
        
        getSingleton().http.addForm(form);
        if(!getSingleton().http.isThreadRunning()){
            getSingleton().http.start();            
        }

        //getSingleton().http.submitForm(form);//not threaded
        
        
    }
       
    
    static  void searchPalettes(string keywords, int numResults=20, int resultOffset=0, string orderCol = "numVotes", string sortBy="DESC"){
        
        getSingleton().callType = CL_SEARCH;
        ofxHttpForm form;//submitting form
        form.name ="search";
        form.method = OFX_HTTP_POST;
        string url = CL_url;
        url+="&keywords="+keywords+"&numResults="+ofToString(numResults) +"&resultOffset="+ofToString(resultOffset)+"&orderCol="+orderCol+"&sortBy="+sortBy;
        form.action = url;
        
        
        //form.clearFormFields();//clear out old send data
        
        /*
         for(int i=0;i<form1.elements.size();i++){
         string v = form1.elements[i]->getValue();
         //  isEmpty = ((v=="0" || v =="") && isEmpty);//only test if not already proved wrong
         form.addFormField(form1.elements[i]->name,v);
         // ofLog()<<form1.elements[i]->name<< v <<endl;
         }*/
        
        
        
        ofLog()<<"submitting search"<<endl;
        //status = PENDING;
        getSingleton().http.addForm(form);
        
        if(!getSingleton().http.isThreadRunning()){
            getSingleton().http.start();            
        }
        //getSingleton().http.submitForm(form);
        
        
    }
    
    static  void getPalette(string id){
        
        
        getSingleton().callType = CL_GET_PALETTE;
        ofxHttpForm form;//submitting form
        form.name ="getPalette";
        form.method = OFX_HTTP_POST;
        string url = CL_purl+id+"?showPaletteWidths=1";
        form.action = url;
        
             
        ofLog()<<"getPalette: "<<id<<endl;
        //status = PENDING;
        getSingleton().http.addForm(form);
        
        if(!getSingleton().http.isThreadRunning()){
            getSingleton().http.start();            
        }
        //getSingleton().http.submitForm(form);
        
        
    }

    
      
    
    
    static string hexToWeb(ofColor col){
        return "#"+ofToHex(col.r)+ofToHex(col.g)+ofToHex(col.b);
    }

    
    
     private:
    
   // int formNum;//number of forms to wait for
    ofxHttpUtils http;
    //static void newResponse(ofxHttpResponse &response);
    ofxXmlSettings serverReply;  
    ColourCallType callType;
   
	    static ofxColourLovers &getSingleton();//check out this pattern...it's quite sweet
    
    
    
    virtual void newResponse(ofxHttpResponse &response) {
        // printf("%s\n", response.responseBody.c_str());
        string responseStr = ofToString(response.status) + ": " + (string)response.responseBody;
        //ofLog()<<responseStr<<endl;
        serverReply.loadFromBuffer(response.responseBody); // parse string
        
        
        ColourLoveEvent newEvent;
        //newEvent.message = responseStr;
        
        
        switch(getSingleton().callType){
            case CL_GET_TOP_PALETTES:
                newEvent.type = CL_GET_TOP_PALETTES;
                parsePalettes(serverReply,newEvent);
                ofLog()<<"CL_GET_TOP_PALETTES reply"<<endl;
                break;
            case CL_GET_TOP_PALETTES_FOR_LOVER:
                newEvent.type = CL_GET_TOP_PALETTES_FOR_LOVER;
                parsePalettes(serverReply,newEvent);
                ofLog()<<"CL_GET_TOP_PALETTES_FOR_LOVER reply"<<endl;
                break;  
            case CL_SEARCH:
                newEvent.type = CL_SEARCH;
                parsePalettes(serverReply,newEvent);
                ofLog()<<"CL_SEARCH reply"<<endl;
                break; 
                
            case CL_GET_PALETTE:
                newEvent.type = CL_GET_PALETTE;
                parsePalettes(serverReply,newEvent);
                ofLog()<<"CL_GET_PALETTE reply"<<endl;
                break;   
                
                
            default:
                break;
                
                
        }
        
        //pass this on so you can save palettes as you please
        newEvent.xml = serverReply;
        
        ofNotifyEvent(ColourLoveEvent::events, newEvent);
    }
    
    
    static void parsePalettes(ofxXmlSettings &palettes, ColourLoveEvent &palette){
        
        palettes.pushTag("palettes");
        int numPalettes = palettes.getNumTags("palette");
        int numCols;
        if(numPalettes>0){
            for(int i=0;i<numPalettes;i++){
                palettes.pushTag("palette",i);
                //
                
                ColourLovePalette cp;
                cp.parseXML(palettes);
                               
                palette.palettes.push_back(cp);
                palettes.popTag();
            }
        }
        palettes.popTag();
    }


};

#endif
