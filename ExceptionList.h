#pragma once
#include<iostream>

class ExceptionList :public std::exception
{
private:
	std::string m_error;

public:
	ExceptionList(const std::string& error) :m_error{ error }
	{

	}

	const char* what() const noexcept override
	{
		return this->m_error.c_str();
	}
};

