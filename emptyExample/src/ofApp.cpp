#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){


	ofBackground(230,230,250);
	restartButton.addListener(this, &ofApp::restartButtonPressed);
	addParticleButton.addListener(this, &ofApp::addParticleButtonPressed);
	gravite = Vecteur3D(0, -9.8, 0);
	Particule p1 = Particule();
	p1.setPosition(Vecteur3D(0,0,0));
	p1.setVelocite(Vecteur3D(70,70,70));
	p1.setAcceleration(gravite);

	listParticules.push_back(p1);
	trails.push_back(p1);
	
	//trails of particles
	
	

	gui.setup();
	//modify gui size
	gui.setSize(300, 300);
	gui.add(p2x.setup("Position (x) de la balle bleue", 0.0, -100.0, 100.0));
	gui.add(p2y.setup("Position (y) de la balle bleue", 30.0, -100.0, 100.0));
	gui.add(p2z.setup("Position (z) de la balle bleue", 0.0, -100.0, 100.0));
    gui.add(v2x.setup("Vitesse (x) de la balle bleue", 70.0, -100.0, 100.0));
	gui.add(v2y.setup("Vitesse (y) de la balle bleue", 0.0, -100.0, 100.0));
	gui.add(v2z.setup("Vitesse (z) de la balle bleue", 70.0, -100.0, 100.0));

	gui.add(addParticleButton.setup("add particle"));
	gui.add(restartButton.setup("restart"));

	
}

//--------------------------------------------------------------
void ofApp::update(){
	double t = ofGetLastFrameTime();
	i= Integrateur();
	for (int k = 0; k < listParticules.size(); k++) {
		i.integrer(&listParticules[k],t);
		trails.push_back(listParticules[k]);
	}
	

	

}

void ofApp::restartButtonPressed() {
	/*p1.setPosition(Vecteur3D(0, 0, 0));
	p1.setVelocite(Vecteur3D(70, 70, 70));
	p1.setAcceleration(gravite);*/
	
	for (int i = 0; i < listParticules.size(); i++) {
		listParticules[i].setPosition(Vecteur3D(0, 0, 0));
		listParticules[i].setVelocite(Vecteur3D(70, 70, 70));
		listParticules[i].setAcceleration(gravite);
	}
	

	//trails of particles
	trails.clear();
	
}

void ofApp::addParticleButtonPressed() {
	Particule p2 = Particule();

	double randomX = ofRandom(-100, 100);
	double randomY = ofRandom(-100, 100);
	double randomZ = ofRandom(-100, 100);
	double randomVX = ofRandom(-100, 100);
	double randomVY = ofRandom(-100, 100);
	double randomVZ = ofRandom(-100, 100);
	p2.setPosition(Vecteur3D(randomX, randomY, randomZ));
	p2.setVelocite(Vecteur3D(randomVX, randomVY, randomVZ));

	p2.setAcceleration(gravite);
	listParticules.push_back(p2);
	trails.push_back(p2);
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
	/*ofSetColor(150,0,160);
	ofDrawSphere(p1.getPosition().getX(), p1.getPosition().getY(), p1.getPosition().getZ(), 10);*/
	for (int k = 0; k < listParticules.size(); k++) {
		ofSetColor(150+k, 0, 160);
		ofDrawSphere(listParticules[k].getPosition().getX(), listParticules[k].getPosition().getY(), listParticules[k].getPosition().getZ(), 10);
	}



	//Draw trails of particles
	for (int i = 0; i < trails.size(); i++) {
		if (i%2==0) {
			ofSetColor(150,0, 160);
		}
		else {
			ofSetColor(30,150,160);
		}
		ofDrawSphere(trails[i].getPosition().getX(), trails[i].getPosition().getY(), trails[i].getPosition().getZ(), 1);
	}


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

