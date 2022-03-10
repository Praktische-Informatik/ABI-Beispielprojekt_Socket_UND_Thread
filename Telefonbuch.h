#pragma once
class CEintrag;

class CTelefonbuch
{
private:
	int maxAnzahlEintraege;
	list <CEintrag*>listeVonEintraegen;
	int anzahlEintraege;
	
public:
	void eintragEinfuegen(CEintrag*);
	void eintragLoeschen(string);
	string nrSuche(string);
	void toString();
	CTelefonbuch();
	CTelefonbuch(int);
	~CTelefonbuch();
};