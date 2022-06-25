import random
from classes import *

def inputVector(k, measure):
	Vectors = []
	if measure == 2:
		Point1 = [0, 0]
		Point2 = [0, 0]
	else:
		Point1 = [0, 0, 0]
		Point2 = [0, 0, 0]
	nullVector = 0
	for i in range(k):
		nullVector = 0
		for j in range(measure):
			Point1[j] =random.randint(0, 10)
			Point2[j] = random.randint(0, 10)
			if Point1[j] == Point2[j]: 
				nullVector +=1
		if nullVector == measure:
			i -= 1
		else:
			if measure == 2:
				Vectors.append(Line2D(Point1, Point2))
			else:
				Vectors.append(Line3D(Point1, Point2))
	return Vectors

def PerpendicularVectorsForFirst(Vectors):
	PerpendicularVectors = []
	for i in range(len(Vectors)):
		if Vectors[i].isPerpendicular(Vectors[0]):
			PerpendicularVectors.append(Vectors[i])
	return PerpendicularVectors



def PointContain(Vectors: list, Point: list):
	VectorsContaining = []
	for i in range(len(Vectors)):
		if Vectors[i].isContain(Point):
			VectorsContaining.append(Vectors[i])
	return VectorsContaining


def PerpendicularVectorsForAll(Vectors: list):
	Perpendicular = []
	for i in range(len(Vectors)):
		flag = True
		for j in range(len(Vectors)):
			if not Vectors[i].isPerpendicular(Vectors[j]):
				if i != j:
					flag = False
					break
		if (flag):
			Perpendicular.append(Vectors[i])
	return Perpendicular