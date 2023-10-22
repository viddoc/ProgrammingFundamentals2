#include <iomanip>
#include "book.h"

Book::Book(std::string numberISBN, std::string bookTitle, std::string authorLast, std::string authorFirst)
:numberISBN(numberISBN), bookTitle(bookTitle), authorLast(authorLast), authorFirst(authorFirst) 
{
    this->bookStatus = "In";
}

std::string Book::getISBN() const
{
    return numberISBN;
}

std::string Book::getTitle() const
{
    return bookTitle;
}

std::string Book::getLast() const
{
    return authorLast;
}

std::string Book::getFirst() const
{
    return authorFirst;
}

std::string Book::getStatus() const
{
    return bookStatus;
}

void Book::updateStatus()
{
    if (bookStatus == "In")
    {
        bookStatus = "Out";
    }
    else
    {
        bookStatus = "In";
    }
}

std::ostream& operator<<(std::ostream& out, const Book& book)
{
    out << std::setw(22) << std::left << book.authorLast + ", " + book.authorFirst << std::setw(44) << book.bookTitle << std::setw(18) << book.numberISBN << book.bookStatus;
    return out;
}

std::istream& operator>>(std::istream& in, Book& book)
{
    getline(in, book.numberISBN);
    getline(in, book.bookTitle);
    in >> book.authorFirst;
    in >> book.authorLast;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return in;
}
