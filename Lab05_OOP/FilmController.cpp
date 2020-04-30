#include "FilmController.h"
#include "Film.h"
#include "userRepo.h"
#include "FilmRepo.h"
#include <windows.h>
#include <atlstr.h>

void FilmController::Add()
{
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

	Film f = Film(title, genre, year, likes, trailer);

	if (repo.filmAdd(f) == true) {

		std::cout << "The film " + title + " was added.\n";
	}
	else
	{
		std::cout << "The film was not found.\n";
	}
}

void FilmController::Delete()
{
	std::string title;
	int apparitionYear;

	std::cout << "The title of the film to be deleted: \n";
	std::getline(std::cin >> std::ws, title);
	std::cout << "The year of apparition: \n";
	std::cin >> apparitionYear;
	Film f = Film(title, "", apparitionYear, -1, L"");
	if (repo.filmDelete(f) == true)
	{
		std::cout << "The film " + title + " has been deleted.\n";
	}
	else
	{
		std::cout << "The film has not been found.\n";
	}

}

void FilmController::GetupdateLikes(Film f, bool likeOrDislike)
{
	return repo.updateLikes(f, likeOrDislike);
}

void FilmController::Update()
{
	std::string title1;
	int apparitionYear;

	std::cout << "The title of the film to be updated: \n";
	std::getline(std::cin >> std::ws, title1);
	std::cout << "The year of apparition: \n";
	std::cin >> apparitionYear;
	Film f_to_search = Film(title1, "", apparitionYear, -1, L"");

	///details about the new film
	std::string title;
	std::cout << "Give new title: ";
	std::getline(std::cin >> std::ws, title);

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
	std::cout << "Give trailer url: ";
	std::wcin >> trailer;

	Film f_to_change = Film(title, genre, year, likes, trailer);

	if (userRepo.wishListDelete(f_to_search) == true) {
		userRepo.wishListAdd(f_to_change);

	}

	if (repo.updateFilm(f_to_search, f_to_change) == true) {

		std::cout << "The film " + title + " was updated.\n";
	}
	else
	{
		std::cout << "The film was not found.\n";
	}
}

void FilmController::ShowMovies()
{
	std::vector<Film> movies = repo.ShowMovies("All");
	std::vector<Film>::iterator ptr;
	for (ptr = movies.begin(); ptr < movies.end(); ptr++) {
		std::cout << ptr->GetTitle() + "     Apparition year: " + std::to_string(ptr->GetApparitionYear()) + "\n";
		std::cout << "Genre : " + ptr->GetGenre() + " Like Amount: " + std::to_string(ptr->GetLikeAmount()) + "\n";
	}

}

void FilmController::GetMoviesWithGenre() {
	int likeKey;
	std::string yesOrNo;
	printf("Which genre are you searching for.\n");
	std::string genre;
	std::cin >> genre;
	std::vector<Film> genreList = repo.ShowMovies(genre);
	std::vector<Film>::iterator ptr;
	for (ptr = genreList.begin(); ptr < genreList.end(); ptr++)
	{
		std::cout << "The title of the movie is: " + ptr->GetTitle() + " . It appered in the year: " + std::to_string(ptr->GetApparitionYear()) + "\nGenre: " + ptr->GetGenre() + "\nLike amount: " + std::to_string(ptr->GetLikeAmount()) + "\n";
		LPCWSTR acces = L"open";
		std::wstring link = ptr->GetTrailer();

		LPCWSTR link_bun = link.c_str();

		ShellExecute(NULL, acces, link_bun, NULL, NULL, SW_SHOWNORMAL);
		std::cout << "Press 1 to like.\nPress 2 to dislike.\nPress 3 to go back\n";
		std::cin >> likeKey;
		if (likeKey == 1)
		{
			repo.updateLikes(*ptr, true);
			std::cout << "Would you like to add your film to your wish list?\n";
			std::cin >> yesOrNo;
			if (yesOrNo == "yes")
			{
				userRepo.wishListAdd(*ptr);
			}
			else
				std::cout << "The film has not been added to the wish list.\n";
		}
		else if (likeKey == 2)
		{
			repo.updateLikes(*ptr, false);
		}
		else if (likeKey == 3)
		{
			break;
		}
	}
}

std::vector<Film>::iterator FilmController::GetSearch(Film f)
{
	return repo.search(f);
}

//USER REPO
bool FilmController::GetwishListAdd(Film f)
{
	return userRepo.wishListAdd(f);
}

void FilmController::ShowWishList()
{
	std::vector<Film> cpy = userRepo.ShowWishList();
	std::vector<Film>::iterator ptr;
	for (ptr = cpy.begin(); ptr < cpy.end(); ptr++)
	{
		std::cout << ptr->GetTitle() + "     Apparition year: " + std::to_string(ptr->GetApparitionYear()) + "\n";
		std::cout << "Genre : " + ptr->GetGenre() + " Like Amount: " + std::to_string(ptr->GetLikeAmount()) + "\n";
	}
}

void FilmController::DeleteFromWishlist()
{
	std::string title;
	int apparitionYear;

	std::cout << "The title of the film to be deleted: \n";
	std::getline(std::cin >> std::ws, title);
	std::cout << "The year of apparition: \n";
	std::cin >> apparitionYear;
	Film f = Film(title, "", apparitionYear, -1, L"");
	if (userRepo.wishListDelete(f) == true)
	{
		std::cout << "The film " + title + " has been deleted.\n";
	}
	else
	{
		std::cout << "The film has not been found.\n";
	}
}

std::vector<Film>::iterator FilmController::GetwishListSearch(Film f)
{
	return userRepo.wishListSearch(f);
}


void FilmController::AddTestFilms() {

	//Film f = Film(title, genre, year, likes, trailer_fain);

	Film f1 = Film("The Matrix", "action", 1999, 1000, L"https://www.youtube.com/watch?v=vKQi3bBA1y8");
	Film f2 = Film("Psycho", "horror", 1960, 909, L"https://www.youtube.com/watch?v=Wz719b9QUqY");
	Film f3 = Film("Titanic", "drama", 1997, 999, L"https://www.youtube.com/watch?v=kVrqfYjkTdQ");
	Film f4 = Film("Hereditary", "horror", 2018, 90, L"https://www.youtube.com/watch?v=YHxcDbai7aU");
	Film f5 = Film("Avengers", "action", 2012, 1234, L"https://www.youtube.com/watch?v=eOrNdBpGMv8");
	Film f6 = Film("Avengers Infinity War", "action", 2017, 999, L"https://www.youtube.com/watch?v=6ZfuNTqbHE8");

	repo.filmAdd(f1);
	repo.filmAdd(f2);
	repo.filmAdd(f3);
	repo.filmAdd(f4);
	repo.filmAdd(f5);
	repo.filmAdd(f6);

}
