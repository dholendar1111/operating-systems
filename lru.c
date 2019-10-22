#include <stdio.h>

int buf[10],index[30];
int main()
{
 int npg,size,pg[30];
 int i,j,m,k=1,x=1,victim,min,count=0,flag=1,pfcount=0;
 printf("\nLRU");
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
     index[pg[i]]=x++;
     flag=1;
     continue;
    }
   else
   {
   index[pg[i]]=x++;
    victim=1;
    min=index[buf[1]];
    for(j=2;j<=size;j++)
    {
     if(index[buf[j]]<min)
     {
      min=index[buf[j]];
      victim=j;
     }
    }
    if(i<=size)
     buf[k]=pg[i];
    else
    buf[victim]=pg[i];
   count++;
   if(count>size)
   {
    pfcount++;
    printf("page:%d::buffer content:",pg[i]);
    for(m=1;m<=size;m++)
     printf("%d ",buf[m]);
    printf("\n");
   }
   if(k<size)
    k++;
   else
    k=1;
   }
  }
  printf("no.of page faults=%d",pfcount);
 
 }
