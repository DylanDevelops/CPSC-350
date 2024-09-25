/**
 * Full Name: Dylan M. Ravel and Natalie M. Eng
 * Student ID: 2445987 and 2437972
 * Chapman Email: ravel@chapman.edu and neng@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA2: Not So Super Mario Bros
*/

#include "GameObject.h"

GameObject::GameObject() {
    charValue = 'x';
}

GameObject::~GameObject() {

}

Transform GameObject::GetTransform() {
    return transform;
}

void GameObject::SetTransform(int xPos, int yPos) {
    transform.SetPosition(xPos, yPos);
}

char GameObject::GetChar() {
    return charValue;
}