/************************************************************
************************************************************/
#include "ofApp.h"

/************************************************************
************************************************************/
/******************************
******************************/
ofApp::ofApp(){

}

/******************************
******************************/
ofApp::~ofApp(){
	if(Gui_Global)	delete Gui_Global;
	if(fp_Log)		fclose(fp_Log);
}

/******************************
******************************/
void ofApp::exit(){

}

/******************************
******************************/
void ofApp::setup(){
	/********************
	********************/
	ofSetBackgroundAuto(true);
	
	ofSetWindowTitle("DMX test");
	ofSetVerticalSync(true);
	ofSetFrameRate(30);
	ofSetWindowShape(MAIN_WINDOW_W, MAIN_WINDOW_H);
	ofSetEscapeQuitsApp(false);
	
	/********************
	********************/
	ofSeedRandom();
	
	ofEnableAntiAliasing();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA); // OF_BLENDMODE_DISABLED, OF_BLENDMODE_ALPHA, OF_BLENDMODE_ADD
	
	/********************
	********************/
	setup_Gui();
	
	DmxSystem.setup();
}

/******************************
description
	memoryを確保は、app start後にしないと、
	segmentation faultになってしまった。
******************************/
void ofApp::setup_Gui()
{
	/********************
	********************/
	Gui_Global = new GUI_GLOBAL;
	Gui_Global->setup("param", "gui.xml", 10, 10);
}

/******************************
******************************/
void ofApp::update(){
	now = ofGetElapsedTimeMillis();
	
	Process_GUI__DmxCommand();
	DmxSystem.update(now);
}

/******************************
******************************/
void ofApp::Process_GUI__DmxCommand(){
	if(Gui_Global->Command_DMX_test)				DmxSystem.set_State(now, DMX_SYSTEM::STATE::Test);
	else if(Gui_Global->Command_DMX_init_immediate)	DmxSystem.set_State(now, DMX_SYSTEM::STATE::InitialImmediate);
	else if(Gui_Global->Command_DMX_init_Fade)		DmxSystem.set_State(now, DMX_SYSTEM::STATE::InitialFade);
	else if(Gui_Global->Command_DMX_wait_Kime)		DmxSystem.set_State(now, DMX_SYSTEM::STATE::wait_Kime);
	else if(Gui_Global->Command_DMX_Kime)			DmxSystem.set_State(now, DMX_SYSTEM::STATE::Kime);
	else if(Gui_Global->Command_DMX_Figure8)		DmxSystem.set_State(now, DMX_SYSTEM::STATE::Figure8);
	else if(Gui_Global->Command_DMX_Coloring)		DmxSystem.set_State(now, DMX_SYSTEM::STATE::Coloring);
	
	Gui_Global->Command_DMX_test = false;
	Gui_Global->Command_DMX_init_immediate = false;
	Gui_Global->Command_DMX_init_Fade = false;
	Gui_Global->Command_DMX_wait_Kime = false;
	Gui_Global->Command_DMX_Kime = false;
	Gui_Global->Command_DMX_Figure8 = false;
	Gui_Global->Command_DMX_Coloring = false;
}

/******************************
******************************/
void ofApp::draw(){
	/********************
	********************/
	ofBackground(20);
	
	ofSetColor(255);
	DmxSystem.SendDmx();
	
	/********************
	********************/
	if(Gui_Global->b_Disp)	Gui_Global->gui.draw();
}

/******************************
******************************/
void ofApp::keyPressed(int key){
	switch(key){
		case 'd':
			Gui_Global->b_Disp = !Gui_Global->b_Disp;
			break;
			
		case 'm':
			Gui_Global->gui.minimizeAll();
			break;
	}
}

/******************************
******************************/
void ofApp::keyReleased(int key){

}

/******************************
******************************/
void ofApp::mouseMoved(int x, int y ){

}

/******************************
******************************/
void ofApp::mouseDragged(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mousePressed(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseReleased(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseEntered(int x, int y){

}

/******************************
******************************/
void ofApp::mouseExited(int x, int y){

}

/******************************
******************************/
void ofApp::windowResized(int w, int h){

}

/******************************
******************************/
void ofApp::gotMessage(ofMessage msg){

}

/******************************
******************************/
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
