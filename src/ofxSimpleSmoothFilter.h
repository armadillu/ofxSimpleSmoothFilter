//
//  ofxSimpleSmoothFilter.h
//  ofxSimpleSmoothFilter
//
//  Created by Oriol Ferrer Mesià on 09/06/13.
//
//

#ifndef ofxSimpleSmoothFilter_h
#define ofxSimpleSmoothFilter_h

#define GHETTO_VAL	0.001f
class ofxSimpleSmoothFilter{

public:

	ofxSimpleSmoothFilter(){
		val = GHETTO_VAL;
		upSpeed = 0.5;
	}

	void setup(float upSpeed_){
		upSpeed = upSpeed_;
	}

	void goUp(){
		if (val <= GHETTO_VAL){
			val = GHETTO_VAL;
		}
		val *= (1.0f + upSpeed * 2.0 * (1.0f - val) );
	}

	void goDown(){
		if (val >= 1.0f - GHETTO_VAL){
			val = 1.0f - GHETTO_VAL;
		}
		val /= (1.0f + upSpeed * 2.0 * (1.0f - val) );
	}

	float getVal(){
		return val;
	}

	float getSpeed(){
		return upSpeed;
	}

	float upSpeed;
	float val;
};

#endif