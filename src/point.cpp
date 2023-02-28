#include "point.hpp"
#include <cstdlib>
#  include <iostream>
#include <cmath>
using namespace std;

Point::Point(){
    x = 0;
    y = 0;
    z = 0;
}
Point::Point(int x, int y, int z){
    this->x = x;
    this->y = y;
    this->z = z;
}
Point::~Point(){}

int Point::getX(){
    return x;
}
int Point::getY(){
    return y;
}
int Point::getZ(){
    return z;
}

void Point::setX(int x){
    this->x = x;
}
void Point::setY(int y){
    this->y = y;
}
void Point::setZ(int z){
    this->z = z;
}

void Point::operator=(const Point& other){
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
}

double Point::getDistance(Point other){
    int dX = pow(abs(this->x - other.getX()), 2);
    int dY = pow(abs(this->y - other.getY()), 2);
    int dZ = pow(abs(this->z - other.getZ()), 2);
    double d = sqrt(dX + dY + dZ);

    return d;
}

void Point::printPoint(){
    cout << "Coordinates - X: " << x << " | Y: " << y << " | Z: " << z << endl;
}
