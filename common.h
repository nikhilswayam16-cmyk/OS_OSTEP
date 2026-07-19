#ifndef __common_h__
#define __common_h__
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>
 
// ------------------------
// Error-checking wrappers
// ------------------------
 
static void *Malloc(size_t size) {
    void *p = malloc(size);
    if (p == NULL) {
        perror("malloc");
        exit(1);
    }
    return p;
}
 
static void Pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                            void *(*start_routine)(void *), void *arg) {
    int rc = pthread_create(thread, attr, start_routine, arg);
    assert(rc == 0);
}
 
static void Pthread_join(pthread_t thread, void **value_ptr) {
    int rc = pthread_join(thread, value_ptr);
    assert(rc == 0);
}
 
static void Pthread_mutex_lock(pthread_mutex_t *mutex) {
    int rc = pthread_mutex_lock(mutex);
    assert(rc == 0);
}
 
static void Pthread_mutex_unlock(pthread_mutex_t *mutex) {
    int rc = pthread_mutex_unlock(mutex);
    assert(rc == 0);
}
 
static void Pthread_cond_signal(pthread_cond_t *cond) {
    int rc = pthread_cond_signal(cond);
    assert(rc == 0);
}
 
static void Pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex) {
    int rc = pthread_cond_wait(cond, mutex);
    assert(rc == 0);
}
 
#endif // __common_h__