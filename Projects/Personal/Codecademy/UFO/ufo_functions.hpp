#include <utility>
#include <vector>

void display_misses(int misses);

// Declare functions
void greet();
std::pair<std::string, std::string> getWordAndAnswer();
void end_game(std::string answer, std::string codeword);
void display_status(std::string answer,  std::vector<char> incorrect);