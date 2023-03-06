#include "SingleLinkedList.h"

// Constructor
SingleLinkedList::SingleLinkedList() {
    headPtr = nullptr;
    tailPtr = nullptr;
    numItems = 0;
}

// Overloaded constructor
SingleLinkedList::SingleLinkedList(Item_Type item) {
    Node* tempPtr = new Node;
    tempPtr->item = item;
    tempPtr->nextPtr = nullptr;
    this->headPtr = tempPtr;
    this->tailPtr = tempPtr;
    numItems = 1;
}



// Pre: none
// Post: Prints all nodes and their item value in the list in order
void SingleLinkedList::printSingleLinkedList() {
    // Iterate through and print the values
    Node* tempPtr = new Node;
    tempPtr = headPtr;
    // While not at the end
    while (tempPtr != nullptr) {
        cout << "->" << tempPtr->item.value;
        // Move to next node
        tempPtr = tempPtr->nextPtr;
    }
    cout << endl << endl;
}

// Pre: requires a struct Item_Type with an int value
// Post: Push item to the very front of the list
void SingleLinkedList::push_front(Item_Type item)
{
    // Make the new node
    Node* newNode = new Node;
    newNode->item = item;
    // Pushing to the front, so make it point to the head node
    newNode->nextPtr = this->headPtr;
    // Increase count
    this->numItems++;
    this->headPtr = newNode;
}

// Pre: requires a struct with an int value
// Post: Push item to the very end of the list
void SingleLinkedList::push_back(Item_Type item)
{
    // Make the new node
    Node* newNode = new Node;
    newNode->item = item;
    newNode->nextPtr = nullptr;
    // Increase count
    this->numItems++;

    // Go to the end of the list and add the node there
    // But if its empty, make the newNode the head
    if (isEmpty()) {
        headPtr = newNode;
    }
    else {
        // Start iterating through the list

        // Make a tempPtr to point to the head, then proceed through each one's nextNode
        Node* tempPtr = headPtr;
        while (tempPtr != nullptr && tempPtr->nextPtr != nullptr) {
            // Iterate through
            tempPtr = tempPtr->nextPtr;
        }
        // If at the very last item...
        newNode->nextPtr = nullptr;
        tempPtr->nextPtr = newNode;
        this->tailPtr = newNode;
    }
}

// Pre: None
// Post: Remove the first item in the list
void SingleLinkedList::pop_front()
{
    // If its empty, do nothing
    if (headPtr == nullptr)
    {
        return;
    }
    else {
        // We want to delete the first value, but we need to advance headPtr to the next value first so nextPtr isn't lost. 
        Node* tempPtr = headPtr;
        headPtr = headPtr->nextPtr;
        delete tempPtr;
        this->numItems--;
    }
}

// Pre: None
// Post: remove the last item in the list
void SingleLinkedList::pop_back()
{ 
    // If its empty, do nothing
    if (headPtr == nullptr)
    {
        return;
    }
    else {
        // Start iterating through the list

        // Make a tempPtr to point to the head, then proceed through each one's nextNode
        Node* tempPtr = headPtr;
        Node* previousPtr = nullptr;
        while (tempPtr->nextPtr != nullptr) {
            // Iterate through
            previousPtr = tempPtr;
            tempPtr = tempPtr->nextPtr;
        }
        // If pointing at the very last item...
        delete tempPtr;
        previousPtr->nextPtr = nullptr;
        this->tailPtr = previousPtr;
        this->numItems--;
    }
}

// Pre: None
// Post: return the first node in the list
Node* SingleLinkedList::front()
{
    return this->headPtr;
}

// Pre: None
// Post: return the last node in the list
Node* SingleLinkedList::back()
{
    return this->tailPtr;
}

// Pre: None
// Post: return true if empty, false otherwise
bool SingleLinkedList::isEmpty()
{
    if (headPtr == nullptr)
    {
        return true;
    }
    else return false;
}

// Pre: an Item_Type struct and the index of where you want to place it.
// Post: inserts item at a specific index
void SingleLinkedList::insert(size_t index, const Item_Type& item)
{
    if (index < 0)
    {
        cout << "Index should be a positive number" << endl;
        return;
    }
    else if (index >= this->numItems)
    {
        // Insert at the end if it is out of range
        push_back(item);
    }
    else
    {
        Node* newNode = new Node;
        newNode->item = item;

        // WHat newNode will point to
        Node* tempPtr = headPtr;
        // What will point to newNode
        Node* previousPtr = nullptr;

        for (size_t i = 0; i < index; i++)
        {
            previousPtr = tempPtr;
            
            tempPtr = tempPtr->nextPtr;
        }
        previousPtr->nextPtr = newNode;
        newNode->nextPtr = tempPtr;
        this->numItems++;
    }
}

// Pre: the index of the item you want to remove
// Post: returns true if the item is removed. false otherwise
bool SingleLinkedList::remove(size_t index)
{
    if (index < 0 || index > this->numItems)
    {
        cout << "Index is out of range" << endl;
        return false;
    }
    else if (index == 0) {
        pop_front();
        return true;
    }
    else {
        // Node to iterate with
        Node* tempPtr = headPtr;
        Node* previousPtr = nullptr;
        tempPtr = headPtr;
        for (size_t i = 0; i < index; i++)
        {
            previousPtr = tempPtr;
            tempPtr = tempPtr->nextPtr;
            // If tempPtr is pointing to the index we want to delete...
            if (i == index - 1)
            {
                // Make the previousPtr's nextPtr point to the correct next item in the list
                previousPtr->nextPtr = tempPtr->nextPtr;
                // Now delete the indexed item, as there is no need for it anymore
                delete tempPtr;
            }
        }
        this->numItems--;
        return true;
    }
}

// Pre: an Item_Type struct
// Post: return index of found item. if not found, returns -1
size_t SingleLinkedList::find(const Item_Type& item)
{
    Node* tempPtr = headPtr;
    size_t index = 0;
    while (!isEmpty()) {
        // Check if found
        if (tempPtr->item.value == item.value)
        {
            return index;
        }
        else {
            index++;
            tempPtr = tempPtr->nextPtr;
        }
    }
    return -1;
}