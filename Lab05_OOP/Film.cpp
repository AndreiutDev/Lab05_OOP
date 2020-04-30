#include "Film.h"
#include <windows.h>
#include <atlstr.h>
Film::Film(std::string title, std::string genre, int apparitionYear, int likeAmount, std::wstring trailer)
{
	this->title = title;
	this->genre = genre;
	this->apparitionYear = apparitionYear;
	this->likeAmount = likeAmount;
	this->trailer = trailer;
}

std::string Film::GetTitle()
{
	return title;
}

std::string Film::GetGenre()
{
	return genre;
}

int Film::GetApparitionYear()
{
	return apparitionYear;
}

int Film::GetLikeAmount()
{
	return likeAmount;
}

std::wstring Film::GetTrailer()
{
	return trailer;
}

void Film::SetTrailer(std::wstring other)
{
	trailer = other;
}

void Film::SetTitle(std::string other)
{
	this->title = other;
}

void Film::SetGenre(std::string other)
{
	this->genre = other;
}

void Film::SetApparitionYearint(int other)
{
	this->apparitionYear = other;
}

void Film::SetLikeAmountint(int other)
{
	this->likeAmount = other;
}
