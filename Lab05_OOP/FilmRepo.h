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

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Adds film to filmList </summary>
	/// 
	/// <param name="f">	A Film to process. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>

	bool filmAdd(Film f);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Deletes film from filmList </summary>
	/// 
	/// <param name="f">	A Film to process. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>

	bool filmDelete(Film f);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Updates the likes. </summary>
	/// 
	/// <param name="f">				A Film to process. </param>
	/// <param name="likeOrDislike">	True to like or dislike. </param>

	void updateLikes(Film f, bool likeOrDislike);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Updates the film. </summary>
	/// 
	/// <param name="f">   	A Film to process. </param>
	/// <param name="newf">	The new Film. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>

	bool updateFilm(Film f, Film newf);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Shows the movies. </summary>
	/// 
	/// <param name="genre">	The genre. </param>
	///
	/// <returns>	A vector with these films </returns>

	std::vector<Film> ShowMovies(std::string genre);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Searches for the first match for the given film. </summary>
	/// 
	/// <param name="f">	A Film to process. </param>
	///
	/// <returns>	A vector with these films </returns>

	std::vector<Film>::iterator search(Film f);

	~FilmRepo();
};

