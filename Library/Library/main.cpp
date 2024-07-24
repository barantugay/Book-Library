#include <iostream>
#include "Library.h"
#include <string>
#include <list>
using namespace std;


void showMenu() {

	cout << endl << endl;
	cout << "*****************************\n";
	cout << "*                           *\n";
	cout << "*          Library          *\n";
	cout << "*                           *\n";
	cout << "*****************************\n\n";

	cout << "New book register = 1" << endl;
	cout << "Show all books = 2" << endl;
	cout << "Show any book = 3" << endl;
	cout << "Change any book information = 4" << endl;
	cout << "Delete book = 5" << endl;
	cout << "Log out = 6 " << endl;


}

void addBook(list<Library>* book) {
	int type, id, page;
	string name;
	cout << "For science fiction: (1)\n";
	cout << "For classics: (2)\n";
	cout << "For romance: (3)\n";
	cout << "For philosophy: (4)\n";
	cout << "For textbook: (5)\n";
	cout << "Type of book: ";
	cin >> type;
	if (type >= 1 && type <= 5) {
		cout << "Book ID: ";
		cin >> id;
		cout << "Book name: ";
		cin.ignore();
		getline(cin, name);
		cout << "Book Page Number: ";
		cin >> page;

		Library wri(type, id, name, page);
		book->push_back(wri);
	}
	else
	{
		cout << "Wrong choice";
	}
	
}

void showBooks(list<Library>* book) {
	
	cout << "Science Siction Books\n\n";
	for (auto it = book->begin(); it != book->end(); ++it) {
		if (it->getTypeOfBook() == 1) {
			it->bookInfos();
			cout << endl;
		}
	}
	cout << "Classics Books\n\n";
	for (auto it = book->begin(); it != book->end(); ++it) {
		if (it->getTypeOfBook() == 2) {
			it->bookInfos();
			cout << endl;
		}
	}
	cout << "Romance Books\n\n";
	for (auto it = book->begin(); it != book->end(); ++it) {
		if (it->getTypeOfBook() == 3) {
			it->bookInfos();
			cout << endl;
		}
	}

	cout << "Philosopy Books\n\n";
	for (auto it = book->begin(); it != book->end(); ++it) {
		if (it->getTypeOfBook() == 4) {
			it->bookInfos();
			cout << endl;
		}
	}
	cout << "Textbook Books\n\n";
	for (auto it = book->begin(); it != book->end(); ++it) {
		if (it->getTypeOfBook() == 5) {
			it->bookInfos();
			cout << endl;
		}
	}
}

void findBook(list<Library>* book) {
	int id;
	list<Library>::iterator it;

	cout << "Book ID: ";
	cin >> id;

	for (it = book->begin(); it != book->end(); it++) {
		if (id == it->getBookId())
			break;
	}
	if (it == book->end()) {
		cout << "Student has not found!!";
	}
	else
	{
		it->bookInfos();
	}


}

void changeStu(list<Library>* book) {
	int id, newType, newID, newPage;
	string newName;
	list<Library>::iterator it;

	cout << "Book ID: ";
	cin >> id;

	for (it = book->begin(); it != book->end(); it++) {
		if (id == it->getBookId())
			break;
	}
	if (it == book->end()) {
		cout << "Book has not found!!";
	}
	else
	{
		cout << "Book Type: ";
		cin >> newType;
		cout << "Book ID: ";
		cin >> newID;
		cout << "Book Name: ";
		cin.ignore();
		getline(cin, newName);
		cin.ignore();
		cout << "Book Page: ";
		cin >> newPage;
		it->setTypeOfBook(newType);
		it->setBookId(newID);
		it->setBookName(newName);
		it->setPageNum(newPage);
	}


}

void delBook(list<Library>* book) {
	int id;
	list<Library>::iterator it;

	cout << "Book ID: ";
	cin >> id;

	for (it = book->begin(); it != book->end(); it++) {
		if (id == it->getBookId())
			break;
	}
	if (it == book->end()) {
		cout << "Student has not found!!";
	}
	else
	{
		book->erase(it);
	}


}







int main() {
	list<Library>* book = new list<Library>();
	int choice = 0;
	do {
		showMenu();
		cout << "Your choice: ";
		cin >> choice;
		cout << endl << endl;

		switch (choice)
		{
		case 1:
			addBook(book);
			book->sort();
			break;
		case 2:
			showBooks(book);
			break;
		case 3:
			findBook(book);
			break;
		case 4:
			changeStu(book);
			break;
		case 5:
			delBook(book);
			break;
		case 6:
			cout << "You logged out";
			break;
		default:
			cout << "Wrong choice" << endl;
		}

	} while (choice != 6);
	
	delete book;
	cout << endl;
	return 0;
}