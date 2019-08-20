import java.util.*;
public class roundrobin
{
    public static void main(String args[])
    {
        int tq,i,j,n,m,ttat=0,twt=0;;
        int[] need= new int[10];
        int[] wt= new int[10];
        int[] tat = new int[10];
        int[] bt = new int[10];
        int[] flag = new int[10];
        float awt,atat;
        System.out.println("Enter the number of processes");
        Scanner sc = new Scanner(System.in);
        n= sc.nextInt();
        m=n;
        System.out.println("Enter the time slice");
        tq = sc.nextInt();
        for(i=0;i<n;i++)
        {
            System.out.println("Enter the burst time for process"+(i+1));
            bt[i] = sc.nextInt();
            need[i] = bt[i];
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

    System.out.println("\n\nProcess\tBurst time\tWait time\tTatime\n");
    for(i=0;i<m;i++)
    {
       System.out.println("\n"+(i+1)+"\t\t"+bt[i]+"\t\t"+wt[i]+"\t\t"+tat[i]);
    }
         System.out.println("\n The average waiting time ="+awt);
         System.out.println("\n The average turn around time ="+atat);
  }
}
