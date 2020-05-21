#include "Book.h"
constexpr auto COUNT_BOOKS = 3;

void DemoBook()
{
	Book books[COUNT_BOOKS];
	for (int i = 0; i < COUNT_BOOKS; i++)
	{
		ReadBookFromConsole(books[i]);
	}

	for (int i = 0; i < COUNT_BOOKS; i++)
	{
		WriteBookToConsole(books[i]);
	}

	string author;
	cout << "Enter number of Authors:";
	getline(cin, author);

	int result = FindBookByAuthor(books, COUNT_BOOKS, author);

	if (result == -1)
	{
		cout << "The author doesn't exist!";
	}
	else {
		WriteBookToConsole(books[result]);
	}

}

void ReadBookFromCoonsole(Book & book)
{
	cout << "Enter title of the book: ";
	getline(cin, book.title);

	while (true)
	{
		cout << "Enter year: ";
		cin >> book.year;
		if (book.year > 0 && book.year <= 2020)
		{
			break;
		}
		cout << "Year must be posit,  but not more than current year.";
		cout << "\nEnter agin!" << endl;
		cin.clear();
		cin.ignore(32767, '\0');
	}

	while (true)
	{
		cout << "\nEnter number of pages:";
		cin >> book.pages;
		if (book.pages > 0)
		{
			break;
		}
		cout << "Pages must be greater than 0: ";
		cout << "\nEnter agin!" << endl;
		cin.clear();
		cin.ignore(32767, '\0');
	}

	while (true)
	{
		cout << "\nEnter number of authors:";
		cin >> book.authorCount;
		if (book.authorCount > 0)
		{
			break;
		}
		cout << "Authors must not be greater than 10: ";
		cout << "\nEnter agin!" << endl;
		cin.clear();
		cin.ignore(32767, '\0');
		
		for (int i = 0; i < book.authorCount; i++)
		{
			cout << "Eter author: № " << i << ": ";
			getline(cin, book.authors[i]);
		}
	}

}

void WriteBookToConsole(Book& book)
{
	if (book.authorCount > 1)
	{
		for (int i = 0; i < book.authorCount - 1; i++)
		{
			cout << book.authors[i] << ", ";
		}
	}
	cout << book.authors[book.authorCount - 1] << " "
		<< book.title << ". " << book.year << ". - "
		<< book.pages << "c. " << endl;
}

int FindBookByAuthor(Book* books, int booksCount, string author)
{
	int index = -1;
	for (int i = 0; i < booksCount; i++)
	{
		for (int j = 0; j < booksCount; j++)
		{
			if (author==books[i].authors[j])
			{
				index = i;
				break;

			}
		}
	}
	return index;
}

