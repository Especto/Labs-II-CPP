#include "Classes.h"

Line::Line() {
	this->Vcords[0] = 0;
	this->Vcords[1] = 0;
	this->Vcords[2] = 0;

	this->Pcords[0] = 0;
	this->Pcords[1] = 0;
	this->Pcords[2] = 0;
}

Line::Line(float vx, float vy, float vz, float px, float py, float pz) {
	this->Vcords[0] = vx;
	this->Vcords[1] = vy;
	this->Vcords[2] = vz;

	this->Pcords[0] = px;
	this->Pcords[1] = py;
	this->Pcords[2] = pz;
}

float Line::getVectorX() { return this->Vcords[0]; }
float Line::getVectorY() { return this->Vcords[1]; }
float Line::getVectorZ() { return this->Vcords[2]; }

float Line::getPointX() { return this->Pcords[0]; }
float Line::getPointY() { return this->Pcords[1]; }
float Line::getPointZ() { return this->Pcords[2]; }