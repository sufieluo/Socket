#ifndef _WORKER_H_
#define _WORKER_H_

#include "WorkQueue.h"
#include "Thread.h"
#include <unistd.h>
#include <iostream>
class Worker :public Thread
{
public:
	Worker()
	{
	}
	Worker(WorkQueue *aqueue,int id)
	{
		m_queue = aqueue;
		m_threadID = id;
	}
	~Worker()
	{
	}

	void run()
	{
		while (1)
		{
		
			while (!m_queue->isEmpty())
			{
				
				Task *task = m_queue->pop();
				cout << "Thread " << pthread_self() << " doing Task " << endl;
				task->doTask();
				
			}
			//sleep(10);
			
		}
	}
private:
	WorkQueue *m_queue;
	pthread_t m_threadID;
};

#endif