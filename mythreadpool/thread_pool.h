#ifndef THREADPOOL_H
#define THREADPOOL_H
#include<queue>
#include<thread>
#include <exception>
#include "../lock/locker.h"
#include "../CGImysql/sql_connection_pool.h"
template <typename T>
class threadpool {
public:
    threadpool() ;
    threadpool(int actor_model, int thread_num, int request_num);
    ~threadpool();
    bool append(T* req, int state);
    bool append_p(T* req);
    


private:
    int m_thread_num;
    int m_request_num;
    std::queue<T*> requests;
    std::thread *m_threads;
    sem m_sem;
    locker m_lock;
    connection_pool *m_connPool;
    int actor_model;
};


#endif