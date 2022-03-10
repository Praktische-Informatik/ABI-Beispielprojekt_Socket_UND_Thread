
#include "Telefonbuch.h"
#include "CEintrag.h"
#include <iostream>
#include <string>
using namespace std;

CTelefonbuch::CTelefonbuch()
{
	anzahlEintraege = 0;
	maxAnzahlEintraege = 10;
}

CTelefonbuch::CTelefonbuch(int anzahl)
{
	maxAnzahlEintraege = anzahl;
	anzahlEintraege = 0;

	// Standardeinträge
	CEintrag* tmp0 = new CEintrag("Anton", "123");
	eintragEinfuegen(tmp0);
	CEintrag* tmp1 = new CEintrag("Betty", "456");
	eintragEinfuegen(tmp1);
	CEintrag* tmp2 = new CEintrag("Cesar", "789");
	eintragEinfuegen(tmp2);
}

CTelefonbuch::~CTelefonbuch()
{
	listeVonEintraegen.clear();
}

string CTelefonbuch::nrSuche(string such)
{
	for (CEintrag* pos : listeVonEintraegen)
	{
		if (pos->getName() == such)
		{
			return pos->getNr();
		}
	}
	return "UNKNOWN";
}

void CTelefonbuch::toString()
{
	cout << "-----Telefonbucheintraege--------" << endl;
	
	for (CEintrag* pos : listeVonEintraegen) {
		cout << pos->getName() << " " << pos->getNr() << endl;
	}
}

// muss nicht implementiert werden
void CTelefonbuch::eintragLoeschen(string loesch)
{
	for (CEintrag* pos : listeVonEintraegen)
	{
		if (pos->getName() == loesch || pos->getNr() == loesch)
		{
			listeVonEintraegen.remove(pos);
			anzahlEintraege--;
			break;
		}
	}
}

// muss nicht implementiert werden
void CTelefonbuch::eintragEinfuegen(CEintrag* einf)
{
	if (anzahlEintraege < maxAnzahlEintraege)
	{
		listeVonEintraegen.push_back(einf);
		anzahlEintraege++;
		//sortieren();
	}
}




