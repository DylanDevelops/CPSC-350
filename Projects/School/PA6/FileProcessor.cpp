/** 
 * Full Name: Dylan M. Ravel
 * Student ID: 2445987
 * Chapman Email: ravel@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA6: Spanning the Gamut
*/

#include "FileProcessor.h"
#include "WGraph.h"

FileProcessor::FileProcessor() {

}

FileProcessor::FileProcessor(std::string inputFile) {
    fileName = inputFile;
}

FileProcessor::~FileProcessor() {

}

void FileProcessor::ProcessInputFile() {
    std::ifstream inputFile;
    inputFile.open(fileName);

    if (!inputFile.is_open()) {
        std::cerr << "[ERROR] - There was an issue opening the input file. Please try again!" << std::endl;
        return;
    }

    int size = 0;
    inputFile >> size;
    
    WGraph<double> graph(size);

    for (int i = 0; i < size; ++i) {
        graph.addVertex(i);
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            double weight;
            inputFile >> weight;
            if (weight != 0.0) {
                std::cout << "Adding edge: " << weight << std::endl;
                graph.addEdge(i, j, (int)weight);
            }
        }
    }

    std::string line;
    while (getline(inputFile, line)) {
        if (line == "END") break;
    }

    inputFile.close();
    graph.calcMST();
}