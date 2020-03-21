#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

class LabTask {
    private:
        int count;
    public:
        LabTask();
        ~LabTask();
        void countTheLines();
        void printInOrder();
};

LabTask::LabTask() {
    //no-op
}

LabTask::~LabTask() {
    //no-op
}

void LabTask::countTheLines() {
    string line;
    ifstream myfile("result.txt");

    while(getline(myfile, line)) {
        count++;
    }
}

void LabTask::printInOrder() {
    vector<string> name;

    ifstream in("result.txt");
    if(!in.is_open()) {
        cout << "Unable to open the file";
    }
    string word;
    while(getline(in, word)) {
        name.push_back(word);
    }

    sort(name.begin(), name.end());

    for(int i = 0; i < name.size(); i++) {
        cout << name[i] << '\n';
    }
}

int main() {
    LabTask obj;
    obj.countTheLines();
    obj.printInOrder();
}