#pragma once

#include "book.hpp"
#include <memory>
#include <string>
#include <vector>

using std::shared_ptr;
using std::string;
using std::vector;

class User {
public:
  User(int id, const string &name);

  int getId() const;
  string getName() const;
  const vector<shared_ptr<Book>> &getBorrowedBooks() const;
  void borrowBook(shared_ptr<Book> book);
  void returnBook(int bookId);

private:
  int id;
  string name;
  vector<shared_ptr<Book>> borrowedBooks;
};
