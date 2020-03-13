#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "NodeStack.h"

bool createTestcases() {
    std::string str;
    std::ofstream ofs ("18b.txt");
    char ch;
    int testcase = 0;
    std::cout << "How much testcase do you want? ";
    std::cin >> testcase;
    std::cin.ignore();
    if (ofs.is_open()) {
        for (int i = 0; i < testcase; i++) {
            if (i != 0) ofs << "\n";
            std::cout << "Testcase " << i+1 << ": ";
            getline(std::cin, str);
            std::stringstream ss(str);
            while(ss >> std::noskipws >> ch) {
                ofs << ch;
            }
        }
        ofs.close();
        return true;
    }
    else {
        std::cout << "Unable to open file";
        return false;
    }
}
bool readFile(std::vector<std::string> &vt) {
    std::ifstream ifs("18b.txt");
    std::string str;
    int i = 0;
    if (ifs.is_open()) {
        while(getline(ifs,str)) {
            std::cout << "Testcase " << ++i << ": " << str << std::endl;
            vt.push_back(str);
        }
        ifs.close();
        return true;
    }
    else {
        std::cout << "Unable to read file";
        return false;
    }
}
bool check(std::string str) {
    Stack S2;
    MAKENULL_STACK(S2);
    for (int i = str.size() - 1; i >= 0; i--)
    {
        switch (str[i]) {
            case '}':
                PUSH(S2, str[i]);
                break;
            case '{':
                if (S2->Element == '}') {
                    POP(S2);
                    break;
                }
                else return false;
            case ')':
                PUSH(S2, str[i]);
                break;
            case '(':
                if (S2->Element == ')') {
                    POP(S2);
                    break;
                }
                else return false;
            case ']':
                PUSH(S2, str[i]);
                break;
            case '[':
                if (S2->Element == ']') {
                    POP(S2);
                    break;
                }
                else return false;
            default:
                break;
        }
    }
    if (EMPTY_STACK(S2)) return true;
    else return false;
}
int main() {
    char ch;
    std::vector<std::string> vt;
    while(true) {
        std::cout << "Press any key to continue (but 0): ";
        std::cin >> ch;
        if (ch == '0') break;
        //createTestcases();
        readFile(vt);
        for (std::string str : vt) {
            if (check(str)) std::cout << "Good!" << std::endl;
            else std::cout << "Bad!" << std::endl;
        }
    }
}
