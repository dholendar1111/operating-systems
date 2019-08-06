import java.util.*;
public class Fcfs
{
    public static void main(String args[])
    {
        int i,twt=0,ttat=0;
        int[] wt = new int[10];
        int[] bt = new int[10];
        int[] tat = new int[10];
        
        float avgwt,avgtat;
        System.out.println("Enter How Many Processes?");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(i=0;i<n;i++)
        {
            System.out.println("Enter Burst Time for process:"+(i+1));
            bt[i]=sc.nextInt();
        }
        wt[0] =0;
        for(i=0;i<n;i++)
        {
            wt[i+1]=wt[i]+bt[i];
            tat[i]=wt[i]+bt[i];
            twt=twt+wt[i];
            ttat=ttat+tat[i];      
        }
            avgwt=(float)twt/n;
            avgtat=(float)ttat/n;
            System.out.println("\nProcessID  BurstTime  WaitingTime  TurnAroundTime\n");
            for(i=0;i<n;i++)
            {
                System.out.println((n+1)+"\t"+bt[i]+"\t"+wt[i]+"\t"+tat[i]);
            }
                System.out.println("\nTotal Waiting Time"+twt+"\n");
                 System.out.println("Total TurnAroundTime:"+ttat+"\n\n");
                 System.out.println("Average Waiting Time:"+avgwt+"\n");
                 System.out.println("Average TurnAroundTime:"+avgtat+"\n");
                
            
           
    }
}
