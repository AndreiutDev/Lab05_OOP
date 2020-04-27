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

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Gets the add film function from the repository </summary>
		/// 
		/// <param name="f">	A Film to process. </param>
		///
		/// <returns>	True if it succeeds, false if it fails. </returns>

		bool GetfilmAdd(Film f);

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Gets the delete film function from the repository </summary>
		/// 
		/// <param name="f">	A Film to process. </param>
		///
		/// <returns>	True if it succeeds, false if it fails. </returns>
		bool GetfilmDelete(Film f);

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Gets the update film function from the repository </summary>
		/// 
		/// <param name="f">	A Film to search and delete </param>
		/// <param name="fnew">	A Film to add. </param>
		void GetupdateLikes(Film f, bool likeOrDislike);

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Gets the update film function from the repository </summary>
		/// 
		/// <param name="f">	A Film to process. </param>
		///
		/// <returns>	True if it succeeds, false if it fails. </returns>
		bool GetupdateFilm(Film f, Film fnew);

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Gets show movies. </summary>
		/// 
		/// <param name="genre">	The genre. </param>
		///
		/// <returns>	The show movies. </returns>

		std::vector<Film> GetShowMovies(std::string genre);

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Gets a search. </summary>
		/// 
		/// <param name="f">	A Film to process. </param>
		///
		/// <returns>	The search. </returns>

		std::vector<Film>::iterator GetSearch(Film f);

		//USER REPO

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Getwish list add. </summary>
		/// 
		/// <param name="f">	A Film to process. </param>
		///
		/// <returns>	True if it succeeds, false if it fails. </returns>

		bool GetwishListAdd(Film f);

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Getwish list delete. </summary>
		/// 
		/// <param name="f">	A Film to process. </param>
		///
		/// <returns>	True if it succeeds, false if it fails. </returns>

		bool GetwishListDelete(Film f);

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Gets show wish list. </summary>
		/// 
		/// <returns>	The show wish list. </returns>

		std::vector<Film> GetShowWishList();

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Getwish list search. </summary>
		/// 
		/// <param name="f">	A Film to process. </param>
		///
		/// <returns>	A std::vector&lt;Film&gt;::iterator. </returns>

		std::vector<Film>::iterator GetwishListSearch(Film f);
};