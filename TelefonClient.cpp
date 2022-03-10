
#include "CSocket.hpp"
#include "TelefonClient.h"
#include <iostream>
#include <string>
using namespace std;

bool TelefonClient::menu(){
	
	return 0;
}

bool TelefonClient::verbinden(string server, int port){

	clientSocket = new CSocket(server,port); 
	string text="", antwort="";
	cout<<"Warte auf Serververbindung"<<endl;

	while(clientSocket->connect() == 0)	
	{
		cout<<".";    
		Sleep(500);   
	}
	cout<<"\nVerbunden mit dem Server"<<endl;

	do{
		cout << "Name eingeben: oder EXIT "<<endl;
		cin >> text;

		clientSocket->write(text);
		antwort=clientSocket->readLine();

		cout << "Telefonnummer von " << text << " lautet: " <<  antwort << endl;
	}while(text!="EXIT");

	return true;
}

bool TelefonClient::abmelden()
{
	clientSocket->close();  
	return true;
}

TelefonClient::TelefonClient(void)
{
	clientSocket = nullptr;
}


TelefonClient::~TelefonClient(void)
{
	delete clientSocket;
}
