#include "../include/user.hpp"

#include <algorithm>
#include <memory>
#include <string>
#include <vector>

using std::remove_if;
using std::shared_ptr;
using std::string;
using std::vector;

User::User(int id, const string &name) : id(id), name(name) {}

int User::getId() const { return id; }

string User::getName() const { return name; }

const vector<shared_ptr<Book>> &User::getBorrowedBooks() const {
  return borrowedBooks;
}

void User::borrowBook(shared_ptr<Book> book) { borrowedBooks.push_back(book); }

void User::returnBook(int bookId) {
  borrowedBooks.erase(remove_if(borrowedBooks.begin(), borrowedBooks.end(),
                                [bookId](const shared_ptr<Book> &book) {
                                  return book->getId() == bookId;
                                }),
                      borrowedBooks.end());
}
