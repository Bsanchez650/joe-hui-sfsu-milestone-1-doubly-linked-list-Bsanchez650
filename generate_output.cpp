/**
* @author - Brandon Sanchez
* @file generate_output.cpp -  This cpp file defines the methods in the generate_output header file.
* 2/07/2025 -  Brandon Sanchez created file
* 2/11/2025 - modified by Brandon Sanchez, added comments
*/


#include <iostream>
#include "doubly_linked_list.h"
#include "generate_output.h"

using namespace std;

void printList(DoublyLinkedList& FIFOList)
{
	DllNode* curr = FIFOList.head;//making variable = head of list
	if(FIFOList.head == nullptr){//checking to see if list is empty
		cout <<"List is empty\n";
		return;
	}

	while (curr != nullptr){//loop to print list from head until empty
		cout << curr->key << ", ";
		curr = curr->next;
	}
	cout << endl;


}

void reversePrintList(DoublyLinkedList& FIFOList)
{
	DllNode* curr = FIFOList.tail;//variable set to equal tail of list
	if(FIFOList.head == nullptr){//checking to see if list is empty
		cout << "List is empty"<<endl;
		return;
	}

	while (curr != nullptr){
		cout << curr->key << ", ";//pringting list from tail to head
		curr = curr->prev;
	}
	cout << endl;
}