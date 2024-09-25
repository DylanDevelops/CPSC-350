#include "CQueue.h"
#include <iostream>
using namespace std;

int main(){

    CQueue<char>* theQ = new CQueue<char>(10);
    theQ->add('P');
    theQ->add('e');
    theQ->add('t');
    theQ->add('e');

    cout << theQ->size() << endl;
    while(!theQ->isEmpty()){
        cout << theQ->remove() << endl;
    }

    cout << theQ->size() << endl;
    theQ = new CQueue<char>(10);
    theQ->add('P');
    theQ->add('a');
    theQ->add('n');
    theQ->add('t');
    theQ->add('h');
    theQ->add('e');
    theQ->add('x');
    theQ->add('y');
    theQ->add('z');

    cout << theQ->peek() << endl;
    cout << theQ->size() << endl;
    theQ->remove();
    theQ->remove();
    theQ->remove();
    theQ->remove();
    theQ->add('w');
    theQ->add('A');
    theQ->add('B');
    theQ->add('C');
    theQ->add('D');
    theQ->add('E');
    theQ->add('F');
    theQ->add('G');
    theQ->add('H');
    theQ->add('I');
    while(!theQ->isEmpty()){
        cout << theQ->remove() << endl;
    }

    
    delete theQ;
    return 0;
}