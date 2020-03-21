#include <iostream>
#include <fstream>
#include <string.h>
#include <cctype>
using namespace std;


class LabTask {
    private:
        string input;
        string token;
    public:
        LabTask();
        ~LabTask();
        int getCount();
        void takingInput();
        void printResult();
        void writeDataToFile();
};

LabTask::LabTask() {
    //no-op
}

LabTask::~LabTask() {
    //no-op
}

void LabTask::takingInput() {
    cout << "Enter string: ";
    getline(cin, input);

    cout << "Enter the Tokenizer: ";
    getline(cin, token);
    
}

void LabTask::printResult() {
    int length = input.length();
    token = 'm';
    for(int i = 0; i <= length; i++) {
        if(input[i] == token[0]) {
            input[i] == '_';
            cout << "\n";
        }
        else {
            cout << input[i];
        }
    }
}

void LabTask::writeDataToFile() {
    takingInput();
    cout << "Output:\n";
    printResult();
    freopen("result.txt", "w", stdout);
    printResult();
    fclose(stdout);
}

int main() {
    LabTask obj;
    obj.writeDataToFile();
}