from abc import ABC, abstractmethod

class Line(ABC):
    def __init__(self, vx = 0, vy = 0 , vz = 0, px = 0, py = 0, pz = 0):
        self.vector = [vx, vy, vz]
        self.__point = [px, py, pz]
    @property
    def getVectorX(self): return self.vector[0]
    @property
    def getVectorY(self): return self.vector[1]
    @property
    def getVectorZ(self): return self.vector[2]
    @property
    def getPointX(self): return self.__point[0]
    @property
    def getPointY(self): return self.__point[1]
    @property
    def getPointZ(self): return self.__point[2]

    @abstractmethod
    def isParallel(self, obj: 'Line'):
        pass
    @abstractmethod
    def isPerpendicular(self, obj: 'Line'):
        pass
    @abstractmethod
    def isContain(self, Point: list):
        pass
    @abstractmethod
    def printVec(self):
        pass


class Line2D(Line):
    def __init__ (self, Point1 : list, Point2 : list):
        super().__init__(Point2[0]-Point1[0], Point2[1]-Point1[1], 0, Point1[0], Point1[1], 0)

    def isParallel(self, obj : 'Line2D'):
        for i in range(2):
            if obj.vector[i] != 0 :
                coef = self.vector[i] / obj.vector[i];
                for j in range(2):
                    if self.vector[j] != obj.vector[j] * coef:
                        return False
        return True

    def isPerpendicular(self, obj : 'Line2D'):
        return self.getVectorX * obj.getVectorX + self.getVectorY * obj.getVectorY == 0

    def isContain(self, Point: list):
        return self.getVectorY * (Point[0] - self.getPointX) == self.getVectorX * (Point[1] - self.getPointY)

    def printVec(self):
        print(f"Vector in 2D: ({self.getVectorX} {self.getVectorY}) Point: ({self.getPointX} {self.getPointY})")

class Line3D(Line):
    def __init__ (self, Point1 : list, Point2 : list):
        super().__init__(Point2[0]-Point1[0], Point2[1]-Point1[1], Point2[2]-Point1[1], Point1[0], Point1[1], Point1[2])

    def isParallel(self, obj : 'Line3D'):
        for i in range(3):
            if obj.vector[i] != 0 :
                coef = self.vector[i] / obj.vector[i];
                for j in range(3):
                    if self.vector[j] != obj.vector[j] * coef:
                        return False
        return True

    def isPerpendicular(self, obj : 'Line3D'):
        x = self.getVectorX * obj.getVectorX
        y = self.getVectorY * obj.getVectorY
        z = self.getVectorZ * obj.getVectorZ
        return x + y + z == 0

    def isContain(self, Point: list):
        Vector = [Point[0] - self.getPointX, Point[1] -self.getPointY, Point[2] - self.getPointZ()]
        i = self.getVectorY * Vector[2] - self.getVectorZ * Vector[1]
        j = self.getVectorX * Vector[2] - self.getVectorZ * Vector[0]
        k = self.getVectorX * Vector[1] - self.getVectorY * Vector[0]
        return (i == 0 and j == 0 and k == 0)

    def printVec(self):
        print(f"Vector in 3D: ({self.getVectorX} {self.getVectorY} {self.getVectorZ}) Point: ({self.getPointX} {self.getPointY} {self.getPointZ})")

