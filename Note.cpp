#include "Note.h"

void Note::setDate(unsigned int day, unsigned int month, unsigned int year)
{
	this->date = Date(day, month, year);
}

void Note::setDate(const Date& date)
{
	this->date = date;
}

void Note::setNote(const std::string& note)
{
	this->note = note;
}

Note& Note::operator=(const Note& note)
{
	this->date = note.date;
	this->note = note.note;
	this->ID = note.ID;

	return *this;
}


bool operator==(const Note& note_1, const Note& note_2)
{
	return (note_1.ID == note_2.ID);
}

bool operator!=(const Note& note_1, const Note& note_2)
{
	return !(note_1 == note_2);
}

std::ostream& operator<<(std::ostream& out, const Note& note)
{
	out << note.ID << ". ";

	if (note.date.isCorrect())
		out << note.date << " ";
	
	out << note.note;


	return out;
}
