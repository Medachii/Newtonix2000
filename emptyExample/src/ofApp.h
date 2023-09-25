#pragma once
#include "ofMain.h"
//#include "ofxGui/src/ofxGui.h"
//#include "ofParameter.h"
#include "ofxGui.h"
#include "../Vecteur3D.h"
#include "../Particule.h"
#include "../Integrateur.h"

class ofApp : public ofBaseApp{
	public:
		
		//list of particles
		

		vector<Particule> listParticules;
		vector<Particule> trails;
		

		Vecteur3D gravite;
		double t;
		Integrateur i;

		ofEasyCam cam;


		//create trails of particles
		

	 


		void setup();
		void update();
		void draw();
		
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
