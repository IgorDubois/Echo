//
//  Segment.hpp
//  echoChamber
//
//  Created by Hippolyte Dubois on 22/10/16.
//
//

#pragma once

#include "ofMain.h"

class Segment{
    
public:
    ofPoint origin;
    ofVec2f v;
    
    Segment(ofPoint p, ofVec2f v);
    Segment();
    bool intersect(Segment s);
};
