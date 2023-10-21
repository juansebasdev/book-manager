#pragma once

#include <iostream>
#include <memory>
#include <stdlib.h>
#include "BookStore.h"
#include "Utils.h"

class Manager
{
private:
    BookStore store = BookStore();

    std::string PrintBook(std::shared_ptr<Book> book);

public:
    std::string CreateBook();
    std::string ShowBooks();
    std::string GetBook();
    std::string DeleteBook();
};