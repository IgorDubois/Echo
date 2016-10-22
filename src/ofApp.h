#pragma once

#include "ofMain.h"
#include "Segment.hpp"
#include <vector>
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void keyReleased(int key);
    
    private:
        ofPath shapes;
        ofPoint origin;
        std::vector<Segment> segments;
    
        int mode;
        ofPoint mouseIn;
        ofPoint mouseOut;
};
