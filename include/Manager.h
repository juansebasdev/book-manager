#pragma once

#include <iostream>
#include <stdlib.h>
#include "BookStore.h"

class Manager
{
private:
    BookStore store;

    std::string PrintBook(Book *book);

public:
    Manager() { store = BookStore(); }
    std::string CreateBook();
    std::string ShowBooks();
    std::string GetBook();
    std::string DeleteBook();
};