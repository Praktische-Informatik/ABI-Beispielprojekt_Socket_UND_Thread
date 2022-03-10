#pragma once
class CSocket;

class TelefonClient
{
private:
	CSocket* clientSocket;
public:
	bool verbinden(string server, int port);
	bool abmelden();
	bool menu();

	TelefonClient(void);
	~TelefonClient(void);
};

