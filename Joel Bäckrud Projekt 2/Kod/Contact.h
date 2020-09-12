#pragma once
using namespace System;


ref class Contact
{

private:
	// Member Variabler
	String^ firstName;
	String^ surName;
	String^ telephoneNumber;

public:
	// Default Konstruktor
	Contact() 
	{
	}
	// Constructor
	Contact(String^ cFirstName, String^ cSurName, String^ cTelephoneNumber)
	{
		this->eFirstName = cFirstName;
		this->eSurName = cSurName;
		this->eTelephoneNumber = cTelephoneNumber;
	}

	// Set & Get
	// e i propertyfunktionernas namn står för egenskap
	property String^ eFirstName 
	{
		String^ get()
		{
			return this->firstName;
		}

		void set(String^ fName)
		{
			this->firstName = fName;
		}
	}

	property String^ eSurName
	{
		String^ get()
		{
			return this->surName;
		}

		void set(String^ sName)
		{
			this->surName = sName;
		}
	}

	property String^ eTelephoneNumber
	{
		String^ get()
		{
			return this->telephoneNumber;
		}

		void set(String^ tNumber)
		{
			this->telephoneNumber = tNumber;
		}
	}
};
