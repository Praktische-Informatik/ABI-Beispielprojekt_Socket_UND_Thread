
#include "TelefonbuchServer.h"
#include <iostream>
#include <string>
using namespace std;

CTelefonbuchServer::CTelefonbuchServer(int port)
{
	serverSocket = new CServerSocket(port);
	telefonbuch = new CTelefonbuch(10);
}

CTelefonbuchServer::~CTelefonbuchServer(void)
{
	serverSocket->close();
	delete serverSocket;
	delete telefonbuch;
}

void CTelefonbuchServer::run()
{
	lock = false;				//Zugriff erlaubt !!

	for (int j = 0; j < 3; j++)
	{
		CSocket* workSocket;
		cout << "Warten auf Verbindungsanfrage Nr. " << j + 1 << " (Blockierende accept-Funktion)!" << endl;
		workSocket = serverSocket->accept();  //Blockierende Funktion
		cout << "Verbindung" << "zum " << j + 1 << ". Client akzeptiert... " << endl;
		// 
		work_sock_Threads[j] = new WorkSocketThread(workSocket, telefonbuch, &lock);
		work_sock_Threads[j]->start();
	}
	//Warten bis alle Threads geschlossen sind !!

	while (work_sock_Threads[0]->get_aktiv() || work_sock_Threads[1]->get_aktiv() || work_sock_Threads[2]->get_aktiv());
	cout << "Alle Clients abgemeldet!" << endl;

	for (int j = 0; j < 3; j++)
		delete work_sock_Threads[j];
}

CTelefonbuch* CTelefonbuchServer::getTelefonbuch()
{
	return telefonbuch;
}
