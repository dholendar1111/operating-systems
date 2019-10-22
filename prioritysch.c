#include<stdio.h>
int main(void)
{
 void sort(int[],int[],int[],int);
 int i,n,p[10],pr[10],wt[10],bt[10],tat[10],twt=0,ttat=0;
 float avgwt,avgtat;

 printf("Enter How Many Processes?");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  printf("Enter Burst Time and priority for process %d:",i+1);
  scanf("%d%d",&bt[i],&pr[i]);
  p[i]=i+1;
 }
 sort(bt,pr,p,n);
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
 printf("\nProcessID  Priority BurstTime  WaitingTime  TurnAroundTime\n");
 for(i=0;i<n;i++)
  printf("\n\n%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],pr[i],bt[i],wt[i],tat[i]);
 printf("\nTotal Waiting Time:%d\n",twt);
 printf("Total TurnAroundTime:%d\n\n",ttat);
 printf("Average Waiting Time:%4.2f\n",avgwt);
 printf("Average TurnAroundTime:%4.2f",avgtat);
}
void sort(int bt[],int pr[],int p[],int n)
{
 int i,j,t;
 for(i=0;i<n;i++)
  for(j=0;j<n-1;j++)
  if(pr[j]>pr[j+1])
  {
   t=pr[j];
   pr[j]=pr[j+1];
   pr[j+1]=t;
   t=bt[j];
   bt[j]=bt[j+1];
   bt[j+1]=t;
   t=p[j];
   p[j]=p[j+1];
   p[j+1]=t;
  }
 }
