#include "Model.h"

Model::Model()
{
    
}

Model::~Model()
{

}

std::string Model::translateSingleConsonant(char consonant)
{
    std::string result = "";

    result += consonant;
    result += 'o';
    result += std::tolower(consonant);

    return result;
}

std::string Model::translateSingleVowel(char vowel)
{
    std::string result = "";
    
    result += vowel;

    return result;
}
