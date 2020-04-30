#include "AdminUI.h"

void AdminUI::PrintMenu()
{
	std::cout << "\n=========================================================================\n";
	std::cout << "= 1. Add Film.                                                          =\n";
	std::cout << "= 2. Delete Film.                                                       =\n";
	std::cout << "= 3. Update Film.                                                       =\n";
	std::cout << "= 4. Show All Films                                                     =\n";
	std::cout << "= 5. Exit                                                               =\n";
	std::cout << "=========================================================================\n";
	std::cout << "/////////////////\n";
	std::cout << "/////////////////\n";
	std::cout << "//  ADMIN MENU //\n";
	std::cout << "/////////////////\n";
	std::cout << "/////////////////\n\n";
}

void AdminUI::Menu()
{
	int key;
	bool running = true;
	while (running) {
		PrintMenu();
		std::cin >> key;
		if (key == 1) {

			this->controller.Add();

		}
		if (key == 2) {
			
			this->controller.Delete();

		}

		if (key == 3) {
			
			this->controller.Update();

		}

		if (key == 4) {
			this->controller.ShowMovies();
		}

		if (key == 5) {
			running = false;
		}
	}
}
