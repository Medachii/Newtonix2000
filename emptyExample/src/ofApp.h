#pragma once
#include "ofMain.h"
//#include "ofxGui/src/ofxGui.h"
//#include "ofParameter.h"
#include "ofxGui.h"
#include "../Vecteur3D.h"
#include "../Particule.h"
#include "../Integrateur.h"
#include "../Collision.h"
#include "../Ground.h"
#include "../ParticleContactGenerator.h"
#include "../ParticleCable.h"
#include "../ParticleForceGenerator.h"
#include "../ParticleGravity.h"

class ofApp : public ofBaseApp{
	public:
		
		//list of particles
		const int maxCollisions = 100;

		vector<Particule> listParticules;
		vector<Particule> trails;
		

		Vecteur3D gravite;
		double t;
		Integrateur i;

		ofEasyCam cam;

		Collision collisionDetector;
		ParticleContact contacts[100];
		ParticleCable cables[100];
		int numberOfContacts=0;
		int numberOfCables = 0;

		Ground ground;

		

	 


		void setup();
		void update();
		void draw();
		void initializeParticles();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void restartButtonPressed();
		void addParticleButtonPressed();

		



		ofxPanel gui;

		ofxFloatSlider p2x;
		ofxFloatSlider p2y;
		ofxFloatSlider p2z;
		ofxFloatSlider v2x;
		ofxFloatSlider v2y;
		ofxFloatSlider v2z;

		ofxButton restartButton;
		ofxButton addParticleButton;
};
