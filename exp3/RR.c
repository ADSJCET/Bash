#include <stdio.h>

void main() {
	 int limit, x, counter = 0, time_quantum; 
	 int wt = 0, tat = 0,  bt[10], temp[10]; 
	 float avg_wt, avg_tat;
	 printf("\nEnter Total Number of Processes:\t"); 
	 scanf("%d", &limit); 
	 x = limit; 
	 
	 for(int i = 0; i < limit; i++) {
		 printf("\nEnter Details of Process[%d]\n", i + 1);
		 printf("Burst Time:\t");
		 scanf("%d", &bt[i]); 
		 temp[i] = bt[i];
	 }
	 
	 printf("\nEnter Time Quantum:\t"); 
	 scanf("%d", &time_quantum); 
	 printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
	 
	 for(int total = 0, i = 0; x != 0;) { 
		 if(temp[i] <= time_quantum && temp[i] > 0) { 
			 total = total + temp[i]; 
			 temp[i] = 0; 
			 counter = 1; 
		 } 
		 else if(temp[i] > 0) { 
			 temp[i] = temp[i] - time_quantum; 
			 total = total + time_quantum; 
		 } 
		 
		 if(temp[i] == 0 && counter == 1) { 
			 x--; 
			 printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1,
			  bt[i], total, total - bt[i]);
			  
			 wt = wt + total - bt[i]; 
			 tat = tat + total ; 
			 counter = 0; 
		 } 
		 
		 if(i == limit - 1)
			 i = 0; 
		 else
			 i++;
	 } 
	
	avg_wt = wt * 1.0 / limit;
	avg_tat = tat * 1.0 / limit;
	
	printf("\n\nAverage Waiting Time:\t%f", avg_wt); 
	printf("\nAvg Turnaround Time:\t%f\n", avg_tat); 
}
