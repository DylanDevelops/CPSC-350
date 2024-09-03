#include "Model.h"

Model::Model() {
    
}

Model::~Model() {

}

std::string Model::translateSingleConsonant(char consonant) {
    // Creates a temp result variable
    std::string result = "";

    // Adds to the result variable with the corresponding rules for translating a single consonant
    result += consonant;
    result += 'o';
    result += std::tolower(consonant);

    // Returns the result of the translation
    return result;
}

std::string Model::translateSingleVowel(char vowel) {
    // Creates a temp result variable
    std::string result = "";
    
    // Adds to the result variable with the corresponding rules for translating a single vowel
    result += vowel;

    // Returns the result
    return result;
}
