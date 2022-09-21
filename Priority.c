#include<stdio.h>
 
int main()
{
int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
printf("Enter Total Number of Process:");
scanf("%d",&n);
 
printf("\nEnter Burst Time and Priority\n");
for(i=0;i<n;i++){
printf("\nP[%d]\n",i+1);
printf("Burst Time:");
scanf("%d",&bt[i]);
printf("Priority:");
scanf("%d",&pr[i]);
p[i]=i+1;}

for(i=0;i<n;i++){
pos=i;
for(j=i+1;j<n;j++){
if(pr[j]<pr[pos])
pos=j;
}
 
temp=pr[i];
pr[i]=pr[pos];
pr[pos]=temp;
 
temp=bt[i];
bt[i]=bt[pos];
bt[pos]=temp;
 
temp=p[i];
p[i]=p[pos];
p[pos]=temp;
}
 
wt[0]=0;
for(i=1;i<n;i++){
wt[i]=0;
for(j=0;j<i;j++)
wt[i]+=bt[j];
 
total+=wt[i];
}
 
avg_wt=total/n;      //average waiting time
total=0;
 
printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
for(i=0;i<n;i++) {
tat[i]=bt[i]+wt[i];     //calculate turnaround time
total+=tat[i];
printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
}
 
avg_tat=total/n;     //average turnaround time
printf("\n\nAverage Waiting Time=%d",avg_wt);
printf("\nAverage Turnaround Time=%d\n",avg_tat);
 
return 0;
}



// // Priority Algorithm
// Step 1: Start
// Step 2: Accept the number of processes in the ready Queue
// Step 3: For each process in the ready Q, assign the process id and accept the CPU burst time
// Step 4: Sort the ready queue according to the priority number.
// Step 5: Set the waiting of the first process as ‘0’ and its burst time as its turn around time
// Step 6: For each process in the Ready Q calculate
// (a) WT for process(n) = WT of process (n-1) + BT of process(n-1)
// (b) TAT for Process(n)= WT of Process(n) + BT for process(n)
// Step 7: Calculate
// (a) Avg WT = TAT / Number of process
// (b) Avg TAT = TAT / Number of process
// Step 8: Stop
