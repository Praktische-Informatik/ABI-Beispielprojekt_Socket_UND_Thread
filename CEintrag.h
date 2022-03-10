#pragma once
#include <string>
using namespace std;

class CEintrag
{
private:
	string name;
	string telefonnr;
public:
	string getNr ();
	string getName ();
	void setNr (string);
	void setName (string);
	CEintrag(string, string);
	~CEintrag();
};