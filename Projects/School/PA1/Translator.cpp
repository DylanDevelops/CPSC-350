#include "Translator.h"

Translator::Translator()
{
    translationModel = new Model();
}

Translator::~Translator()
{
    delete translationModel;
}

std::string Translator::translateEnglishWord(std::string englishWord)
{
    std::string result = "";

    for(int i = 0; i < englishWord.size(); i++) {
        switch ((char) std::tolower(englishWord[i])) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
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
                result += translationModel->translateSingleConsonant(englishWord[i]);
                break;

            default:
                result += englishWord[i];
                break;
        }
    }

    return result;
}

std::string Translator::translateEnglishSentence(std::string englishSentence)
{
    std::string result = "";
    std::string currentWord = "";

    for(int i = 0; i < englishSentence.size(); i++) {
        if(englishSentence[i] == ' ') {
            result += translateEnglishWord(currentWord) += ' ';
            currentWord = "";
        } else {
            if(i == englishSentence.size() - 1) {
                result += translateEnglishWord(currentWord);
            } else {
                currentWord += englishSentence[i];
            }
        }
    }

    return result;
}
