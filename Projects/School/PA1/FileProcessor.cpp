#include "FileProcessor.h"

std::string FileProcessor::getTopOfHTMLFile() {
    return "<!DOCTYPE html>\n<html>\n<head>\n<title>English to Robber Translation</title>\n</head>\n<body>\n";
}

std::string FileProcessor::getBottomOfHTMLFile() {
    return "</body>\n</html>";
}

std::string FileProcessor::getFormattedEnglishSentences(std::string english) {
    std::string result = "";

    result += getEnglishHTMLPrefix() + english + getEnglishHTMLSuffix();

    return result;
}

std::string FileProcessor::getEnglishHTMLPrefix() {
    return "<p><b>";
}

std::string FileProcessor::getEnglishHTMLSuffix() {
    return "</b><br></p>\n";
}

std::string FileProcessor::getEnglishFinalLineBreak() {
    return "<p><b></b><br></p>\n";
}

std::string FileProcessor::getFormattedRobberSentences(std::string robber) {
    std::string result = "";

    result += getRobberHTMLPrefix() + robber + getRobberHTMLSuffix();

    return result;
}

std::string FileProcessor::getRobberHTMLPrefix() {
    return "<p><i>";
}

std::string FileProcessor::getRobberHTMLSuffix() {
    return "</i><br></p>\n";
}

std::string FileProcessor::getRobberFinalLineBreak() {
    return "<p><i></i><br></p>\n";
}

FileProcessor::FileProcessor() {
    translator = new Translator();
}

FileProcessor::~FileProcessor() {
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
