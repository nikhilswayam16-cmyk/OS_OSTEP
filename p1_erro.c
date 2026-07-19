#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int agrc, char *argv[])
{
//Now this c program may look normal to a normal eye but if you are clever enough, you would realize that it is not so! check
// out, if you can find any error in this code!
printf("Hello! we are today going to learn about process API. \n");
for(int i = 0; i<5 ;i++){
int child = fork();
if(child < 0)
{
fprintf(stderr,"fork failed\n");
}
else if(child == 0)
{
printf("Success! pid of child : %d\n",child);
}
else {
printf("Here is the parent of pid : %d\n", (int)getpid());
}
}
return 0;
}
