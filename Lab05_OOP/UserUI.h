#pragma once
#include "FilmController.h"
#include <iostream>
class UserUI
{
private:
	FilmController controller;
public:
	UserUI(FilmController cont)
	{
		this->controller = cont;
	}

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Print menu. </summary>
	///
	/// <remarks>	PC, 4/25/2020. </remarks>

	void PrintMenu();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Shows the running menu until the user/admin exits  </summary>
	///
	/// <remarks>	PC, 4/25/2020. </remarks>

	void Menu();
};

