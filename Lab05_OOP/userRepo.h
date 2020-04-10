#pragma once
#include <vector>
#include  "Film.h"

class userRepo
{
private:
	std::vector<Film> wishList;
public:
	bool wishListAdd(Film f);

	bool wishListDelete(Film f);

	std::vector<Film>::iterator wishListSearch(Film f);

	std::vector<Film> ShowWishList();
};

