#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	gui.init();
	auto deviceList = ofxBlackmagic::Iterator::getDeviceList();

	for(auto device : deviceList) {
		auto input = shared_ptr<ofxBlackmagic::Input>(new ofxBlackmagic::Input());

		static int index = 0;
		auto mode = index++ == 0 ? bmdModeHD1080p25 : bmdModeHD1080p24;
		input->startCapture(device, mode);
		this->inputs.push_back(input);

		auto panel = gui.add(*input, device.modelName);
		panel->onDraw += [input] (ofxCvGui::DrawArguments&) {
			if (input->isFrameNew()) {
				ofxCvGui::AssetRegister.drawText("New frame", 30, 90);
			}
		};
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	for(auto input : this->inputs) {
		input->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
