#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // initialize variables
    startingX = 0;
    startingY = 0;
    spacingX = ofGetWidth() / numX;
    spacingY = ofGetHeight() / numY;

    stepSize = 20;
    goCrazy = false;

    // iterate over matrix by rows, then columns
    for(int i = 0; i < numX; i++){
        for(int j = 0; j < numY; j++){
            noiseSeeds[i][j] = ofRandom(0,1000);
        }
    }


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

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
