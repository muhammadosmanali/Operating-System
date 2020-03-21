#include <iostream>
using namespace std;

class Task {
    private:
        int memory_size;
        int block_size;
        int no_of_block;
        int external_frag;
        int internal_frag;
        int no_of_process;
        int memory_of_process[10];
        int count;
        int i;
        int num;
        char again;
        int temp;
    public:
        Task();
        ~Task();
        void Input();
        void MVT();
};

Task::Task() {
    count = 0;
    internal_frag = 0;
}

Task::~Task() {
    //no-op
}


void Task::MVT() {
    again = 'y';
    cout << "\nEnter the total memory avaliable (in Bytes): ";
    cin >> memory_size;
    temp = memory_size;

    for(int i = 0; again == 'y'; i++, count++) {
        cout << "\nEnter memory required for process " << i + 1 << " :";
        cin >> memory_of_process[i];
        if(memory_of_process[i] <= temp) {
            cout << "\nMemory is allocated for process " << i + 1;
            temp = temp - memory_of_process[i];
        }
        else {
            break;
        }
        cout << "\nDo you want to Continue(y/n): ";
        cin >> again;
    }
    cout << "\n\nProcess\t\t Memory Allocated\t\t Memory Assigned(Yes/No)";
    for(i = 0; i < count; i++) {
        cout << "\n" << i + 1 << "\t\t" << memory_of_process[i] << "\t\t\tYes";
    }

    cout << "\n\nTotal Memory Allocated is " << memory_size - temp;
    cout << "\nTotal External Fragmentation is " << temp;
    
}

int main() {
    Task obj;
    obj.MVT();
}

