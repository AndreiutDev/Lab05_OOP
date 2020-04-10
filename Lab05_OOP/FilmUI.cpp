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

void FilmUI::printUserMenu()
{
	std::cout << "\n=========================================================================\n";
	std::cout << "= 1. Search after genre.                                                =\n";
	std::cout << "= 2. Delete from wishlist.                                              =\n";
	std::cout << "= 3. Show wishlist.                                                     =\n";
	std::cout << "= 4. Exit                                                               =\n";
	std::cout << "=========================================================================\n";
	std::cout << "/////////////////\n";
	std::cout << "/////////////////\n";
	std::cout << "//  USER MENU //\n";
	std::cout << "/////////////////\n";
	std::cout << "/////////////////\n\n";
}

void FilmUI::printAdminMenu()
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
	this->AddTestFilms();
	if (this->person == "User") {
		this->UserMenu();
	}
	else{
		this->AdminMenu();
	}
}


void FilmUI::UserMenu()
{
	std::string yesOrNo;
	int key;
	int likeKey;
	int wishListKey;
	bool running = true;
	while (running)
	{
		printUserMenu();
		std::cin >> key;
		if (key == 1)
		{
			printf("Which genre are you searching for.\n");
			std::string genre;
			std::cin >> genre;
			std::vector<Film> genreList = controller.GetShowMovies(genre);
			std::vector<Film>::iterator ptr;
			for (ptr = genreList.begin(); ptr < genreList.end(); ptr++)
			{
				std::cout << "The title of the movie is: " + ptr->GetTitle() + " . It appered in the year: " + std::to_string(ptr->GetApparitionYear()) + "\nGenre: " + ptr->GetGenre() + "\nLike amount: " + std::to_string(ptr->GetLikeAmount()) + "\n";
				LPCWSTR acces = L"open";
				LPCWSTR link = ptr->GetTrailer();
				ShellExecute(NULL, acces, link, NULL, NULL, SW_SHOWNORMAL);
				std::cout << "Press 1 to like.\nPress 2 to dislike.\nPress 3 to go back\n";
				std::cin >> likeKey;
				if (likeKey == 1)
				{
					controller.GetupdateLikes(*ptr, true);
					std::cout << "Would you like to add your film to your wish list?\n";
					std::cin >> yesOrNo;
					if (yesOrNo == "yes")
					{
						controller.GetwishListAdd(*ptr);
					}
					else
						std::cout << "The film has not been added to the wish list.\n";
				}
				else if (likeKey == 2)
				{
					controller.GetupdateLikes(*ptr, false);
				}
				else if (likeKey == 3)
				{
					break;
				}
			}
		}
		else if (key == 2)
		{
			std::string title;
			int apparitionYear;

			std::cout << "The title of the film to be deleted: \n";
			std::cin >> title;
			std::cout << "The year of apparition: \n";
			std::cin >> apparitionYear;
			Film f = Film(title, "", apparitionYear, -1, L"");
			if (controller.GetwishListDelete(f) == true)
			{
				std::cout << "The film " + title + " has been deleted.\n";
			}
			else
			{
				std::cout << "The film has not been found.\n";
			}
		}
		else if (key == 3)
		{
			std::vector<Film> cpy =  controller.GetShowWishList();
			std::vector<Film>::iterator ptr;
			for (ptr = cpy.begin(); ptr < cpy.end(); ptr++)
			{
				std::cout << ptr->GetTitle() + "     Apparition year: " + std::to_string(ptr->GetApparitionYear()) + "\n";
				std::cout << "Genre : " + ptr->GetGenre() + " Like Amount: " + std::to_string(ptr->GetLikeAmount()) + "\n";
			}
		}
		else if (key == 4) {
			running = false;
		}
	}
}

void FilmUI::AdminMenu()
{
	int key;
	bool running = true;
	while (running) {
		printAdminMenu();
		std::cin >> key;
		if (key == 1) {
			std::string title;
			std::cout << "Give title: ";
			std::cin >> title;

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
			std::cin >> title;
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