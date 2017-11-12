#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // initialize variables
    objSizeX = 3;
    objSizeY = 3;
    spacingX = objSizeX * 6;
    spacingY = objSizeY * 6;
    // center matrix within variable screen size
    // !! see if this breaks if screen size smaller than matrix needs
    startingX = (ofGetWidth() - (spacingX * numX)) /2;
    startingY = (ofGetHeight() - (spacingY * numY)) /2;

    stepSize = 20;
    goCrazy = false;

    // iterate over matrix by rows, then columns
    for(int i = 0; i < numX; i++){
        for(int j = 0; j < numY; j++){
            noiseSeeds[i][j] = ofRandom(0,1000);
        }
    }

    ofSetBackgroundColor(0);


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    // ghosting instead of background
    ofSetColor(0,20);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());

    // reset color to default settings : white, full alpha
    ofSetColor(255,255);

    // 2D matrix
    // center 2D matrix
    ofTranslate(startingX, startingY);
    // position individual ellipses in matrix
    for(int i = 0; i < numX; i++){
        for(int j = 0; j < numY; j++){
            int locX = i * spacingX;
            int locY = j * spacingY;
            if(goCrazy == false){
                //locX = locX + noiseSeeds[i][j];
                //locY = locY + noiseSeeds[i][j];
            }
            ofPushMatrix();
                ofTranslate(locX,locY);
                ofDrawEllipse(0,0,objSizeX,objSizeY);
            ofPopMatrix();

            //noiseSeeds[i][j] = ofRandom(0,1000);
        }
    }
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
    goCrazy = !goCrazy;
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
