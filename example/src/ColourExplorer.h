#pragma once

#include "ofMain.h"
#include "ofxUI.h"
#include "ofxColourLovers.h"
//#include "ofxColourTheory.h"
class ColourExplorer : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    ofxUILabel *bgLabel;
    ofxUICanvas *gui;   
    ofxUIScrollableCanvas *colourLab; 
    ofxUICanvas *paletteView;
    void setPalette(int p);
    int palettesX;
    int currPalette;
    vector<ColourLovePalette> palettes;
    
    void guiEvent(ofxUIEventArgs &e);
    
    void colourLoveEvent(ColourLoveEvent &e);
    void colourLabEvent(ofxUIEventArgs &e);
    
     void colourPaletteEvent(ofxUIEventArgs &e);
    
    ofColor bg;
    bool updateFlag;
    void updateColourLab();
    vector<ofxUIButton *>   coloursPalette;
    vector<ofxUIButton *>   colourRanges;
    string lastSearch;
    
    
    void loadFavourites();
    void loadHistory();
    
};
