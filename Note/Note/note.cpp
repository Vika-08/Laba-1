#include "note.h"

Note::Note()
{
	name = "empty";
	telephone = 88005553535;
	for (int i = 0; i < 3; i++) date[i] = 0;
}

void Note::set(string name, long long int telephone, int *date)
{
	this->name = name;
	this->telephone = telephone;
	for (int i = 0; i < 3; i++) this->date[i] = date[i];
}

void Note::get(int ID)
{
	cout << ID + 1 << "\t\t\t" << name << "\t\t\t\t\t" << telephone << "\t\t\t";
	for (int i = 0; i < 3; i++)
	{
		cout << date[i];
		if (i < 2) cout << ".";
	}
	cout << endl;
}

int Note::get_day()
{
	return date[0];
}

int Note::get_month()
}