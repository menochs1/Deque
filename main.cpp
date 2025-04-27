#include <iostream>
#include "deque.h"

using namespace std;

int main() {
    Deque dq;
    const int nums = 100;

    // Pushing values to the back
    for (int i = 0; i < nums / 2; ++i) {
        dq.pushBack(i);
    }

    // Pushing values to the front
    for (int i = 0; i < nums / 2; ++i) {
        dq.pushFront(i);
    }

    // Printing initial state
    cout << "Initial contents: ";
    dq.print();
    cout << "Size: " << dq.getSize() << endl;

    // Popping elements from both ends
    dq.popFront();
    dq.popFront();
    dq.popBack();
    dq.popBack();

    cout << "After 2 popFronts and 2 popBacks: ";
    dq.print();
    cout << "Size: " << dq.getSize() << endl;

    // Adding new values
    int x1 = 93, x2 = 89;
    dq.pushFront(x1);
    dq.pushBack(x2);

    cout << "After pushing x1 to front and x2 to back: ";
    dq.print();
    cout << "Size: " << dq.getSize() << endl;

    // Peek at front and back
    cout << "Front value: " << dq.getFront() << endl;
    cout << "Back value: " << dq.getBack() << endl;

    // Index access demonstration
    cout << "Element at index 0: " << dq[0] << endl;
    cout << "Element at index " << dq.getSize() - 1 << ": " << dq[dq.getSize() - 1] << endl;

    return 0;
}
