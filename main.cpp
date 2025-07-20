#include<iostream>
#include"Book.hpp"
#include"Library.hpp"

using namespace std;

// Show menu options
void menu(){
    cout << "=== Library Management System ===" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Display All Books" << endl;
    cout << "3. List Books" << endl;
    cout << "4. Search Book by Title and ISBN" << endl;
    cout << "5. Borrow Book" << endl;
    cout << "6. Return Book" << endl;
    cout << "0. Exitint......" << endl ;
}

Library library; // Create library object

int main() {
    system("cls"); // Clear screen

    library.loadBooksFromFile("books.txt"); // Load books

    int op;
    do {
        menu(); // Show menu
        cout << "Please enter an option: ";   

        while (true) {
            if (cin >> op && op >= 0 && op <= 6) {
                break;
            } else {
                cout << "Invalid input! Please enter a number from 0 to 6: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }
        cin.ignore();
        cout << "Result: " << op  <<" Invalid input!  number from 0 to 6: "<< endl; 
        switch (op) {
            case 1: {
                system("cls");
                string title, author, isbn;

                cout << "Please enter title: ";
                getline(cin, title); // Get book title
                cout << "Please enter author: ";
                getline(cin, author); // Get author
                cout << "Please  enter ISBN: ";
                getline(cin, isbn); // Get ISBN

                library.addBook(Book(title, author, isbn)); // Add book
                cout << "Book added successfully." << endl;
                break;
            }
            case 2:
                system("cls");
                library.displayAllBooks(); // Show all books
                break;

            case 3:
                system("cls");
                library.listBooks(); // List books
                break;
            // case 4: {
            //     system("cls");
            //     string title;
            //     cout << "Enter title to search: ";
            //     getline(cin, title);
            //     library.searchByTitleOrISBN(title);
            //     break;
            // }
            case 4: {
                system("cls");
                string keyword;
                cout << "Enter title or ISBN to search: ";
                getline(cin, keyword); // Get search keyword
                library.searchByTitleOrISBN(keyword); // Search book
                break;
            }
            case 5: {
                system("cls");
                library.displayAllBooks();
                string title;
                cout << "Enter title to borrow: ";
                getline(cin, title); // Get title to borrow
                if (library.borrowBook(title))
                    cout << "Book borrowed successfully." << endl;
                else
                    cout << "Book not available or does not exist." << endl;
                break;
            }
            case 6: {
                system("cls");
                library.displayAllBooks();
                string title;
                cout << "Enter title to return: ";
                getline(cin, title); // Get title to return
                if (library.returnBook(title))
                    cout << "Book returned successfully." << endl;
                else
                    cout << "Book was not borrowed or does not exist." << endl;
                break;
            }
            case 0:{
                system("cls");
                library.saveBooksToFile("books.txt"); // Save books before exiting
                cout << "Exit" << endl;
                return 0;
            }
        }
    } while (op != 0);

    return 0;
}