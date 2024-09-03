#include "Translator.h"

Translator::Translator() {
    // Creates the pointer in the constructor
    translationModel = new Model();
}

Translator::~Translator() {
    // Deletes the pointer in the deconstructor
    delete translationModel;
}

std::string Translator::translateEnglishWord(std::string englishWord) {
    // Creates a temp variable to use
    std::string result = "";

    // Loops through every letter in the word
    for(int i = 0; i < englishWord.size(); i++) {
        // Checks if it is a vowel, consonant, or punctuation/other character
        switch ((char) std::tolower(englishWord[i])) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                // If it is a vowel, translate using the vowel translation method from the model class
                result += translationModel->translateSingleVowel(englishWord[i]);
                break;

            case 'b':
            case 'c':
            case 'd':
            case 'f':
            case 'g':
            case 'h':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
                // If it is a consonant, translate using the consonant translation method from the model class
                result += translationModel->translateSingleConsonant(englishWord[i]);
                break;

            default:
                // If it is punctuation/other, just keep it as is.
                result += englishWord[i];
                break;
        }
    }

    // Returns the translated word
    return result;
}

std::string Translator::translateEnglishSentence(std::string englishSentence) {
    // Creates two variables to use temporarily
    std::string result = "";
    std::string currentWord = "";

    // Loops through every letter in the english sentence
    for(int i = 0; i < englishSentence.size(); i++) {
        if(englishSentence[i] == ' ') {
            // If the loop comes across the space, it knows current word is complete and it sends it to be translated
            result += translateEnglishWord(currentWord) += ' ';

            // Resets current word to empty
            currentWord = "";
        } else {
            if(i == englishSentence.size() - 1) {
                // If it is the last letter in the sentence, translate the current word
                result += translateEnglishWord(currentWord);
            } else {
                // If it is just a random letter, keep adding letters to current word
                currentWord += englishSentence[i];
            }
        }
    }

    // // if the current word is not empty at the very end, it will translate that last bit.
    // if(!currentWord.empty()) {
    //     result += translateEnglishWord(currentWord);
    // }

    // Return the translated sentence
    return result;
}
