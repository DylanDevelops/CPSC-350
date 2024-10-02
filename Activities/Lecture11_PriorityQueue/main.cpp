#include <iostream>
#include "DblList.h"
#include "PQueue.h"
using namespace std;

int main(){
   PQueue<int> pq(false);
   pq.add(10);
   pq.add(50);
   pq.add(30);
   cout << "peek: " << pq.peek() << endl;
   while(!pq.isEmpty()){
    cout << pq.remove() << endl;
   }
   cout << "Size: " << pq.size() << endl;
}