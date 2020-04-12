#include "Film.h"
#include "FilmRepo.h"
#include <windows.h>
#include <atlstr.h>

FilmRepo::FilmRepo()
{

}

bool FilmRepo::filmAdd(Film f)
{
	std::vector<Film>::iterator ptr = search(f);
	if (ptr != filmList.end())
		return false;
	filmList.push_back(f);
	return true;
}

std::vector<Film>::iterator FilmRepo::search(Film f)
{
	std::vector<Film>::iterator ptr;
	for (ptr = filmList.begin(); ptr < filmList.end(); ptr++)
	{
		if (f.GetTitle() == ptr->GetTitle() && f.GetApparitionYear() == ptr->GetApparitionYear())
		{
			return ptr;
		}
	}
	return ptr;
}

bool FilmRepo::filmDelete(Film f)
{
	std::vector<Film>::iterator ptr = search(f);
	if (ptr == filmList.end())
		return false;
	filmList.erase(ptr);
	return true;
}

void FilmRepo::updateLikes(Film f, bool likeOrDislike) {

	std::vector<Film>::iterator ptr = search(f);
	ptr->SetLikeAmountint(300);
}

bool FilmRepo::updateFilm(Film f, Film newf)
{
	std::vector<Film>::iterator ptr = search(f);
	if (ptr == filmList.end())
		return false;
	else {
		filmList.erase(ptr);
		filmList.push_back(newf);
		return true;
	}
}

std::vector<Film> FilmRepo::ShowMovies(std::string genre) {

	std::vector<Film>::iterator ptr;
	std::vector<Film> genre_list;
	bool ok = false;

	for (ptr = filmList.begin(); ptr < filmList.end(); ptr++) {
		if (ptr->GetGenre() == genre) {
			genre_list.push_back(*ptr);
			ok = true;
		}
	}
	if (ok == false) {
		genre_list = this->filmList;
	}

	return genre_list;
}

FilmRepo::~FilmRepo()
{
	this->filmList.clear();
}