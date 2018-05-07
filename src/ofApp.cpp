#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofSetVerticalSync(false);
	
//	outFbo.allocate(1920, 1080);
//	outputSyphonServer.setName("FreePostersSyphonServer");
	
	movie1.load("movies/1.mp4");
	movie2.load("movies/2.mp4");
	movie3.load("movies/3.mp4");
	movie4.load("movies/4.mp4");
	
	poster1.load("posters/1.jpg");
	poster2.load("posters/2.jpg");
	poster3.load("posters/3.jpg");
	poster4.load("posters/4.jpg");

	

	movie1.play();
	movie1.setPaused(true);
	movie2.play();
	movie2.setPaused(true);
	movie3.play();
	movie3.setPaused(true);
	movie4.play();
	movie4.setPaused(true);

	movieTex.allocate(1920, 1080,GL_RGBA);
	
//	kinect1SyphonClient.setup();
//	kinect1SyphonClient.setServerName("Composition");
	
	// countour
//	contourArea = 0.0f;
//	contourCentroid.set(0, 0);
//	contourBoundingBox.set(0, 0, 0, 0);
//
//	contourImage.allocate(640, 360);
	
	gui.setup("settings");
//	gui.add(bThreshWithOpenCV.set("thresh with opencv",false));
//	gui.add(minAreaContour.set("min contour area", 10, 0, 100));
//	gui.add(maxAreaContour.set("max contour area", 10, 0, 1000));
//	gui.add(contourConsidered.set("contour considered",0,1,10));
//	gui.add(bContourFindHole.set("contour with hole",false));

	
	// seva setting with give name
	if (!ofFile("settings.xml"))
		gui.saveToFile("settings.xml");
	
	gui.loadFromFile("settings.xml");
}

//--------------------------------------------------------------
void ofApp::update(){
//	cout << mouseX << endl;
//	contourFinder.findContours(contourImage,
//								 minAreaContour.get(),
////								 10,
//								 maxAreaContour.get(),
////								 1000,
//								 contourConsidered.get(),
////								 5,
//								 bContourFindHole.get()
////								 false
//								 );
	movie1.update();
	movie2.update();
	movie3.update();
	movie4.update();
//
//	int hidePosterNumber;
//	if(mouseX < 320){
//		hidePosterNumber = 1;
//		movie1.setPaused(false);
//		movie2.setPaused(true);
//		movie3.setPaused(true);
//		movie4.setPaused(true);
//		movieTex = movie1.getTexture();
//
//	}else if(mouseX > 320 & mouseX < 640){
//		hidePosterNumber = 2;
//
//		movie1.setPaused(true);
//		movie2.setPaused(false);
//		movie3.setPaused(true);
//		movie4.setPaused(true);
//		movieTex = movie2.getTexture();
//
//	}else if(mouseX > 640 & mouseX < 960){
//		hidePosterNumber = 3;
//
//		movie1.setPaused(true);
//		movie2.setPaused(true);
//		movie3.setPaused(false);
//		movie4.setPaused(true);
//		movieTex = movie3.getTexture();
//
//	}else if(mouseX > 960){
//		hidePosterNumber = 4;
//
//		movie1.setPaused(true);
//		movie2.setPaused(true);
//		movie3.setPaused(true);
//		movie4.setPaused(false);
//		movieTex = movie4.getTexture();
//
//	}
////
////	outFbo.begin();
////	ofClear(0, 0, 0);
//	movieTex.draw(0,0,1280,720);
//	switch (hidePosterNumber) {
//		case 1:
//			poster2.draw(320,0);
//			poster3.draw(640,0);
//			poster4.draw(960,0);
//			break;
//		case 2:
//			poster1.draw(0,0);
//			poster3.draw(640,0);
//			poster4.draw(960,0);
//			break;
//		case 3:
//			poster1.draw(0,0);
//			poster2.draw(320,0);
//			poster4.draw(960,0);
//			break;
//		case 4:
//			poster1.draw(0,0);
//			poster2.draw(320,0);
//			poster3.draw(640,0);
//			break;
//
//		default:
//			break;
//	}
//	outFbo.end();
	
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	gui.draw();
	int hidePosterNumber;
	if(mouseX < 480){
		hidePosterNumber = 1;
		movie1.setPaused(false);
		movie2.setPaused(true);
		movie3.setPaused(true);
		movie4.setPaused(true);
		movieTex = movie1.getTexture();
		
	}else if(mouseX > 480 & mouseX < 960){
		hidePosterNumber = 2;
		
		movie1.setPaused(true);
		movie2.setPaused(false);
		movie3.setPaused(true);
		movie4.setPaused(true);
		movieTex = movie2.getTexture();
		
	}else if(mouseX > 960 & mouseX < 1440){
		hidePosterNumber = 3;
		
		movie1.setPaused(true);
		movie2.setPaused(true);
		movie3.setPaused(false);
		movie4.setPaused(true);
		movieTex = movie3.getTexture();
		
	}else if(mouseX > 1440){
		hidePosterNumber = 4;
		
		movie1.setPaused(true);
		movie2.setPaused(true);
		movie3.setPaused(true);
		movie4.setPaused(false);
		movieTex = movie4.getTexture();
		
	}
	//
	//	outFbo.begin();
	//	ofClear(0, 0, 0);
	movieTex.draw(0,0,1920,1080);
	switch (hidePosterNumber) {
		case 1:
			poster2.draw(480,0);
			poster3.draw(960,0);
			poster4.draw(1440,0);
			break;
		case 2:
			poster1.draw(0,0);
			poster3.draw(960,0);
			poster4.draw(1440,0);
			break;
		case 3:
			poster1.draw(0,0);
			poster2.draw(480,0);
			poster4.draw(1440,0);
			break;
		case 4:
			poster1.draw(0,0);
			poster2.draw(480,0);
			poster3.draw(960,0);
			break;
			
		default:
			break;
	}
//	outputSyphonServer.publishTexture(&outFbo.getTexture());
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
