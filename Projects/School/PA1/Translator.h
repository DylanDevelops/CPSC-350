#include <iostream>
#include <cctype>
#include "Model.h"

class Translator {
    private:
        // A pointer to the Model class
        Model* translationModel;
    public:
        // Constructor and Deconstructor
        Translator();
        ~Translator();

        // Methods
        std::string translateEnglishWord(std::string englishWord);
        std::string translateEnglishSentence(std::string englishSentence);
};