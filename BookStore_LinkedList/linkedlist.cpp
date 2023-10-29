#include <stdexcept>

#include "linkedlist.h"

LinkedList::LinkedList()
    :head(nullptr), tail(nullptr), size(0){}

LinkedList::LinkedList(dataType data)
    :LinkedList()
{
    addToFront(data);
}

LinkedList::LinkedList(const LinkedList& rhs)
{
    Node* curr = rhs.head;
    while (curr != nullptr)
    {
        this->addToRear(curr->getData());
        curr = curr->getNext();
    }
}

LinkedList LinkedList::operator=(const LinkedList& rhs)
{
    //Clear this list
    while (!isEmpty())
    {
        removeFromFront();
    }
    //Copy the data from the rhs to this linked list
    Node* curr = rhs.head;
    while (curr != nullptr)
    {
        this->addToRear(curr->getData());
        curr = curr->getNext();
    }
    return *this;
}

LinkedList::~LinkedList()
{
    while (!isEmpty())
    {
        removeFromFront();
    }
}
//Add a node to the front of the list
void LinkedList::addToFront(dataType data)
{
    //Build a node with the data
    //Dynamically allocate memory for Node
    Node* node = new Node(data);
    //Check if the list is empty
    if (head == nullptr)
    {
        //List is empty 
        head = node;
        tail = node;
    }
    else
    {
        //List is not empty, place node before head node
        node->setNext(head);
        head = node;
    }
    size++;
}

void LinkedList::addToRear(dataType data)
{
    //Build a node with the data
    //Dynamically allocate memory for Node
    Node* node = new Node(data);
    //Check if the list is empty
    if (head == nullptr)
    {
        //List is empty 
        head = node;
        tail = node;
    }
    else
    {
        //List is not empty, place node after tail node
        tail->setNext(node);
        tail = node;
    }
    size++;
}

void LinkedList::addAt(dataType data, int pos)
{
    //Add the node in front of pos
    //If pos == size, add at the end
    //Validate pos
    if (pos < 0 || pos > size)
    {
        throw std::runtime_error("Position out of range");
    }
    else if (pos == 0)
    {
        addToFront(data);
    }
    else if (pos == size)
    {
        addToRear(data);
    }
    else
    {
        //Add somewhere in the middle
        Node* prev = getNodeAtPosition(pos - 1);
        if (prev == nullptr || prev->getNext() == nullptr)
        {
            throw std::runtime_error("Something wicked this way comes");
        }
        Node* curr = prev->getNext();
        Node* node = new Node(data);
        node->setNext(curr);
        prev->setNext(node);
        size++;
    }
}

dataType LinkedList::getFromFront() const
{
    if (isEmpty())
    {
        throw std::runtime_error("Cannot get data from empty list");
    }
    return head->getData();
}

dataType LinkedList::getFromRear() const
{
    if (isEmpty())
    {
        throw std::runtime_error("Cannot get data from empty list");
    }
    return tail->getData();
}

dataType LinkedList::getAt(int pos) const
{
    if (pos < 0 || pos > size - 1)
    {
        throw std::runtime_error("Position out of range");
    }
    Node* node = getNodeAtPosition(pos);
    return node->getData();
}

void LinkedList::setFront(dataType data)
{
    if (isEmpty())
    {
        throw std::runtime_error("Cannot set data from empty list");
    }
    head->setData(data);
}

void LinkedList::setRear(dataType data)
{
    if (isEmpty())
    {
        throw std::runtime_error("Cannot set data from empty list");
    }
    tail->setData(data);
}

void LinkedList::setAt(dataType data, int pos)
{
    if (pos < 0 || pos > size)
    {
        throw std::runtime_error("Position out of range");
    }
    Node* node = getNodeAtPosition(pos);
    node->setData(data);
}

dataType LinkedList::removeFromFront()
{
    if (isEmpty())
    {
        throw std::runtime_error("Cannot remove item from empty list");
    }
    //Get the data from the node
    dataType data = head->getData();
    //Declare pointer to node and point to head
    Node* temp = head;
    //Move the head to next node
    head = head->getNext();
    //Break the link from the first node and return allocated memory to OS
    temp->setNext(nullptr);
    delete temp;
    //This will only happen with a one node list
    if (head == nullptr)
    {
        tail = head;
    }
    size--;
    return data;
}

dataType LinkedList::removeFromRear()
{
    if (isEmpty())
    {
        throw std::runtime_error("Cannot remove item from empty list");
    }
    //Get the data from the node
    dataType data = tail->getData();
    if (head == tail)
    {
        //Only have one node
        delete head; //Releases allocated memory
        head = tail = nullptr;
    }
    else
    {
        //Find the node before tail in order to remove tail
        Node* prev = getNodeAtPosition(size-2);
        if (prev == nullptr)
        {
            throw std::runtime_error("Something wicked this way comes");
        }
        //Break off last node
        prev->setNext(nullptr);
        delete tail; //Releases allocated memory
        tail = prev;
    }
    size--;
    return data;
}

dataType LinkedList::removeAt(int pos)
{
    return dataType();
}

int LinkedList::getSize() const
{
    return size;
}

bool LinkedList::isEmpty() const
{
    return head == nullptr;
}

LinkedList::Node* LinkedList::getNodeAtPosition(int pos) const
{
    //pos: 0 is the head
    //pos: size - 1 is the tail
    Node* curr = head;
    for (int i{ 0 }; curr != nullptr && i < pos; i++)
    {
        curr = curr->getNext();
    }
    return curr;
}

LinkedList::Node::Node(dataType data)
    :Node(data, nullptr) {}

LinkedList::Node::Node(dataType data, Node* next)
    :data(data), next(next) {}

void LinkedList::Node::setNext(Node* next)
{
    this->next = next;
}

void LinkedList::Node::setData(dataType data)
{
    this->data = data;
}

LinkedList::Node* LinkedList::Node::getNext() const
{
    return next;
}

dataType LinkedList::Node::getData() const
{
    return data;
}
