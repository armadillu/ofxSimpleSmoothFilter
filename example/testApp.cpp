#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofBackground(66);
	ofSetVerticalSync(true);
	ofEnableAlphaBlending();
	ofSetFrameRate(60);

	float minS = 0.01;
	float maxS = 0.8;

	for(int i = 0 ; i < NUM_PLOTS; i++){
		float percent = i / (float)(NUM_PLOTS - 1) ;

		plot[i] = new ofxHistoryPlot(NULL,"input", 200, false);
		plot[i]->setRange(-0.2, 1.2);
		plot[i]->setColor(ofColor(ofRandom(64,255), ofRandom(64,255), ofRandom(64,255) ));
		plot[i]->setGridUnit(10);
		plot[i]->setShowNumericalInfo(false);
		float s = minS + (maxS - minS) * percent * percent;
		cout << "setting up filter with speed :" << s << endl;
		filter[i].setup(s);
	}
}

//--------------------------------------------------------------
void testApp::update(){
	for(int i = 0 ; i < NUM_PLOTS; i++){
		if (mouseY > ofGetHeight()/2){
			filter[i].goDown();
		}else{
			filter[i].goUp();
		}
		plot[i]->update(filter[i].getVal());
	}
}

//--------------------------------------------------------------
void testApp::draw(){

	int h = ofGetHeight()/NUM_PLOTS;
	int y = 0;
	for(int i = 0 ; i < NUM_PLOTS; i++){
		ofSetColor(128,0,0);
		plot[i]->draw(0, y , ofGetWidth(), h);
		y += h;
	}
	y = 0;
	ofSetColor(64);

	for(int i = 0 ; i < NUM_PLOTS; i++){
		ofSetColor(128);
		ofLine(0, y, ofGetWidth(), y);
		ofSetColor(128,0,0);
		ofDrawBitmapString( "filterVal: " + ofToString(filter[i].getSpeed()), 5, y + 11 );
		y += h;

	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}