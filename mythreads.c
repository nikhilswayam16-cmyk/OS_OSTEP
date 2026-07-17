#include<stdio.h>
#include<assert.h>
#include<pthread.h>
#include "common.h"
#include "common_threads.h"
static volatile int counter;
void * a(void *p){
    int temp = *(int *)p;
    printf("%d\n",temp+1);
    return NULL;
}
void* b(void *q){
    int temp = *(int *)q;
    printf("%d\n",temp+1);
    return NULL;
}
int main(int argc,char *argv[]){
    pthread_t p1, p2;
   int p = 1;
   int q = 2;
   int *pa = &p;
   int *qb = &q;
    printf("We have entered Main()\n");
    Pthread_create(&p1,NULL,a,pa);
    Pthread_create(&p2,NULL,b,qb);
    Pthread_join(p1,NULL);
    Pthread_join(p2,NULL);
    printf("WE have exited Main()\n");
    return 0;
}
