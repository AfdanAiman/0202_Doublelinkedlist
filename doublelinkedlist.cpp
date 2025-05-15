#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
private:
    Node *START;

public:
    DoubleLinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        string nim;
        cout << "\nEnter the roll number of the student : ";
        cin >> nim;

        //step 1 : Allocate memory for the new code
        Node *newNode = new Node();

        //step 2: Assign value to the date fields
        newNode->noMhs = nim;

        //Step 3: Insert at beginning if list is empty or nim is smallest
        if(START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplicate number not allowed" << endl;
                return;
            }
            //Step 4: newNode.next = START
            newNode->next = START;

            //Step 5: START.prev = newNode (if START exists)
            if (START != NULL)
                START->prev = newNode;

            //Step 6 : newNode.prev = NULL
            newNode->prev =NULL;

            //Step 7: START = newNode
            START = newNode;
            return;
        }

        // insert in between node
        // Step 8: Locate position for insertion
        Node *current = START;
        while (current->next != NULL && current->next->noMhs < nim)
        {
            current = current->next;
        }

        if (current->next != NULL && nim == current->next->noMhs)
        {
            cout << "\nDuplicate roll numbers not allowed" << endl;
            return;
        }

        // Step 9: Insert between current and current->next
        newNode->next = current->next; // Step 9a: newNode.next = current.next
        newNode->prev = current;       // Step 9b: newNode.prev = current

        // insert last node
        if (current->next != NULL)
            current->next->prev = newNode; // step 9c: current.next.prev = newNode

 
           current->next = newNode; // step 9d: current.next = newNode

    }

    void hapus()
    
};
