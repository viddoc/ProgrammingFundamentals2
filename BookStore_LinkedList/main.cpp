//Tommy Hudson BookStore using Linked Lists
#include <iostream>
#include <fstream>

#include "book.h"
#include "linkedlist.h"

int main()
{
	LinkedList bookList;
	std::ifstream file("book_list.txt");

	Book book;
	while (file >> book)
	{
		bookList.addToRear(book);
	}

	for (int i = 0; i < bookList.getSize(); i++)
	{
		std::cout << bookList.getAt(i) << std::endl;
	}
}
