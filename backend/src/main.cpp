#include "../include/libraryService.hpp"
#include <httplib.h>
#include <iostream>
#include <string>

using httplib::Server, httplib::Response, httplib::Request;
using std::exception;
using std::stoi;
using std::string_view;

int main() {
  LibraryService libraryService;
  Server server;
  constexpr string_view host = "localhost";
  constexpr int port = 5000;

  server.Post("/borrow", [&](const Request &req, Response &res) {
    int userId = stoi(req.get_param_value("userId"));
    int bookId = stoi(req.get_param_value("bookId"));
    try {
      libraryService.borrowBook(userId, bookId);
      res.set_content("Book borrowed successfully", "text/plain");
    } catch (const exception &e) {
      res.status = 400;
      res.set_content(e.what(), "text/plain");
    }
  });

  server.Post("/return", [&](const Request &req, Response &res) {
    int userId = stoi(req.get_param_value("userId"));
    int bookId = stoi(req.get_param_value("bookId"));

    try {
      libraryService.returnBook(userId, bookId);
      res.set_content("Book returned successfully", "text/plain");
    } catch (const exception &e) {
      res.status = 400;
      res.set_content(e.what(), "text/plain");
    }
  });

  std::cout << "[status] server is running on "
            << "http://" << host << ":" << port << "\n";
  server.listen(host.data(), port);
  return 0;
}
