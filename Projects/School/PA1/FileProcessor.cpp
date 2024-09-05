#include "FileProcessor.h"

std::string FileProcessor::getTopOfHTMLFile() {
    // returns what the top of the html file should be
    return "<!DOCTYPE html>\n<html>\n<head>\n<title>English to Robber Translation</title>\n</head>\n<body>\n";
}

std::string FileProcessor::getBottomOfHTMLFile() {
    // Returns what the bottom of the html file should be
    return "</body>\n</html>";
}

std::string FileProcessor::getFormattedEnglishSentences(std::string english) {
    // Inserts the english sentence in between the corresponding prefix and suffix
    std::string result = "";

    result += getEnglishHTMLPrefix() + english + getEnglishHTMLSuffix();

    return result;
}

std::string FileProcessor::getEnglishHTMLPrefix() {
    // Gets what comes right before english sentences
    return "<p><b>";
}

std::string FileProcessor::getEnglishHTMLSuffix() {
    // Gets what comes right after english sentences
    return "</b><br></p>\n";
}

std::string FileProcessor::getEnglishFinalLineBreak() {
    // Gets the final line break at the end of the english sentences
    return "<p><b></b><br></p>\n";
}

std::string FileProcessor::getFormattedRobberSentences(std::string robber) {
    // Inserts the robber sentence in between the corresponding prefix and suffix
    std::string result = "";

    result += getRobberHTMLPrefix() + robber + getRobberHTMLSuffix();

    return result;
}

std::string FileProcessor::getRobberHTMLPrefix() {
    // Gets what comes right before robber sentences
    return "<p><i>";
}

std::string FileProcessor::getRobberHTMLSuffix() {
    // Gets what comes right after robber sentences
    return "</i><br></p>\n";
}

std::string FileProcessor::getRobberFinalLineBreak() {
    // Gets the final line break at the end of the robber sentences
    return "<p><i></i><br></p>\n";
}

FileProcessor::FileProcessor() {
    // Creates a pointer to the Translator class
    translator = new Translator();
}

FileProcessor::~FileProcessor() {
    // Deletes the translator pointer
    delete translator;
}

void FileProcessor::processFile(std::string inputFileName, std::string outputFileName) {
    // Reads from the input file
    std::ifstream inputFile;
    inputFile.open(inputFileName);

    if(inputFile.is_open()) {
        // Creates variables to store full sentences to later be outputted
        std::string englishSentences = "";
        std::string robberSentences = "";

        // Creates temp variable to store each line
        std::string line = "";
        
        // Goes line by line
        while(getline(inputFile, line)) {
            // Saves formatted lines to corresponding variables
            englishSentences += getFormattedEnglishSentences(line);
            robberSentences += getFormattedRobberSentences(translator->translateEnglishSentence(line));
        }

        // Close input file
        inputFile.close();

        // formats the text that will be sent to the output file
        std::string outputFormatted = getTopOfHTMLFile();
        outputFormatted += englishSentences;
        outputFormatted += getEnglishFinalLineBreak();
        outputFormatted += robberSentences;
        outputFormatted += getRobberFinalLineBreak();
        outputFormatted + getBottomOfHTMLFile();

        // Creates the output file stream
        std::ofstream outputFile;
        outputFile.open(outputFileName);

        if(outputFile.is_open()) {
            // Outputs to the output file
            outputFile << outputFormatted;

            // Closes the output file
            outputFile.close();
        } else {
            // Error handling for output file
            std::cerr << "[ERROR] There was an issue opening the output file. Please try again!" << std::endl;
        }
    } else {
        // Error handling for input file
        std::cerr << "[ERROR] There was an issue opening the input file. Please try again!" << std::endl;
    }

    return;
}
