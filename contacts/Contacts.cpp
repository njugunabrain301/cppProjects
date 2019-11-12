// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title : Circuits_List.cpp
// Course : Computational Problem Solving II (CPET-321)
// By : John Alvarez
// Date : 9/22/19
// Description : Program that opens list.txt and preforms a number of actions on the list.
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "Variables.h"
int main()
{
	ContactList *head;
	char n;
    while(true){
            cout << "Contact List Menu:" << endl;
		cout << "(R)ead File" << setw(20) << "(W)rite File" << setw(20)
			 << "(S)how Contacts" << setw(20) << "(I)nsert Contact" << endl;
		cout << "(D)elete Contact" << setw(19) << "(U)pdate Contact" << setw(13)
			 << "(T)oggle ICE" << setw(13) << "(Q)uit" << endl;

		cout << "Enter Character: " << endl;
		cin >> n;

		if (n == 'R'){
			 head = Read();
		}else if(n == 'S'){
            Show(head);
		}else if(n == 'D'){
            int pos;
            cout << "Enter position to delete" << endl;
            cin >> pos;
            Delete(head, pos);
		}else if(n == 'T'){
            int pos;
            cout << "Enter position to toggle" << endl;
            cin >> pos;
            Toggle(head, pos);
		}else if(n == 'W'){
            Write(head);
		}else if(n == 'I'){
            int pos;
            cout << "Enter position to insert" << endl;
            cin >> pos;
            insert(head, pos);
		}else if(n == 'U'){
            int pos;
            cout << "Enter position to update" << endl;
            cin >> pos;
            Update(head, pos);
		}else if(n == 'Q'){
            exit(0);
		}
    }


return (0);
}
