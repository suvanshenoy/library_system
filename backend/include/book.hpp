#pragma once

#include <string>

using std::string;

class Book {
public:
  Book(int id, const string &title, const string &author);

  int getId() const;
  string getTitle() const;
  string getAuthor() const;
  bool isAvailable() const;
  void setAvailable(bool available);

private:
  int id;
  string title;
  string author;
  bool available;
};
