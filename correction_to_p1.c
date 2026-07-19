#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(int argc, char *argv[])
{
//This is a corrected version of the erroneous code that we saw in the previous example.
//fork() works exponentially , so when you created a child function and didn't explicitly ended it, it called fork() and
//created its own child process! so one makes two, two make four and four make eight and so on!!!!!!!
//to fix this we can have wait(). Also another issue worth flagging is the possibility of orphan processes in the previous code! 
//so main() can finish even before child proceeses are done!!!!!!!!!! so overwriting the terminal.
for(int i=0;i<5;i++)
{
int child =  fork();
if(child <0)
{
fprintf(stderr,"Error!\n");
exit(1);
}
else if(child == 0)
{
printf("Child with pid: %d has been created. The parent of this child is with pid : %d\n", (int)getpid(),(int)getppid());
exit(0); //necessay to stop the child from breeding!!!!!! ;)
}
}
for(int j = 0;j<5;j++)
{
wait(NULL);
}
return 0;
}
