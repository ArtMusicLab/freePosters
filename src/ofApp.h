#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#include "ofxSyphon.h"
#include "ofxOpenCv.h"
#include "ofxCv.h"
using namespace cv;
using namespace ofxCv;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
	
	ofImage				poster1;
	ofImage				poster2;
	ofImage				poster3;
	ofImage				poster4;

	ofVideoPlayer 		movie1;
	ofVideoPlayer 		movie2;
	ofVideoPlayer 		movie3;
	ofVideoPlayer 		movie4;

	ofTexture			movieTex;

	ofFbo				kinect1Fbo;
	ofFbo				kinect2Fbo;
	ofxSyphonClient		kinect1SyphonClient;
	ofxSyphonClient		kinect2SyphonClient;

	ofFbo				outFbo;
	ofxSyphonServer 	outputSyphonServer;

	
	
	ofxPanel			gui;
	ofParameter<bool> 	bThreshWithOpenCV;
	ofParameter<int>	minAreaContour;
	ofParameter<int>	maxAreaContour;
	ofParameter<int>    contourConsidered;
	ofParameter<bool>	bContourFindHole;
	int					contourBlobs;
	
	ofxCvContourFinder 	contourFinder;
	ofxCvGrayscaleImage	contourImage;
	
	ofxCvColorImage 	colorImg;
	
	
	ofPoint				contourCentroid;
	float				contourArea;
	ofRectangle			contourBoundingBox;

};
