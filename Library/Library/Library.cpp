#include "Library.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

Library::Library(int type, int id, string name, int page) {
	typeOfBook = type;
	bookId = id;
	bookName = name;
	pageNum = page;

}

Library::~Library(){

}

void Library::setTypeOfBook(int type) {
    typeOfBook = type;
}
int Library::getTypeOfBook() {
    return typeOfBook;
}

void Library::setBookId(int id) {
    bookId = id;
}
int Library::getBookId() {
    return bookId;
}


void Library::setBookName(string name) {
    bookName = name;
}
string Library::getBookName() {
    return bookName;
}


void Library::setPageNum(int page) {
    pageNum = page;
}
int Library::getPageNum() {
    return pageNum;
}

bool Library::operator<(const Library& other) const {
    return bookName < other.bookName;
}

void Library::bookInfos() {
    cout << "Book id: " << bookId << endl;
    cout << "Book name: " << bookName << endl;
    cout << "Book page number: " << pageNum << endl;
}