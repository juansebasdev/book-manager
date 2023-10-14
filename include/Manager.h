#pragma once

#include <iostream>
#include <stdlib.h>
#include "BookStore.h"
#include "Utils.h"

class Manager
{
private:
    BookStore store = BookStore();

    std::string PrintBook(Book *book);

public:
    std::string CreateBook();
    std::string ShowBooks();
    std::string GetBook();
    std::string DeleteBook();
};