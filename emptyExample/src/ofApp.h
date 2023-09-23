#pragma once
#include "ofMain.h"
#include "../Vecteur3D.h"
#include "../Particule.h"
#include "../Integrateur.h"
class ofApp : public ofBaseApp{
	public:
		
		Particule p;
		Vecteur3D gravite;
		double t;
		Integrateur i;


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
};
