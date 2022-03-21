#pragma once
#include "CServerSocket.hpp"
#include "WorkSocketThread.h"
#include "Telefonbuch.h"

class CTelefonbuchServer
{
private:
	CServerSocket *serverSocket;
	WorkSocketThread* wsThread[3];
	CTelefonbuch* telefonbuch;
	bool lock; 

public:
	void startServer(int port);
	CTelefonbuch* getTelefonbuch();
	CTelefonbuchServer();
	~CTelefonbuchServer();
};