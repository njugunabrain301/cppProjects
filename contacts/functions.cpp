#include "Variables.h"

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//
//		input 		: N/A
//		output		: pointer to the head of the linked-list
//		description : reads the content of the file "rapper_names.txt" and
//					  builds the linked-list
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
ContactList *Read()
{

	ifstream inFile;
	string tmp;

	inFile.open("contacts.txt"); // Contacts.cpp List.txt

	if (inFile.fail())
	{
		cout << "\nThe file did not successfully open... Program Terminated\n" << endl;
		exit (1);
	}
	else{
		cout << "\nFile Opened\n" << endl;

	}

	ContactList *current, *head;

	current = new ContactList;
	head = current;

	while(!inFile.eof()){
        string name, number, email;
        getline(inFile, name);
        getline(inFile, number);
        getline(inFile, email);
        getline(inFile, tmp);

        current->name = name;
        current->cellnumber = number;
        current->emailAddress = email;
        if(tmp == "0")
            current->ICE = false;
        else
            current->ICE = true;
        current->nextcontact = new ContactList;
        current = current->nextcontact;
	}
	inFile.close();

	return (head);
}

ContactList *Write(ContactList *head){
	ofstream outfile; // write to file
	outfile.open("contacts_updated.txt");
    ContactList * current = head;
    while(current != NULL){
        outfile << current->name<<endl;
        outfile << current->cellnumber << endl;
        outfile << current->emailAddress << endl;
        outfile << current->ICE << endl;

        current = current->nextcontact;
    }
	outfile.close();

	return(0);
}



// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// display_rappers()
//
//		input 		: pointer to head of list
//		output		: void
//		description : displays the rappers' names in the linked-list
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Show(ContactList *head)
{
	ContactList *current = head;
	int num = 0;
	while(current != NULL)
	{
		cout << (num + 1) << ")" << setw(5) << current->name << setw(20)
			 << current->cellnumber << setw(5) << current-> emailAddress << setw(10);

		if(current->ICE == true)
		{
			cout << "<--- Emergency Contact";
		}
		cout <<endl;

		current = current->nextcontact;
	}
	return ; //return (0)
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// delete_rapper()
//
//		input 		: pointer to the head of the linked-list and the
//					  position in the list where the name is to be deleted.
//		output		: pointer to the head of the updated linked-list.
//		description : deletes the rapper's name at the postion entered.
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
ContactList *Delete(ContactList *head, int m)
{

	ContactList *current, *previous;

	current = head;

	if (m==1)
	{
		head = current->nextcontact;
	}
	else
	{
		for (int i=1; i<m; i++)
		{
			previous = current;
			current = current->nextcontact;
		}
		previous->nextcontact = current->nextcontact;
	}
	delete(current);
	return(head);
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// insert_rapper()
//
//		input 		: pointer to the head of the linked-list and the
//					  position in the list where the name is to be deleted.
//		output		: pointer to the head of the updated linked-list.
//		description : inserted the rapper's name at the postion entered.
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

ContactList *insert(ContactList *head, int m)
{

	ContactList *current, *previous, *tmp;

	current = head;
	tmp = new ContactList;
	cout << "Contact's Name : ";
	cin >> tmp->name;
    cout << "Contact's Number : ";
	cin >> tmp->cellnumber;
	cout << "Contact's Email : ";
	cin >> tmp->emailAddress;
	cout << "Contact's ICE (0 for false, 1 for true) : ";
	string inICE;
	cin >> inICE;
	if(inICE == "0")
        tmp->ICE = false;
    else
        tmp->ICE = true;
	if (m==1)
	{
		tmp->nextcontact = current;
		head = tmp;
	}
	else
	{
		for (int i=1; i<m; i++)
		{
			previous = current;
			current = current->nextcontact;
		}
		tmp->nextcontact = current;
		previous->nextcontact = tmp;
	}
	return (head);
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Update()
//
//		input 		: pointer to the head of the linked-list and the
//					  position in the list where the name is to be Updated.
//		output		: pointer to the head of the updated linked-list.
//		description : Prompts the user to enter the contact info and updates
//					  this info in the linked list at the position entered
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
ContactList *Update(ContactList *head, int m)
{
	Delete(head, m);
	insert(head, m);
	return(head);
}

ContactList *Quit(){
    exit(0);
}

ContactList *Toggle(ContactList * head, int m){
    ContactList *current;

	current = head;


		for (int i=0; i<m; i++)
		{
			current = current->nextcontact;
		}
		if(current->ICE)
            current->ICE = false;
        else
            current->ICE = true;
	return(head);
}
