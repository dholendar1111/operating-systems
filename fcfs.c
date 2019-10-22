#include<stdio.h>

int main()
{
 int i,n,wt[10],bt[10],tat[10],twt=0,ttat=0;
 float avgwt,avgtat;

 printf("Enter How Many Processes?");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  printf("Enter Burst Time for process %d:",i+1);
  scanf("%d",&bt[i]);
 }
 wt[0]=0;
 for(i=0;i<n;i++)
 {
  wt[i+1]=wt[i]+bt[i];
  tat[i]=wt[i]+bt[i];
  twt=twt+wt[i];
  ttat=ttat+tat[i];
 }
 avgwt=(float)twt/n;
 avgtat=(float)ttat/n;
 printf("\nProcessID  BurstTime  WaitingTime  TurnAroundTime\n");
 for(i=0;i<n;i++)
  printf("\n\n%d\t\t%d\t\t%d\t\t%d\n",n+1,bt[i],wt[i],tat[i]);
 printf("\nTotal Waiting Time:%d\n",twt);
 printf("Total TurnAroundTime:%d\n\n",ttat);
 printf("Average Waiting Time:%4.2f\n",avgwt);
 printf("Average TurnAroundTime:%4.2f",avgtat);

}
