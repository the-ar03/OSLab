// Shortest Job First algorithm
#include <stdio.h>
int main()
{
int A[100][4]; 
int i, j, n, total = 0, index, temp;
float avg_wt, avg_tat;
printf("Enter number of process: ");
scanf("%d", &n);
printf("Enter Burst Time:\n");
	
for (i = 0; i < n; i++) {
printf("P%d: ", i + 1);
scanf("%d", &A[i][1]);
A[i][0] = i + 1;
}
	
for (i = 0; i < n; i++) {
index = i;
for (j = i + 1; j < n; j++)
if (A[j][1] < A[index][1])
index = j;
temp = A[i][1];
A[i][1] = A[index][1];
A[index][1] = temp;

temp = A[i][0];
A[i][0] = A[index][0];
A[index][0] = temp;
}
A[0][2] = 0;
	
for (i = 1; i < n; i++) {
A[i][2] = 0;
for (j = 0; j < i; j++)
A[i][2] += A[j][1];
total += A[i][2];
}
avg_wt = (float)total / n;
total = 0;
printf("P	 BT	 WT	 TAT\n");

for (i = 0; i < n; i++) {
A[i][3] = A[i][1] + A[i][2];
total += A[i][3];
printf("P%d	 %d	 %d	 %d\n", A[i][0],
A[i][1], A[i][2], A[i][3]);
}
avg_tat = (float)total / n;
printf("Average Waiting Time= %f", avg_wt);
printf("\nAverage Turnaround Time= %f", avg_tat);
}



//SJF Algorithm
// Step 1: Start
// Step 2: Accept the number of processes in the ready Queue
// Step 3: For each process in the ready queue, assign the process id and accept the CPU burst time
// Step 4: Start the Ready queue according the shortest Burst time by sorting according to lowest to highest burst time.
// Step 5: Set the waiting time of the first process as ‘0’ and its turnaround time as its burst time.
// Step 6: For each process in the ready queue, calculate 
// (a) WT for process(n) = WT of process (n-1) + BT of process(n-1)
// (b) TAT for Process(n) = WT of Process(n)+ BT for process(n)
// Step 7: Calculate 
// (a) Avg WT = Total WT / Number of process
// (b) Avg TAT = Total TAT / Number of process
// Step 8: Stop
