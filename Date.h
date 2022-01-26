#pragma once
#include<iostream>

class Date
{
private:
	unsigned int day;
	unsigned int month;
	unsigned int year;

	bool isSet;

public:
	Date() = default;
	Date(unsigned int day, unsigned int month, unsigned int year);
	Date(const Date& date);

	//gets

	inline unsigned int getDay() const
	{
		return this->day;
	}

	inline unsigned int getMonth() const
	{
		return this->month;
	}

	inline unsigned int getYear() const
	{
		return this->year;
	}

	inline bool isCorrect() const
	{
		return this->isSet;
	}

	Date& operator=(const Date& date);

	friend std::ostream& operator<<(std::ostream& out, const Date& date);
};

