#include<stdio.h>

int swap(int *a, int *b){
	int t;
	t = *a;
	*a = *b;
	*b = t;
	return 0;
}


void main() {
	int tot_tat=0, tot_wt=0, PR_wt=0,PR_tat=0, n;
	int p[30], bt[30], pr[30], wt[30], tat[30];
	
	printf("\nEnter the no.of processes \n");
	scanf("%d",&n);
	
	for(int i = 0; i < n; i++) {
		printf("Enter burst time and priority of process[%d]:",i+1);
		scanf("%d%d",&bt[i],&pr[i]);
		p[i] = i;
	}
	
	for(int i=0; i<n; i++){
		for(int j = i+1; j<n; j++){
			if(pr[i] > pr[j]){
				swap(&bt[j], &bt[i]);
				swap(&p[j], &p[i]);
				swap(&pr[j], &pr[i]);
			}
		}
	}
	
	for(int i = 0; i<n; i++){
		if(i == 0)
			tat[i] = bt[i];
		else
			tat[i] = tat[i-1] + bt[i];
		tot_tat = tot_tat+tat[i];
	}
	
	wt[0] = 0;
	for(int i = 1; i<n; i++) {
		wt[i] = wt[i-1] + bt[i-1];
		tot_wt = tot_wt+wt[i];
	}
	
	printf("\nPROCESS\t\tBURST TIME\tPRIORITY\tTURN AROUND TIME\tWAITINGTIME");
	
	
	for(int i = 0; i<n; i++)
		printf("\nprocess[%d]\t\t%d\t\t%d\t\t%d\t\t%d",p[i]+1,bt[i],pr[i],tat[i],wt[i]);
		
		
	printf("\n\nTotal Turn around Time:%d",tot_tat);
	printf("\nAverage Turn around Time :%d ", tot_tat/n);
	printf("\nTotal Waiting Time:%d",tot_wt);
	printf("\nTotal avg. Waiting Time:%d",tot_wt/n);
}
