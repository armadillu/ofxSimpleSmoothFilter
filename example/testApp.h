#pragma once

#include "ofMain.h"
#include "ofxHistoryPlot.h"
#include "ofxSimpleSmoothFilter.h"

#define NUM_PLOTS 10

class testApp : public ofBaseApp{

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

	ofxHistoryPlot * plot[NUM_PLOTS];
	ofxSimpleSmoothFilter filter[NUM_PLOTS];
};
