#include <stdio.h>

void main(){
 int p[30], bt[30], wt[30], tat[30];
 int tot_tat = 0,  FCFS_wt = 0, tot_wat = 0;
 int n;

 printf("|n Enter the no og process\n");
 scanf("%d", &n);
 printf("Enter trhe burst time for each process\n");
 
 for (int i =0; i < n; i++){
  	scanf("%d", &bt[i]);
  	p[i] = i;
 }

 printf("\nFCFS Algorithm\n");
for (int i=0; i <n; i++){
	if(i==0)
		tat[i] = bt[i];
	else {
			tat[i] = tat[i-1] + bt[i];
			tot_tat = tot_tat + tat[i];
		}
	}
	
	printf("\nProcess\t\t Burst Time\tTurn Around Time\t Waiting Time");
	
	for (int i=0; i < n; i++){
		printf("\nProcess[%d]\t\t %d \t %d \t %d", p[i], bt[i], tat[i], wt[i]);
	}
	
	printf("\n\nTotal Turn Around Time: %d", tot_tat);
	printf("\nAverage Turn Around Time: %d", tot_tat / n);
	printf("\nTotal Wating Time: %d", tot_wat);
	printf("\nAverege Wating Time: %d", tot_wat / n);
}
