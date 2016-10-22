#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    origin = ofPoint(320,240);
    
    for(int i = 0; i < 12; i++){
        float theta = ofDegToRad(i * (360/12));
        float cosTheta = cos(theta);
        float sinTheta = sin(theta);
        
        ofVec2f v(300,0);
        Segment s;
        s.origin = origin;
        s.v = ofVec2f(v.x * cosTheta - v.y * sinTheta, v.x * sinTheta + v.y * cosTheta);
        segments.push_back(s);
    }
    
    mode = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    if(mode != 0){
        ofSetColor(220,0,0);
        std::vector<ofPolyline> outline = shapes.getOutline();
        for(ofPolyline line : outline){
            auto iterator = line.getVertices().begin();
            while(iterator != line.getVertices().end()){
                Segment s(*iterator, ofVec2f(*std::next(iterator,1) - *iterator));
                for(Segment ray : segments){
                    if(!ray.intersect(s)){
                        ofDrawLine(ray.origin, ray.origin + ray.v);
                    }
                }
                iterator = next(iterator,1);
            }
        }
        ofSetColor(255);
        shapes.draw();
        ofSetColor(10);
        ofDrawCircle(origin, 10);
    }
    ofSetColor(10);
    ofDrawCircle(origin, 10);
}

void ofApp::mousePressed(int x, int y, int button){
    mouseIn = ofPoint(x,y);
}

void ofApp::mouseReleased(int x, int y, int button){
    mode =1;
    mouseOut = ofPoint(x,y);
//    switch(mode){
//        case 0: shapes.rectangle(mouseIn, mouseOut.x - mouseIn.x, mouseOut.y - mouseIn.y);
//            break;
//        case 1: shapes.circle(mouseIn, mouseIn.distance(mouseOut));
//            break;
//        default: printf("lel");
//    }
//    shapes.close();
    shapes.lineTo(mouseOut);
}

void ofApp::keyReleased(int key){
    if (key == 'c'){
        shapes.close();
    }
    if (key == 'r'){
        mode = 0;
        shapes.clear();
    }
}
