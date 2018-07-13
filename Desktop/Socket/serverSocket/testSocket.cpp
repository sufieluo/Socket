#include "ServerSocket.h"
#include "WorkQueue.h"
#include "WorkThreadPool.h"
#include "MyTask.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;


int main()
{
	ServerSocket server;
	server.initSocket();
	int server_fd = server.getServerfd();
	int client_fd;
	
	WorkThreadPool *threadPool = new WorkThreadPool(2);

	while (1)
	{
		if ((client_fd = accept(server_fd, NULL, NULL)) < 0)
		{
			continue;
		}
		cout << "client_fd" << client_fd << endl;
		Task *task = new MyTask(client_fd);
		threadPool->addTask(task);
	}
	close(server_fd);
	return 0;
}