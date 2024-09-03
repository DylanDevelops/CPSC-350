#include <iostream>
#include <fstream>
#include "Translator.h"

class FileProcessor {
    private:
        // Pointer to the Translator
        Translator* translator;

        // HTML Help
        std::string getTopOfHTMLFile();
        std::string getBottomOfHTMLFile();

        // HTML Help for the English Preview
        std::string getFormattedEnglishSentences(std::string english);
        std::string getEnglishHTMLPrefix();
        std::string getEnglishHTMLSuffix();
        std::string getEnglishFinalLineBreak();

        // HTML Help for the Robber Preview
        std::string getFormattedRobberSentences(std::string robber);
        std::string getRobberHTMLPrefix();
        std::string getRobberHTMLSuffix();
        std::string getRobberFinalLineBreak();

    public:
        // Constructors and Destructors
        FileProcessor();
        ~FileProcessor();

        // Methods
        void processFile(std::string inputFileName, std::string outputFileName);
};