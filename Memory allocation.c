#include<stdio.h>

#include<conio.h>

int main()

{

int p[20],f[20],min,minindex,n,i,j,c,f1[20],f2[20],f3[20],k=0,h=0,flag,t=0,n1;

clrscr();

printf("enter the number of memory partitions:\n");

scanf("%d",&n);

printf("enter the number of process");

scanf("%d",&n1);

for(i=0;i<n;i++)

{

printf("\n enter the memory partition size %d:",i+1);

scanf("%d",&f[i]);

f2[i]=f[i];

f3[i]=f[i];

}

for(i=0;i<n;i++)

{

printf("\n enter the page size %d:",i+1);

 L SAI KISHORE

 36110657

38

scanf("%d",&p[i]);

}

do

{

printf("\n1.first fit\n");

printf("\n2.best fit\n");

printf("\n3.worst fit\n");

printf("\nenter your choice\n");

scanf("%d",&c);

switch(c)

{

case 1:

for(i=0;i<n1;i++)

{

for(j=0;j<n;j++)

{

f1[i]=0;

if(p[i]<=f[j])

{

f1[i]=f[j];

f[j]=0;

break;

}

}

}

 L SAI KISHORE

 36110657

39

break;

case 2:

for(i=0;i<n1;i++)

{

min=9999;

minindex=-1;

for(j=0;j<n;j++)

{

if(p[i]<=f2[j] && f2[j]!=0 && min>f2[j])

{

min=f2[j];

minindex=j;

}

}

f1[i]=f[minindex];

f2[minindex]=0;

}

break;

case 3:

for(i=0;i<n1;i++)

{

f1[i]=0;

for(j=0;j<n;j++)

{

if(p[i]<f3[j])

 L SAI KISHORE

 36110657

40

{

k++;

if(k==1)

f1[i]=f3[j];

if(f1[i]<=f3[j])

{

flag=1;

f1[i]=f3[j];

h=j;

}

}

}

k=0;

if(flag==1)

f3[h]=0;

}

break;

default:

printf("\n out of choice");

}

printf("\n----------\n");

printf("\n|page |frame |free \n");

printf("\n----------\n");

t=0;

for(i=0;i<n1;i++)

 L SAI KISHORE

 36110657



{

h=f1[i]-p[i];

if(h<0)

h=0;

printf("\n%d\t\t%d\t\t%d",p[i],f1[i],h);

t=t+h;

}

printf("\n----------\n");

printf("\n total free spae in memory:%d",t);

}

while(c<4);

}
