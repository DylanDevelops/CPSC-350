/** 
 * Full Name: Dylan M. Ravel
 * Student ID: 2445987
 * Chapman Email: ravel@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA3: Do You See What I See?
*/

#include <iostream>
#include "SpeakerView.h"

int main(int argc, char* argv[]) {
    if(argc != 2) {
        std::cerr << "[ERROR] Incorrect Usage of Program! Please try again as so: \"" << argv[0] << " INPUT_FILE_NAME.txt\"" << std::endl;
        return 1;
    }

    // Creates a Speaker View
    SpeakerView speakerView = SpeakerView(argv[1]);

    // Processes SpeakerView
    speakerView.Process();

    return 0;
}