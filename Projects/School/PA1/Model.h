#include <iostream>

class Model {
    private:

    public:
        // Constructor and Deconstructor
        Model();
        ~Model();

        // Methods
        std::string translateSingleConsonant(char consonant);
        std::string translateSingleVowel(char vowel);
};