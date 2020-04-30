#pragma once
#include <vector>
#include  "Film.h"

class WishlistRepo
{
private:
	std::vector<Film> wishList;
public:

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Wish list add. </summary>
	/// 
	/// <param name="f">	A Film to process. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>

	bool wishListAdd(Film f);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Wish list delete. </summary>
	/// 
	/// <param name="f">	A Film to process. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>

	bool wishListDelete(Film f);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Wish list search. </summary>
	/// TODO-aici!
	/// <param name="f">	A Film to process. </param>


	std::vector<Film>::iterator wishListSearch(Film f);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Shows the wish list. </summary>
	/// 
	/// <returns>	A vector with the films from the wishList </returns>

	std::vector<Film> ShowWishList();
};

