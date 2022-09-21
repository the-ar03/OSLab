// First Come First Serve sheduling Algorithm

#include<stdio.h>
void findWaitingTime(int processes[], int n, int bt[], int wt[]){
wt[0] = 0;
for (int i = 1; i < n ; i++ )
wt[i] = bt[i-1] + wt[i-1] ;
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
for (int i = 0; i < n ; i++)
tat[i] = bt[i] + wt[i];
}

void findavgTime( int processes[], int n, int bt[]) {
int wt[n], tat[n], total_wt = 0, total_tat = 0;

findWaitingTime(processes, n, bt, wt);

findTurnAroundTime(processes, n, bt, wt, tat);

printf("P_id BT WT TAT\n");

for (int i=0; i<n; i++) {
total_wt = total_wt + wt[i];
total_tat = total_tat + tat[i];
printf(" %d ",(i+1));
printf(" %d ", bt[i] );
printf(" %d ",wt[i] );
printf(" %d\n",tat[i] );
}
int s=(float)total_wt / (float)n;
int t=(float)total_tat / (float)n;
printf("Average waiting time = %d",s);
printf("\n");
printf("Average turn around time = %d ",t);
}

int main(){
int processes[] = { 1, 2, 3};
int n = sizeof processes / sizeof processes[0];
int burst_time[] = {10, 5, 8};

findavgTime(processes, n, burst_time);
return 0;
}



// FCFS Algorithm
// Step 1: Start
// Step 2: Accept the number of processes in the ready Queue
// Step 3: For each process in the ready Q, assign the process id and accept the CPU burst time
// Step 4: Set the waiting of the first process as ‘0’ and its burst time as its turn around time
// Step 5: for each process in the Ready Q calculate
// (a) Waiting time for process(n)= waiting time of process (n-1) + Burst time of process(n-1)
// (b) Turn around time for Process(n)= waiting time of Process(n)+ Burst time for process(n)
// Step 6: Calculate
// (a) Avg WT = total WT / Number of process
// (b) Avg TAT = total TAT / Number of process
// Step 7: Stop
