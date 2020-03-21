#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class MemoryManagement {
    private:
        int blockSize[20];
        int numOfBlocks;
        int processSize[20];
        int numOfProcess;
        int allOfProcess[20];
    public:
        void input();
        void firstFit();
        void bestFit();
        void worstFit();
        void print();
        void Run();
};

void MemoryManagement::input() {
    memset(allOfProcess, -1, sizeof(allOfProcess));
    cout << "\nEnter the number of blocks: ";
    cin >> numOfBlocks;
    cout << "\n";
    for(int i = 0; i < numOfBlocks; i++) {
        cout << "Block # " << i + 1 << ": ";
        cin >> blockSize[i];
        cout << "\n";
    }
    cout << "\nEnter the number of Processess: ";
    cin >> numOfProcess;
    cout << "\n";
    for(int j = 0; j < numOfProcess; j++) {
        cout << "Process # " << j + 1 << ": ";
        cin >> processSize[j];
        cout << "\n";
    }
}

void MemoryManagement::firstFit() {
    for(int i = 0; i < numOfProcess; i++) {
        for(int k = 0; k < numOfBlocks; k++) {
            if(blockSize[k] >= processSize[i]) {
                allOfProcess[i] = k;
                blockSize[k] -= processSize[i];
                break;
            }
        }
    }
}

void MemoryManagement::bestFit() {
    for(int i = 0; i < numOfProcess; i++) {
        int index = -1;
        for(int k = 0; k < numOfBlocks; k++) {
            if(blockSize[k] >= processSize[i]) {
                if(index == -1) {
                    index = k;
                }
                else if(blockSize[index] > blockSize[k]) {
                    index = k;
                }
            }
        }
        if(index != -1) {
            allOfProcess[i] = index;
            blockSize[index] -= processSize[i];
        }
    }
}

void MemoryManagement::worstFit() {
    for(int i = 0; i < numOfProcess; i++) {
        int index = -1;
        for(int k = 0; k < numOfBlocks; k++) {
            if(blockSize[k] >= processSize[i]) {
                if(index == -1) {
                    index = k;
                }
                else if(blockSize[index] < blockSize[k]) {
                    index = k;
                }
            }
        }
        if(index != -1) {
            allOfProcess[i] = index;
            blockSize[index] -= processSize[i];
        }
    }
}

void MemoryManagement::print() {
    cout << "\nProcess # \tProcess Size \tBlock #\n";
    for(int i = 0; i < numOfProcess; i++) {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if(allOfProcess[i] != -1) {
            cout << allOfProcess[i] + 1;
        }
        else {
            cout << "Not Allocated";
        }
        cout << "\n";
    }
}

void MemoryManagement::Run() {
    int in;
    cout << "Which Memory Management Alogrithm you want to Run\n";
    cout << "1. First Fit\n";
    cout << "2. Best Fit\n";
    cout << "3. Worst Fit\n";

    cout << "Select using 1, 2 and 3: ";
    cin >> in;
    if(in == 1) {
        input();
        firstFit();
        print();
    }
    else if(in == 2) {
        input();
        bestFit();
        print();
    }
    else if(in = 3) {
        input();
        worstFit();
        print();
    }

}

int main() {
    MemoryManagement obj;
    obj.Run();
}