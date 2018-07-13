#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

class ServerSocket
{
public:
	ServerSocket();
	~ServerSocket();
	void initSocket();
	int getServerfd();
private:
	int m_iServerfd;
	sockaddr_in m_serverAddr;
};

