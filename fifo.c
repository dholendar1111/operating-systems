#include <stdio.h>

int buf[20];
int main()
{
 int npg,size,pg[30];
 int i,j,m,k=1,count=0,flag=1,pfcount=0;
 printf("\nFIFO");
 printf("\nEnter the number of pages:");
 scanf("%d",&npg);
 printf("Enter the buffer size:");
 scanf("%d",&size);
 for(i=1;i<=npg;i++)
 {
  printf("Enter page frame %d:",i);
  scanf("%d",&pg[i]);
 }

 for(i=1;i<=npg;i++)
 {
  for(j=1;j<=size;j++)
   {
    if(pg[i]==buf[j])
    flag=0;
   }
   if(flag==0)
    {
     flag=1;
     continue;
    }
   else
   {
   buf[k]=pg[i];
   count++;
   if(count>size)
   {
    pfcount++;
    printf("page:%d buffer content:",pg[i]);
    for(m=1;m<=size;m++)
     printf("%d ",buf[m]);
    printf("\n");
   }
   if(k<size)
    k++;
   else
    {
    k=1;
    }
   }
  }
  printf("no.of page faults=%d",pfcount);

 }

