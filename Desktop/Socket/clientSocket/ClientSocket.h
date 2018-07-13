#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
class ClientSocket
{
public:
	ClientSocket();
	~ClientSocket();
	void initSocket();
	void passMessage();
private:
	int m_iClientfd;
	sockaddr_in m_serverAddr;

};