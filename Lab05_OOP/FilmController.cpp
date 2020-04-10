#include "FilmController.h"
#include "Film.h"
#include "userRepo.h"
#include "FilmRepo.h"
#include <windows.h>
#include <atlstr.h>
bool FilmController::GetfilmAdd(Film f)
{
	return repo.filmAdd(f);
}

bool FilmController::GetfilmDelete(Film f)
{
	return repo.filmDelete(f);
}

void FilmController::GetupdateLikes(Film f, bool likeOrDislike)
{
	return repo.updateLikes(f, likeOrDislike);
}

bool FilmController::GetupdateFilm(Film f, Film fnew)
{
	return repo.updateFilm(f, fnew);
}

std::vector<Film> FilmController::GetShowMovies(std::string genre)
{
	return repo.ShowMovies(genre);
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

std::vector<Film> FilmController::GetShowWishList()
{
	return userRepo.ShowWishList();
}

bool FilmController::GetwishListDelete(Film f)
{
	return userRepo.wishListDelete(f);
}

std::vector<Film>::iterator FilmController::GetwishListSearch(Film f)
{
	return userRepo.wishListSearch(f);
}
