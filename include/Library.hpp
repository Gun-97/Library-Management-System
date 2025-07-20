#pragma once
#include"Book.hpp"
#include<vector>
#include<string>
class Library {

    private:
    std::vector<Book> books;

    public:
    Library();

    void addBook(const Book& book);
    void displayAllBooks() const;
    bool borrowBook(const std::string& title);
    bool returnBook(const std::string& title);
    // void searchByTitleOrISBN(const std::string& title) const;
    void searchByTitleOrISBN(const std::string& keyword) const;
    void listBooks() const;
    void saveBooksToFile(const std::string& filename) const;
    void loadBooksFromFile(const std::string& filename);
};