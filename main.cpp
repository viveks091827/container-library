#include <iostream>
#include "vector.h"

int main() {
    Vector<int> arr;

    arr.pushBack(1);
    arr.pushBack(2);
    arr.pushBack(3);
    arr.pushBack(4);

    for (Vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
        std::cout << *it << std::endl;
    }

    arr.assign(5, 100);

    for (Vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
        std::cout << *it << std::endl;
    }

    arr.assign(200, arr.begin(), arr.begin()+8);

    arr.popBack();
    arr.popBack();
    arr.popBack();
    arr.popBack();

    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << std::endl;
    }

    return 0;
}