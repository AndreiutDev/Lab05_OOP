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
	this->AddTestFilms();
	if (this->person == "User") {

		UserUI UserMenu = UserUI(controller);
		UserMenu.Menu();
	}
	else{

		AdminUI AdminMenu = AdminUI(controller);
		AdminMenu.Menu();
	}
}




void FilmUI::AddTestFilms() {

	//Film f = Film(title, genre, year, likes, trailer_fain);

	Film f1 = Film("The Matrix", "action", 1999, 1000, L"https://www.youtube.com/watch?v=vKQi3bBA1y8");
	Film f2 = Film("Psycho", "horror", 1960, 909, L"https://www.youtube.com/watch?v=Wz719b9QUqY");
	Film f3 = Film("Titanic", "drama", 1997, 999, L"https://www.youtube.com/watch?v=kVrqfYjkTdQ");
	Film f4 = Film("Hereditary", "horror", 2018, 90, L"https://www.youtube.com/watch?v=YHxcDbai7aU");
	Film f5 = Film("Avengers", "action", 2012, 1234, L"https://www.youtube.com/watch?v=eOrNdBpGMv8");
	Film f6 = Film("Avengers Infinity War", "action", 2017, 999, L"https://www.youtube.com/watch?v=6ZfuNTqbHE8");

	controller.GetfilmAdd(f1);
	controller.GetfilmAdd(f2);
	controller.GetfilmAdd(f3);
	controller.GetfilmAdd(f4);
	controller.GetfilmAdd(f5);
	controller.GetfilmAdd(f6);

}