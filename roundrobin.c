#include<stdio.h>

int main()
{
int tq,need[10],wt[10],tat[10],i,j,n,m;
int bt[10],flag[10],ttat=0,twt=0;
float awt,atat;
printf("Enter the number of processes\n");
scanf("%d",&n);
m=n;
printf("\nEnter the time slice\n");
scanf("%d",&tq);
for(i=0;i<n;i++)
{
 printf("\nEnter the burst time for process %d ",i+1);
 scanf("%d",&bt[i]);
 need[i]=bt[i];
}
for(i=0;i<n;i++)
{
 flag[i]=1;
 wt[i]=0;
}
while(n>=0)
{
 for(i=0;i<m;i++)
 {
  if(need[i]>=tq)
  {
   for(j=0;j<m;j++)
   {
    if((i!=j)&&(flag[i]==1)&&(need[j]!=0))
     wt[j]+=tq;
   }
   need[i]-=tq;
   if(need[i]==0)
   {
    flag[i]=0;
    n--;
   }
  }
  else
  {
   for(j=0;j<m;j++)
   {
    if((i!=j)&&(flag[i]==1)&&(need[j]!=0))
     wt[j]+=need[i];
   }
   need[i]=0;
   n--;
   flag[i]=0;
  }
 }
}
 for(i=0;i<m;i++)
 {
  tat[i]=wt[i]+bt[i];
  twt=twt+wt[i];
  ttat=ttat+tat[i];
 }
 awt=(float)twt/m;
 atat=(float)ttat/m;
 printf("\n\nProcess\tBurst time\tWait time\tTatime\n");
 for(i=0;i<m;i++)
 {
  printf("\n%5d\t\t%5d\t\t%5d\t\t%5d",i+1,bt[i],wt[i],tat[i]);
 }
 printf("\n The average waiting time = %4.2f",awt);
 printf("\n The average turn around time = %4.2f",atat);
}
