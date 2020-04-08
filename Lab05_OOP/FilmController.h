#pragma once
#include "FilmRepo.h"
#include "userRepo.h"

class FilmController
{
	private:
		FilmRepo repo;
		userRepo userRepo;
	public:
		//FILM REPO

		bool GetfilmAdd(Film f);

		bool GetfilmDelete(Film f);

		bool GetupdateLikes(Film f);

		std::vector<Film> GetShowMovies(std::string genre);

		std::vector<Film>::iterator GetSearch(Film f);

		//USER REPO
		bool GetwishListAdd(Film f);

		bool GetwishListDelete(Film f);

		std::vector<Film>::iterator GetwishListSearch(Film f);
};