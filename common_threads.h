#ifndef __common_threads_h__
#define __common_threads_h__

#include <pthread.h>
#include <semaphore.h>
#include <assert.h>

#define Pthread_create(thread, attr, start_routine, arg) assert(pthread_create(thread, attr, start_routine, arg) == 0)
#define Pthread_join(thread, value_ptr)                  assert(pthread_join(thread, value_ptr) == 0)

#define Pthread_mutex_lock(m)                            assert(pthread_mutex_lock(m) == 0)
#define Pthread_mutex_unlock(m)                          assert(pthread_mutex_unlock(m) == 0)
#define Pthread_mutex_init(m, a)                         assert(pthread_mutex_init(m, a) == 0)
#define Pthread_mutex_destroy(m)                         assert(pthread_mutex_destroy(m) == 0)

#define Pthread_cond_init(c, a)                          assert(pthread_cond_init(c, a) == 0)
#define Pthread_cond_wait(c, m)                          assert(pthread_cond_wait(c, m) == 0)
#define Pthread_cond_signal(c)                           assert(pthread_cond_signal(c) == 0)
#define Pthread_cond_broadcast(c)                        assert(pthread_cond_broadcast(c) == 0)

#define Sem_init(sem, pshared, value)                    assert(sem_init(sem, pshared, value) == 0)
#define Sem_wait(sem)                                     assert(sem_wait(sem) == 0)
#define Sem_post(sem)                                     assert(sem_post(sem) == 0)
#define Sem_destroy(sem)                                   assert(sem_destroy(sem) == 0)

#endif // __common_threads_h__