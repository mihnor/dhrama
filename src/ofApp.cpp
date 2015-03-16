#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    setupDhrama();
    setupMapping();
    setupExporter();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    updateAnimatable();
    updateMapping();
    updateDhrama();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    drawMapping();
    drawExporter();
    mouseMovedDhrama();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    keyPressedExporter(key);
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

    resetup();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
