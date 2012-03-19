#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	if(player.loadMovie("movie.mov"))
	//{
	player.setLoopState(OF_LOOP_NORMAL);
	player.play();
	tex.allocate(player.getWidth(),player.getHeight(),GL_RGB);
	//}
	player.setLoopState(OF_LOOP_NORMAL);
	frameByframe = false;
}

//--------------------------------------------------------------
void testApp::update(){
	//if(player.isLoaded())
	{
			player.update();
		tex.loadData(player.getPixels(),player.getWidth(),player.getHeight(),GL_RGB);
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	tex.draw(0,0);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	switch(key){
	case 'f':
		frameByframe=!frameByframe;
		player.setPaused(frameByframe);
		break;
	case OF_KEY_LEFT:
		player.previousFrame();
		break;
	case OF_KEY_RIGHT:
		player.nextFrame();
		break;
	case '0':
		player.firstFrame();
		break;
	case 'l':
		player.stop();
		player.close();
		player.loadMovie("movie.mov");
	player.setLoopState(OF_LOOP_NORMAL);
	player.play();
	tex.allocate(player.getWidth(),player.getHeight(),GL_RGB);
			break;

	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	//if(!frameByframe){
	//	int width = ofGetWidth();
	//	float pct = (float)x / (float)width;
	//	float speed = (2 * pct - 1) * 5.0f;
	//	player.setSpeed(speed);
	//}
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	//if(!frameByframe){
	//	int width = ofGetWidth();
	//	float pct = (float)x / (float)width;
	//	player.setPosition(pct);
	//}
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	//if(!frameByframe){
	//	player.setPaused(true);
	//}
	int width = ofGetWidth();
	float pct = (float)x / (float)width;
	player.setPosition(pct);
}


//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	//if(!frameByframe){
	//	player.setPaused(false);
	//}
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}