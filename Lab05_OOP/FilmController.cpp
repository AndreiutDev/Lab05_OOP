#include "FilmController.h"

bool FilmController::GetfilmAdd(Film f)
{
	return repo.filmAdd(f);
}

bool FilmController::GetfilmDelete(Film f)
{
	return repo.filmDelete(f);
}

bool FilmController::GetupdateLikes(Film f)
{
	return repo.updateLikes(f);
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

bool FilmController::GetwishListDelete(Film f)
{
	return userRepo.wishListDelete(f);
}

std::vector<Film>::iterator FilmController::GetwishListSearch(Film f)
{
	return userRepo.wishListSearch(f);
}
