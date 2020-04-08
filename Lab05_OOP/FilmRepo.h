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

	bool updateLikes(Film f);

	std::vector<Film> ShowMovies(std::string genre);

	std::vector<Film>::iterator search(Film f);

	~FilmRepo();
};

