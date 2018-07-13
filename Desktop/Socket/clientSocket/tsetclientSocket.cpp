#include <iostream>
#include "ClientSocket.h"
using namespace std;

int main(int argc, char *argv[])
{
	ClientSocket client;
	client.initSocket();
	client.passMessage();
	return 0;
}