#include "../include/book.hpp"
#include <string>

using std::string;

Book::Book(int id, const string &title, const string &author)
    : id(id), title(title), author(author), available(true) {}

int Book::getId() const { return id; }

string Book::getTitle() const { return title; }

string Book::getAuthor() const { return author; }

bool Book::isAvailable() const { return available; }

void Book::setAvailable(bool available) { this->available = available; }
