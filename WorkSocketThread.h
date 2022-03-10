#pragma once
#include "Thread.h"
#include "CSocket.hpp"
#include "Telefonbuch.h"

class WorkSocketThread : public CThread
{
private:
	CSocket* workSocket;
	static int anzahlClients;
	int nummer;
	bool aktiv;	
	bool* lock;		// Synchronisation der Threads (Schreibrechte darf nur einer haben)
	CTelefonbuch* telefonbuch;

public:
	WorkSocketThread(CSocket* ws, CTelefonbuch* d, bool* l);
	virtual void run();
	bool get_aktiv();
	~WorkSocketThread();
};

