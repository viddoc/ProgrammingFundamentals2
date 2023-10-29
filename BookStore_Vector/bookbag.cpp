#include <stdexcept>
#include "bookbag.h"

BookBag::BookBag(std::string customerName, std::string currentDate)
    :customerName(customerName), currentDate(currentDate){}

std::string BookBag::getCustomerName() const
{
    return customerName;
}

std::string BookBag::getDate() const
{
    return currentDate;
}

int BookBag::getNumBooksInBag() const
{
    int total = 0;
    for (const Book& book : books)
    {
        total += book.getQuantity();
    }
    return total;
}

double BookBag::getCostOfBag() const
{
    double total = 0.0;
    for (const Book& book : books)
    {
        total += book.getQuantity()*book.getPrice();
    }
    return total;
}

int BookBag::getUniqueBookCount() const
{
    return books.size();
}

void BookBag::addBook(Book book)
{
    for (Book& aBook : books)
    {
        if (aBook == book)
        {
            aBook.setQuantity(aBook.getQuantity() + book.getQuantity());
            return;
        }
    }
    books.push_back(book);
}

void BookBag::removeBook(std::string title, std::string description)
{
    for (int i = 0; i < books.size(); i++)
    {
        if (books.at(i).getTitle() == title && books.at(i).getDescription() == description)
        {
            books.erase(books.begin() + i);
            break;
        }
    }
}

void BookBag::removeBook(Book book)
{
    removeBook(book.getTitle(), book.getDescription());
}

void BookBag::modifyBook(const Book& book)
{
    /*
    * The only attributes that can be modified in a book are the price and quantity.
    * The parameter book should be a default that has the title and description set
    * and only set the price or quantity if that is to change.
    */
    Book defaultBook; //instantiate a default book
    for (Book& aBook : books)
    {
        if (aBook == book)
        {
            //Check which attributes to update (modify)
            if (book.getPrice() != defaultBook.getPrice())
            {
                aBook.setPrice(book.getPrice());
            }
            if (book.getQuantity() != defaultBook.getQuantity())
            {
                if (book.getQuantity() == 0)
                {
                    removeBook(aBook);
                }
                else
                {
                    aBook.setQuantity(book.getQuantity());
                }
            }
            break;
        }
    }
}

void BookBag::printTotal() const
{
    throw std::runtime_error("printTotal not implemented");
}

void BookBag::printDescriptions() const
{
    throw std::runtime_error("printDescriptions not implemented");
}

BookBag BookBag::operator+(BookBag rhs)
{
    BookBag tempBag(this->customerName, this->currentDate);
    tempBag.books = this->books;
    for (const Book& book : rhs.books)
    {
        tempBag.addBook(book);
    }
    return tempBag;
}

BookBag BookBag::operator+(Book rhs)
{
    BookBag tempBag(this->customerName, this->currentDate);
    tempBag.books = this->books;
    tempBag.addBook(rhs);
    return tempBag;
}

BookBag BookBag::operator-(Book rhs)
{
    BookBag tempBag(this->customerName, this->currentDate);
    tempBag.books = this->books;
    tempBag.removeBook(rhs);
    return tempBag;
}

Book& BookBag::operator[](int index)
{
    if (index < 0 || index >= books.size())
    {
        throw std::runtime_error("index out of range");
    }
    return books[index];
}

std::ostream& operator<<(std::ostream& out, const BookBag& bag)
{
    if (bag.books.empty())
    {
        out << "BOOK BAG IS EMPTY";
        return out;
    }
    out << bag.customerName << "'s Book Bag - " << bag.currentDate << std::endl
        << "Number of books: " << bag.getNumBooksInBag() << std::endl << std::endl
        << "Books in bag \n";
    for (const Book& book : bag.books)
    {
        out << book << std::endl;
    }
    out << std::endl << "Total: $" << bag.getCostOfBag();

    return out;
}
