#include "StdAfx.h"
#include "CEintrag.h"


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
