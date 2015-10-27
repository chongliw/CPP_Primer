//
// Created by Chongli Wang on 10/27/15.
//

#include <iostream>
#include <queue>

using std::priority_queue;
using std::cout;
using std::endl;

int main() {
    priority_queue<int, std::vector<int>, std::greater<int>> pq;
    pq.push(2);
    pq.push(10);
    pq.push(4);
    while (!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }
    return 0;
}