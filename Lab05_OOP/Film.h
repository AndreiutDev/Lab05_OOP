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
	std::wstring trailer;

public:
	Film(std::string title, std::string genre, int apparitionYear, int likeAmount, std::wstring trailer);
	std::string GetTitle();
	std::string GetGenre();
	int GetApparitionYear();
	int GetLikeAmount();
	std::wstring GetTrailer();

	void SetTrailer(std::wstring other);
	void SetTitle(std::string other);
	void SetGenre(std::string other);
	void SetApparitionYearint(int other);
	void SetLikeAmountint(int other);
};

