
/*
    Program to Read Student Names and Grades from grades.txt and Write Passed and Failed Students 
    to Separate Files (passed.txt, failed.txt)

    MUST HAVE A grades.txt file with the format:
    Elia: 67
    Mark: 23
    Erik: 100
    Ella: 98
    ...

*/


#include <iostream>   // Include the iostream library for input/output operations
#include <fstream>    // Include the fstream library to handle file input/output
#include <string>     // Include the string library to use the std::string class

int main() {
    std::ifstream inFile("grades.txt");     // Open the input file "grades.txt"
    std::ofstream passedFile("passed.txt");// Open the output file "passed.txt"
    std::ofstream failedFile("failed.txt");// Open the output file "failed.txt"
    std::string line;                       // Declare a string variable to store each line from the input file

    // Check if the input file was successfully opened
    if (inFile.is_open() && passedFile.is_open() && failedFile.is_open()) {
        // Read each line from the file
        while (getline(inFile, line)) {
            size_t delimiterPos = line.find(":");  // Find the position of the colon delimiter
                                                   // if a colon is not found, the fnction returns "std::string::npos" (kinda like null)
            if (delimiterPos != std::string::npos) { // check if there is in fact a colon in the line, if not then skip
                // Extract the student's name and grade from the line
                std::string name = line.substr(0, delimiterPos);        // Get the name part before the colon, the name
                int grade = std::stoi(line.substr(delimiterPos + 1));  // Get the grade part after the colon and convert it to an integer

                // Determine if the student passed or failed
                if (grade >= 50) {
                    passedFile << name << ": " << grade << std::endl;  // Write the name and grade to passedFile if grade >= 50
                } else {
                    failedFile << name << ": " << grade << std::endl;  // Write the name and grade to failedFile if grade < 50
                }
            } else {
                std::cout << "Skipping malformed line: " << line << std::endl; // there is no colon in the line
            }
        }
        inFile.close();                      // Close the input file after processing all records
        passedFile.close();                  // Close the passedFile after writing all passing students
        failedFile.close();                  // Close the failedFile after writing all failing students
    } else {
        // If the input or output files couldn't be opened, print an error message
        std::cout << "Unable to open one or more files" << std::endl;
        return 1;                            // Return 1 to indicate an error occurred
    }

    return 0;                                // Return 0 to indicate successful completion of the program
}
