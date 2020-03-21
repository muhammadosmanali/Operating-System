#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class LabTask {
    private:
        string input;
        int i;
    public:
        LabTask();
        ~LabTask();
        void takingInput();
        bool fileExist(string filename);
        void openFile(string filename);
        void createFile();
};

LabTask::LabTask(): i(1) {
    //no-op
}

LabTask::~LabTask() {
    //no-op
}

void LabTask::takingInput() {
    cout << "Enter the file name: ";
    cin >> input;
    cout << '\n';
}

bool LabTask::fileExist(string filename) {
    ifstream infile(filename);
    return infile.good();
}

void LabTask::openFile(string filename) {
    ofstream outfile;
    outfile.open(filename);
    outfile.close();
}

void LabTask::createFile() {
    if(!fileExist(input + ".txt")) {
        string file = input + ".txt";
        cout << "File Created of Name: " + file + "\n\n";
        openFile(file);
    } 
    else {
        while(fileExist(input + "(" + to_string(i) + ")" + ".txt")) {
            if(fileExist(input + "(" + to_string(i) + ")" + ".txt")) {
                cout << "File Already Exist of Name: " + input + "(" + to_string(i) + ")" + ".txt" + "\n";
                i = i + 1;
            }
            else {
                cout << "File Created of Name: " + input + "(" + to_string(i) + ")" + ".txt" + "\n";
                openFile(input + "(" + to_string(i) + ")" + ".txt");
            }
        }
        if(!fileExist(input + "(" + to_string(i) + ")" + ".txt")) {
            cout << "File Created of Name: " + input + "(" + to_string(i) + ")" + ".txt" + "\n\n";
            openFile(input + "(" + to_string(i) + ")" + ".txt");
        }
    }
}

int main() {
    LabTask obj;
    obj.takingInput();
    obj.createFile();
    return 0;
}