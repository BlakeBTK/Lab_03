/*****************************************
* Question 2: Swap the Value
* Author: Blake Kuechler
* Date: 9/21/2021
* Description: This program contains two functions that swaps the values
* of two different integers
******************************************/
#include <iostream>
#include <string>

// Function that swaps the values of two ints by references
void swapRef(int &a, int &b) {
    int c = b;
    b = a;
    a = c;
}

// Function that swaps the values of two ints by pointers
void swapPoint(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}


int main() {
    int a = 2;
    int b = 10;

    std::cout << a << ", " << b << std::endl;
    swapRef(a, b);
    std::cout << a << ", " << b << std::endl;

    std::cout << a << ", " << b << std::endl;
    swapPoint(&a, &b);
    std::cout << a << ", " << b << std::endl;
}