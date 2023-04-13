#include <stdio.h>

int swap(int *a, int *b){
	int t;
	t = *a;
	*a = *b;
	*b = t;
	return 0;
}

void main(){

	int n, tot_tat=0, tot_wt=0, SJF_wt=0,SJF_tat=0;
	int p[30], bt[30], wt[30], tat[30];
	float awt,avg_tat,avg_wt;
	printf("\nEnter the no.of processes \n");
	scanf("%d",&n);
	printf("Enter burst time for each process\n");
	
	for(int i=0; i<n; i++){
		scanf("%d",&bt[i]);
		p[i] = i;
	}
	
	for(int i=0; i<n; i++){
		for(int j = i+1; j<n; j++){
			if(bt[i]>bt[j]){
				swap(&bt[j],&bt[i]);
				swap(&p[j],&p[i]);
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		if(i==0)
			tat[i] = bt[i];
		else
			tat[i] = tat[i-1] + bt[i];
			
		tot_tat=tot_tat+tat[i];
	}
	
	wt[0]=0;
	for(int i=1;i<n;i++){
		wt[i]=wt[i-1]+bt[i-1];
		tot_wt = tot_wt+wt[i];
	}
	
	printf("\nPROCESS\t\tBURST TIME\tTURN AROUND TIME\tWAITING TIME");
	for(int i=0; i<n; i++)
		printf("\nprocess[%d]\t\t%d\t\t%d\t\t%d",p[i]+1,bt[i],tat[i],wt[i]);
		printf("\n\nTotal Turn around Time:%d",tot_tat);
		printf("\nAverage Turn around Time :%d ", tot_tat /n);
		printf("\nTotal Waiting Time:%d",tot_wt);
		printf("\nTotal avg. Waiting Time:%d",tot_wt /n);
	}
	
	
