from classes import *
from functions import *

def main():
    m = int(input("Input amount of 2D vectors: "))
    n = int(input("Input amount of 3D vectors: "))
    Point = [1, 2]

    Vectors2D = inputVector(m, 2)
    Vectors3D = inputVector(n, 3)

    PerpendicularVectors2D = PerpendicularVectorsForFirst(Vectors2D)
    VectorwithPoint = PointContain(PerpendicularVectors2D, Point)

    PerpendicularsVectors3D = PerpendicularVectorsForAll(Vectors3D);

    print("Generated vectors on the plane:")
    for i in range(len(Vectors2D)):
        Vectors2D[i].printVec()

    if len(PerpendicularVectors2D) == 0:
        print(f"\n\nVectors perpendicular to the first vector on the plane not found..")
    else:
        print("\n\nVectors perpendicular to the first vector on the plane:")

    for i in range(len(PerpendicularVectors2D)):
        PerpendicularVectors2D[i].printVec()

    if len(VectorwithPoint) == 0 :
        print("\n\nVectors containing this point were not found..")
    else:
        print(f"\n\nVectors containing point ({Point[0]} {Point[1]}):")
        for i in range(len(VectorwithPoint)):
            VectorwithPoint[i].printVec()
    
    print("\n\nGenerated vectors in space:")
    for i in range(len(Vectors3D)):
        Vectors3D[i].printVec()

    if len(PerpendicularsVectors3D) == 0:
        print("\n\nVectors are perpendicular to all others were not found..")
    else:
        print("\n\nVectors are perpendicular to all others:")
        for i in range(len(PerpendicularsVectors3D)):
            PerpendicularsVectors3D[i].printVec()
main()