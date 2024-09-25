/**
 * Full Name: Dylan M. Ravel and Natalie M. Eng
 * Student ID: 2445987 and 2437972
 * Chapman Email: ravel@chapman.edu and neng@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA2: Not So Super Mario Bros
*/

#include "Transform.h"

Transform::Transform() {
    this->x = 0;
    this->y = 0;
}

Transform::Transform(int x, int y) {
    this->x = x;
    this->y = y;
}

Transform::~Transform() {
    
}

void Transform::SetPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

std::string Transform::ToString() {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

int Transform::GetX() {
    return x;
}

int Transform::GetY() {
    return y;
}