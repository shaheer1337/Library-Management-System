#include "User.h"
#include "Book.h"

User::User()
    : userId(0), name(""), numBooksBorrowed(0), maxBooks(5)
{
    booksBorrowed = new Book *[maxBooks];
    for (int i = 0; i < maxBooks; ++i)
    {
        booksBorrowed[i] = nullptr;
    }
}

User::User(int id, const string &n, int borrow, int max) : userId(id), name(n), numBooksBorrowed(borrow), maxBooks(max)
{
    booksBorrowed = new Book *[maxBooks];
    for (int i = 0; i < maxBooks; ++i)
    {
        booksBorrowed[i] = nullptr;
    }
}

User::~User()
{
    delete[] booksBorrowed;
}

void User::borrowBook(Book *book)
{
    if (this->getNumBooksBorrowed() >= this->getMaxBooks())
    {
        cout << "You cannot borrow more books." << endl;
        return;
    }

    if (book->getInventoryCount() > 0)
    {
        book->changeInventoryCount(-1);
        booksBorrowed[numBooksBorrowed] = book;
        numBooksBorrowed++;
        cout << "Successfully borrowed: " << book->getTitle() << endl;
    }
    else
    {
        cout << "This book is currently unavailable." << endl;
    }
}

void User::returnBook(Book *book)
{
    for (int i = 0; i < numBooksBorrowed; ++i)
    {

        if (booksBorrowed[i]->getId() == book->getId())
        {
            book->changeInventoryCount(1);

            for (int j = i; j < numBooksBorrowed - 1; ++j)
            {
                booksBorrowed[j] = booksBorrowed[j + 1];
            }
            booksBorrowed[--numBooksBorrowed] = nullptr;
            cout << "Successfully returned: " << book->getTitle() << endl;
            return;
        }
    }
    cout << "This book was not borrowed by you." << endl;
}

int User::getNumBooksBorrowed() const
{
    return numBooksBorrowed;
}

int User::getUserId() const
{
    return userId;
}

string User::getUserName() const
{
    return name;
}

int User::getMaxBooks() const
{
    return maxBooks;
}

void User::viewBorrowedBooks() const
{
    if (numBooksBorrowed == 0)
    {
        cout << name << " has not borrowed any books." << endl;
        return;
    }

    int capacity = 10;
    string *uniqueBooks = new string[capacity];
    int *counts = new int[capacity];
    int uniqueCount = 0;

    for (int i = 0; i < numBooksBorrowed; ++i)
    {
        string title = booksBorrowed[i]->getTitle();
        bool found = false;

        for (int j = 0; j < uniqueCount; ++j)
        {
            if (uniqueBooks[j] == title)
            {
                counts[j]++;
                found = true;
                break;
            }
        }

        if (!found)
        {
            if (uniqueCount >= capacity)
            {
                capacity *= 2;
                string *newUniqueBooks = new string[capacity];
                int *newCounts = new int[capacity];

                for (int k = 0; k < uniqueCount; ++k)
                {
                    newUniqueBooks[k] = uniqueBooks[k];
                    newCounts[k] = counts[k];
                }

                delete[] uniqueBooks;
                delete[] counts;

                uniqueBooks = newUniqueBooks;
                counts = newCounts;
            }

            uniqueBooks[uniqueCount] = title;
            counts[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    for (int i = 0; i < uniqueCount - 1; ++i)
    {
        for (int j = 0; j < uniqueCount - i - 1; ++j)
        {
            if (uniqueBooks[j] < uniqueBooks[j + 1])
            {
                string tempTitle = uniqueBooks[j];
                uniqueBooks[j] = uniqueBooks[j + 1];
                uniqueBooks[j + 1] = tempTitle;

                int tempCount = counts[j];
                counts[j] = counts[j + 1];
                counts[j + 1] = tempCount;
            }
        }
    }

    cout << name << "'s Borrowed Books:" << endl;
    for (int i = 0; i < uniqueCount; ++i)
    {
        cout << uniqueBooks[i] << " (x" << counts[i] << ")" << endl;
    }

    delete[] uniqueBooks;
    delete[] counts;
}

void User::giveRating(BookList &list, int bookId, double newRating)
{
    if (this->getNumBooksBorrowed() >= this->getMaxBooks())
    {
        cout << "User is blocked and cannot rate books." << endl;
        return;
    }

    list.rateBook(bookId, newRating);
}

void User::updateMaxBooks(int additionalSlots)
{
    if (additionalSlots > 0)
    {
        int newMaxBooks = maxBooks + additionalSlots;
        Book **newBooksBorrowed = new Book *[newMaxBooks];

        for (int i = 0; i < numBooksBorrowed; ++i)
        {
            newBooksBorrowed[i] = booksBorrowed[i];
        }

        delete[] booksBorrowed;

        booksBorrowed = newBooksBorrowed;
        maxBooks = newMaxBooks;
        cout << "Max books updated to: " << maxBooks << endl;
    }
    else
    {
        cout << "Invalid number of additional slots." << endl;
    }
}