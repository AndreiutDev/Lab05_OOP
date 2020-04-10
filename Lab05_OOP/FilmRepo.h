#pragma once
#include <vector>
#include <algorithm>
#include "Film.h"
#include <string>

class FilmRepo
{
private:
	std::vector<Film> filmList;
public:
	FilmRepo();

	bool filmAdd(Film f);

	bool filmDelete(Film f);

	void updateLikes(Film f, bool likeOrDislike);

	bool updateFilm(Film f, Film newf);

	std::vector<Film> ShowMovies(std::string genre);

	std::vector<Film>::iterator search(Film f);

	~FilmRepo();
};

