#include "stdafx.h"
#include "WorkSocketThread.h"

WorkSocketThread::WorkSocketThread(CSocket* s, CTelefonbuch* tb, bool* l)
{
	nummer = ++anzahlClients;
	workSocket = s;
	aktiv  = false; // sind alle drei WorkSockets false, werden alle WS gelöscht mit delete
	lock = l;		 // 
	telefonbuch = tb;
	telefonbuch->toString();
}

void WorkSocketThread::run()
{
	aktiv = true;
	string anfrageName = "";
	char anfrage[100] = { 0 }; 	//workSocket->read(anfrage, sizeof(anfrage));
	string antwort;

	//Blockierende read-Funktion
	while (anfrageName != "EXIT")
	{
			anfrageName = workSocket->readLine();
			antwort = telefonbuch->nrSuche(anfrageName);
		while ((*lock) == true) {
				cout << ".";
				sleep(100);
			}

		(*lock) = true;
		cout << "Client " << nummer << "; Empfange Anfrage " << anfrageName << " ; " << "Sende Antwort " << antwort << endl;
		workSocket->write(antwort);
		(*lock) = false;
	
	}
	aktiv = false;
}

bool WorkSocketThread::get_aktiv()
{
	return aktiv;
}

WorkSocketThread::~WorkSocketThread()
{
	cout << "Client Nr. " << nummer << " wurde zerstoert!" << endl;

}

int WorkSocketThread::anzahlClients = 0;