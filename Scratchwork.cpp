#include <iostream>
#include <stack>
#include <queue>

using namespace std;

string reverseString(string& input) {
    stack<char> letters;
    queue<int> digits;
    string finalString = "";

    for(int i = 0; i < input.size(); ++i) {
        if(isalpha(input[i])) {
            letters.push(input[i]);
        } else if(isdigit(input[i])) {
            digits.push(input[i]);
        }
    }

    while(!letters.empty()) {
        finalString += letters.top();
        letters.pop();
    }

    while(!digits.empty()) {
        finalString += digits.front();
        digits.pop();
    }

    return finalString;
}

int main() {
    string test = "a1b2c3";

    cout << reverseString(test) << endl;
}