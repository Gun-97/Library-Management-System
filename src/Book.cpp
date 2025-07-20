#include "Book.hpp"
#include <iostream> 

Book::Book(const std::string& title, const std::string& author, const std::string& isbn)
        :title(title), author(author), isbn(isbn), available(true) {}

std::string Book::getTitle() const { 
        return title;
}
std::string Book::getAuthor() const { 
        return author;
}
std::string Book::getISBN() const { 
        return isbn;
}
bool Book::isAvailable() const { 
        return available;
}
void Book::borrowBook() { 
        available = false; 
}
void Book::returnBook() { 
        available = true; 
}
void Book::setTitle(const std::string& title) {
        this->title = title;
}
void Book::setAuthor(const std::string& author) {
        this->author = author;
}
void Book::setISBN(const std::string& isbn) {
        this->isbn = isbn;
}
void Book::display() const {
    // Print book details
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "ISBN: " << isbn << std::endl;
    std::cout << "Status: " << (available ? "Available" : "Borrowed") << std::endl;
}