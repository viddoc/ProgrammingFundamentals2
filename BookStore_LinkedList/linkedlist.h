#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include"book.h"

using dataType = Book;

class LinkedList
{
private:
	//Variable for the number of nodes
	int size{};
	//Forward declaration of Node
	class Node;
	//Pointers to head and tail of list
	Node* head{ nullptr };
	Node* tail{ nullptr };
	//Private method to return a pointer
	Node* getNodeAtPosition(int pos) const;

public:
	//Constructors, one empty and one with a one node list
	LinkedList();
	LinkedList(dataType data);

	//The Big Three necessary whenever your class dynamically allocates memory: Copy constructor, assignment operator override, destructor
	//Copy Constructor
	LinkedList(const LinkedList& rhs);
	//Assignment operator override
	LinkedList operator=(const LinkedList& rhs);
	//Destructor
	virtual ~LinkedList();

	//Insertion methods
	void addToFront(dataType data);
	void addToRear(dataType data);
	void addAt(dataType data, int pos);

	//Getter methods
	dataType getFromFront() const;
	dataType getFromRear() const;
	dataType getAt(int pos) const;

	//Setter methods
	void setFront(dataType data);
	void setRear(dataType data);
	void setAt(dataType data, int pos);

	//Deletion methods
	dataType removeFromFront();
	dataType removeFromRear();
	dataType removeAt(int pos);

	int getSize() const;
	bool isEmpty() const;

private:
	class Node
	{
	private:
		dataType data;
		Node* next;

	public:
		Node(dataType data);
		Node(dataType data, Node* next);

		//Setter methods
		void setNext(Node* next);
		void setData(dataType data);
		//Getter methods
		Node* getNext() const;
		dataType getData() const;
	};
};

#endif // !_LINKEDLIST_H_
