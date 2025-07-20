#pragma once
#include<string>

class Book {
    private:
    std::string title;
    std::string author;
    std::string isbn;
    bool available; // Is book available?

    public:
    Book(const std::string& title, const std::string& author, const std::string& isbn);

    std::string getTitle() const;   // Get title
    std::string getAuthor() const;  // Get author
    std::string getISBN() const;    // Get ISBN
    bool isAvailable() const;       // Check if available

    void setTitle(const std::string& title);
    void setAuthor(const std::string& author);
    void setISBN(const std::string& isbn);

    void borrowBook();  // Mark as borrowed
    void returnBook();  // Mark as returned

    void display() const; // Show book info

};