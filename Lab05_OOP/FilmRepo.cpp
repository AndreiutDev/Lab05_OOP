#include "FilmRepo.h"

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

bool FilmRepo::updateLikes(Film f) {

	std::vector<Film>::iterator ptr = search(f);
	ptr->SetLikeAmountint(ptr->GetLikeAmount() + 1);

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