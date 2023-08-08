#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
key_t key = ftok("hehe",65);
int shmid =   shmget(key,1024,0666|IPC_CREAT);
printf("IPC ID:%d\n",shmid);

int n;
printf("1.Read\n2.Write\n3.Remove\n4.Show All IPc\n");
scanf("%d",&n);

switch(n)
{
 case 1:
        {
        char *str = (char*) shmat(shmid,0,0);
        printf("Data: %s\n", str);
        shmdt(str);
        break;
        }
case 2:
       {
       char *str=(char*) shmat(shmid,0,0);
       printf("enter the data");
       scanf("%s",str);
       shmdt(str);
       break;
       }
case 3:
      {
       shmctl(shmid,IPC_RMID,0);
       break;
       }
case 4 :
        {
        system("ipc -m");
        break;
        }
}


} 
