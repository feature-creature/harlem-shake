#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    /*  initialize global variables
        I added a few extra global variables
        to make the code a little more abstract.
        these deal with object size and noise.
    */

    goCrazy = false;
    objSizeX = 3;
    objSizeY = 3;
    spacingX = objSizeX * 6;
    spacingY = objSizeY * 6;

    /*  this gives us a centered, standard grid, regardless if the screen size changes.
        it finds the difference between the width of the screen and width of the matrix
        and uses that to give the matrix an equal padding on all sides.
    */
    // !! TODO: see if the program breaks if screen size smaller than the matrix itself.
    startingX = (ofGetWidth() - (spacingX * numX)) /2;
    startingY = (ofGetHeight() - (spacingY * numY)) /2;

    /*  maximum possible amount of movement for an ellipse per frame.
        originally named stepSize, rename to stepSizeMax for clarity.
        added two noise global variables so that they can be easily updated.
    */
    stepSizeMax = 20;
    noiseStep = 0.02;
    noiseVarianceY = 500;

    // iterate over matrix by rows, then columns
    for(int i = 0; i < numX; i++){
        for(int j = 0; j < numY; j++){
            noiseSeeds[i][j] = ofRandom(0,1000);
        }
    }

    // initialize background settings
    // for ghosting effect instead of standard background
    ofSetBackgroundColor(0);
    ofSetBackgroundAuto(false);


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    // ghosting effect
    ofSetColor(0,20);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());

    // reset color to default settings of white, full alpha
    ofSetColor(255,255);

    /*  draw 2D matrix
        this push/pop isn't technically necessary
        but I like to use it to keep the matrix contained
        if I want to add new features in the future.
    */
    ofPushMatrix();
    // center the entire 2D matrix on the screen
    ofTranslate(startingX, startingY);
    // position the matrix's individual ellipses
    // iterate over the matrix by rows, then by columns
    for(int i = 0; i < numX; i++){
        for(int j = 0; j < numY; j++){
            // calculate the individual ellipse' default location
            // and set to local variable
            int locX = i * spacingX;
            int locY = j * spacingY;
            /*  only perform the 'extra' calculations if needed:
                harlem-shake-ify the current ellipse's location
                if we are currently dealing with the 'harlem shake starter' ellipse
                (which is independent of goCrazy variable)
                or
                if we are in goCrazy mode harlem-shake-ify all ellipses locations
                (all ellipses that are and are not dependent on goCrazy variable)
            */
            if(( i == 20 && j == 23 ) || goCrazy == true){
                /*  ofSignedNoise returns a float between -1.0 and 1.0 (provides up and down motion)
                    multiply it by the maximum possible step size.
                    (consistenly) increment up the ellipse's noiseSeed value for movement.
                */
                int stepX = stepSizeMax * ofSignedNoise( noiseSeeds[i][j] );
                int stepY = stepSizeMax * ofSignedNoise( noiseSeeds[i][j] + noiseVarianceY );
                noiseSeeds[i][j] += noiseStep;

                // update the default location values with the harlem-shake-ify values
                locX = locX + stepX;
                locY = locY + stepY;
            }
            ofPushMatrix();
                // translate and draw current ellipse
                ofTranslate(locX,locY);
                ofDrawEllipse(0,0,objSizeX,objSizeY);
            ofPopMatrix();
        }
    }
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // save a png screenshot for documentation in bin/data
    // use date and framerate for unique naming
    if(key == 's'){
        ofSaveScreen(ofGetTimestampString() + "-" + ofToString(ofGetFrameNum()) + ".png");
    }
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
    // if the mouse is pressed, flip the boolean value for goCrazy
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
