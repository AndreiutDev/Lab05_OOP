#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab05_OOP/Film.h"
#include "../Lab05_OOP/Film.cpp"
#include "../Lab05_OOP/FilmRepo.h"
#include "../Lab05_OOP/FilmRepo.cpp"
#include "../Lab05_OOP/userRepo.h"
#include "../Lab05_OOP/userRepo.cpp"
#include "../Lab05_OOP/FilmController.h"
#include "../Lab05_OOP/FilmController.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab05Test
{
	TEST_CLASS(Lab05Test)
	{
	public:
		TEST_METHOD(TestAddRepo)
		{
			FilmController controller;
			Film f1 = Film("The Matrix", "action", 1999, 1000, L"https://www.youtube.com/watch?v=vKQi3bBA1y8");
			Film f2 = Film("Psycho", "horror", 1960, 909, L"https://www.youtube.com/watch?v=Wz719b9QUqY");
			Film f3 = Film("Titanic", "drama", 1997, 999, L"https://www.youtube.com/watch?v=kVrqfYjkTdQ");
			Film f4 = Film("Hereditary", "horror", 2018, 90, L"https://www.youtube.com/watch?v=YHxcDbai7aU");
			Film f5 = Film("Avengers", "action", 2012, 1234, L"https://www.youtube.com/watch?v=eOrNdBpGMv8");
			Film f6 = Film("Avengers Infinity War", "action", 2017, 999, L"https://www.youtube.com/watch?v=6ZfuNTqbHE8");

			
			Assert::AreEqual(controller.GetfilmAdd(f1), true);
			Assert::AreEqual(controller.GetfilmAdd(f1), false);
			Assert::AreEqual(controller.GetfilmAdd(f2), true);
			Assert::AreEqual(controller.GetfilmAdd(f2), false);
			Assert::AreEqual(controller.GetfilmAdd(f3), true);
			Assert::AreEqual(controller.GetfilmAdd(f3), false);
			Assert::AreEqual(controller.GetfilmAdd(f4), true);
			Assert::AreEqual(controller.GetfilmAdd(f5), true);
			Assert::AreEqual(controller.GetfilmAdd(f5), false);
			Assert::AreEqual(controller.GetfilmAdd(f6), true);
			Assert::AreEqual(controller.GetfilmAdd(f6), false);
		}
		TEST_METHOD(TestDeleteRepo)
		{
			FilmController controller;
			Film f1 = Film("The Matrix", "action", 1999, 1000, L"https://www.youtube.com/watch?v=vKQi3bBA1y8");
			Film f2 = Film("Psycho", "horror", 1960, 909, L"https://www.youtube.com/watch?v=Wz719b9QUqY");
			Film f3 = Film("Titanic", "drama", 1997, 999, L"https://www.youtube.com/watch?v=kVrqfYjkTdQ");
			Film f4 = Film("Hereditary", "horror", 2018, 90, L"https://www.youtube.com/watch?v=YHxcDbai7aU");
			Film f5 = Film("Avengers", "action", 2012, 1234, L"https://www.youtube.com/watch?v=eOrNdBpGMv8");
			Film f6 = Film("Avengers Infinity War", "action", 2017, 999, L"https://www.youtube.com/watch?v=6ZfuNTqbHE8");

			controller.GetfilmAdd(f1);
			controller.GetfilmAdd(f2);
			controller.GetfilmAdd(f3);
			controller.GetfilmAdd(f4);
			controller.GetfilmAdd(f5);
			controller.GetfilmAdd(f6);
			Assert::AreEqual(controller.GetfilmDelete(f1), true);
			Assert::AreEqual(controller.GetfilmDelete(f3), true);
			Assert::AreEqual(controller.GetfilmDelete(f5), true);
			Assert::AreEqual(controller.GetfilmDelete(f6), true);
			Assert::AreEqual(controller.GetfilmDelete(f6), false);
		}
		TEST_METHOD(TestUpdateRepo)
		{
			FilmController controller;
			Film f1 = Film("The Matrix", "action", 1999, 1000, L"https://www.youtube.com/watch?v=vKQi3bBA1y8");
			Film f2 = Film("Psycho", "horror", 1960, 909, L"https://www.youtube.com/watch?v=Wz719b9QUqY");
			Film f3 = Film("Titanic", "drama", 1997, 999, L"https://www.youtube.com/watch?v=kVrqfYjkTdQ");
			Film f4 = Film("Hereditary", "horror", 2018, 90, L"https://www.youtube.com/watch?v=YHxcDbai7aU");
			Film f5 = Film("Avengers", "action", 2012, 1234, L"https://www.youtube.com/watch?v=eOrNdBpGMv8");
			Film f6 = Film("Avengers Infinity War", "action", 2017, 999, L"https://www.youtube.com/watch?v=6ZfuNTqbHE8");

			controller.GetfilmAdd(f1);
			controller.GetupdateFilm(f1, f2);
			Assert::AreEqual(controller.GetfilmAdd(f1), true);
			Assert::AreEqual(controller.GetfilmAdd(f2), false);
		}

		TEST_METHOD(TestWishListAdd)
		{
			FilmController controller;
			Film f1 = Film("The Matrix", "action", 1999, 1000, L"https://www.youtube.com/watch?v=vKQi3bBA1y8");
			Film f2 = Film("Psycho", "horror", 1960, 909, L"https://www.youtube.com/watch?v=Wz719b9QUqY");
			Film f3 = Film("Titanic", "drama", 1997, 999, L"https://www.youtube.com/watch?v=kVrqfYjkTdQ");
			Film f4 = Film("Hereditary", "horror", 2018, 90, L"https://www.youtube.com/watch?v=YHxcDbai7aU");
			Film f5 = Film("Avengers", "action", 2012, 1234, L"https://www.youtube.com/watch?v=eOrNdBpGMv8");
			Film f6 = Film("Avengers Infinity War", "action", 2017, 999, L"https://www.youtube.com/watch?v=6ZfuNTqbHE8");

			controller.GetfilmAdd(f1);
			controller.GetfilmAdd(f2);
			controller.GetfilmAdd(f3);
			controller.GetfilmAdd(f4);
			Assert::AreEqual(controller.GetwishListAdd(f1), true);
			Assert::AreEqual(controller.GetwishListAdd(f1), false);
			Assert::AreEqual(controller.GetwishListAdd(f5), true);
			Assert::AreEqual(controller.GetwishListAdd(f6), true);
			Assert::AreEqual(controller.GetwishListAdd(f6), false);
		}

		TEST_METHOD(TestWishListDele)
		{
			FilmController controller;
			Film f1 = Film("The Matrix", "action", 1999, 1000, L"https://www.youtube.com/watch?v=vKQi3bBA1y8");
			Film f2 = Film("Psycho", "horror", 1960, 909, L"https://www.youtube.com/watch?v=Wz719b9QUqY");
			Film f3 = Film("Titanic", "drama", 1997, 999, L"https://www.youtube.com/watch?v=kVrqfYjkTdQ");
			Film f4 = Film("Hereditary", "horror", 2018, 90, L"https://www.youtube.com/watch?v=YHxcDbai7aU");
			Film f5 = Film("Avengers", "action", 2012, 1234, L"https://www.youtube.com/watch?v=eOrNdBpGMv8");
			Film f6 = Film("Avengers Infinity War", "action", 2017, 999, L"https://www.youtube.com/watch?v=6ZfuNTqbHE8");

			controller.GetfilmAdd(f1);
			controller.GetfilmAdd(f2);
			controller.GetfilmAdd(f3);
			controller.GetfilmAdd(f4);
			Assert::AreEqual(controller.GetwishListDelete(f1), false);

		}
	};
}
