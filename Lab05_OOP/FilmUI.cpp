#include "FilmUI.h"

FilmUI::FilmUI() {
	this->person = "";
}

void FilmUI::Login() {
	bool running = true;
	int key;
	std::string pass;

	while (running) {
		std::cout << "What are you?\n1.Administrator\n2.User\n0.Exit";
		std::cin >> key;
		switch (key) {
		case 1:
			std::cout << "Password: ";
			std::cin >> pass;
			if (pass == "1234") {
				this->person == "Admin";
				running = false;
			}
			break;
		case 2:
			this->person = "User";
			running = false;
			break;
		case 0:
			running = false;
			break;

		default:
			std::cout << "Invalid option. Choose again!";
		}
	}
	this->Menu();
}

void printUserMenu()
{
	std::cout << "\n=========================================================================\n";
	std::cout << "= 1. Search after genre.                                                =\n";
	std::cout << "= 2. Delete Film.                                                       =\n";
	std::cout << "= 3. Update Film.                                                       =\n";
	std::cout << "= 4. Show All Films                                                     =\n";
	std::cout << "= 5. Exit                                                               =\n";
	std::cout << "=========================================================================\n";
	std::cout << "/////////////////\n";
	std::cout << "/////////////////\n";
	std::cout << "//  USER MENU //\n";
	std::cout << "/////////////////\n";
	std::cout << "/////////////////\n\n";
}

void printAdminMenu()
{
	std::cout << "\n=========================================================================\n";
	std::cout << "= 1. Add Film.                                                          =\n";
	std::cout << "= 2. Delete Film.                                                       =\n";
	std::cout << "= 3. Update Film.                                                       =\n";
	std::cout << "= 4. Show All Films                                                     =\n";
	std::cout << "= 5. Exit                                                               =\n";
	std::cout << "=========================================================================\n";
	std::cout << "/////////////////\n";
	std::cout << "/////////////////\n";
	std::cout << "//  ADMIN MENU //\n";
	std::cout << "/////////////////\n";
	std::cout << "/////////////////\n\n";
}

void FilmUI::Menu() {
	if (this->person == "User") {
		this->UserMenu();
	}
	else if(this->person == "Admin"){
		this->AdminMenu();
	}
}

void FilmUI::UserMenu()
{
	bool running = true;
	while (running)
	{

	}
}