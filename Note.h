#pragma once
#include<iostream>
#include"Date.h"

class Note
{
private:
	unsigned int ID;
	Date date;
	std::string note;

public:
	Note(unsigned int ID, const Date& date, const std::string& note) :ID{ ID }, date{ date }, note{ note }
	{

	}

	//gets
	inline const Date& getDate() const
	{
		return this->date;
	}

	inline const std::string& getNote() const
	{
		return this->note;
	}

	inline unsigned int getID() const
	{
		return this->ID;
	}

	//sets
	void setDate(unsigned int day, unsigned int month, unsigned int year);
	void setDate(const Date& date);
	void setNote(const std::string& note);

	Note& operator=(const Note& note);

	friend bool operator==(const Note& note_1, const Note& note_2);
	friend bool operator!=(const Note& note_1, const Note& note_2);

	friend std::ostream& operator<<(std::ostream& out, const Note& note);
};

