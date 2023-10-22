#include "ofApp.h"

void ofApp::initializeParticles() {
	gravite = Vecteur3D(0, -9.8, 0);

	//Collisions classiques entre deux particules

	Particule p1 = Particule();
	p1.setPosition(Vecteur3D(0, 0, 0));
	p1.setVelocite(Vecteur3D(70, 70, 0));
	p1.setAcceleration(Vecteur3D(0, 0, 0));
	p1.setId(1);
	p1.setColor(ofColor::blue);
	numberOfParticles++;
	Particule p2 = Particule();
	//p2 goes the other way to collide with p1
	p2.setPosition(Vecteur3D(100, 0, 0));
	p2.setVelocite(Vecteur3D(-70, 70, 0));
	p2.setAcceleration(gravite);
	p2.setId(2);
	p2.setColor(ofColor::blue);
	numberOfParticles++;
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
	p3.setVelocite(Vecteur3D(90, 150, 0));
	p3.setAcceleration(gravite);
	p3.setId(3);
	p3.setColor(ofColor::green);
	numberOfParticles++;
	Particule p4 = Particule();
	p4.setPosition(Vecteur3D(-60., 0, 0));
	p4.setVelocite(Vecteur3D(-60, 70, 100));
	p4.setAcceleration(gravite);
	p4.setId(4);
	p4.setColor(ofColor::green);
	numberOfParticles++;

	ParticleCable cable;
	cable.setParticleCable(p3, p4, 200, 0.4);
	cables.push_back(cable);
	numberOfCables++;

	Particule p5 = Particule();
	p5.setPosition(Vecteur3D(-100, 0, 0));
	p5.setVelocite(Vecteur3D(90, 30, 0));
	p5.setAcceleration(gravite);
	p5.setId(5);
	p5.setColor(ofColor::green);

	ParticleCable cable2;
	cable2.setParticleCable(p3, p5, 100, 0.4);
	cables.push_back(cable2);
	numberOfCables++;

	Particule p8 = Particule();
	p8.setPosition(Vecteur3D(30., 5, 30));
	p8.setVelocite(Vecteur3D(5, 5, 0));
	p8.setAcceleration(gravite);
	p8.setId(8);
	p8.setColor(ofColor::yellow);

	Particule p9 = Particule();
	p9.setPosition(Vecteur3D(40., 5, 40));
	p9.setVelocite(Vecteur3D(-5, 5, 0));
	p9.setAcceleration(gravite);
	p9.setId(9);
	p9.setColor(ofColor::yellow);




	registry.my_registry.push_back({ &p1,Pgravity });
	ParticleDrag* Pdrag = new ParticleDrag();
	registry.my_registry.push_back({ &p1,Pdrag });

	ParticleSpring* Pspring8 = new ParticleSpring(&p9, 3, 10);
	ParticleSpring* Pspring9 = new ParticleSpring(&p8, 3, 10);
	registry.my_registry.push_back({ &p8, Pspring8 });
	registry.my_registry.push_back({ &p9, Pspring9 });
	registry.my_registry.push_back({ &p8, Pgravity });
	registry.my_registry.push_back({ &p9, Pgravity });

	registry.updateForces(0.2);

	listParticules.push_back(p1);
	listParticules.push_back(p2);
	trails.push_back(p1);
	trails.push_back(p2);

	listParticules.push_back(p3);
	listParticules.push_back(p4);
	listParticules.push_back(p5);
	trails.push_back(p3);
	trails.push_back(p4);
	trails.push_back(p5);


	//Collisions tiges

	Particule p6 = Particule();
	p6.setPosition(Vecteur3D(-300, 20, 0));
	p6.setVelocite(Vecteur3D(30, 100, 0));
	p6.setAcceleration(gravite);
	p6.setId(6);
	p6.setColor(ofColor::red);
	numberOfParticles++;

	Particule p7 = Particule();
	p7.setPosition(Vecteur3D(-400, 0, 0));
	p7.setVelocite(Vecteur3D(100, 200, 20));
	p7.setAcceleration(gravite);
	p7.setId(7);
	p7.setColor(ofColor::red);

	ParticleRod rod;
	rod.setParticleRod(p6, p7, 100);
	rods.push_back(rod);
	numberOfRods++;

	listParticules.push_back(p6);
	listParticules.push_back(p7);
	trails.push_back(p6);
	trails.push_back(p7);



	listParticules.push_back(p5);
	listParticules.push_back(p6);
	trails.push_back(p5);
	trails.push_back(p6);

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

	//Collision cables

	for (int k = 0; k < numberOfCables; k++) {
		//addcontact
		numberOfContacts += cables[k].addContact(contacts, maxCollisions - numberOfContacts);
	}
	
	//Collision rods

	for (int l = 0; l < numberOfRods; l++) {
		//addcontact
		numberOfContacts += rods[l].addContact(contacts, maxCollisions - numberOfContacts);
	}

	// Algorithme de résolution
	vector<ParticleContact> tempContact;
	for (int i = 0; i < numberOfContacts; i++) {
		int first = 0;
		int second = 0;
		//get the two particles of contacts from listParticules
		
		for (int j = 0; j < listParticules.size(); j++) {
			if (contacts[i].particle[0]->getId() == listParticules[j].getId()) {
				first = j;
			}
			if (contacts[i].particle[1]->getId() == listParticules[j].getId()) {
				second = j;
			}
		}
		

		ParticleContact temp = contacts[i].resolve(t);
		tempContact.push_back(temp);
		//replace in listParticles
		listParticules[first] = *temp.particle[0];
		listParticules[second] = *temp.particle[1];

	}
	//update contacts and replace all particule 
	
	

	
	//replace particles in cables with new particles
	for (int i = 0; i < numberOfCables; i++) {
		for (int j = 0; j < listParticules.size(); j++) {
			if (cables[i].getParticleCable1().getId() == listParticules[j].getId()) {
				cables[i].setParticleCable1(listParticules[j]);
			}
			if (cables[i].getParticleCable2().getId() == listParticules[j].getId()) {
				cables[i].setParticleCable2(listParticules[j]);
			}
		}
	}

	//replace particles in rods with new particles
	for (int i = 0; i < numberOfRods; i++) {
		for (int j = 0; j < listParticules.size(); j++) {
			if (rods[i].getParticleRod1().getId() == listParticules[j].getId()) {
				rods[i].setParticleRod1(listParticules[j]);
			}
			if (rods[i].getParticleRod2().getId() == listParticules[j].getId()) {
				rods[i].setParticleRod2(listParticules[j]);
			}
		}
	}

	

	//clear contacts
	numberOfContacts = 0;
	contacts.clear();
	tempContact.clear();

	registry.updateForces(0.2);


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
		ofSetColor(listParticules[k].getColor());
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

