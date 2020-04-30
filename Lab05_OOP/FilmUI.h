#pragma once
#include <iostream>
#include "FilmController.h"
#include "AdminUI.h"
#include "UserUI.h"
class FilmUI
{
	private:
		FilmController controller;
		FilmRepo repo;


		std::string person;
	public:
		void Menu();

		FilmUI();

		///-------------------------------------------------------------------------------------------------
		/// <summary>	Login for the user/admin </summary>
		///
		/// <remarks>	PC, 4/25/2020. </remarks>

		void Login();


};

