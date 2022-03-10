#pragma once
#include "CServerSocket.hpp"
#include "WorkSocketThread.h"
#include "Telefonbuch.h"

class CTelefonbuchServer
{
private:
	CServerSocket *serverSocket;
	WorkSocketThread* work_sock_Threads[3];
	CTelefonbuch* telefonbuch;
	bool lock; 

public:
	void run();
	CTelefonbuch* getTelefonbuch();
	CTelefonbuchServer(int port);
	~CTelefonbuchServer();
};