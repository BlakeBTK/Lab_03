/*****************************************
* Question 3: Array Operation B
* Author: Blake Kuechler
* Date: 9/21/2021
* Description: This program finds the local minimum and local maximum values in
* an int array, and returns the indexes of each local min and max
******************************************/
#include <iostream>
#include <string>
#include <array>

// Function that finds the indexes of local mins and local maxes in an int array
void minMax(int array[], int length) {
    int relay[length];
    // Determines if an in in the array is a local min or max and copies indexes to another array
    for(int i = 1; i < length - 1; i++) {
        if (array[i] > array[i - 1] && array[i] > array[i + 1]) {
            relay[i] = i;
        } else if (array[i] < array[i - 1] && array[i] < array[i + 1]) {
            relay[i] = i;
        }
    }

    int size = 0;
    // Finds the amount of actual indexes in the array
    for (int j = 0; j < length; j++) {
        if(relay[j] < length && relay[j] > 0) {
            size++;
        }
    }

    int end[size];
    int index = 0;
    // Loop that copies indexes to another array to remove all the null values 
    for(int i = 0; i < length; i++) {
        if(relay[i] < length && relay[i] > 0) {
            end[index++] = relay[i];
        }
    }

    // Moves the indexes in the array to a string to display to the console output
    std::string list;
    for(int i = 0; i < size; i++) {
        list += std::to_string(end[i]) + ", ";
    }
    list = list.substr(0, list.length() - 2);
    std::cout << list << std::endl;

}


int main() {
    int a[] = {12, 11, 122, 112, 222, 222, 222, 221, 76, 36, 31, 234, 256, 76, 73};
    minMax(a, 15);
}