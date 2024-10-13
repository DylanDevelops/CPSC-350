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
    CalculateVisibility();
}

void SpeakerView::DetermineDimensions() {
    std::ifstream inputFile;
    inputFile.open(inputPath);
    
    std::string line = "";
    bool inSelection = false;
    bool foundCols = false;

    if(inputFile.is_open()) {
        while(getline(inputFile, line)) {
            if(line == "BEGIN") {
                inSelection = true;
                continue;
            }

            if(line == "END") {
                break;
            }

            if(inSelection && !line.empty()) {
                numRows++;
                if(!foundCols) {
                    for(char c : line) {
                        if(c == ' ') {
                            numCols++;
                        }
                    }
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
    std::ifstream inputFile;
    inputFile.open(inputPath);

    std::string line = "";
    bool inSelection = false;

    heights = new double*[numRows];
    for(int i = 0; i < numRows; ++i) {
        heights[i] = new double[numCols];
    }

    int row = 0;

    if(inputFile.is_open()) {
        while(getline(inputFile, line)) {
            if(line == "BEGIN") {
                inSelection = true;
                continue;
            }

            if(line == "END") {
                break;
            }

            if(inSelection && !line.empty()) {
                int col = 0;
                int start = 0;
                int end = 0;

                while(end < line.length()) {
                    while(end < line.length() && line[end] != ' ') {
                        // Locate the next empty space
                        end++;
                    }

                    heights[row][col] = std::stod(line.substr(start, end - start));
                    col++;

                    end++;
                    start = end;
                }
                row++;
            }
        }
        inputFile.close();
    } else {
        std::cerr << "[ERROR] There was an issue opening the input file. Please try again!" << std::endl;
    }
}

void SpeakerView::CalculateVisibility() {
    for(int col = 0; col < numCols; ++col) {
        MonoStack<double> monoStack(numRows, 'd');
        double* visibleHeights = new double[numRows];
        int visibleCount = 0;

        for(int row = 0; row < numRows; ++row) {
            monoStack.push(heights[row][col]);
            visibleHeights[visibleCount++] = heights[row][col];
        }

        std::cout << "In column " << col << " there are " << visibleCount << " that can see. Their heights are: ";
        for(int i = 0; i < visibleCount; ++i) {
            std::cout << visibleHeights[i];
            if(i != visibleCount - 1) {
                std::cout << ", ";
            }
        }
        std::cout << " inches." << std::endl;

        delete[] visibleHeights;
    }
}