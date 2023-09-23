#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
//Draw a point
	ofBackground(230,230,250);
	p = Particule();
	gravite = Vecteur3D(0,9.8,0);
	
	//Initialisation d'une position initiale
	p.setPosition(Vecteur3D(20,300,0));
	//Initialisation d'une vitesse initiale
	p.setVelocite(Vecteur3D(70,-70,0));
	p.setAcceleration(gravite);
	


	
}

//--------------------------------------------------------------
void ofApp::update(){
	i = Integrateur();
	i.integrer(&p);
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