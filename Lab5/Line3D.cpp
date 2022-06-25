#include "Classes.h"
using namespace std;

Line3D::Line3D() :Line() {}
Line3D::Line3D(vector<float> Point1, vector<float> Point2) : Line(Point2[0] - Point1[0], Point2[1] - Point1[1], Point2[2]-Point1[2], Point1[0], Point1[1], Point1[2]){}

void Line3D::printVec()
{
	cout << "Vector in 3D: (" << this->getVectorX() << " " << this->getVectorY() << " " << this->getVectorZ() << ")"
		<< " Point: (" << this->getPointX() << " " << this->getPointY() << " " << this->getPointZ() << ")" << endl;
}

bool Line3D::isParallel(Line* line)
{
	if (typeid(*line)==typeid(Line3D)) {
		for (int i = 0; i < 3; i++) {
			if (line->Vcords[i] != 0) {
				float coef = this->Vcords[i] / line->Vcords[i];
				for (int j = 0; j < 3; j++) {
					if (this->Vcords[j] != line->Vcords[j] * coef) {
						return false;
					}

				}
			}
		}
	}
	return true;
}

bool Line3D::isPerpendicular(Line* line)
{
	return typeid(*line) == typeid(Line3D) && this->getVectorX() * line->getVectorX() + this->getVectorY() * line->getVectorY() + this->getVectorZ() * line->getVectorZ() == 0;
}

bool Line3D::isContain(vector<float> Point)
{
	float i, j, k;
	vector<float> Vector{ (Point[0] - this->getPointX()), (Point[1] - this->getPointY()), (Point[2] - this->getPointZ()) }; 
	//знаходимо координати вектора, що проходить через точку базового вектору та точку яку перевіряємо
	i = this->getVectorY() * Vector[2] - this->getVectorZ() * Vector[1];
	j = this->getVectorX() * Vector[2] - this->getVectorZ() * Vector[0]; //векторне множення векторів
	k = this->getVectorX() * Vector[1] - this->getVectorY() * Vector[0];
	return (i == 0 && j == 0 && k == 0); //якщо резульютуючий вектор є нульовим, то вектори колінеарні, тобто задана точка належить базовому вектору
		
}
