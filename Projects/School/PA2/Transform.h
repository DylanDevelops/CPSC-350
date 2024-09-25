/** 
 * Full Name: Dylan M. Ravel and Natalie M. Eng
 * Student ID: 2445987 and 2437972
 * Chapman Email: ravel@chapman.edu and neng@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA2: Not So Super Mario Bros
*/

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <iostream>

// This class provides an object for storing x and y coordinates on the 2D plane
class Transform {
    public:
        Transform();
        Transform(int x, int y);
        void SetPosition(int x, int y);
        std::string ToString();
        int GetX();
        int GetY();
        ~Transform();

    private:
        int x;
        int y;
};

#endif