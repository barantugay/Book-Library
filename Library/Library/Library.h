#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;

class Library{
public:
	Library(int type, int id, string name, int page);
	~Library();

	void setTypeOfBook(int type);
	int getTypeOfBook();

	void setBookId(int id);
	int getBookId();

	void setBookName(string name);
	string getBookName();

	void setPageNum(int page);
	int getPageNum();

	void bookInfos();

	bool operator<(const Library& other) const;


private:
	int typeOfBook;
	int bookId;
	string bookName;
	int pageNum;


};


