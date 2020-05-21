#pragma once
#include <iostream>
#include <string>

using namespace std;

//static const int SIZE = 10;

struct Book {
	string title;
	int year;
	int pages;
	string authors[10]; 
	int authorCount;
};


void DemoBook();
void ReadBookFromConsole(Book& book);
void WriteBookToConsole(Book& book);
int FindBookByAuthor(Book* books, int booksCount, string author);