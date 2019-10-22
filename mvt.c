#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int i=0;
int main()
{
    int tot,sz,b[20],ch,size[20];
    char p[20][20],pro[10];
    int j,k,status[10],tot1;
    printf("\n Enter total Memory ::");
    scanf("%d",&tot);
    tot1=tot;
    printf("\n Enter the size of o.s::");
    scanf("%d",&sz);
    tot1=tot1-sz;
    do
    {
        printf("\n-----------------------------------------------------\n");
        printf("\n\t\tMulti Variable Task(MVT)");
        printf("\n-----------------------------------------------------\n");
        printf("\n\t\t1.Allocation\n\t\t2.Deletion\n\t\t3.Display\n\t\t4.Exit");
        printf("\n-----------------------------------------------------\n");
        printf("\n Enter Ur choice ::");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\n Enter process %d::",i+1);
                scanf("%s",p[i]);
                printf("\n Enter memory size for process%d::",i+1);
                scanf("%d",&size[i]);
                if(tot1 >=size[i])
                {
                    b[i]=size[i];
                    tot1=tot1-size[i];
                    status[i]=1;
                    i++;
                    printf("\n Process is allocated ::");
                }
                else
                    printf("\n memory size is not Available ::");

                break;
            case 2:
                printf("\n Enter a process U want to delete ::");
                scanf("%s",pro);
                j=0;
                while(j<i)
                {
                    if(strcmp(p[j],pro)==0)
                    {
                        status[j]=0;
                        tot1+=b[j];
                        b[j]-=size[j];
                    }
                    j++;
                }
                printf("\n Process is deleted ::");
                break;
               case 3:
                printf("\n\n Total Memory size ::%d",tot);
                printf("\n\n Memory size of o.s::%d",sz);
                printf("\n\n No.of processes   ::%d",i);
                printf("\n----------------------------------------------------------------------------\n");
                printf("\npname\tAllocated Memory\tStatus\n");
                printf("\n----------------------------------------------------------------------------\n");
                for(k=0;k<i;k++)
                {
                    if(b[k]!=0)
                    {
                        printf("\n%s\t\t%d\t\t",p[k],b[k]);
                        if(status[k]==1)
                            printf("Full");
                        else
                            printf("Available");
                    }
                }
                printf("\n----------------------------------------------------------------------------\n");
                printf("\n Total Available Space ::%d",tot1);
                break;
            case 4:
                exit(0);
            default:
                printf("\n Wrong Choice ::");
        }

    }while(1);
}
