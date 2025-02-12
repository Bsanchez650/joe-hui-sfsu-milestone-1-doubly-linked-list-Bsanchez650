/**
* @author - Brandon Sanchez
* @file doubly_linked_list.cpp -  This cpp file defines the methods in the doubly_linked_list header file.
* 2/07/2025 -  Brandon Sanchez created file
* 2/11/2025 - modified by Brandon Sanchez, added comments and modified remove method
*/


#include <iostream>
#include "doubly_linked_list.h"
using namespace std;

    DoublyLinkedList::DoublyLinkedList()
    {

        head = nullptr;
        tail = nullptr;

    }

    DoublyLinkedList::~DoublyLinkedList()
    {
        clear();
    }

    bool DoublyLinkedList::isEmpty()
    {
        return head==nullptr;
    }

    void DoublyLinkedList::insertAtHead(int key)
    {
        DllNode* newNode = new DllNode(key);

        if (head == nullptr) {//if list is empty 
            head =tail = newNode;
            return;
        }
        else {//adding node to head
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void DoublyLinkedList::insertAtTail(int key)
    {
        DllNode* newNode = new DllNode(key);
        if (tail == nullptr) {//if list is empty
            head = tail = newNode;
            return;
            
        }else{//adding to tail
            tail ->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void DoublyLinkedList::remove(int key)
    {
        //if empty list
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        DllNode* temp = head;
        //find node through loop
        while (temp != nullptr && temp->key != key) {
            temp = temp->next;
        }
        //if not found
        if (temp == nullptr) {
            cout << "Value " << key << " Not found in the list " << endl;
            return;
        }
        //if last node in list
        if (temp == head && temp == tail) {
            head = tail = nullptr;
        } else if (temp == head) {//if head node
            head = head->next;
            head->prev = nullptr;
        } else if (temp == tail) {//if tail node
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            //if node in the middle
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    void DoublyLinkedList::removeHeaderNode()
    {
        //cheacking if list is empty
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        DllNode* temp = head;
        head = head->next;

        //cheaking to see if its head
        if (head != nullptr) {
            head->prev = nullptr;
        }

        delete temp;
    }

    void DoublyLinkedList::removeTailNode()
    {
        //cheacking if list is empty
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        
        //looping to see if tal, and if so to delete
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        }

    }

    void DoublyLinkedList::moveNodeToHead(int key)
    {
        bool isHead = true;

        //cheacking if list is empty
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        DllNode* temp = head;

        //looping through our list
        while (temp != nullptr && temp->key != key)
        {
            temp = temp->next;
        }
        //if our value is not found
        if (temp == nullptr) {
            cout << "Key not found\n";
            return;
        }
        //calling remove function
        remove(key);

        //checking bool if true
        if (isHead) {
            insertAtHead(key);
        }

    }

    void DoublyLinkedList::moveNodeToTail(int key)
    {
        bool isTail = true;
        //cheacking if list is empty
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        DllNode* temp = head;
        //traversing through out list
        while (temp != nullptr && temp->key != key) {
            temp = temp->next;
        }

        remove(key);
        //checking if our boolian is True, add to tail
        if (isTail) {
            insertAtTail(key);
        }
        //if our value is not found return 
        if (temp == nullptr) {
            cout << "key not found\n";
            return;
        }

    }

    void DoublyLinkedList::clear()
    {
        DllNode* temp = head;
        //creating loop showing not empty
        while (temp != nullptr)
        {
            DllNode* c = temp;
            temp = temp->next;
            delete c;
        }
        head = nullptr;
    }

