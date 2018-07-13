#include "Task.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
class MyTask : public Task
{
public:
	MyTask()
	{
	}
	MyTask(int clientfd)
	{
		m_clientfd = clientfd;
	}
	~MyTask()
	{
	}
	void setClientfd(int clientfd)
	{
		m_clientfd = clientfd;
	}
	void doTask()
	{
		const int size = 1024;
		char buff[size];
		int len;
		if ((len = read(m_clientfd, buff, size)) < 0)
		{
			printf("recv error\n");
			return;
		}

		if (write(m_clientfd, buff, strlen(buff)) < 0)
		{
			printf("send error\n");
			return;
		}
		cout << "send finish\n";
		close(m_clientfd);

	}
private:
	int m_clientfd;
};

