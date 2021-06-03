#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(1.5);
	ofEnableDepthTest();

	this->line.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);

	this->face.clear();
	this->line.clear();

	auto len = 50;
	auto noise_param = ofRandom(1000);
	for (int param = 0; param < 200; param += 1) {

		int height = ofMap(ofNoise(noise_param, param * 0.05 - ofGetFrameNum() * 0.03), 0, 1, 10, ofMap(param, 0, 500, 30, 100));

		vector<glm::vec3> vertices;
		vertices.push_back(glm::vec3(this->make_point(len, param), 0));
		vertices.push_back(glm::vec3(this->make_point(len, param + 1), 0));
		vertices.push_back(glm::vec3(this->make_point(len, param + 1), height));
		vertices.push_back(glm::vec3(this->make_point(len, param), height));

		this->face.addVertices(vertices);
		this->line.addVertices(vertices);

		this->face.addIndex(this->face.getNumVertices() - 1); this->face.addIndex(this->face.getNumVertices() - 2); this->face.addIndex(this->face.getNumVertices() - 3);
		this->face.addIndex(this->face.getNumVertices() - 1); this->face.addIndex(this->face.getNumVertices() - 3); this->face.addIndex(this->face.getNumVertices() - 4);

		this->line.addIndex(this->line.getNumVertices() - 1); this->line.addIndex(this->line.getNumVertices() - 2);
		this->line.addIndex(this->line.getNumVertices() - 2); this->line.addIndex(this->line.getNumVertices() - 3);
		this->line.addIndex(this->line.getNumVertices() - 3); this->line.addIndex(this->line.getNumVertices() - 4);
		this->line.addIndex(this->line.getNumVertices() - 4); this->line.addIndex(this->line.getNumVertices() - 1);

		for (int i = 0; i < vertices.size(); i++) {

			this->face.addColor(ofColor(239, 30, 30));
			this->line.addColor(ofColor(39));
		}

		len += 1;
	}

	len = 50;
	noise_param = ofRandom(1000);
	for (int param = 50; param < 250; param += 1) {

		int height = ofMap(ofNoise(noise_param, param * 0.05 + ofGetFrameNum() * 0.03), 0, 1, 10, ofMap(param, 0, 500, 30, 100));

		vector<glm::vec3> vertices;
		vertices.push_back(glm::vec3(this->make_point(len, param), 0));
		vertices.push_back(glm::vec3(this->make_point(len, param + 1), 0));
		vertices.push_back(glm::vec3(this->make_point(len, param + 1), height));
		vertices.push_back(glm::vec3(this->make_point(len, param), height));

		this->face.addVertices(vertices);
		this->line.addVertices(vertices);

		this->face.addIndex(this->face.getNumVertices() - 1); this->face.addIndex(this->face.getNumVertices() - 2); this->face.addIndex(this->face.getNumVertices() - 3);
		this->face.addIndex(this->face.getNumVertices() - 1); this->face.addIndex(this->face.getNumVertices() - 3); this->face.addIndex(this->face.getNumVertices() - 4);

		this->line.addIndex(this->line.getNumVertices() - 1); this->line.addIndex(this->line.getNumVertices() - 2);
		this->line.addIndex(this->line.getNumVertices() - 2); this->line.addIndex(this->line.getNumVertices() - 3);
		this->line.addIndex(this->line.getNumVertices() - 3); this->line.addIndex(this->line.getNumVertices() - 4);
		this->line.addIndex(this->line.getNumVertices() - 4); this->line.addIndex(this->line.getNumVertices() - 1);

		for (int i = 0; i < vertices.size(); i++) {

			this->face.addColor(ofColor(239));
			this->line.addColor(ofColor(39));
		}

		len += 1;
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	ofSetColor(239);
	this->face.draw();

	ofSetColor(39);
	this->line.drawWireframe();

	this->cam.end();
}

//--------------------------------------------------------------
glm::vec2 ofApp::make_point(int len, int param) {

	param = param % 100;
	if (param < 25) {

		return glm::vec2(ofMap(param, 0, 25, -len * 0.5, len * 0.5), -len * 0.5);
	}
	else if (param < 50) {

		return glm::vec2(len * 0.5, ofMap(param, 25, 50, -len * 0.5, len * 0.5));
	}
	else if (param < 75) {

		return glm::vec2(ofMap(param, 50, 75, len * 0.5, -len * 0.5), len * 0.5);
	}
	else {

		return glm::vec2(-len * 0.5, ofMap(param, 75, 100, len * 0.5, -len * 0.5));
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}