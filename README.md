# Library Management System

## Overview

This C++ project simulates a library management system. It allows you to manage users, books, and borrowing/returning functionalities. The system also includes features for rating books, sorting, and searching.

## Features

*   **User Management:**
    *   Add new users to the library.
    *   Upgrade user borrowing slots.
    *   Display all users and their details.
*   **Book Management:**
    *   Add new books to the library.
    *   Remove books from the library.
    *   Display all books in the library.
    *   Search for books by ID.
*   **Borrowing and Returning:**
    *   Users can borrow books, subject to availability and borrowing limits.
    *   Users can return borrowed books.
*   **Book Rating:**
    *   Users can rate books.
    *   The system calculates and updates average ratings.
*   **Sorting and Searching:**
    *   Sort books by rating or title.
    *   Find books with the highest or lowest ratings.
*   **Revenue Tracking:**
    *   The library tracks revenue from user upgrades and book additions.

## Key Components

*   **`Book` Class (`Book.h` and `Book.cpp`):** Represents a book with attributes like ID, title, author, inventory count, and rating.
    *   `changeInventoryCount(int c)`:  Modifies the book's inventory.  Used when books are borrowed or returned.
    *   `addRating(double newRating)`: Adds a new rating to the book and updates the average rating.
*   **`BookList` Class (`BookList.h` and `BookList.cpp`):**  Manages a linked list of `Book` objects.
    *   `insertBook(Book *book)`: Adds a book to the list or increases the inventory count if the book already exists.
    *   `removeBook(Book *book)`: Removes a book from the list. If the inventory count is greater than 1, it decrements the count instead of deleting the book.
    *   `sortBooks(SortCriteria criteria)`: Sorts the book list by rating or title.
*   **`User` Class (`User.h` and `User.cpp`):** Represents a library user with borrowing privileges.
    *   `borrowBook(Book *book)`: Allows a user to borrow a book, decreasing the book's inventory count.
    *   `returnBook(Book *book)`: Allows a user to return a book, increasing the book's inventory count.
    *   `giveRating(BookList &list, int bookId, double newRating)`: Allows a user to rate a book in the library's book list.
*   **`Library` Class (`Library.h` and `Library.cpp`):** Manages users and the library's book inventory.  This class acts as the central hub, coordinating interactions between users and books.

    *   **Constructor and Destructor:**

        ```cpp
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
        ```

        *   The constructor initializes the library with a given capacity for users and sets the initial revenue to 0. It dynamically allocates an array of `User` pointers.
        *   The destructor deallocates the memory used by the `User` objects and the `users` array to prevent memory leaks.

    *   **Adding a User:**

        ```cpp
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
        ```

        *   This function adds a new user to the library. If the user capacity is reached, it doubles the capacity by allocating a new array, copying the existing users, and deleting the old array. A new `User` object is created and added to the array, the total revenue is increased, and the user count is incremented.

    *   **Upgrading User Slots:**

        ```cpp
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
        ```

        *   This function upgrades the maximum number of books a user can borrow. It iterates through the `users` array to find the user with the given ID. If the user is found, the upgrade cost is added to the total revenue, the user's maximum books are updated, and a confirmation message is printed. If the user is not found, an error message is printed.

    *   `addUser(int id, const string &name)`: Adds a new user to the library's user list.
    *   `addNewBook(Book *book)`: Adds a new book to the library's book list.  It also increases the library's revenue.
    *   `upgradeUserSlots(int userId, int additionalSlots)`: Upgrades the maximum number of books a user can borrow, increasing the library's revenue.
    *   `borrowBook(int userId, int bookId)`: Allows a user to borrow a specific book. It checks if the user exists, if the book exists and is available, and if the user has enough borrowing slots. It then updates the user's borrowed books and the book's inventory.
    *   `returnBook(int userId, int bookId)`: Allows a user to return a borrowed book. It updates the user's borrowed books and the book's inventory.
    *   `getBookList()`: Returns a reference to the library's `BookList` object, allowing access to book management functions.
    *   `getUserList()`: Returns a reference to the library's `UserList` object, allowing access to user management functions.

## How the Program Works (main.cpp)

The `main` function in `main.cpp` acts as a test harness.  It presents a menu of test cases (1-17) that demonstrate the functionality of the library management system.

1.  **Test Case Selection:** The program prompts the user to select a test case.
2.  **Library Initialization:**  A `Library` object is created.  This is the core object that manages all other objects.
3.  **User and Book Creation:**  Users and books are created and added to the library using the `Library` class's `addUser` and `addNewBook` methods.
4.  **Functionality Demonstration:** The selected test case then calls various functions of the `Library`, `User`, and `BookList` classes *through the `Library` object* to demonstrate features like:
    *   Adding users and books (via `Library::addUser` and `Library::addNewBook`)
    *   Borrowing and returning books (via `Library::borrowBook` and `Library::returnBook`)
    *   Rating books (often involving getting the `BookList` from the `Library` and then calling `Book::addRating`)
    *   Sorting books (getting the `BookList` from the `Library` and then calling `BookList::sortBooks`)
    *   Displaying library information (using methods in `Library`, `BookList`, and `UserList`).
5.  **Memory Management:**  The test cases ensure that dynamically allocated memory (using `new`) is properly released (using `delete`) to prevent memory leaks.

**The Central Role of the `Library` Class:**

The `Library` class is the heart of the system. It holds instances of `BookList` and `UserList`, and it provides the methods that allow users to interact with books.  The `main` function primarily interacts with the `Library` object, which then delegates tasks to the other classes.  This design promotes modularity and makes the system easier to extend.

## Building the Project

To build the project, you can use the provided `makefile` (`makefile`).

1.  **Navigate to the project directory:**

    ```bash
    cd ~/LMS
    ```

2.  **Compile the code:**

    ```bash
    make
    ```

## Running the Tests

After building the project, run the executable and enter a number between 1 and 17 to run the corresponding test case.

## Dependencies

*   A C++ compiler (e.g., g++)
*   Make (for building with the `makefile`)

## Future Enhancements

*   Implement a more persistent storage mechanism (e.g., file I/O or a database) to save and load library data.
*   Add a graphical user interface (GUI) for easier interaction.
*   Implement more advanced search and filtering options.
*   Add user authentication and authorization.
*   Implement late fee tracking.