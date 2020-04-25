#include "AdminUI.h"

void AdminUI::PrintMenu()
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

void AdminUI::Menu()
{
	int key;
	bool running = true;
	while (running) {
		PrintMenu();
		std::cin >> key;
		if (key == 1) {
			std::string title;
			std::cout << "Give title: ";
			std::getline(std::cin >> std::ws, title);

			int year;
			std::cout << "Give apparition year: ";
			std::cin >> year;

			std::string genre;
			std::cout << "Give genre: ";
			std::cin >> genre;

			int likes;
			std::cout << "Give number of likes: ";
			std::cin >> likes;

			std::wstring trailer;
			std::cout << "Give trailer url: ";
			std::wcin >> trailer;
			LPCWSTR trailer_fain = trailer.c_str();

			Film f = Film(title, genre, year, likes, trailer_fain);

			if (controller.GetfilmAdd(f) == true) {

				std::cout << "The film " + title + " has been added.\n";
			}
			else
			{
				std::cout << "The film has not been found.\n";
			}

		}
		if (key == 2) {
			std::string title;
			int apparitionYear;

			std::cout << "The title of the film to be deleted: \n";
			std::getline(std::cin >> std::ws, title);
			std::cout << "The year of apparition: \n";
			std::cin >> apparitionYear;
			Film f = Film(title, "", apparitionYear, -1, L"");
			if (controller.GetfilmDelete(f) == true)
			{
				std::cout << "The film " + title + " has been deleted.\n";
			}
			else
			{
				std::cout << "The film has not been found.\n";
			}
		}

		if (key == 3) {
			std::string title1;
			int apparitionYear;

			std::cout << "The title of the film to be updated: \n";
			std::cin >> title1;
			std::cout << "The year of apparition: \n";
			std::cin >> apparitionYear;
			Film f_to_search = Film(title1, "", apparitionYear, -1, L"");

			///details about the new film
			std::string title;
			std::cout << "Give new title: ";
			std::cin >> title;

			int year;
			std::cout << "Give new apparition year: ";
			std::cin >> year;

			std::string genre;
			std::cout << "Give new genre: ";
			std::cin >> genre;

			int likes;
			std::cout << "Give new number of likes: ";
			std::cin >> likes;

			std::wstring trailer;
			std::cout << "Give new trailer url: ";
			std::wcin >> trailer;
			LPCWSTR trailer_fain = trailer.c_str();

			Film f_to_change = Film(title, genre, year, likes, trailer_fain);

			if (controller.GetupdateFilm(f_to_search, f_to_change) == true) {

				std::cout << "The film " + title + " has been updated.\n";
			}
			else
			{
				std::cout << "The film has not been found.\n";
			}
		}

		if (key == 4) {
			std::vector<Film> movies = controller.GetShowMovies("All");
			std::vector<Film>::iterator ptr;
			for (ptr = movies.begin(); ptr < movies.end(); ptr++) {
				std::cout << ptr->GetTitle() + "     Apparition year: " + std::to_string(ptr->GetApparitionYear()) + "\n";
				std::cout << "Genre : " + ptr->GetGenre() + " Like Amount: " + std::to_string(ptr->GetLikeAmount()) + "\n";
			}
		}

		if (key == 5) {
			running = false;
		}
	}
}
