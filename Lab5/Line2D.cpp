#include "Classes.h"
#include <stdio.h>
using namespace std;

Line2D::Line2D() :Line() {}
Line2D::Line2D(vector<float> Point1, vector<float> Point2) :Line(Point2[0]-Point1[0], Point2[1] - Point1[1], 0, Point1[0], Point1[1], 0){}
void Line2D::printVec() {
	cout << "Vector in 2D: (" << this->getVectorX() << " " << this->getVectorY() << ")" 
		<< " Point: (" << this->getPointX() << " " << this->getPointY() <<")"<< endl;
}

bool Line2D::isParallel(Line *line)
{
	if (typeid(*line) == typeid(Line2D)) {
		for (int i = 0; i < 2; i++) {
			if (line->Vcords[i] != 0) {
				float coef = this->Vcords[i] / line->Vcords[i];
				for (int j = 0; j < 2; j++) {
					if (this->Vcords[j] != line->Vcords[j] * coef) {
						return false;
					}
					
				}
			}
		}
	}
	return true;
}

bool Line2D::isPerpendicular(Line* line)
{
	return typeid(*line) == typeid(Line2D) && this->getVectorX() * line->getVectorX() + this->getVectorY() * line->getVectorY() == 0;
}

bool Line2D::isContain(vector<float> Point)
{
	return this->getVectorY() * (Point[0] - this->getPointX()) == this->getVectorX() * (Point[1] - this->getPointY());
}
