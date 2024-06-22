#pragma once

#include "book.hpp"
#include "user.hpp"
#include <memory>
#include <vector>

using std::shared_ptr;
using std::vector;

class LibraryService {
public:
  LibraryService();

  void borrowBook(int userId, int bookId);
  void returnBook(int userId, int bookId);

private:
  vector<shared_ptr<Book>> books;
  vector<shared_ptr<User>> users;

  shared_ptr<User> findUserById(int userId);
  shared_ptr<Book> findBookById(int bookId);
};
