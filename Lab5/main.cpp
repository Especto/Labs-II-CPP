#include "Classes.h"
#include "Functions.h"
#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cout << "Input amount of 2D vectors: "; cin >> m;
    cout << "Input amount of 3D vectors: "; cin >> n;
    vector<float> Point{ 1,2 };

    vector<Line2D> Vectors2D = inputVector<Line2D>(m); //створенн€ m вектор≥в на площин≥
    vector<Line3D> Vectors3D = inputVector<Line3D>(n); //створенн€ n вектор≥в у простор≥

    

    vector<Line2D> PerpendicularVectors2D = PerpendicularVectorsForFirst<Line2D>(Vectors2D); //знаходимо вектори, що перпендикул€рн≥ першому вектору на площин≥
    vector<Line2D> VectorwithPoint = PointContain(PerpendicularVectors2D, Point); //знаходимо вектори, що мають задану точку

    vector<Line3D> PerpendicularsVectors3D = PerpendicularVectorsForAll(Vectors3D); //знаходимо вектори, що перпендикул€рн≥ вс≥м ≥ншим векторам в простор≥

    cout << "Generated vectors on the plane:\n";
    for (int i = 0; i < m; i++) {
        Vectors2D[i].printVec();
    }

    cout << "\n\nVectors perpendicular to the first vector on the plane:\n";

    for (int i = 0; i < PerpendicularVectors2D.size(); i++) {
        PerpendicularVectors2D[i].printVec();
    }


    if (VectorwithPoint.size() == 0) {
        cout << "\n\nVectors containing this point were not found..\n";
    }
    else {
        cout << "\n\nVectors containing point (" << Point[0] << " " << Point[1]<< "):\n";
        for (int i = 0; i < VectorwithPoint.size(); i++) {
            VectorwithPoint[i].printVec();
        }
    }

    
    cout << "\n\nGenerated vectors in space:\n";
    for (int i = 0; i < Vectors3D.size(); i++) {
        Vectors3D[i].printVec();
    }
    

    if (PerpendicularsVectors3D.size() == 0) {
        cout << "\n\nVectors are perpendicular to all others were not found..\n";
    }
    else {
        cout << "\n\nVectors are perpendicular to all others:\n";
        for (int i = 0; i < PerpendicularsVectors3D.size(); i++) {
            PerpendicularsVectors3D[i].printVec();
        }
    }

}