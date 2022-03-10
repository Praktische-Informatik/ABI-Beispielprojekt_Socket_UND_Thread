// CThread.h: Klasse zur Erzeugung von Threads in Anlehnnung an die im Abitur
//            verwendete java-Klasse Thread
//
//  
//  Andreas John 02.03.2018
//
//  Hinweise zur Verwendung:
//
		//class CMyThread : public CThread
		//{
		//private:
		//...
		//public:
		//...

		//virtual void run(){
		//	//Ausformulierung der run-Funktion, die als Thread läuft
		//	};

		//virtual bool start()
		//{
		//	// Initianisierungsaufgaben
		//	CThread::start();
		//	return true;
		//};
//
//
//////////////////////////////////////////////////////////////////////


#pragma once
#include <string>
#include <thread>
#include <windows.h>
using namespace std;

class CThread
{
private:
	thread* p_thread;
public:
	CThread(void);
	~CThread(void);
	virtual void run() = 0 ;
	void test(){};
	virtual bool start(void);
	void sleep(long);
	
};

