#include<iostream>
using namespace std; 

struct SJF
{
	int arrivaltime;
	int bursttime;
    int pid;
};

void TAT(SJF job[], int numbers, int wait[], int turnaround[])
{
	for (int i = 0; i < numbers; i++)
	{
	   turnaround[i] = job[i].bursttime + wait[i]; 	
	} 
}
void WT(SJF job[], int numbers, int wait[])
{
	int arr[numbers];
	for (int i = 0; i < numbers; i++)
	{
		arr[i] = job[i].bursttime; 
	}
	int shortesttime = 0; 
	int endtime;
	int completiontime = 0;
	bool find = false;
	int minimum = INT_MAX; 
	int time = 0;
	while (completiontime != numbers)
	{
		for (int j = 0; j < numbers; j++)
		{ 
            if ((job[j].arrivaltime <= time) && (arr[j] < minimum && arr[j] > 0))
			{ 
                minimum = arr[j]; 
                shortesttime = j; 
                find = true; 
            } 
        } 
        if (find == false) 
		{ 
            time++; 
            continue; 
        } 
	    arr[shortesttime]--; 
        minimum = arr[shortesttime]; 
        if (minimum == 0) 
        {
           minimum = INT_MAX; 	
		} 
        if (arr[shortesttime] == 0) 
		{  
           completiontime++; 
           find = false;  
           endtime = time + 1;  
           wait[shortesttime] = endtime - job[shortesttime].bursttime - job[shortesttime].arrivaltime; 
  
            if (wait[shortesttime] < 0) 
            {
            	wait[shortesttime] = 0; 
		    }
        } 
        time++; 
   }
}
void Average(SJF job[], int numbers) 
{ 
    int turnaround[numbers];
	int totalwaittime = 0;
    int wait[numbers];
    int totalturnaroundtime = 0;
	WT(job, numbers, wait); 
    TAT(job, numbers, wait, turnaround); 
     cout << ".*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*."<< endl;
     cout << "===========================================================" << endl;
     cout << "Processes || Burst Time || Waiting Time || Turn Around Time" << endl;
     cout << "===========================================================" << endl;
    for (int i = 0; i < numbers; i++)
	{ 
        totalwaittime = totalwaittime + wait[i]; 
        totalturnaroundtime = totalturnaroundtime + turnaround[i]; 
        cout << " " 
		     << job[i].pid 
			 << "\t\t"
             << job[i].bursttime 
			 << "\t\t " 
			 << wait[i] 
             << "\t\t " 
			 << turnaround[i] << endl; 
    }  
	cout << "\nAverage Waiaiting Time = "
         << (float)totalwaittime / (float)numbers; 
    cout << "\nAverage Turn Around Time = "
         << (float)totalturnaroundtime / (float)numbers;    
}
int main()
{
    // {Arrival, Burst, processId}
	 SJF job[] = { { 2, 3, 1 }, { 3, 2, 2 }, { 4, 3, 3 }, { 6, 1, 4 }, {8, 2, 5} }; 
     int numbers = sizeof(job) / sizeof(job[0]); 
     Average(job, numbers); 
     return 0; 
     
}
