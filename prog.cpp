#include <iostream>
#include<Windows.h>
#include<conio.h>
#include<string>
#include"Organizer.h"

void showAll(const Organizer& org);
void addNote(Organizer& org);
void enterNote(Date& date, std::string& note);
void editNote(Organizer& org);
void removeNote(Organizer& org);

int main()
{
	Organizer org;

	do
	{
		system("cls");

		std::cout << "1 - Show all notes\n";
		std::cout << "2 - Add a note\n";
		std::cout << "3 - Edit a note\n";
		std::cout << "4 - Remove a note\n";
		std::cout << "0 - Exit\n";

		char ch;

		ch = _getch();

		if (ch == '0')
			break;

		try
		{
			switch (ch)
			{
			case '1':
				showAll(org);
				system("pause");
				break;

			case '2':
				addNote(org);
				std::cout << "Added...";
				Sleep(1000);
				break;

			case '3':
				editNote(org);
				Sleep(1000);
				break;

			case '4':
				removeNote(org);
				Sleep(1000);
				break;

			default:
				std::cout << "Wrong choise...\n";
				Sleep(1000);
				break;
			}

		}
		catch (ExceptionList& error)
		{
			std::cout << error.what();
			Sleep(1000);
		}


	} while (true);

}

void showAll(const Organizer& org)
{
	if (org.size() == 0)
	{
		std::cout << "You have not notes\n";
	}

	else
	{
		org.print();
	}
}

void enterNote(Date& date, std::string& note)
{
	unsigned int day, month, year;

	std::cout << "Enter a date (dd/mm//yyyy): ";
	scanf_s("%i/%i/%i", &day, &month, &year);

	std::cin.ignore();

	date = Date(day, month, year);

	std::cout << "Enter a note: ";
	std::getline(std::cin, note);
}

void addNote(Organizer& org)
{
	Date date;
	std::string note;

	enterNote(date, note);

	org.add(date, note);
}

void editNote(Organizer& org)
{
	showAll(org);

	if (org.size() != 0)
	{
		std::cout << "Enter an ID: ";
		unsigned int ID;

		std::cin >> ID;

		std::cin.ignore();

		std::cout << *org.getByID(ID) << "\n";

		Date date;
		std::string note;

		enterNote(date, note);

		org.edit(ID, date, note);

		std::cout << "Edited...\n";
	}
}

void removeNote(Organizer& org)
{
	showAll(org);

	if (org.size() != 0)
	{
		std::cout << "Enter an ID: ";
		unsigned int ID;

		std::cin >> ID;

		std::cin.ignore();

		std::cout << *org.getByID(ID) << "\n";

		std::cout << "Are you sure (1 for delete): ";
		char ch;
		ch = _getch();

		if (ch == '1')
			org.remove(ID);

		std::cout << "Deleted...\n";
	}
}