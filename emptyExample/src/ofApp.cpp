#include "ofApp.h"

void ofApp::initializeParticles() {
	gravite = Vecteur3D(0, -9.8, 0);
	ParticleForceRegistry registry;

	//Collisions classiques entre deux particules

	Particule p1 = Particule();
	p1.setPosition(Vecteur3D(0, 0, 0));
	p1.setVelocite(Vecteur3D(70, 70, 0));
	p1.setAcceleration(Vecteur3D(0, 0, 0));

	Particule p2 = Particule();
	//p2 goes the other way to collide with p1
	p2.setPosition(Vecteur3D(100, 0, 0));
	p2.setVelocite(Vecteur3D(-70, 70, 0));
	p2.setAcceleration(gravite);

	ParticleGravity* Pgravity = new ParticleGravity();
	registry.my_registry.push_back({&p1,Pgravity});
	registry.updateForces(0.2);

	listParticules.push_back(p1);
	listParticules.push_back(p2);
	trails.push_back(p1);
	trails.push_back(p2);

	//Collisions cables

	Particule p3 = Particule();
	p3.setPosition(Vecteur3D(-200., 0, 0));
	p3.setVelocite(Vecteur3D(70, 70, 0));
	p3.setAcceleration(gravite);

	Particule p4 = Particule();
	p4.setPosition(Vecteur3D(-140., 0, 0));
	p4.setVelocite(Vecteur3D(-70, 70, 0));
	p4.setAcceleration(gravite);

	ParticleCable cable;
	cable.setParticleCable(p3, p4, 30, 1);
	cables.push_back(cable);
	numberOfCables++;

	listParticules.push_back(p3);
	listParticules.push_back(p4);
	trails.push_back(p3);
	trails.push_back(p4);

	ground.setXYZ(0, -100, 0);
}

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFrameRate(60);
	ofBackground(230,230,250);
	restartButton.addListener(this, &ofApp::restartButtonPressed);
	addParticleButton.addListener(this, &ofApp::addParticleButtonPressed);
	
	
	initializeParticles();

	//gui.setup();
	//modify gui size
	/*gui.setSize(300, 300);
	gui.add(p2x.setup("Position (x) de la balle bleue", 0.0, -100.0, 100.0));
	gui.add(p2y.setup("Position (y) de la balle bleue", 30.0, -100.0, 100.0));
	gui.add(p2z.setup("Position (z) de la balle bleue", 0.0, -100.0, 100.0));
    gui.add(v2x.setup("Vitesse (x) de la balle bleue", 70.0, -100.0, 100.0));
	gui.add(v2y.setup("Vitesse (y) de la balle bleue", 0.0, -100.0, 100.0));
	gui.add(v2z.setup("Vitesse (z) de la balle bleue", 70.0, -100.0, 100.0));

	gui.add(addParticleButton.setup("add particle"));
	gui.add(restartButton.setup("restart"));*/

	
}

//--------------------------------------------------------------
void ofApp::update(){
	double t = ofGetLastFrameTime();

	for (int j = 0; j < listParticules.size(); j++) {
		if (collisionDetector.checkCollisionWithGround(listParticules[j], ground)) {
			//TODO
		}
	}

	// Detection des collisions classiques
	for (int m = 0; m < listParticules.size()-1; m++) {
		for (int n = m + 1; n < listParticules.size(); n++) {
			if (collisionDetector.checkCollision(listParticules[m], listParticules[n])) {

				ParticleContact sphereContact;
				sphereContact.particle[0] = &listParticules[m];
				sphereContact.particle[1] = &listParticules[n];
				sphereContact.restitution = 1;
				sphereContact.penetration = listParticules[m].getRayon() + listParticules[n].getRayon() - (listParticules[m].getPosition() - listParticules[n].getPosition()).norme();
				sphereContact.contactNormal = (listParticules[m].getPosition() - listParticules[n].getPosition())*(1 / (listParticules[m].getPosition() - listParticules[n].getPosition()).norme());
				//add sphereContact to contacts (contacts is not a vector)
				if (numberOfContacts < maxCollisions) {
					contacts.push_back(sphereContact);
					numberOfContacts++;
				}
			}
		}
	}

	for (int k = 0; k < numberOfCables; k++) {
		//addcontact
		numberOfContacts += cables[k].addContact(contacts, maxCollisions - numberOfContacts);
	}
	

	// Algorithme de résolution
	vector<ParticleContact> tempContact;
	for (int i = 0; i < numberOfContacts; i++) {
		//can you resolve the contact using reference of particules ?
		ParticleContact temp = contacts[i].resolve(t);
		tempContact.push_back(temp);
	}
	//update contacts and replace all particule 
	contacts = tempContact;
	
	//go through all particles in contacts and replace them in listParticules
	for (int i = 0; i < numberOfContacts; i++) {
		for (int j = 0; j < listParticules.size(); j++) {
			if (contacts[i].particle[0] == &listParticules[j]) {
				listParticules[j] = *contacts[i].particle[0];
			}
			if (contacts[i].particle[1] == &listParticules[j]) {
				listParticules[j] = *contacts[i].particle[1];
			}
		}
	}

	

	//clear contacts
	numberOfContacts = 0;



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
	
	listParticules.clear();
	trails.clear();
	numberOfContacts = 0;
	initializeParticles();
	//trails of particles
	
	
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
	ofSetColor(0, 0, 0);
	ofDrawBox(ground.getX(), ground.getY(), ground.getZ(), ground.width, ground.height, ground.depth);
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
		ofDrawSphere(listParticules[k].getPosition().getX(), listParticules[k].getPosition().getY(), listParticules[k].getPosition().getZ(), listParticules[k].getRayon());
	}

	


	//Draw trails of particles
	for (int i = 0; i < trails.size(); i++) {


		ofSetColor(30,150,160);

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

