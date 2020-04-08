#include "userRepo.h"

std::vector<Film>::iterator userRepo::wishListSearch(Film f)
{
	std::vector<Film>::iterator ptr;
	for (ptr = wishList.begin(); ptr < wishList.end(); ptr++)
	{
		if (f.GetTitle() == ptr->GetTitle() && f.GetApparitionYear() == ptr->GetApparitionYear())
		{
			return ptr;
		}
	}
	return ptr;
}

bool userRepo::wishListAdd(Film f)
{
	std::vector<Film>::iterator ptr = wishListSearch(f);
	if (ptr != wishList.end())
		return false;
	wishList.push_back(f);
	return true;
}

bool userRepo::wishListDelete(Film f)
{
	std::vector<Film>::iterator ptr = wishListSearch(f);
	if (ptr == wishList.end())
		return false;
	wishList.erase(ptr);
	return true;
}