#include <stdio.h>

void add(int value, int arr[], int len){
	for(int i =0; i< len; i++){
		if (arr[i] == -1){
			arr[i] = value;
			return;
		}
	}
	arr[0] = value;
}

int main() {
	int f;
	printf("Enter no of Frames ");
	scanf("%d", &f);
	
	int frames[f];
	for(int i=0; i < f; i++) frames[i] = -1;
	
	int p;
	printf("Enter no of pages ");
	scanf("%d", &p);
	
	int page[p];
	printf("Enter Pages\n");
	for(int i=0; i < p; i++) scanf("%d", &page[i]);
	
	
	for(int i=0; i < p; i++) {
		int avail = 0;
		
		printf("%d\t", page[i]);
		for(int x=0; x < f; x++) {
			int temp = frames[x];
			if (temp == page[i]) avail = 1;
			
		}
		if (avail == 1) printf("Hit ");	
		else {
			add(page[i], frames, f);
			printf("Miss ");		
		}
		for(int x=0; x < f; x++) {
			int temp = frames[x];
			temp == -1 ? printf(" - ") : printf(" %d ",temp);
		}
		printf("\n");	
	}
}
