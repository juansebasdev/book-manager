#pragma once

#include <string>

class Book
{
private:
    int id;
    std::string title;
    std::string description;

public:
    static int currentId;

public:
    Book(int id, std::string title, std::string description) : title(title), description(description), id(id) { currentId++; }

    std::string GetTitle() { return this->title; }
    std::string GetDescription() { return this->description; }
    int GetId() { return this->id; }

    void UpdateBook(const std::string &title, const std::string &description);
};