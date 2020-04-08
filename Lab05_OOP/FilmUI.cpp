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

void FilmUI::Menu() {
	if (this->person == "User") {
		this->UserMenu();
	}
	else if(this->person == "Admin"){
		this->AdminMenu();
	}
}