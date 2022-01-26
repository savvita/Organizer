#pragma once
#include"DLinkedList.h"
#include"Note.h"

class Organizer
{
private:
	DLinkedList<Note> notes;
	unsigned int count;

public:
	Organizer() :count{ 0 }
	{

	}

	inline unsigned int size() const
	{
		return this->notes.getSize();
	}

	void add(const Date& date, const std::string& note);

	Note* getByID(unsigned int ID) const;

	void edit(unsigned int ID, const Date& newDate, const std::string& newNote);

	void remove(unsigned int ID);

	void print(std::ostream& out = std::cout) const;

};

