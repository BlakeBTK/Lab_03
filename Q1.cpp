#include <iostream>
# include <string>

int totalLetters(std::string a) {
    char check;
    int total = 0;
    for (int i = 0; i < a.size(); i++) {
        check = a[i];
        if((check >= 65 && check <= 90) || (check >= 97 && check <= 122)) {
            total++;
        }
    }
    return total;
}

int totalDigits(std::string a) {
    char check;
    int total = 0;
    for (int i = 0; i < a.size(); i++) {
        check = a[i];
        if((check >= 48 && check <= 57)) {
            total++;
        }
    }
    return total;
}

int totalNumbers(std::string a) {
    char check;
    int total = 0;
    int i = 0;
    while(i < a.size()) {
        check = a[i];
        if((check >= 48 && check <= 57)) {
            total++;
            check = a[++i];
            while(check >= 48 && check <= 57){
                check = a[++i];
            }
        } else {
            i++;
        }
    }
    return total;
}

bool emailCheck(std::string a) {
    char check;
    int i = 0;
    while(i < a.size()) {
        check = a[i];
        if((check == 109)) {
            if(i > a.size() - 5) {
                return false;
            } else {
                std::string word;
                std::string correct = "miami";
                for (int j = 0; j < 5; j++) {
                    word[j] = a[i];
                    i++;
                }
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

int totalLettersCapitalization(std::string a, char cap) {
    char check;
    int total = 0;
    int change;
    if (cap == 85 || cap == 117) {
        change = 32;
    } else {
        change = -32;
    }
    for (int i = 0; i < a.size(); i++) {
        check = a[i];
        if((check >= 65 && check <= 90) || (check >= 97 && check <= 122)) {
            total++;
            if (check <= 90 && change > 0) {
                a[i] = a[i] + change;
            } else if (check >= 97 && change < 0) {
                a[i] = a[i] + change;
            }
        }
    }
    return total;
}



int main() {
    std::string b = "feng17@miamiOh.edu_^&*-----2055";
    std::cout << totalLettersCapitalization(b, 'u') << std::endl;
    std::cout << b << std::endl;
}



