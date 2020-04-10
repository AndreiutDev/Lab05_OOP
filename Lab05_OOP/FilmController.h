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

		void GetupdateLikes(Film f, bool likeOrDislike);

		bool GetupdateFilm(Film f, Film fnew);

		std::vector<Film> GetShowMovies(std::string genre);

		std::vector<Film>::iterator GetSearch(Film f);

		//USER REPO
		bool GetwishListAdd(Film f);

		bool GetwishListDelete(Film f);

		std::vector<Film> GetShowWishList();

		std::vector<Film>::iterator GetwishListSearch(Film f);
};