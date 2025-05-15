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
    {
        if (START == NULL)
        {
            cout << "\nList is empety" << endl;
            return;
        }

        cout << "\nEnter the roll number of the student whose record is to be deleted: ";
        int rollNo;
        cin >> rollNo;

        Node *current = START;

        // Step 1: Traverse the list to find the node
        while (current != NULL && current->noMhs != rollNo)
            current = current->next;

         if (current == NULL)
            {
                cout << "Record not found" << endl;
                return;
            }

            // Step 2: if node is at the beginning
            if (current == START)
            {
                START = current->next; // Step 2a: START = START.next
                if (START != NULL)
                    START->prev = NULL; // Step 2b: START.prev = NULL
            }
            else
            {
                // Step 3: Link previous node to next of current
                current->prev->next = current->next;

                // Step 4: if current is not the last node
                if (current->next != NULL)
                    current->next->prev = current->prev;

            }

            // Step 5: Delete the current node
            delete current;
            cout << "Record with roll number " <<rollNo << " deleted" << endl;
    }

    void traverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }
        // Step 1: Mark first node as currentNode
        Node *currentNode = START;
        //Step 2: Repeat until currentNode == NULL
        cout << "\nRecords in ascending order of roll number are:\n";
        int i = 0;
        while (currentNode != NULL)
        {
            cout << i + 1 << ". " << currentNode->noMhs << " " << endl;
            // Step 3: Move to next node
            currentNode = currentNode->next;
            i++;
        }
    }

    void revtraverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empety" << endl;
            return;
        }

        // Step 1: Move to last node
        Node *currentNode = START;
        int i = 0;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
            i++;
        }

        // Step 2: Traverse backward
        cout << "\nRecords in descending order of roll number are:\n";
        while (currentNode != NULL)
        {
            cout << i + 1 << ". " << currentNode->noMhs << " " << endl;

            // Step 3: Move to previous node
            currentNode = currentNode->prev;
            i--;
        }
    }

    void searchData()
    {
        if (START == NULL)
        {
            cout << "\nList is empety" << endl;
            return;
        }

        int rollNo;
        cout << "\nEnter the roll number to search: ";
        cin >> rollNo;

        Node *current = START;

        // Step 1: Traverse to find matching roll number
        while (current != NULL && current->noMhs != rollNo)
            current = current->next;

            // Step 2: Output result
            if (current == NULL)
            {
                cout << "Record not found\n";
            }
            else
            {
                cout << "record foumd\n";
                cout << "Roll Number: " << current->noMhs << endl;
            }
    }
}; 

int main()
{
    DoubleLinkedList list;
    char choice;

    do 
    {
        cout << "\nMenu:\n";
        cout << "1. Add record\n";
        cout << "2. Delete record\n";
        cout << "3. View Ascending\n";
        cout << "4. View Descending\n";
        cout << "5. Search record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
            case '1':
                list.addNode();
                break;
            case '2':
                list.hapus();
                break;
            case '3':
                list.traverse();
                break;
            case '4':
                list.revtraverse();
                break;
            case '5':
                list.searchData();
                break;
            case '6':
                return 0;
            default:
                cout << "Invalid option\n";

            

        }
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
        cout << endl;
        system("clear");

    }while (choice != '6');
}
// End of program
