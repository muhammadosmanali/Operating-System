#include <iostream>
#include <algorithm>
using namespace std;

class Task {
    private:
        int n;
        float avg_turn_time;
        float avg_wait_time;
        int arr_time[20];
        int sort_arr_time[20];
        int dup_arr_time[20];
        int sort_dup_arr_time[20];
        int bur_time[20];
        int sort_bur_time[20];
        int comp_time[20];
        int turn_time[20];
        int wait_time[20];
    public:
        Task();
        ~Task();
        void taskScheduling();
        void swap(int *xp, int *yp);
        void BubbleSort(int arr[], int n);
        void arrInput();
        void sortArrivalTime();
        void dupInArrTime();
        void sortDupInArrTime();
        void burInput();
        void sortBurstTime();
        void findCompletionTime();
        void findTurnAroundTime();
        void findWaitingTime();
        void findAverage();
        void output();
};

Task::Task() : avg_turn_time(0), avg_wait_time(0) {
    //no-op
}

Task::~Task() {
    //no-op
}

void Task::swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
// A function to implement bubble sort 
void Task::BubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
}

void Task::arrInput() {
    cout << "Enter the Number of processes: ";
    cin >> n;
    cout << "\nArrival Time\n";
    for(int i = 0; i < n; i++) {
        cout << "Enter Arrival Time: ";
        cin >> arr_time[i];
    }
}

void Task::sortArrivalTime() {
    for(int k = 0; k < n; k++) {
        sort_arr_time[k] = arr_time[k];
        dup_arr_time[k] = arr_time[k];
    }
    BubbleSort(sort_arr_time, n);
}

void Task::dupInArrTime() {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(dup_arr_time[i] == dup_arr_time[j]) {
                dup_arr_time[j] = dup_arr_time[j] + 1;
            }
        }
    }
}

void Task::sortDupInArrTime() {
    for(int i = 0; i < n; i++) {
        sort_dup_arr_time[i] = dup_arr_time[i];
    }
    BubbleSort(sort_dup_arr_time, n);
}

void Task::burInput() {
    cout << "\nBurst Time\n";
    for(int j = 0; j < n; j++) {
        cout << "Enter Burst Time: ";
        cin >> bur_time[j];
    }
}

void Task::sortBurstTime() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(sort_dup_arr_time[i] == dup_arr_time[j]) {
                sort_bur_time[i] = bur_time[j];
            }
        }
    }
}

void Task::findCompletionTime() {
    comp_time[0] = sort_arr_time[0] + sort_bur_time[0];
    for(int i = 1; i < n; i++) {
        comp_time[i] = comp_time[i - 1] + sort_bur_time[i];
    }
}

void Task::findTurnAroundTime() {
    for(int i = 0; i < n; i++) {
        turn_time[i] = comp_time[i] - sort_arr_time[i];
    }
}

void Task::findWaitingTime() {
    for(int i = 0; i < n; i++) {
        wait_time[i] = turn_time[i] - sort_bur_time[i];
    }
}

void Task::findAverage() {
    for(int i = 0; i < n; i++) {
        avg_turn_time += turn_time[i];
        avg_wait_time += wait_time[i];
    }
    avg_turn_time = avg_turn_time / n;
    avg_wait_time = avg_wait_time / n;
}

void Task::output() {
    cout << "\n\n\n";
    cout << "Process\tArrival Time\tBurst Time\tTurn Around Time\tWaiting Time";
    for(int i = 0; i < n; i++) {
        cout << "\nP[" << i << "]" << "\t\t" << sort_arr_time[i] << "\t\t" << sort_bur_time[i] << "\t\t" << turn_time[i] << "\t\t" << wait_time[i];
    }
    cout << "\n\n\n";
    cout << "Average Turn Around Time: " << avg_turn_time  << "ms\n";
    cout << "Average Waiting Time: " << avg_wait_time << "ms\n\n";
}

int main() {
    Task obj;
    obj.arrInput();
    obj.sortArrivalTime();
    obj.dupInArrTime();
    obj.sortDupInArrTime();
    obj.burInput();
    obj.sortBurstTime();
    obj.dupInArrTime();
    obj.findCompletionTime();
    obj.findTurnAroundTime();
    obj.findWaitingTime();
    obj.findAverage();
    obj.output();
} 

