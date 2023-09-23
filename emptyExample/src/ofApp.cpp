#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
//Draw a point
	ofBackground(230,230,250);
	p = Particule();
	gravite = Vecteur3D(0,-9.8,0);
	
	//Initialisation d'une vitesse initiale
	p.setVelocite(Vecteur3D(5,5,0));



	
}

//--------------------------------------------------------------
void ofApp::update(){
	//Calcul de la nouvelle position de la particule
	p.setPosition(p.getPosition().add(p.getVelocite()));
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	//Draw a point at the position of particule p
	ofSetColor(255,0,0);
	ofDrawCircle(p.getPosition().getX(), p.getPosition().getY(), 10);
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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