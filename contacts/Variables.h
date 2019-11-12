#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>			// needed to open file
#include <cstdlib>			// needed to exit()

using namespace std;

struct ContactList
{
	string name;
	string cellnumber;
	string emailAddress;
	ContactList *nextcontact;
	bool ICE;

};

void Show(ContactList *head);
ContactList *Read();
ContactList *Delete(ContactList *head, int m);
ContactList *insert(ContactList *head, int m);
ContactList *Update(ContactList *head, int m);
ContactList *Write (ContactList *head);
ContactList *Toggle (ContactList *head, int m);
ContactList *Quit();

