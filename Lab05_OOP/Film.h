#pragma once
#include <windows.h>
#include <string>
class Film
{
private:
	std::string title;
	std::string genre;
	int apparitionYear;
	int likeAmount;
	LPCWSTR trailer;

public:
	Film(std::string title, std::string genre, int apparitionYear, int likeAmount, LPCWSTR trailer);
	std::string GetTitle();
	std::string GetGenre();
	int GetApparitionYear();
	int GetLikeAmount();
	LPCWSTR GetTrailer();

	void SetTrailer(LPCWSTR other);
	void SetTitle(std::string other);
	void SetGenre(std::string other);
	void SetApparitionYearint(int other);
	void SetLikeAmountint(int other);
};

