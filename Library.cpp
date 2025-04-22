#include "Library.h"

Library::Library(int initialCapacity) : userCount(0), capacity(initialCapacity), totalRevenue(0.0)
{
    users = new User *[capacity];
}

Library::~Library()
{
    for (int i = 0; i < userCount; ++i)
    {
        delete users[i];
    }
    delete[] users;
}

void Library::addUser(int id, const string &name)
{
    if (userCount >= capacity)
    {
        capacity *= 2;
        User **newUsers = new User *[capacity];
        for (int i = 0; i < userCount; ++i)
        {
            newUsers[i] = users[i];
        }
        delete[] users;
        users = newUsers;
    }

    users[userCount] = new User(id, name, 0, 5);
    totalRevenue += 5.0;
    userCount++;
}

void Library::upgradeUserSlots(int userId, int additionalSlots)
{
    for (int i = 0; i < userCount; ++i)
    {
        if (users[i]->getUserId() == userId)
        {
            double upgradeCost = additionalSlots * 1.0;
            totalRevenue += upgradeCost;
            users[i]->updateMaxBooks(additionalSlots);
            cout << "User ID " << userId << " upgraded by " << additionalSlots << " slots." << endl;
            return;
        }
    }
    cout << "User ID " << userId << " not found." << endl;
}

double Library::getTotalRevenue() const
{
    return totalRevenue;
}

void Library::displayUsers() const
{
    for (int i = 0; i < userCount; ++i)
    {
        cout << "User ID: " << users[i]->getUserId() << ", Name: " << users[i]->getUserName()
             << ", Borrowed Books: " << users[i]->getNumBooksBorrowed()
             << ", Max Books: " << users[i]->getMaxBooks() << endl;
    }
}

User *Library::getUserById(int userId) const
{
    for (int i = 0; i < userCount; ++i)
    {
        if (users[i]->getUserId() == userId)
        {
            return users[i];
        }
    }
    return nullptr;
}

void Library::addNewBook(Book *book)
{
    const double bookCost = 2.0;
    if (totalRevenue >= bookCost)
    {
        libraryInventory.insertBook(book);
        totalRevenue -= bookCost;
        cout << "Book '" << book->getTitle() << "' added to the library." << endl;
    }
    else
    {
        cout << "Insufficient funds to add the book '" << book->getTitle() << "'." << endl;
    }
}

void Library::removeBook(int bookId)
{
    Book *bookToRemove = libraryInventory.searchList(bookId);
    if (bookToRemove != nullptr)
    {
        while (libraryInventory.searchList(bookId) != nullptr)
        {
            libraryInventory.removeBook(bookToRemove);
            totalRevenue += 1.0;
        }
    }
    else
    {
        cout << "Book with ID " << bookId << " not found in the library." << endl;
    }
}

void Library::displayBooks() const
{
    libraryInventory.displayBooks();
}

BookList &Library::getLibraryInventory()
{
    return libraryInventory;
}