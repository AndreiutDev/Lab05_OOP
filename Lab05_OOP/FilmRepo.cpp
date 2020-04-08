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