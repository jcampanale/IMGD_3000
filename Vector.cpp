#include "Vector.h"
#include "LogManager.h"
using namespace df;

Vector::Vector(float xPos, float yPos){
    setX(xPos);
    setY(yPos);
}

Vector::Vector() {
    setX(0);
    setY(0);
}

float Vector::getMagnitude() const{
    float mag = sqrt((x*x) + (y*y));
    return mag;
}

float Vector::getX() const{
    return x;
}

void Vector::setX(float newX){
    x = newX;
}

float Vector::getY() const{
    return y;
}

void Vector::setY(float newY){
    y = newY;
}

void Vector::scale(float s) {
    x = x * s;
    y = y * s;
}

void Vector::normalize() {
    float length = getMagnitude();
    if (length > 0) {
        x = x / length;
        y = y / length;
    }
}

Vector Vector::operator+(const Vector& other) const {
    Vector returnVector; 
    float newX = this->getX() + other.getX();
    float newY = this->getY() + other.getY();
    returnVector.setX(newX);
    returnVector.setY(newY);
    return returnVector;
}

