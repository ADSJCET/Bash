#include <stdio.h>

int main() {
	int f;
	printf("Enter no of Frames");
	scanf("%d", &f);
	
	int frames[f] = {-1};
	printf("Enter no of pages");
	
	int p;
	printf("Enter no of pages");
	scanf("%d", &p);
	
	int page[p];
	printf("Enter pages");
	for(int i=0; i < p; i++) scanf("%d", &page[i]);
	
	printf("%d %d", page[1],frames[1] );
	
	for(int i=0; i < p; i++) {
		int avail = 0;
		
		printf("%d\t", page[i]);
		for(int x=0; x < f; x++) {
			frames[x] == -1 ? printf(" - ") : printf(" %d ",frames[i]);
			if (frames[x] == page[i]){
				avail = 1;
				printf(
			}
		}	
	}
}
