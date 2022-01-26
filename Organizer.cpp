#include "Organizer.h"

void Organizer::add(const Date& date, const std::string& note)
{
	this->notes.add(Note(this->count++, date, note));
}

Note* Organizer::getByID(unsigned int ID) const
{
	unsigned int size = this->notes.getSize();

	for (unsigned int i = 0; i < size; i++)
	{
		if (this->notes[i].getID() == ID)
			return &(this->notes.getByIndex(i));
	}

	throw ExceptionList("No note with that ID\n");
}

void Organizer::edit(unsigned int ID, const Date& newDate, const std::string& newNote)
{
	Note* curr = this->getByID(ID);

	if (curr == nullptr)
		throw ExceptionList("Invalid ID\n");

	*curr = Note(curr->getID(), newDate, newNote);
}

void Organizer::remove(unsigned int ID)
{
	Note* curr = this->getByID(ID);

	if (curr == nullptr)
		throw ExceptionList("Invalid ID\n");

	this->notes.remove(*curr);
}

void Organizer::print(std::ostream& out) const
{
	this->notes.print(out);
}