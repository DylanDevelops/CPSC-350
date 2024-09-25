/** 
 * Full Name: Dylan M. Ravel and Natalie M. Eng
 * Student ID: 2445987 and 2437972
 * Chapman Email: ravel@chapman.edu and neng@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA2: Not So Super Mario Bros
*/

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Transform.h"

class GameObject {
    public:
        GameObject();
        ~GameObject();

        // methods
        Transform GetTransform();
        void SetTransform(int xPos, int yPos);
        char GetChar();

    private:
        Transform transform;

    protected:
        char charValue;
};

#endif