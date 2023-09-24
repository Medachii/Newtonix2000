#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){


	ofBackground(230,230,250);
	restartButton.addListener(this, &ofApp::restartButtonPressed);

	p1 = Particule();
	p2 = Particule();


	gravite = Vecteur3D(0,-9.8,0);
	
	p1.setPosition(Vecteur3D(0,0,0));
	p1.setVelocite(Vecteur3D(70,70,70));
	p1.setAcceleration(gravite);

	p2.setPosition(Vecteur3D(0,30,0));
	p2.setVelocite(Vecteur3D(70,0,70));
	p2.setAcceleration(gravite);
	
	


	gui.setup();
	gui.add(p2x.setup("Position (x) de la balle bleue", 0.0, 0.0, 100.0));
	gui.add(p2y.setup("Position (y) de la balle bleue", 30.0, 0.0, 100.0));
	gui.add(p2z.setup("Position (z) de la balle bleue", 0.0, 0.0, 100.0));
    gui.add(v2x.setup("Vitesse (x) de la balle bleue", 70.0, 0.0, 100.0));
	gui.add(v2y.setup("Vitesse (y) de la balle bleue", 0.0, 0.0, 100.0));
	gui.add(v2z.setup("Vitesse (z) de la balle bleue", 70.0, 0.0, 100.0));


	gui.add(restartButton.setup("restart"));

	
}

//--------------------------------------------------------------
void ofApp::update(){
	i = Integrateur();
	i.integrer(&p1);
	i.integrer(&p2);
}

void ofApp::restartButtonPressed() {
	p1.setPosition(Vecteur3D(0, 0, 0));
	p1.setVelocite(Vecteur3D(70, 70, 70));
	p1.setAcceleration(gravite);

	p2.setPosition(Vecteur3D(p2x, p2y, p2z));
	p2.setVelocite(Vecteur3D(v2x, v2y, v2z));
	p2.setAcceleration(gravite);
}
//--------------------------------------------------------------
void ofApp::draw(){
	//Draw a point at the position of particule p
	cam.begin();
	ofSetColor(255,255,255);
	ofSetColor(255,0,0);
	ofDrawArrow(glm::vec3(0,0,0), glm::vec3(300, 0, 0), 10);
	ofSetColor(0,255,0);
	ofDrawArrow(glm::vec3(0, 0, 0), glm::vec3(0, 300, 0), 10);
	ofSetColor(0,0, 255);
	ofDrawArrow(glm::vec3(0, 0, 0), glm::vec3(0, 0, 300), 10);
	ofSetColor(150,0,160);
	ofDrawSphere(p1.getPosition().getX(), p1.getPosition().getY(), p1.getPosition().getZ(), 10);
	ofSetColor(30, 150, 160);
	ofDrawSphere(p2.getPosition().getX(), p2.getPosition().getY(), p2.getPosition().getZ(), 10);

	cam.end();
	
	gui.draw();
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

