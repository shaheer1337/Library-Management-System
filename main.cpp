#include <iostream>
#include "Book.h"
#include "BookList.h"
#include "User.h"
#include "Library.h"

using namespace std;

bool SELECT_PROMPT = false;

int main()
{
    if (SELECT_PROMPT)
        std::cout << "Select testing module: ";
    int testCase;
    std::cin >> testCase;
    if (SELECT_PROMPT)
        std::cout << std::endl;
    std::cin.get();

    switch (testCase)
    {
    case 1:
    {
        cout << "Test case 1 selected" << endl;

        Library library;

        library.addUser(1, "Alice");
        library.addUser(2, "Bob");

        User *user1 = library.getUserById(1);
        User *user2 = library.getUserById(2);

        cout << "User details:" << endl;
        cout << "User ID: " << user1->getUserId() << " with name: " << user1->getUserName() << " has been added." << endl;
        cout << "User ID: " << user2->getUserId() << " with name: " << user2->getUserName() << " has been added." << endl;

        break;
    }
    case 2:
    {
        cout << "Test case 2 selected" << endl;

        Library library;

        library.addUser(1, "Alice");
        library.addUser(2, "Bob");

        cout << "Total Revenue before adding books: $" << library.getTotalRevenue() << endl;

        Book *book1 = new Book(1, "The Great Gatsby", "F. Scott Fitzgerald", 7);
        Book *book2 = new Book(2, "1984", "George Orwell", 3);
        Book *book3 = new Book(3, "To Kill a Mockingbird", "Harper Lee", 2);
        Book *book4 = new Book(4, "Great Expectations", "Charles Dickens", 1);

        library.addNewBook(book1);
        library.addNewBook(book2);
        library.addNewBook(book3);
        library.addNewBook(book4);

        cout << "Total Revenue after adding books: $" << library.getTotalRevenue() << endl;

        library.displayBooks();

        delete book1;
        delete book2;
        delete book3;
        delete book4;

        break;
    }
    case 3:
    {
        cout << "Test case 3 selected" << endl;

        Library library;

        library.addUser(1, "Alice");
        library.addUser(2, "Bob");
        library.addUser(3, "Charlie");

        User *user1 = library.getUserById(1);
        User *user2 = library.getUserById(2);
        User *user3 = library.getUserById(3);

        Book *book1 = new Book(1, "The Great Gatsby", "F. Scott Fitzgerald", 7);
        Book *book2 = new Book(2, "1984", "George Orwell", 3);
        Book *book3 = new Book(3, "To Kill a Mockingbird", "Harper Lee", 2);
        Book *book4 = new Book(4, "Great Expectations", "Charles Dickens", 1);

        library.addNewBook(book1);
        library.addNewBook(book2);
        library.addNewBook(book3);
        library.addNewBook(book4);

        cout << endl;

        cout << "Initially Alice has " << user1->getNumBooksBorrowed() << " books" << endl;
        cout << "Initially Bob has " << user2->getNumBooksBorrowed() << " books" << endl;

        cout << endl;

        user1->borrowBook(book1);
        user1->borrowBook(book2);
        user2->borrowBook(book3);
        user2->borrowBook(book4);

        cout << "After borrowing books:" << endl
             << endl;
        cout << "Alice borrowed " << user1->getNumBooksBorrowed() << " books." << endl;
        user1->viewBorrowedBooks();
        cout << endl;
        cout << "Bob borrowed " << user2->getNumBooksBorrowed() << " books." << endl;
        user2->viewBorrowedBooks();
        cout << endl;
        cout << "Charlie borrowed " << user3->getNumBooksBorrowed() << " books." << endl;
        user3->viewBorrowedBooks();

        delete book1;
        delete book2;
        delete book3;
        delete book4;

        break;
    }
    case 4:
    {
        cout << "Test case 4 selected" << endl;

        Library library;

        library.addUser(1, "Alice");

        User *user1 = library.getUserById(1);

        library.displayUsers();

        Book *book1 = new Book(1, "The Great Gatsby", "F. Scott Fitzgerald", 7);

        library.addNewBook(book1);

        cout << endl;

        cout << "Initially Alice has " << user1->getNumBooksBorrowed() << " books" << endl;
        cout << endl;

        for (int i = 0; i < 7; i++)
        {
            user1->borrowBook(book1);
        }

        cout << "After borrowing books:" << endl
             << endl;
        cout << "Alice borrowed " << user1->getNumBooksBorrowed() << " books." << endl;
        user1->viewBorrowedBooks();

        delete book1;

        break;
    }
    case 5:
    {
        cout << "Test case 5 selected" << endl;

        Library library;

        library.addUser(1, "Bob");

        User *user1 = library.getUserById(1);

        library.displayUsers();

        Book *book1 = new Book(1, "The Great Gatsby", "F. Scott Fitzgerald", 7);

        library.addNewBook(book1);

        cout << endl;

        cout << "Initially Bob has " << user1->getNumBooksBorrowed() << " books" << endl;
        cout << endl;

        for (int i = 0; i < 6; i++)
        {
            user1->borrowBook(book1);
        }

        cout << "After borrowing books:" << endl;
        cout << "Bob borrowed " << user1->getNumBooksBorrowed() << " books." << endl;

        cout << endl;
        user1->returnBook(book1);

        cout << "After returning 1 book:" << endl;
        cout << "Bob borrowed " << user1->getNumBooksBorrowed() << " books.";
        user1->viewBorrowedBooks();

        delete book1;

        break;
    }
    case 6:
    {
        cout << "Test case 6 selected" << endl;

        Library library;

        library.addUser(1, "Alice");
        library.addUser(2, "Bob");
        library.addUser(3, "Charlie");

        User *user2 = library.getUserById(2);
        User *user3 = library.getUserById(3);

        Book *book1 = new Book(1, "The Great Gatsby", "F. Scott Fitzgerald", 7);
        Book *book2 = new Book(2, "1984", "George Orwell", 3);
        Book *book3 = new Book(3, "To Kill a Mockingbird", "Harper Lee", 2);
        Book *book4 = new Book(4, "Great Expectations", "Charles Dickens", 1);
        Book *book5 = new Book(5, "Pride and Prejudice", "Jane Austen", 0);
        Book *book6 = new Book(6, "The Catcher in the Rye", "J.D Salinger", 4);

        library.addNewBook(book1);
        library.addNewBook(book2);
        library.addNewBook(book3);
        library.addNewBook(book4);
        library.addNewBook(book5);
        library.addNewBook(book6);

        cout << "There are " << library.getLibraryInventory().countBooks() << " books in the library." << endl;

        cout << endl;

        user2->borrowBook(book1);
        user2->borrowBook(book2);
        user3->borrowBook(book2);
        user3->borrowBook(book4);
        user2->borrowBook(book5);

        cout << endl;

        user2->giveRating(library.getLibraryInventory(), 2, 5.0);
        user2->giveRating(library.getLibraryInventory(), 1, 10.0);
        user2->giveRating(library.getLibraryInventory(), 5, 2.0);
        user3->giveRating(library.getLibraryInventory(), 2, 1.0);
        user3->giveRating(library.getLibraryInventory(), 1, 4.0);
        user3->giveRating(library.getLibraryInventory(), 3, 2.5);

        cout << endl;

        cout << "There are " << library.getLibraryInventory().countBooks() << " books in the library. They are:" << endl;

        library.displayBooks();

        delete book1;
        delete book2;
        delete book3;
        delete book4;
        delete book5;
        delete book6;

        break;
    }
    case 7:
    {
        cout << "Test case 7 selected" << endl;

        Library library;

        library.addUser(1, "Alice");
        library.addUser(2, "Bob");
        library.addUser(3, "Charlie");

        User *user1 = library.getUserById(1);
        User *user2 = library.getUserById(2);
        User *user3 = library.getUserById(3);

        Book *book1 = new Book(1, "The Great Gatsby", "F. Scott Fitzgerald", 7);
        Book *book2 = new Book(2, "1984", "George Orwell", 3);
        Book *book3 = new Book(3, "To Kill a Mockingbird", "Harper Lee", 2);
        Book *book4 = new Book(4, "Great Expectations", "Charles Dickens", 1);

        library.addNewBook(book1);
        library.addNewBook(book2);
        library.addNewBook(book3);
        library.addNewBook(book4);

        cout << endl;

        user2->giveRating(library.getLibraryInventory(), 2, 5.0);
        user2->giveRating(library.getLibraryInventory(), 1, 10.0);
        user3->giveRating(library.getLibraryInventory(), 2, 1.0);
        user3->giveRating(library.getLibraryInventory(), 1, 4.0);
        user1->giveRating(library.getLibraryInventory(), 1, 5.0);
        user1->giveRating(library.getLibraryInventory(), 3, 2.0);

        cout << endl;

        cout << "Books sorted in alphabetical order: " << endl;
        library.getLibraryInventory().sortBooks(BY_TITLE);

        library.displayBooks();

        delete book1;
        delete book2;
        delete book3;
        delete book4;

        break;
    }
    case 8:
    {
        cout << "Test case 8 selected" << endl;

        Library library;

        library.addUser(1, "Alice");
        library.addUser(2, "Bob");
        library.addUser(3, "Charlie");

        User *user1 = library.getUserById(1);
        User *user2 = library.getUserById(2);
        User *user3 = library.getUserById(3);

        Book *book1 = new Book(1, "The Great Gatsby", "F. Scott Fitzgerald", 7);
        Book *book2 = new Book(2, "1984", "George Orwell", 3);
        Book *book3 = new Book(3, "To Kill a Mockingbird", "Harper Lee", 2);
        Book *book4 = new Book(4, "Great Expectations", "Charles Dickens", 1);

        library.addNewBook(book1);
        library.addNewBook(book2);
        library.addNewBook(book3);
        library.addNewBook(book4);

        cout << endl;

        user2->giveRating(library.getLibraryInventory(), 2, 5.0);
        user2->giveRating(library.getLibraryInventory(), 1, 10.0);
        user3->giveRating(library.getLibraryInventory(), 2, 1.0);
        user3->giveRating(library.getLibraryInventory(), 1, 4.0);
        user1->giveRating(library.getLibraryInventory(), 1, 5.0);
        user1->giveRating(library.getLibraryInventory(), 3, 2.0);

        cout << endl;

        cout << "Books sorted in ascending order of ratings: " << endl;
        library.getLibraryInventory().reverseBooksByRating();

        library.displayBooks();

        delete book1;
        delete book2;
        delete book3;
        delete book4;

        break;
    }
    case 9:
    {
        cout << "Test case 9 selected" << endl;

        Library library;

        library.addUser(1, "Alice");
        library.addUser(2, "Bob");
        library.addUser(3, "Charlie");

        User *user1 = library.getUserById(1);
        User *user2 = library.getUserById(2);
        User *user3 = library.getUserById(3);

        Book *book1 = new Book(1, "The Great Gatsby", "F. Scott Fitzgerald", 7);
        Book *book2 = new Book(2, "1984", "George Orwell", 3);
        Book *book3 = new Book(3, "To Kill a Mockingbird", "Harper Lee", 2);
        Book *book4 = new Book(4, "Great Expectations", "Charles Dickens", 1);

        library.addNewBook(book1);
        library.addNewBook(book2);
        library.addNewBook(book3);
        library.addNewBook(book4);

        cout << endl;

        user2->giveRating(library.getLibraryInventory(), 2, 5.0);
        user2->giveRating(library.getLibraryInventory(), 1, 10.0);
        user3->giveRating(library.getLibraryInventory(), 2, 1.0);
        user3->giveRating(library.getLibraryInventory(), 1, 4.0);
        user1->giveRating(library.getLibraryInventory(), 1, 5.0);
        user1->giveRating(library.getLibraryInventory(), 3, 2);

        cout << endl;

        Book *maxBook = library.getLibraryInventory().getBookWithMaxRating();
        Book *minBook = library.getLibraryInventory().getBookWithMinRating();

        cout << "Book with highest rating: " << maxBook->getTitle() << endl;
        cout << "Book with lowest rating: " << minBook->getTitle() << endl;

        delete book1;
        delete book2;
        delete book3;
        delete book4;

        break;
    }
    case 10:
    {
        cout << "Test case 10 selected" << endl;

        Library library;
        cout << "Initial Library Revenue: $" << library.getTotalRevenue() << endl;

        library.addUser(1, "Bob");
        User *user1 = library.getUserById(1);
        Book *book1 = new Book(1, "The Great Gatsby", "F. Scott Fitzgerald", 7);
        library.addNewBook(book1);

        cout << endl;
        cout << "Initially Bob has " << user1->getNumBooksBorrowed() << " books" << endl;
        cout << endl;

        for (int i = 0; i < 6; i++)
        {
            user1->borrowBook(book1);
        }

        cout << endl;
        cout << "After borrowing books:" << endl;
        cout << "Bob borrowed " << user1->getNumBooksBorrowed() << " books." << endl;
        cout << "Total Revenue before adding slots: $" << library.getTotalRevenue() << endl;

        library.upgradeUserSlots(1, 2);
        for (int i = 0; i < 3; i++)
        {
            user1->borrowBook(book1);
        }

        cout << endl;
        user1->viewBorrowedBooks();
        cout << "Total Revenue after adding slots: $" << library.getTotalRevenue() << endl;

        delete book1;

        break;
    }
    case 11:
    {
        cout << "Hidden test case 1 selected" << endl;

        Library library;

        library.addUser(1, "Sam");
        library.addUser(2, "John");

        User *user1 = library.getUserById(1);
        User *user2 = library.getUserById(2);

        cout << "User details:" << endl;
        cout << "User ID: " << user1->getUserId() << " with name: " << user1->getUserName() << " has been added." << endl;
        cout << "User ID: " << user2->getUserId() << " with name: " << user2->getUserName() << " has been added." << endl;

        break;
    }
    case 12:
    {
        cout << "Hidden test case 2 selected" << endl;

        Library library;

        library.addUser(1, "Sam");
        library.addUser(2, "Elizabeth");

        cout << "Total Revenue before adding books: $" << library.getTotalRevenue() << endl;

        Book *book1 = new Book(1, "Frankenstein", "Mary Shelley", 4);
        Book *book2 = new Book(2, "Hamlet", "William Shakespeare", 2);
        Book *book3 = new Book(3, "Lord of the Flies", "William Golding", 5);

        library.addNewBook(book1);
        library.addNewBook(book2);
        library.addNewBook(book3);

        cout << "Total Revenue after adding books: $" << library.getTotalRevenue() << endl;

        library.displayBooks();

        delete book1;
        delete book2;
        delete book3;

        break;
    }
    case 13:
    {
        cout << "Hidden test case 3 selected" << endl;

        Library library;

        library.addUser(1, "Sam");
        library.addUser(2, "John");
        library.addUser(3, "Amanda");

        User *user1 = library.getUserById(1);
        User *user2 = library.getUserById(2);
        User *user3 = library.getUserById(3);

        Book *book1 = new Book(1, "Frankenstein", "Mary Shelley", 4);
        Book *book2 = new Book(2, "Hamlet", "William Shakespeare", 2);
        Book *book3 = new Book(3, "Lord of the Flies", "William Golding", 5);
        Book *book4 = new Book(4, "Catch-22", "Joseph Heller", 1);

        library.addNewBook(book1);
        library.addNewBook(book2);
        library.addNewBook(book3);
        library.addNewBook(book4);

        cout << endl;

        cout << "Initially Sam has " << user1->getNumBooksBorrowed() << " books" << endl;
        cout << "Initially John has " << user2->getNumBooksBorrowed() << " books" << endl;
        cout << "Initially Amanda has " << user3->getNumBooksBorrowed() << " books" << endl;

        cout << endl;

        user1->borrowBook(book1);
        user1->borrowBook(book1);
        user1->borrowBook(book1);

        user1->borrowBook(book2);
        user1->borrowBook(book2);

        user2->borrowBook(book3);

        cout << "After borrowing books:" << endl
             << endl;

        cout << "Sam borrowed " << user1->getNumBooksBorrowed() << " books." << endl;
        user1->viewBorrowedBooks();
        cout << endl;
        cout << "John borrowed " << user2->getNumBooksBorrowed() << " books." << endl;
        user2->viewBorrowedBooks();
        cout << endl;
        cout << "Amanda borrowed " << user3->getNumBooksBorrowed() << " books." << endl;
        user3->viewBorrowedBooks();

        delete book1;
        delete book2;
        delete book3;
        delete book4;

        break;
    }
    case 14:
    {
        cout << "Hidden test case 4 selected" << endl;

        Library library;

        library.addUser(1, "Sam");
        library.addUser(2, "John");
        library.addUser(3, "Amanda");

        User *user1 = library.getUserById(1);
        User *user2 = library.getUserById(2);
        User *user3 = library.getUserById(3);

        Book *book1 = new Book(1, "Frankenstein", "Mary Shelley", 4);
        Book *book2 = new Book(2, "Hamlet", "William Shakespeare", 2);
        Book *book3 = new Book(3, "Lord of the Flies", "William Golding", 5);
        Book *book4 = new Book(4, "Catch-22", "Joseph Heller", 1);

        library.addNewBook(book1);
        library.addNewBook(book2);
        library.addNewBook(book3);
        library.addNewBook(book4);

        cout << endl;

        cout << "There are " << library.getLibraryInventory().countBooks() << " books in the library. They are:" << endl;
        library.displayBooks();

        cout << endl;

        user1->borrowBook(book1);
        user1->borrowBook(book1);
        user1->borrowBook(book1);

        user2->borrowBook(book3);
        user2->borrowBook(book4);

        user3->borrowBook(book3);

        cout << endl
             << "Sam has " << user1->getNumBooksBorrowed() << " books" << endl;
        cout << "John has " << user2->getNumBooksBorrowed() << " books" << endl;
        cout << "Amanda has " << user3->getNumBooksBorrowed() << " books" << endl;

        cout << endl;

        cout << "After users borrow, there are " << library.getLibraryInventory().countBooks() << " books in the library." << endl;

        user1->returnBook(book1);

        cout << "After user returns, there are " << library.getLibraryInventory().countBooks() << " books in the library." << endl;

        delete book1;
        delete book2;
        delete book3;
        delete book4;

        break;
    }
    case 15:
    {
        cout << "Hidden test case 5 selected" << endl;

        Library library;

        library.addUser(1, "Sam");
        library.addUser(2, "John");
        library.addUser(3, "Amanda");

        User *user1 = library.getUserById(1);
        User *user2 = library.getUserById(2);
        User *user3 = library.getUserById(3);

        Book *book1 = new Book(1, "Frankenstein", "Mary Shelley", 4);
        Book *book2 = new Book(2, "Hamlet", "William Shakespeare", 2);
        Book *book3 = new Book(3, "Lord of the Flies", "William Golding", 5);
        Book *book4 = new Book(4, "Catch-22", "Joseph Heller", 1);

        library.addNewBook(book1);
        library.addNewBook(book2);
        library.addNewBook(book3);
        library.addNewBook(book4);

        user1->giveRating(library.getLibraryInventory(), 2, 5.0);
        user2->giveRating(library.getLibraryInventory(), 1, -5.0);
        user2->giveRating(library.getLibraryInventory(), 4, 3.0);
        user3->giveRating(library.getLibraryInventory(), 2, 2.5);
        user3->giveRating(library.getLibraryInventory(), 1, 5.0);
        user3->giveRating(library.getLibraryInventory(), 3, 1.4);

        library.getLibraryInventory().sortBooks(BY_RATING);
        library.displayBooks();

        Book *maxBook = library.getLibraryInventory().getBookWithMaxRating();
        Book *minBook = library.getLibraryInventory().getBookWithMinRating();

        cout << "Book with highest rating: " << maxBook->getTitle() << endl;
        cout << "Book with lowest rating: " << minBook->getTitle() << endl;

        delete book1;
        delete book2;
        delete book3;
        delete book4;

        break;
    }
    case 16:
    {
        cout << "Hidden test case 6 selected" << endl;

        Book *book1 = new Book(1, "The Diary of Anne Frank", "Anne Frank", 1, 5.0);
        Book *book2 = new Book(2, "The Grapes of Wrath", "John Steinbeck", 1, 3.0);

        BookList originalList;
        originalList.insertBook(book1);
        originalList.insertBook(book2);

        BookList copiedList = originalList;

        cout << "Original Book List:" << endl;
        originalList.displayBooks();
        cout << endl;

        cout << "Copied Book List:" << endl;
        copiedList.displayBooks();
        cout << endl;

        cout << "Let's remove The Grapes of Wrath from the original book list." << endl;
        originalList.removeBook(book2);

        cout << "Original Book List (after removal):" << endl;
        originalList.displayBooks();
        cout << endl;

        cout << "Copied Book List:" << endl;
        copiedList.displayBooks();
        cout << endl;

        delete book1;
        delete book2;

        break;
    }
    case 17:
    {
        cout << "Hidden test case 7 selected" << endl;

        Library library;

        library.addUser(1, "Sam");
        library.addUser(2, "John");
        library.addUser(3, "Amanda");

        Book *book1 = new Book(1, "Frankenstein", "Mary Shelley", 4);
        Book *book2 = new Book(2, "Hamlet", "William Shakespeare", 2);
        Book *book3 = new Book(3, "Lord of the Flies", "William Golding", 1);

        library.addNewBook(book1);
        library.addNewBook(book2);
        library.addNewBook(book3);

        cout << endl
             << "Number of books in library = " << library.getLibraryInventory().countBooks() << endl;
        library.removeBook(3);

        cout << "Number of books in library after removing the book = " << library.getLibraryInventory().countBooks() << endl;
        delete book1;
        delete book2;
        delete book3;

        break;
    }
    }

    return 0;
}