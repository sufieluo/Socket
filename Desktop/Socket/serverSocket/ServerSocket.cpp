#include "ServerSocket.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#define PORT 6666
using namespace std;


ServerSocket::ServerSocket()
{
	
}

ServerSocket::~ServerSocket()
{
}
void ServerSocket::initSocket()
{
	m_iServerfd = socket(AF_INET, SOCK_STREAM, 0);
	m_serverAddr.sin_family = AF_INET;
	m_serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	m_serverAddr.sin_port = htons(PORT);

	bind(m_iServerfd, (sockaddr*)&m_serverAddr, sizeof(m_serverAddr));

	listen(m_iServerfd, 10);
	
}

int ServerSocket::getServerfd()
{
	return m_iServerfd;
}


