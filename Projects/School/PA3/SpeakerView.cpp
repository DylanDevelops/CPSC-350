/** 
 * Full Name: Dylan M. Ravel
 * Student ID: 2445987
 * Chapman Email: ravel@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA3: Do You See What I See?
*/

#include "SpeakerView.h"

SpeakerView::SpeakerView(std::string inputFile) {
    inputPath = inputFile;
    numRows = 0;
    numCols = 0;
    heights = nullptr;
}

SpeakerView::~SpeakerView() {
    for(int i = 0; i < numRows; ++i) {
        delete[] heights[i];
    }

    delete[] heights;
}

void SpeakerView::Process() {
    DetermineDimensions();
    ReadHeights();
    CalculateAndDisplayVisibility();
}

void SpeakerView::DetermineDimensions() {
    // Create file stream
    std::ifstream inputFile;
    inputFile.open(inputPath);
    
    // Temp variables to use while accessing
    std::string line = "";
    bool inSelection = false;
    bool foundCols = false;

    if(inputFile.is_open()) {
        while(getline(inputFile, line)) {
            if(line == "BEGIN") {
                // Skip the begin line
                inSelection = true;
                continue;
            }

            if(line == "END") {
                // Break out if you hit the end of the file
                break;
            }

            if(inSelection && !line.empty()) {
                // For every row iterate numRows
                numRows++;
                if(!foundCols) {
                    // For the first column iterate numCols
                    for(char c : line) {
                        if(c == ' ') {
                            numCols++;
                        }
                    }
                    // Since we only need to do this once, set this value to true
                    foundCols = true;
                }
            }
        }
        inputFile.close();
    } else {
        std::cerr << "[ERROR] There was an issue opening the input file. Please try again!" << std::endl;
    }
}

void SpeakerView::ReadHeights() {
    // Create file stream
    std::ifstream inputFile;
    inputFile.open(inputPath);

    // Create temp variables to use while accessing
    std::string line = "";
    bool inSelection = false;

    // Setup 2D array with all the heights that are read in
    heights = new double*[numRows];
    for(int i = 0; i < numRows; ++i) {
        heights[i] = new double[numCols];
    }

    int row = 0;

    if(inputFile.is_open()) {
        while(getline(inputFile, line)) {
            if(line == "BEGIN") {
                // If start of file skip line
                inSelection = true;
                continue;
            }

            if(line == "END") {
                // If end of file break out of loop
                break;
            }

            if(inSelection && !line.empty()) {
                // If you are within BEGIN and END and the line is not empty
                int col = 0;
                int start = 0;
                int end = 0;

                // Parse the line to extract heights
                while(end < line.length()) {
                    // Find the end of the current number
                    while(end < line.length() && line[end] != ' ') {
                        end++;
                    }

                    // Convert the substring to a double and store it in the heights 2D array
                    heights[row][col] = std::stod(line.substr(start, end - start));
                    col++;

                    // Move to the next number
                    end++;
                    start = end;
                }
                // Account for the last row
                row++;
            }
        }
        inputFile.close();
    } else {
        std::cerr << "[ERROR] There was an issue opening the input file. Please try again!" << std::endl;
    }
}

void SpeakerView::CalculateAndDisplayVisibility() {
    for(int col = 0; col < numCols; ++col) {
        // Declare temp variables to be used
        MonoStack<double> monoStack(numRows, 'd');
        double* visibleHeights = new double[numRows];
        int visibleCount = 0;

        // Traverse the column from bottom to top
        for(int row = numRows - 1; row >= 0; --row) {
            // Pop elements from the stack that are less than or equal to the current height
            while(!monoStack.isEmpty() && monoStack.peek() <= heights[row][col]) {
                monoStack.pop();
            }
            // Push the current height onto the stack
            monoStack.push(heights[row][col]);
        }

        // Pop all elements from the stack to get the visible heights
        while(!monoStack.isEmpty()) {
            visibleHeights[visibleCount++] = monoStack.pop();
        }

        // Display the results
        std::cout << "In column " << col << " there are " << visibleCount << " that can see. Their heights are: ";
        for(int i = 0; i < visibleCount; ++i) {
            std::cout << visibleHeights[i];
            if(i != visibleCount - 1) {
                std::cout << ", ";
            }
        }
        std::cout << " inches." << std::endl;

        // Delete the dynamically allocated memory
        delete[] visibleHeights;
    }
}