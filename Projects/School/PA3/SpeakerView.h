/** 
 * Full Name: Dylan M. Ravel
 * Student ID: 2445987
 * Chapman Email: ravel@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA3: Do You See What I See?
*/

#ifndef SPEAKER_VIEW_H
#define SPEAKER_VIEW_H

#include <iostream>

class SpeakerView {
    public:
        SpeakerView(std::string inputFile);
        ~SpeakerView();

        void Process();

    private:
        void DisplayResults();
        void DetermineDimensions();

        // variables
        std::string inputPath;
        int numRows;
        int numCols;
};

#endif