#include "../include/libraryService.hpp"
#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>

using std::cout;
using std::endl;
using std::find_if;
using std::make_shared;
using std::runtime_error;

LibraryService::LibraryService() {
  books.push_back(make_shared<Book>(1, "1984", "George Orwell"));
  books.push_back(
      std::make_shared<Book>(2, "To Kill a Mockingbird", "Harper Lee"));
  users.push_back(make_shared<User>(1, "Alice"));
  users.push_back(make_shared<User>(2, "Bob"));
}

void LibraryService::borrowBook(int userId, int bookId) {
  auto user = findUserById(userId);
  auto book = findBookById(bookId);

  if (!user) {
    throw runtime_error("User not found");
  }
  if (!book || !book->isAvailable()) {
    throw runtime_error("Book not available");
  }

  book->setAvailable(false);
  user->borrowBook(book);
  cout << user->getName() << " borrowed \"" << book->getTitle() << "\"" << endl;
}

void LibraryService::returnBook(int userId, int bookId) {
  auto user = findUserById(userId);
  auto book = findBookById(bookId);

  if (!user || !book) {
    throw runtime_error("User or book not found");
  }

  book->setAvailable(true);
  user->returnBook(bookId);
  cout << user->getName() << " returned \"" << book->getTitle() << "\"" << endl;
}

std::shared_ptr<User> LibraryService::findUserById(int userId) {
  auto it = find_if(users.begin(), users.end(),
                    [userId](const shared_ptr<User> &user) {
                      return user->getId() == userId;
                    });
  return (it != users.end()) ? *it : nullptr;
}

std::shared_ptr<Book> LibraryService::findBookById(int bookId) {
  auto it = find_if(books.begin(), books.end(),
                    [bookId](const shared_ptr<Book> &book) {
                      return book->getId() == bookId;
                    });
  return (it != books.end()) ? *it : nullptr;
}
