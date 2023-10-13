#pragma once

#include <vector>
#include <algorithm>
#include "Book.h"

class BookStore
{
private:
    std::vector<Book *> books;

public:
    void AddBook(Book *book);
    Book *GetBook(int id);
    std::vector<Book *> GetBooks() { return books; }
    void DeleteBook(int id);
};