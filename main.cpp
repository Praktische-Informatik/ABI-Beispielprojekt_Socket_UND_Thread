
#include "TelefonbuchServer.h"
#include "TelefonClient.h"
#include <iostream>
using namespace std;

#define SERVERPORT 5566
#define SERVERIP "127.0.0.1"

void server();
void client();

int main()
{
	int typ;

	cout << endl << " Server\t-->[1]"
		<< endl << " Client\t-->[2]"
		<< endl << endl << "Bitte auswaehlen --> ";

	cin >> typ;

	if (typ == 1) server();
	if (typ == 2) client();

	return 0;
}

void server()
{
	CTelefonbuchServer tbServer(SERVERPORT);
	cout << "------------SERVER--------------" << endl;
	tbServer.run();

}

void client()
{
	TelefonClient tc;
	cout << "------------CLIENT--------------" << endl;
	if (tc.verbinden(SERVERIP, SERVERPORT) == false) 
		cout << "Server nicht gefunden!" << endl;
	
	if (tc.abmelden() == false)
		cout << "Nicht abgemeldet!" << endl;

}