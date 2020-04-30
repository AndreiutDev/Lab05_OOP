#include "FilmUI.h"
#include "FilmController.h"
#include "Film.h"
#include "userRepo.h"
#include "FilmRepo.h"
#include <windows.h>
#include <atlstr.h>

FilmUI::FilmUI() {
	this->person = "";
}

void FilmUI::Login() {
	this->person = "";
	bool running = true;
	int key;
	int pass;

	while (running) {
		std::cout << "What are you?\n1.Administrator\n2.User\n0.Exit\n";
		std::cin >> key;
		switch (key) {
		case 1:
			std::cout << "Password: ";
			std::cin >> pass;
			if (pass == 1234) {
				this->person == "Admin";
				running = false;
			}
			this->Menu();
			break;
		case 2:
			this->person = "User";
			this->Menu();
			running = false;

			break;
		case 0:
			this->person = "";
			running = false;
			break;

		default:
			std::cout << "Invalid option. Choose again!";
		}
	}
	
}

void FilmUI::Menu() {
	controller.AddTestFilms();
	if (this->person == "User") {

		UserUI UserMenu = UserUI(controller);
		UserMenu.Menu();
		Login();
	}
	else{

		AdminUI AdminMenu = AdminUI(controller);
		AdminMenu.Menu();
		Login();
	}
}



