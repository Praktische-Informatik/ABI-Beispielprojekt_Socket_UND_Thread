#include "CEintrag.h"
#include <string>
using namespace std;

CEintrag::CEintrag(string n_init, string nr_init)
{
	name = n_init;
	telefonnr = nr_init;
}

CEintrag::~CEintrag()
{
}

string CEintrag::getNr()
{
	return telefonnr;
}

string CEintrag::getName()
{
	return name;
}

void CEintrag::setNr(string tmp)
{
	telefonnr = tmp;
}

void CEintrag::setName(string tmp)
{
	name = tmp;
}
