#include "Date.h"
#include "ExceptionList.h"

Date::Date(unsigned int day, unsigned int month, unsigned int year) :isSet{ false }, day{ 0 }, month{ 0 }, year{ 0 }
{
	if (day > 31 || month > 12 || year <= 1900)
	{
		throw ExceptionList("Incorrect date\n");
	}

	this->day = day;
	this->month = month;
	this->year = year;

	isSet = true;
}

Date::Date(const Date& date) :day{ date.day }, month{ date.month }, year{ date.year }, isSet{ date.isSet }
{
}

Date& Date::operator=(const Date& date)
{
	this->day = date.getDay();
	this->month = date.getMonth();
	this->year = date.getYear();
	this->isSet = date.isCorrect();
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	if(date.isSet)
		out << date.day << "/" << date.month << "/" << date.year;
	
	return out;
}
