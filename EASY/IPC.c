#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main() {
	key_t key = ftok("hehe",65);
	
	int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
	printf("IPC ID: %d\n", shmid);
	
	int x;
	printf("1.Read\n2.Write\n3.Remove\n4.Show All IPCs\n");
	scanf("%d", &x);
	
	if(x == 1){
		char *str = (char*) shmat(shmid, 0, 0);
		printf("Data: %s\n",	str);	
		shmdt(str);	
	}
	else if (x == 2){
		char *str = (char*) shmat(shmid, 0, 0);
		printf("Enter Data: ");
		scanf("%s",str);
		shmdt(str);
	}
	else if (x == 3) shmctl(shmid, IPC_RMID, 0);
	else if (x == 4) system("ipcs -m");
	else printf("Invalid Command");

	return 0;
}
