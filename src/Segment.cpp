//
//  Segment.cpp
//  echoChamber
//
//  Created by Hippolyte Dubois on 22/10/16.
//
//

#include "Segment.hpp"

Segment::Segment(){
    this->origin = ofPoint(0,0);
    this->v = ofVec2f(0,0);
}

Segment::Segment(ofPoint p, ofVec2f v){
    this->origin = p;
    this->v = v;
}

bool Segment::intersect(Segment otherSegment){
    
    float s, t;
    s = -this->v.y * (this->origin.x - otherSegment.origin.x);
    s += this->v.x * (this->origin.y - otherSegment.origin.y);
    s /= (-otherSegment.v.x * this->v.y + this->v.x * otherSegment.v.y);
    
    t = otherSegment.v.x * (this->origin.y - otherSegment.origin.y);
    t -= otherSegment.v.y * (this->origin.x - otherSegment.origin.x);
    t /= (-otherSegment.v.x * this->v.y + this->v.x * otherSegment.v.y);
    
    if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
    {
        return true;
    }
    
    return false; // No collision
}
