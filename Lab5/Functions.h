#pragma once
#include <vector>
#include <ctime>
#include "Classes.h"

using namespace std;

class Line2D;

template <class T1>
vector<T1> inputVector(int k){
	srand(time(0));
	vector<T1> Vectors;
	vector<float> Point1;
	vector<float> Point2;
	int d = 3;
	int nullVector = 0;

	if (typeid(T1) == typeid(Line2D)) {
		d = 2;
	}

	Vectors.resize(k);
	Point1.resize(d);
	Point2.resize(d);

	for (int i = 0; i < k; i++) {
		nullVector = 0;
		for (int j = 0; j < d; j++) {
			Point1[j] = (rand() % 10) + 1;
			Point2[j] = (rand() % 10) + 1;
			if (Point1[j] == Point2[j]) { 
				nullVector++;
			}
		}
		if (nullVector == d){ // перевірка на те чи не буде веткор нульовим
			i--;
		}
		else {
			Vectors[i] = T1(Point1, Point2);
		}
	}
	return Vectors;
}

template <class T2>
vector<T2> PerpendicularVectorsForFirst(vector<T2> Vectors) {
	vector<T2> PerpendicularVectors;

	for (int i = 1; i < Vectors.size(); i++) {
		if ((Vectors[i]).isPerpendicular(&(Vectors[0]))) {
			PerpendicularVectors.push_back(Vectors[i]);
		}
	}
	return PerpendicularVectors;
}

template <class T3>
vector<T3> PointContain(vector<T3> Vectors, vector<float> Point) {
	vector<T3> VectorsContaining;
	for (int i = 0; i < Vectors.size(); i++) {
		if (Vectors[i].isContain(Point)) {
			VectorsContaining.push_back(Vectors[i]);
		}
	}
	return VectorsContaining;
}

template <class T4>
vector<T4> PerpendicularVectorsForAll(vector<T4> Vectors) {
	
	vector<T4> Perpendicular;
	for (int i = 0; i < Vectors.size(); i++) {
		bool flag = true;
		for (int j = 0; j < Vectors.size(); j++) {
			if (!(Vectors[i].isPerpendicular(&Vectors[j]))) {
				if (i != j) { //перевірка чи не порівнюється вектор самим з собою
					flag = false;
					break;
				}
				
			}
		}
		if (flag) {
			Perpendicular.push_back(Vectors[i]);
		}
	}
	return Perpendicular;
}