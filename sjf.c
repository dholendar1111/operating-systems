#include<stdio.h>

int main()
{
 void sort(int[],int[],int);
 int i,n,p[20],wt[20],bt[20],tat[20],twt=0,ttat=0;
 float avgwt,avgtat;
 printf("Enter How Many Processes?");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  printf("Enter Burst Time for process %d:",i+1);
  scanf("%d",&bt[i]);
  p[i]=i+1;
 }
 sort(bt,p,n);
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
  printf("%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],wt[i],tat[i]);
 printf("Total Waiting Time:%d\n",twt);
 printf("Total TurnAroundTime:%d\n\n",ttat);
 printf("Average Waiting Time:%4.2f\n",avgwt);
 printf("Average TurnAroundTime:%4.2f",avgtat);

}
void sort(int bt[],int p[],int n)
{
 int i,j,t;
 for(i=0;i<n;i++)
  for(j=0;j<n-1;j++)
  if(bt[j]>bt[j+1])
  {
   t=bt[j];
   bt[j]=bt[j+1];
   bt[j+1]=t;
   t=p[j];
   p[j]=p[j+1];
   p[j+1]=t;
  }
 }
