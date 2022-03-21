
#include "TelefonbuchServer.h"
#include <iostream>
#include <string>
using namespace std;

CTelefonbuchServer::CTelefonbuchServer()
{
	serverSocket = nullptr;
	telefonbuch = new CTelefonbuch(10);
}

CTelefonbuchServer::~CTelefonbuchServer(void)
{
	serverSocket->close();
	delete serverSocket;
	delete telefonbuch;
}

void CTelefonbuchServer::startServer(int port)
{
	serverSocket = new CServerSocket(port);
	lock = false;				//Zugriff erlaubt !!

	for (int j = 0; j < 3; j++)
	{
		CSocket* workSocket;
		cout << "Warten auf Verbindungsanfrage Nr. " << j + 1 << " (Blockierende accept-Funktion)!" << endl;
		workSocket = serverSocket->accept();  //Blockierende Funktion
		cout << "Verbindung" << "zum " << j + 1 << ". Client akzeptiert... " << endl;
		// 
		wsThread[j] = new WorkSocketThread(workSocket, telefonbuch, &lock);
		wsThread[j]->start();
	}
	//Warten bis alle Threads geschlossen sind !!

	while (wsThread[0]->get_aktiv() || wsThread[1]->get_aktiv() || wsThread[2]->get_aktiv());
	cout << "Alle Clients abgemeldet!" << endl;

	for (int j = 0; j < 3; j++)
		delete wsThread[j];
}

CTelefonbuch* CTelefonbuchServer::getTelefonbuch()
{
	return telefonbuch;
}
