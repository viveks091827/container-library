#include <iostream>
#include "vector.h"
#include "array.h"
#include "queue.h"


std::ostream& operator<< (std::ostream&stream, Array<int, 5>& r) {
    return stream << r[0] << ", " << r[1] << ", " << r[2] << ", " << r[3] << ", " << r[4] << std::endl;
}

int main() {
    Queue<Array<int, 5>, Vector<Array<int, 5>>> s;
    Array<int, 5> arr1;
    arr1[0] = 11;
    arr1[1] = 12;
    arr1[2] = 13;
    arr1[3] = 14;
    arr1[4] = 15;
    Array<int, 5> arr2;
    arr2[0] = 21;
    arr2[1] = 22;
    arr2[2] = 23;
    arr2[3] = 24;
    arr2[4] = 25;
    Array<int, 5> arr3;
    arr3[0] = 31;
    arr3[1] = 32;
    arr3[2] = 33;
    arr3[3] = 34;
    arr3[4] = 35;
    Array<int, 5> arr4;
    arr4[0] = 41;
    arr4[1] = 42;
    arr4[2] = 43;
    arr4[3] = 44;
    arr4[4] = 45;
    Array<int,5> arr5; 
    arr5[0] = 51;
    arr5[1] = 52;
    arr5[2] = 53;
    arr5[3] = 54;
    arr5[4] = 55;

    std::cout << "size: " << s.size() << std::endl;

    s.push(arr1);
    s.push(arr2);
    s.push(arr3);
    

    std::cout << "size: " << s.size() << std::endl; 

    std::cout << s.front() << std::endl;
    std::cout << s.back() << std::endl;

    s.pop();
    s.pop();

    s.push(arr4);
    s.push(arr5);
  
   std::cout << s.front() << std::endl;
   std::cout << s.back() << std::endl;
    return 0;
}