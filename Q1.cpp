/*****************************************
* Question 1: Advanced String Operation
* Author: Blake Kuechler
* Date: 9/21/2021
* Description: This program contains multiple functions that returns information
* about a given string 
******************************************/
#include <iostream>
# include <string>

// Function that finds the total amount of letters in a string
int totalLetters(std::string a) {
    char check;
    int total = 0;
    for (int i = 0; i < a.size(); i++) {
        check = a[i];
        // Checks to see if a char in the string array is a letter
        if((check >= 65 && check <= 90) || (check >= 97 && check <= 122)) {
            total++;
        }
    }
    return total;
}

// Function that finds the total amount of digits in a string
int totalDigits(std::string a) {
    char check;
    int total = 0;
    for (int i = 0; i < a.size(); i++) {
        check = a[i];
        // Checks to see if a a char in the string array is a digit
        if((check >= 48 && check <= 57)) {
            total++;
        }
    }
    return total;
}

// Function that finds the total amount of numbers in a string
int totalNumbers(std::string a) {
    char check;
    int total = 0;
    int i = 0;
    while(i < a.size()) {
        check = a[i];
        // Finds out if a char in the string array is a digit
        if((check >= 48 && check <= 57)) {
            total++;
            check = a[++i];
            // Continues through the string array as long as the next char is a digit
            while(check >= 48 && check <= 57){
                check = a[++i];
            }
        } else {
            i++;
        }
    }
    return total;
}

// Boolean function that checks if "miami" is in a string
bool emailCheck(std::string a) {
    char check;
    int i = 0;
    while(i < a.size()) {
        check = a[i];
        // First checks for the char m in the string array
        if((check == 109)) {
            // if there isn't enough chars past m, return false
            if(i > a.size() - 5) {
                return false;
            } else {
                std::string word;
                std::string correct = "miami";
                // Copies the five char values into a string
                for (int j = 0; j < 5; j++) {
                    word[j] = a[i];
                    i++;
                }
                // Compares to see if the five copied char values match "miami"
                for(int k = 0; k < 5; k++) {
                    if(word[k] != correct[k]) {
                        return false;
                    }
                }
            }
            return true;
        } else {
            i++;
        }
    }
    return false;
}

// Function that counts the letters in a string, and converts them all to either upper or 
// lower case letters
int totalLettersCapitalization(std::string a, char cap) {
    char check;
    int total = 0;
    int change;
    // Checks whether the user wants it uppercase (U or u) or lowercase (L, l)
    if (cap == 85 || cap == 117) {
        change = -32;
    } else if (cap == 76 || cap == 108) {
        change = 32;
    }
    for (int i = 0; i < a.size(); i++) {
        check = a[i];
        // Checks to see if a char in the array is a letter
        if((check >= 65 && check <= 90) || (check >= 97 && check <= 122)) {
            total++;
            // Changes the capitalization of a letter depending on user selection
            if (check <= 90 && change > 0) {
                a[i] = check + change;
            } else if (check >= 97 && change < 0) {
                a[i] = check + change;
            }
        }
    }
    std::cout << a << std::endl;
    return total;
}

// Function that combines the ouptput of the first three functions in the program
void stringReader(std::string a) {
    std::cout << "Total Letters: " << totalLetters(a) << "\nTotal Digits: " << totalDigits(a)
        << "\nTotal Numbers: " << totalNumbers(a) << std::endl;
}



int main() {
    std::string b = "feng17@miamiOh.edu_^&*-----2055";
    std::cout << emailCheck(b) << std::endl;
    std::cout << totalLettersCapitalization(b, 'u') << std::endl;
    stringReader(b);

}



