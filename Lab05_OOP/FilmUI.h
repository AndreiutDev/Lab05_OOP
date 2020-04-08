#pragma once
#include <iostream>
class FilmUI
{
	private:
		std::string person;

		void Menu();

		void UserMenu();

		void AdminMenu();
	public:
		FilmUI();

		void Login();


};

