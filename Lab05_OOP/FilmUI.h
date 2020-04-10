#pragma once
#include <iostream>
#include "FilmController.h"
class FilmUI
{
	private:
		FilmController controller;

		std::string person;
	public:
		void Menu();

		void printUserMenu();

		void printAdminMenu();

		void UserMenu();

		void AdminMenu();

		FilmUI();

		void Login();


};

