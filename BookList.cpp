#include "BookList.h"
#include "Book.h"

BookList::BookList() : head(nullptr) {}

BookList::BookList(const BookList &other) : head(nullptr)
{
    if (other.head == nullptr)
    {
        return;
    }

    head = new Node(other.head->data);
    Node *currentOther = other.head->next;
    Node *currentNew = head;

    while (currentOther != nullptr)
    {
        currentNew->next = new Node(currentOther->data);
        currentNew = currentNew->next;
        currentOther = currentOther->next;
    }
}

// Destructor
BookList::~BookList()
{
    Node *current = head;
    Node *nextNode = nullptr;

    while (current != nullptr)
    {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

bool BookList::isEmpty() const
{
    return head == nullptr;
}

void BookList::insertBook(Book *book)
{
    if (isEmpty())
    {
        head = new Node(book);
    }
    else
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data->getId() == book->getId())
            {
                current->data->changeInventoryCount(1);
                return;
            }
            if (current->next == nullptr)
            {
                break;
            }
            current = current->next;
        }
        current->next = new Node(book);
    }
}

void BookList::removeBook(Book *book)
{
    if (isEmpty() || book == nullptr)
        return;

    if (head->data->getId() == book->getId())
    {
        head->data->changeInventoryCount(-1);

        if (head->data->getInventoryCount() <= 0)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        return;
    }

    Node *current = head;
    while (current->next != nullptr)
    {
        if (current->next->data->getId() == book->getId())
        {
            current->next->data->changeInventoryCount(-1);

            if (current->next->data->getInventoryCount() <= 0)
            {
                Node *temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
            return;
        }
        current = current->next;
    }
}

void BookList::displayBooks() const
{
    cout << "Library Book Details:" << endl;
    if (isEmpty())
    {
        cout << "The book list is empty." << endl;
        return;
    }

    Node *current = head;
    while (current != nullptr)
    {
        cout << "ID: " << current->data->getId() << " - ";
        cout << "Title: " << current->data->getTitle() << " - ";
        cout << "Author: " << current->data->getAuthor() << " - ";
        cout << "Rating: " << current->data->getRating() << endl;
        current = current->next;
    }
}

void BookList::sortBooks(SortCriteria criteria)
{
    if (isEmpty())
        return;

    bool swapped;
    do
    {
        swapped = false;
        Node *current = head;

        while (current->next != nullptr)
        {
            bool condition = false;

            if (criteria == BY_RATING)
            {
                condition = current->data->getRating() < current->next->data->getRating();
            }
            else if (criteria == BY_TITLE)
            {
                condition = current->data->getTitle() > current->next->data->getTitle();
            }

            if (condition)
            {
                Book *temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

Book *BookList::searchList(int bookId) const
{
    if (isEmpty())
        return nullptr;

    Node *current = head;
    while (current != nullptr)
    {
        if (current->data->getId() == bookId)
        {
            return current->data;
        }
        current = current->next;
    }
    return nullptr;
}

int BookList::countBooks() const
{
    int totalCount = 0;
    Node *current = head;
    while (current != nullptr)
    {
        totalCount += current->data->getInventoryCount();
        current = current->next;
    }
    return totalCount;
}

void BookList::rateBook(int bookId, double newRating)
{
    Book *book = searchList(bookId);
    if (book == nullptr)
    {
        cout << "Book with ID " << bookId << " not found." << endl;
        return;
    }

    book->addRating(newRating);
    cout << "Rating updated for Book " << bookId << ". New rating: " << book->getRating() << endl;
}

Book *BookList::getBookWithMaxRating() const
{
    if (isEmpty())
    {
        cout << "The book list is empty." << endl;
        return nullptr;
    }

    Node *current = head;
    Book *maxBook = current->data;

    while (current != nullptr)
    {
        if (current->data->getRating() > maxBook->getRating())
        {
            maxBook = current->data;
        }
        current = current->next;
    }
    return maxBook;
}

Book *BookList::getBookWithMinRating() const
{
    if (isEmpty())
    {
        cout << "The book list is empty." << endl;
        return nullptr;
    }

    Node *current = head;
    Book *minBook = current->data;

    while (current != nullptr)
    {
        if (current->data->getRating() < minBook->getRating())
        {
            minBook = current->data;
        }
        current = current->next;
    }
    return minBook;
}

void BookList::reverseBooksByRating()
{
    if (isEmpty())
        return;

    sortBooks(BY_RATING);

    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}