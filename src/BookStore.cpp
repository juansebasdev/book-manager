#include "BookStore.h"

void BookStore::AddBook(Book *book)
{
    books.push_back(book);
    UpdateDataFile();
}

Book *BookStore::GetBook(int id)
{
    auto it = std::find_if(books.begin(), books.end(), [&id](Book *book)
                           { return book->GetId() == id; });

    if (it != books.end())
    {
        int idx = std::distance(books.begin(), it);
        return books[idx];
    }

    return nullptr;
}

void BookStore::DeleteBook(int id)
{
    auto it = std::find_if(books.begin(), books.end(), [&id](Book *book)
                           { return book->GetId() == id; });

    if (it != books.end())
    {
        int idx = std::distance(books.begin(), it);
        books.erase(books.begin() + idx);
        UpdateDataFile();
    }
}

void BookStore::UpdateDataFile()
{
    fileManager.WriteFile(books);
}