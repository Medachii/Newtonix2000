#include "ofApp.h"



void ofApp::initializeParticles() {
	gravite = Vecteur3D(0, -9.8, 0);
	ParticleGravity* Pgravity = new ParticleGravity();
	ParticleDrag* Pdrag = new ParticleDrag();
	//Collisions classiques entre deux particules
	//*numberOfParticles = 0;


	Particule* p1 = new Particule(numberOfParticles,Vecteur3D(0, 0, 0), Vecteur3D(70, 70, 0), Vecteur3D(0, 0, 0), 10, 1, ofColor::blue);
	Particule* p2 = new Particule(numberOfParticles,Vecteur3D(0, 0, 50), Vecteur3D(70, 70, 0), Vecteur3D(0, 0, 0), 10, 1, ofColor::blue);
	Particule* p3 = new Particule(numberOfParticles,Vecteur3D(0, 0, 100), Vecteur3D(70, 30, 0), Vecteur3D(0, 0, 0), 10, 1, ofColor::yellow); //spring avec p4
	Particule* p4 = new Particule(numberOfParticles,Vecteur3D(0, 0, 150), Vecteur3D(-70, -20, 0), Vecteur3D(0, 0, 0), 10, 1, ofColor::yellow); //spring avec p3
	Particule* p5 = new Particule(numberOfParticles,Vecteur3D(-50, 0, 0), Vecteur3D(30, 70, 0), Vecteur3D(0, 0, 0), 10, 1, ofColor::blue);


	

	//Particule p6 = Particule(6, Vecteur3D(-300, 20, 0), Vecteur3D(30, 100, 20), Vecteur3D(0, 0, 0));
	//p6.setColor(ofColor::red);
	//numberOfParticles++;
	//
	//Particule p7 = Particule(7,Vecteur3D(-400, 0, 0),Vecteur3D(50, 70, 20), Vecteur3D(0, 0, 0));
	//p7.setColor(ofColor::red);
	//numberOfParticles++;

	//Particule p8 = Particule(8,Vecteur3D(10., 5, 30),Vecteur3D(5, 5, 0),Vecteur3D(0,0,0));
	//p8.setColor(ofColor::yellow);
	//numberOfParticles++;

	//Particule p9 = Particule(9, Vecteur3D(40., 5, 70), Vecteur3D(-5, 5, 0),Vecteur3D(0,0,0));
	//p9.setColor(ofColor::yellow);
	//numberOfParticles++;

	//Particule p10 = Particule(10, Vecteur3D(-20, 20, 60), Vecteur3D(0, -20, 0),Vecteur3D(0,0,0));
	//p10.setColor(ofColor::purple);
	//numberOfParticles++;
	//
	//Particule p11 = Particule(11, Vecteur3D(-210, 0, -210), Vecteur3D(0, 0, 0), Vecteur3D(0, 0, 0));
	//p11.setColor(ofColor::hotPink);
	//numberOfParticles++;


	//ParticleCable cable;
	//cable.setParticleCable(p3, p4, 200, 0.4);
	//cables.push_back(cable);
	//numberOfCables++;

	//ParticleCable cable2;
	//cable2.setParticleCable(p3, p5, 100, 0.4);
	//cables.push_back(cable2);
	//numberOfCables++;

	//ParticleCable cable3;
	//cable3.setParticleCable(p4, p8, 300, 0.5);
	//cables.push_back(cable3);
	//numberOfCables++;

	//ParticleRod rod;
	//rod.setParticleRod(p6, p7, 100);
	//rods.push_back(rod);
	//numberOfRods++;



	//ParticleSpring* Pspring8 = new ParticleSpring(&p9, 1, 10);
	////ParticleSpring* Pspring9 = new ParticleSpring(&p8, 1, 10);
	//springs.push_back(*Pspring8);

	//ParticleSpring* Pspring4 = new ParticleSpring(&p6, 1, 100);
	//springs.push_back(*Pspring4);
	//ParticleSpring* Pspring6 = new ParticleSpring(&p4, 1, 100);
	//springs.push_back(*Pspring6);

	//ParticleAnchorSpring* anchor = new ParticleAnchorSpring(Vecteur3D(-200, 0, -200), 3, 30);
	//anchorsLink.push_back(std::make_pair(p11, Vecteur3D(-200, 0, -200)));


	//ParticleForceRegistry::ParticleForceRegistration* pfr = new ParticleForceRegistry::ParticleForceRegistration();
	//pfr->particule = p1;
	//pfr->fg = Pgravity;
	//registry->my_registry.push_back(*pfr);

	ParticleSpring* Pspring4 = new ParticleSpring(p4, 1, 30);
	ParticleSpring* Pspring3 = new ParticleSpring(p3, 1, 30);
	ParticleAnchorSpring* anchor = new ParticleAnchorSpring(Vecteur3D(0, 0, 0), 1, 60);

	registry->my_registry.push_back({p1,Pgravity});
	registry->my_registry.push_back({ p1,Pdrag });
	registry->my_registry.push_back({ p2,Pgravity });
	registry->my_registry.push_back({ p3,Pgravity });
	registry->my_registry.push_back({ p4,Pgravity });
	registry->my_registry.push_back({ p3,Pspring4 });
	registry->my_registry.push_back({ p4,Pspring3 });
	registry->my_registry.push_back({ p5,Pgravity });
	registry->my_registry.push_back({ p5,Pdrag });
	registry->my_registry.push_back({ p5,anchor });
	//registry->my_registry.push_back({ &p6,Pgravity });
	//registry->my_registry.push_back({ &p7,Pgravity });
	//registry->my_registry.push_back({ &p8, Pspring8 });
	////registry.my_registry.push_back({ &p9, Pspring9 });
	//registry->my_registry.push_back({ &p8, Pgravity });
	//registry->my_registry.push_back({ &p9, Pgravity });
	//registry->my_registry.push_back({ &p10,Pgravity });
	//registry->my_registry.push_back({ &p11,Pgravity });
	//registry->my_registry.push_back({ &p11,anchor });


	//registry2.push_back(std::make_pair(p1, Pgravity));
	//registry2.push_back(std::make_pair(p1, Pdrag));
	//registry2.push_back(std::make_pair(p2, Pgravity));
	//registry2.push_back(std::make_pair(p3, Pgravity));
	//registry2.push_back(std::make_pair(p4, Pgravity));

	//registry2.push_back(std::make_pair(p5, Pgravity));
	//registry2.push_back(std::make_pair(p6, Pgravity));
	//registry2.push_back(std::make_pair(p7, Pgravity));
	//registry2.push_back(std::make_pair(p8, Pgravity));
	//registry2.push_back(std::make_pair(p9, Pgravity));
	//registry2.push_back(std::make_pair(p8, Pdrag));
	//registry2.push_back(std::make_pair(p9, Pdrag));
	//registry2.push_back(std::make_pair(p8, Pspring8));
	////registry2.push_back(std::make_pair(p9, Pspring9));

	//registry2.push_back(std::make_pair(p10, Pgravity));
	//registry2.push_back(std::make_pair(p11, Pgravity));
	//registry2.push_back(std::make_pair(p11, anchor));

	//registry.updateForces(0.2);


	listParticules.push_back(p1);
	listParticules.push_back(p2);
	listParticules.push_back(p3);
	listParticules.push_back(p4);
	listParticules.push_back(p5);
	//listParticules.push_back(p6);
	//listParticules.push_back(p7);
	//listParticules.push_back(p8);
	//listParticules.push_back(p9);
	//listParticules.push_back(p10);
	//listParticules.push_back(p11);

	
	trails.push_back(*p1);
	trails.push_back(*p2);
	trails.push_back(*p3);
	trails.push_back(*p4);
	trails.push_back(*p5);
	//trails.push_back(p6);
	//trails.push_back(p7);
	//trails.push_back(p8);
	//trails.push_back(p9);
	//trails.push_back(p10)
	//trails.push_back(p11);


	//ground.setXYZ(0, -100, 0);
}



//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(230, 230, 250);
	//restartButton.addListener(this, &ofApp::restartButtonPressed);
	//addParticleButton.addListener(this, &ofApp::addParticleButtonPressed);
	

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
void ofApp::update() {
	if (paused) {
		return;
	}
	t = ofGetLastFrameTime();

	//cout << "Number of particles : " << listParticules.size() << endl;


	registry->updateForces(t);




	//for (int m = 0; m < listParticules.size() - 1; m++) {
	//	for (int n = m + 1; n < listParticules.size(); n++) {
	//		if (collisionDetector.checkCollision(listParticules[m], listParticules[n])) {

	//			ParticleContact sphereContact;
	//			sphereContact.particle[0] = listParticules[m];
	//			sphereContact.particle[1] = listParticules[n];
	//			sphereContact.restitution = 0.8;
	//			sphereContact.penetration = listParticules[m]->getRayon() + listParticules[n]->getRayon() - (listParticules[m]->getPosition() - listParticules[n]->getPosition()).norme();
	//			sphereContact.contactNormal = (listParticules[m]->getPosition() - listParticules[n]->getPosition()) * (1 / (listParticules[m]->getPosition() - listParticules[n]->getPosition()).norme());
	//			//add sphereContact to contacts (contacts is not a vector)
	//			if (numberOfContacts < maxCollisions) {
	//				contacts[numberOfContacts] = sphereContact;
	//				numberOfContacts++;
	//			}
	//		}
	//	}
	//}

	//Collision cables

	//for (int k = 0; k < numberOfCables; k++) {
	//	//addcontact
	//	numberOfContacts += cables[k].addContact(contacts, maxCollisions - numberOfContacts);
	//}

	////Collision rods

	//for (int l = 0; l < numberOfRods; l++) {
	//	//addcontact
	//	numberOfContacts += rods[l].addContact(contacts, maxCollisions - numberOfContacts);
	//}

	//// Algorithme de résolution
	//vector<ParticleContact> tempContact;
	//for (int i = 0; i < numberOfContacts; i++) {
	//	int first = 0;
	//	int second = 0;
	//	//get the two particles of contacts from listParticules

	//	for (int j = 0; j < listParticules.size(); j++) {
	//		if (contacts[i].particle[0]->getId() == listParticules[j].getId()) {
	//			first = j;
	//		}
	//		if (contacts[i].particle[1]->getId() == listParticules[j].getId()) {
	//			second = j;
	//		}
	//	}


	//	ParticleContact temp = contacts[i].resolve(t);
	//	tempContact.push_back(temp);
	//	//replace in listParticles
	//	listParticules[first] = *temp.particle[0];
	//	listParticules[second] = *temp.particle[1];

	//}
	//update contacts and replace all particule 




	//replace particles in cables with new particles
	//for (int i = 0; i < numberOfCables; i++) {
	//	for (int j = 0; j < listParticules.size(); j++) {
	//		if (cables[i].getParticleCable1().getId() == listParticules[j].getId()) {
	//			cables[i].setParticleCable1(listParticules[j]);
	//		}
	//		if (cables[i].getParticleCable2().getId() == listParticules[j].getId()) {
	//			cables[i].setParticleCable2(listParticules[j]);
	//		}
	//	}
	//}

	////replace particles in rods with new particles
	//for (int i = 0; i < numberOfRods; i++) {
	//	for (int j = 0; j < listParticules.size(); j++) {
	//		if (rods[i].getParticleRod1().getId() == listParticules[j].getId()) {
	//			rods[i].setParticleRod1(listParticules[j]);
	//		}
	//		if (rods[i].getParticleRod2().getId() == listParticules[j].getId()) {
	//			rods[i].setParticleRod2(listParticules[j]);
	//		}
	//	}
	//}



	////clear contacts
	//numberOfContacts = 0;
	//contacts.clear();
	//tempContact.clear();


	i = Integrateur();
	for (int k = 0; k < listParticules.size(); k++) {
		i.integrer(listParticules[k], t);
		trails.push_back(*listParticules[k]);
	}

	//replace all velocity of particles in cables and rods and registry2
	//for (int i = 0; i < listParticules.size(); i++) {
	//	for (int j = 0; j < cables.size(); j++) {
	//		if (listParticules[i].getId() == cables[j].getParticleCable1().getId()) {
	//			cables[j].setParticleCable1(listParticules[i]);
	//		}
	//		if (listParticules[i].getId() == cables[j].getParticleCable2().getId()) {
	//			cables[j].setParticleCable2(listParticules[i]);
	//		}
	//	}

	//	for (int k = 0; k < rods.size(); k++) {
	//		if (listParticules[i].getId() == rods[k].getParticleRod1().getId()) {
	//			rods[k].setParticleRod1(listParticules[i]);
	//		}
	//		if (listParticules[i].getId() == rods[k].getParticleRod2().getId()) {
	//			rods[k].setParticleRod2(listParticules[i]);
	//		}
	//	}

	//	for (int l = 0; l < registry2.size(); l++) {
	//		if (listParticules[i].getId() == registry2[l].first.getId()) {
	//			registry2[l].first = listParticules[i];
	//		}
	//	}
	//	//for springs
	//	for (int m = 0; m < springs.size(); m++) {
	//		if (listParticules[i].getId() == springs[m].getOther().getId()) {
	//			springs[m].setOther(&listParticules[i]);
	//		}
	//	}

	//	for (int n = 0; n < anchorsLink.size(); n++) {
	//		if (listParticules[i].getId() == anchorsLink[n].first.getId()) {
	//			anchorsLink[n].first = listParticules[i];
	//		}
	//	}

	//}




}

void ofApp::restartButtonPressed() {


	//listParticules.clear();
	//trails.clear();
	//numberOfContacts = 0;
	//contacts.clear();
	//registry->my_registry.clear();
	//cables.clear();
	//rods.clear();
	//springs.clear();
	//anchorsLink.clear();
	//numberOfParticles = 0;
	//numberOfCables = 0;
	//numberOfRods = 0;
	//numberOfSprings = 0;

	//initializeParticles();





}

void ofApp::addParticleButtonPressed() {
	/*numberOfParticles++;
	Particule pr = Particule();

	double randomX = ofRandom(-70, 100);
	double randomY = ofRandom(-70, 100);
	double randomZ = ofRandom(-70, 100);
	double randomVX = ofRandom(-100, 100);
	double randomVY = ofRandom(-100, 100);
	double randomVZ = ofRandom(-100, 100);
	pr.setPosition(Vecteur3D(randomX, randomY, randomZ));
	pr.setVelocite(Vecteur3D(randomVX, randomVY, randomVZ));
	pr.setId(numberOfParticles);
	numberOfParticles++;


	registry2.push_back(std::make_pair(pr, new ParticleGravity()));
	listParticules.push_back(pr);
	trails.push_back(pr);*/
}

void ofApp::addCableButtonPressed() {
	/*numberOfParticles++;
	Particule pone = Particule();
	Particule ptwo = Particule();
	double randomX = ofRandom(-70, 100);
	double randomX2 = ofRandom(-70, 100);
	double randomY = ofRandom(-70, 100);
	double randomY2 = ofRandom(-70, 100);
	double randomZ = ofRandom(-70, 100);
	double randomZ2 = ofRandom(-70, 100);
	double randomVX = ofRandom(-100, 100);
	double randomVX2 = ofRandom(-100, 100);
	double randomVY = ofRandom(-100, 100);
	double randomVY2 = ofRandom(-100, 100);
	double randomVZ = ofRandom(-100, 100);
	double randomVZ2 = ofRandom(-100, 100);
	pone.setPosition(Vecteur3D(randomX, randomY, randomZ));
	pone.setVelocite(Vecteur3D(randomVX, randomVY, randomVZ));
	pone.setId(numberOfParticles);
	numberOfParticles++;
	ptwo.setPosition(Vecteur3D(randomX2, randomY2, randomZ2));
	ptwo.setVelocite(Vecteur3D(randomVX2, randomVY2, randomVZ2));
	ptwo.setId(numberOfParticles);
	numberOfParticles++;
	ParticleCable cable;
	double randomCable = ofRandom(50, 300);
	cable.setParticleCable(pone, ptwo, randomCable, 0.4);
	cables.push_back(cable);
	numberOfCables++;
	registry2.push_back(std::make_pair(pone, new ParticleGravity()));
	registry2.push_back(std::make_pair(ptwo, new ParticleGravity()));
	listParticules.push_back(pone);
	listParticules.push_back(ptwo);
	trails.push_back(pone);
	trails.push_back(ptwo);*/

}


void ofApp::addRodButtonPressed() {
	//numberOfParticles++;
	////create two particles with random position and velocity that will be linked by a rod
	//Particule pone = Particule();
	//Particule ptwo = Particule();
	//double randomX = ofRandom(-70, 100);
	//double randomX2 = ofRandom(-70, 100);
	//double randomY = ofRandom(-70, 100);
	//double randomY2 = ofRandom(-70, 100);
	//double randomZ = ofRandom(-70, 100);
	//double randomZ2 = ofRandom(-70, 100);
	//double randomVX = ofRandom(-100, 100);
	//double randomVX2 = ofRandom(-100, 100);
	//double randomVY = ofRandom(-100, 100);
	//double randomVY2 = ofRandom(-100, 100);
	//double randomVZ = ofRandom(-100, 100);
	//double randomVZ2 = ofRandom(-100, 100);
	//pone.setPosition(Vecteur3D(randomX, randomY, randomZ));
	//pone.setVelocite(Vecteur3D(randomVX, randomVY, randomVZ));
	//pone.setId(numberOfParticles);
	//numberOfParticles++;
	//ptwo.setPosition(Vecteur3D(randomX2, randomY2, randomZ2));
	//ptwo.setVelocite(Vecteur3D(randomVX2, randomVY2, randomVZ2));
	//ptwo.setId(numberOfParticles);
	//numberOfParticles++;
	//ParticleRod rod;
	//rod.setParticleRod(pone, ptwo, 100);
	//rods.push_back(rod);
	//numberOfRods++;
	//registry2.push_back(std::make_pair(pone, new ParticleGravity()));
	//registry2.push_back(std::make_pair(ptwo, new ParticleGravity()));
	//listParticules.push_back(pone);
	//listParticules.push_back(ptwo);
	//trails.push_back(pone);
	//trails.push_back(ptwo);

}


//--------------------------------------------------------------
void ofApp::draw() {
	//Draw a point at the position of particule p
	cam.begin();

	/*ofSetColor(0, 0, 0);
	ofDrawBox(ground.getX(), ground.getY(), ground.getZ(), ground.width, ground.height, ground.depth);*/
	ofSetColor(255, 255, 255);
	ofSetColor(255, 0, 0);
	ofDrawArrow(glm::vec3(0, 0, 0), glm::vec3(300, 0, 0), 10);
	ofSetColor(0, 255, 0);
	ofDrawArrow(glm::vec3(0, 0, 0), glm::vec3(0, 300, 0), 10);
	ofSetColor(0, 0, 255);
	ofDrawArrow(glm::vec3(0, 0, 0), glm::vec3(0, 0, 300), 10);
	ofSetColor(0, 255, 255);
	ofDrawArrow(glm::vec3(0, -125, 0), glm::vec3(0, -75, 0), 10);
	/*ofSetColor(150,0,160);
	ofDrawSphere(p1.getPosition().getX(), p1.getPosition().getY(), p1.getPosition().getZ(), 10);*/


	//Draw trails of particles
	for (int i = 0; i < trails.size(); i++) {


		ofSetColor(30, 150, 160);

		ofDrawSphere(trails[i].getPosition().getX(), trails[i].getPosition().getY(), trails[i].getPosition().getZ(), 1);
	}

	for (int k = 0; k < listParticules.size(); k++) {
		ofSetColor(listParticules[k]->getColor());
		ofDrawSphere(listParticules[k]->getPosition().getX(), listParticules[k]->getPosition().getY(), listParticules[k]->getPosition().getZ(), listParticules[k]->getRayon());
	}

	//Draw a line between the two particles
	/*ofSetColor(0, 255, 0);
	for (int i = 0; i < numberOfCables; i++) {
		ofDrawLine(cables[i].getParticleCable1().getPosition().getX(), cables[i].getParticleCable1().getPosition().getY(), cables[i].getParticleCable1().getPosition().getZ(), cables[i].getParticleCable2().getPosition().getX(), cables[i].getParticleCable2().getPosition().getY(), cables[i].getParticleCable2().getPosition().getZ());
	}
	ofSetColor(255, 0, 0);
	for (int i = 0; i < numberOfRods; i++) {
		ofDrawLine(rods[i].getParticleRod1().getPosition().getX(), rods[i].getParticleRod1().getPosition().getY(), rods[i].getParticleRod1().getPosition().getZ(), rods[i].getParticleRod2().getPosition().getX(), rods[i].getParticleRod2().getPosition().getY(), rods[i].getParticleRod2().getPosition().getZ());
	}
	ofSetColor(0, 0, 255);
	for (int i = 0; i < anchorsLink.size(); i++) {
		ofDrawLine(anchorsLink[i].first.getPosition().getX(), anchorsLink[i].first.getPosition().getY(), anchorsLink[i].first.getPosition().getZ(), anchorsLink[i].second.getX(), anchorsLink[i].second.getY(), anchorsLink[i].second.getZ());
	}*/



	cam.end();

	//gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	
	//quand on appuie sur espace, mets un pause la boucle
	if (key == ' ') {
		paused = !paused;
	}


	if (key == OF_KEY_UP) {
		for (int i = 0; i < listParticules.size(); i++) {
			listParticules[i]->setVelocite(listParticules[i]->getVelocite() + Vecteur3D(0, 50, 0));
		}
	}

	if (key == OF_KEY_DOWN) {
		for (int i = 0; i < listParticules.size(); i++) {
			listParticules[i]->setVelocite(listParticules[i]->getVelocite() + Vecteur3D(0, -50, 0));
		}
	}

	if (key == OF_KEY_LEFT) {
		for (int i = 0; i < listParticules.size(); i++) {
			listParticules[i]->setVelocite(listParticules[i]->getVelocite() + Vecteur3D(-50, 0, 0));
		}
	}

	if (key == OF_KEY_RIGHT) {
		for (int i = 0; i < listParticules.size(); i++) {
			listParticules[i]->setVelocite(listParticules[i]->getVelocite() + Vecteur3D(50, 0, 0));
		}
	}

	if (key == 'r') {
		restartButtonPressed();
	}

	if (key == 'a') {
		addParticleButtonPressed();
	}

	if (key == 'c') {
		addCableButtonPressed();
	}

	if (key == 'e') {
		addRodButtonPressed();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

