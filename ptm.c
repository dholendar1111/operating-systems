#include<stdio.h>
#include<graphics.h>
#include<conio.h>
int pt[10];
void main()
{
 int gd=DETECT,gm,i,j,n;
 char s[20];
 initgraph(&gd,&gm,"d:\\software\\dossoft\\tc");
 printf("Enter How many pages");
 scanf("%d",&n);
 printf("Enter Page Table Entries\n");
 for(i=0;i<n;i++)
 {
    printf("pt[%d]:",i);
    scanf("%d",&pt[i]);
 }
 setcolor(YELLOW);
 rectangle(300,100,400,400);
 j=1;
 for(i=120;i<=400;i+=20)
 {
 line(300,i,400,i);
 sprintf(s,"Frame No:%d ",j);
 j++;
 outtextxy(200,i-10,s);
 }
 for(i=0;i<n;i++)
 {
  if(pt[i]!=0)
  {
   setcolor(4);
   settextjustify(0,0);
   sprintf(s,"   Page-%d",i);
   outtextxy(300,100+pt[i]*20,s);
  }
 }
 getch();
}
