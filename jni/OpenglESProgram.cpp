#include "OpenglESProgram.h"

const char* OpenglESProgram::vertexString = "a_position";
const char* OpenglESProgram::matrixString = "u_Matrix";
const char* OpenglESProgram::textureCoordinatesString = "a_TextureCoordinates";
const char* OpenglESProgram::textureUnitString = "u_TextureUnit";
const char* OpenglESProgram::colorString = "u_color";
const char* OpenglESProgram::alphaString = "u_alpha";
const char* OpenglESProgram::inVec4String = "u_inVec4";
const char* OpenglESProgram::showVec4String = "u_showVec4";
const char* OpenglESProgram::changeMatrixString = "u_changeMatrix";

const int OpenglESProgram::R_INDEX = 0;
const int OpenglESProgram::G_INDEX = 1;
const int OpenglESProgram::B_INDEX = 2;	
const int OpenglESProgram::A_INDEX = 3;

OpenglESProgram::OpenglESProgram() {
	bgColor[R_INDEX] = 0.8f;
	bgColor[G_INDEX] = 0.8f;
	bgColor[B_INDEX] = 0.8f;
	bgColor[A_INDEX] = 0.0f;
	Matrix::setLookAtM(mVMatrix, 0, 0, 0, 0.1f, 0, 0, 0, 0, 1, 0);
}


OpenglESProgram::~OpenglESProgram() {
	
}

void OpenglESProgram::onSurfaceCreated() {
	glClearColor(bgColor[R_INDEX], bgColor[G_INDEX], bgColor[B_INDEX], bgColor[A_INDEX]);
}

void OpenglESProgram::onSurfaceChanged(int width, int height) {
	glViewport(0, 0, width, height);
	//投影
	float aspectRatio = width > height ?
		(float) width / (float) height :
		(float) height / (float) width;
	float halfW = 1, halfH = 1;
	if (width > height) {
		halfW = aspectRatio;
	} else {
		halfH = aspectRatio;
	}
	Matrix::orthoM(mProjMatrix, 0, -halfW, halfW, -halfH, halfH, -1, 1);
	Matrix::multiplyMM(mMVPMatrix, 0, mProjMatrix, 0, mVMatrix, 0);
}

void OpenglESProgram::onDrawFrame() {
	glClear(GL_COLOR_BUFFER_BIT);
}

void OpenglESProgram::setBgColor(float r, float g, float b, float alpha) {
	bgColor[R_INDEX] = r;
	bgColor[G_INDEX] = g;
	bgColor[B_INDEX] = b;
	bgColor[A_INDEX] = alpha;
}