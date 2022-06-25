#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Line
{
protected:
	Line();
	Line(float vx, float vy, float vz, float px, float py, float pz);
public:
	vector<float> Vcords{ 0,0,0 }; //координати вектору
	vector<float> Pcords{ 0,0,0 }; // оординати точки
	float getVectorX();
	float getVectorY();
	float getVectorZ();
	float getPointX();
	float getPointY();
	float getPointZ();
	virtual bool isParallel(Line *line) = 0;
	virtual bool isPerpendicular(Line *line) = 0;
	virtual bool isContain(vector<float>) = 0;
	virtual void printVec() = 0;
};

class Line2D: public Line
{
public:
	Line2D();
	Line2D(vector<float> Point1, vector<float> Point2);

	bool isParallel(Line *line) override;
	bool isPerpendicular(Line *line) override;
	bool isContain(vector<float>) override;
	void printVec() override;
};

class Line3D : public Line
{
public:
	Line3D();
	Line3D(vector<float> Point1, vector<float> Point2);

	bool isParallel(Line *line) override;
	bool isPerpendicular(Line *line) override;
	bool isContain(vector<float>) override;
	void printVec() override;
};