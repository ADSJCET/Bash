#include <stdio.h>
void allZero (int arr[], int x){
	for (int i=0; i < x; i++) arr[i] = 0;
}
int main() {
	int ABC, P;
	
	printf("\nEnter the number of processes and the number of resources:\n");
	scanf("%d%d", &P, &ABC);
	
	printf("\nEnter maximum instances of resources\n");
	int Resource[ABC];
	for (int x = 0; x < ABC; x++){
		scanf("%d", &Resource[x]);
	}
	
	int MAX[P][ABC];
	printf("\nEnter MAX matrix\n");
	for (int x = 0; x < P; x++){
		for (int y = 0; y < ABC; y++){
			scanf("%d", &MAX[x][y]);
		}
	}
	
	int ALLOC[P][ABC] , NEED[P][ABC];
	printf("\nEnter ALLOC matrix\n");
	for (int x = 0; x < P; x++){
		for (int y = 0; y < ABC; y++){
			scanf("%d", &ALLOC[x][y]);
			
			NEED[x][y] = MAX[x][y] - ALLOC[x][y];
			
		}
	}
	int TotalALLOC[ABC];
	for (int y = 0; y < ABC; y++){
			int A = 0;
			for (int x = 0; x < P; x++){
					A += ALLOC[x][y];
			}
			TotalALLOC[y] = A;
	}
	
	int WORK[ABC]; // AVAILABLE
	for (int x = 0; x < ABC; x++) WORK[x] = Resource[x] - TotalALLOC[x];
	
	
	int FINISH[P];
	int SAFEseq[P];
	
	allZero(FINISH, P);
	allZero(SAFEseq, P);
	
	int safeIndex = 0;
	for (int k = 0; k < P	; k++){
	for (int x = 0; x < P; x++){
		if (FINISH[x] == 0){
			int Bool = 1;
			for(int y=0; y < ABC; y++){
				if (NEED[x][y] > WORK[y]) Bool = 0;					
			}
			
			if(Bool){
				for(int y=0; y < ABC; y++){
					WORK[y] += ALLOC[x][y];				
				}
				FINISH[x] = 1;
				SAFEseq[safeIndex++] = x + 1;
					
			}
		}
	}
	}
	
	for (int x = 0; x < P; x++){
		if (FINISH[x] == 0) {
			printf("\nSystem is in unsafe state");
			return 0;
		}
	}
	printf("Safe Sequence");
	for (int x = 0; x < safeIndex; x++){
		printf("P%d\t", SAFEseq[safeIndex]);
	}


}
