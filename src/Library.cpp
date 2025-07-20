#include"Library.hpp"
#include<iomanip>
#include<iostream>
#include<fstream>
#include <sstream>

void Library::addBook (const Book& book){
    books.push_back(book);// Add book to list
}
Library::Library() {}
void Library::listBooks() const {
    // Print books with numbers
    std::cout << std::left 
              << std::setw(5)  << "No"
              << std::setw(30) << "Title"
              << std::setw(20) << "Author"
              << std::setw(15) << "ISBN"
              << std::setw(12) << "Status"
              << std::endl;

    std::cout << std::string(82, '-') << std::endl;

    int index = 1;
    for (const auto& book : books) {
        std::cout << std::left
                  << std::setw(5)  << index++
                  << std::setw(30) << book.getTitle()
                  << std::setw(20) << book.getAuthor()
                  << std::setw(15) << book.getISBN()
                  << std::setw(12) << (book.isAvailable() ? "Available" : "Borrowed")
                  << std::endl;
    }
}
void Library::displayAllBooks() const {
    std::cout << std::left 
        << std::setw(30) << "Title"
        << std::setw(20) << "Author"
        << std::setw(15) << "ISBN"
        << std::setw(12) << "Status"
        << std::endl;

    std::cout << std::string(77, '-') << std::endl;

    for (const auto& book : books) {
        std::cout << std::left 
            << std::setw(30) << book.getTitle()
            << std::setw(20) << book.getAuthor()
            << std::setw(15) << book.getISBN()
            << std::setw(12) << (book.isAvailable() ? "Available" : "Borrowed")
            << std::endl;
    }
}

bool Library::borrowBook(const std::string& title) {
    for (auto& book : books) {
        if (book.getTitle() == title && book.isAvailable()) {
            book.borrowBook();  // Borrow book
            return true;
        }
    }
    return false;
}
bool Library::returnBook(const std::string& title) {
    for (auto& book : books) {
        if (book.getTitle() == title && !book.isAvailable()) {
            book.returnBook();
            return true;
        }
    }
    return false;
}
// void Library::searchByTitleOrISBN(const std::string& title) const {
//     bool found = false;
//     for (const auto& book : books) {
//         if (!title.empty() && book.getTitle() == title) {
//             book.display();
//             found = true;
//         }
//     }
//     if (!found) {
//         std::cout << "Book not found." << std::endl;
//     }
// }
void Library::searchByTitleOrISBN(const std::string& keyword) const {
    bool found = false;
    // Search for book by title or ISBN
    for (const auto& book : books) {
        if (book.getTitle().find(keyword) != std::string::npos ||
            book.getISBN().find(keyword) != std::string::npos) {
            book.display();
            std::cout << "---------------------------" << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "No book found matching: " << keyword << std::endl;
    }
}
void Library::saveBooksToFile(const std::string& filename) const {
    std::ofstream outFile(filename); 

    if (outFile.is_open()) {
        for (const auto& book : books) {
            outFile << book.getTitle() << ","
                    << book.getAuthor() << ","
                    << book.getISBN() << ","
                    << (book.isAvailable() ? "true" : "false") << std::endl;
        }
        outFile.close();
        std::cout << "Books saved to " << filename << " successfully." << std::endl;
    } else {
        std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
    }
}
void Library::loadBooksFromFile(const std::string& filename) {
    std::ifstream inFile(filename); // Open file for reading

    if (inFile.is_open()) {
        books.clear(); // Clear existing books before loading from file
        std::string line;
        while (std::getline(inFile, line)) {
            std::stringstream ss(line);
            std::string title, author, isbn, availableStr;
            
if (std::getline(ss, title, ',') &&
                std::getline(ss, author, ',') &&
                std::getline(ss, isbn, ',') &&
                std::getline(ss, availableStr)) {

                Book book(title, author, isbn);
                if (availableStr == "false") {
                    book.borrowBook(); // Set status based on file
                }
                books.push_back(book);
            }
        }
        inFile.close();
        std::cout << "Books loaded from " << filename << " successfully." << std::endl;
    } else {
        std::cerr << "No existing book data found in " << filename << ". Starting with default books." << std::endl;
        books.push_back(Book("C++ learning", "Mr.Minh", "098975675"));
        books.push_back(Book("C++ Programming Language", "They", "0987654321"));
        books.push_back(Book("C++ hard", "Coco", "1122334455"));
    }
}