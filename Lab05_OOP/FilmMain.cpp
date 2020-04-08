#include <stdio.h>
#include "Film.h"
#include <windows.h>
#include <atlstr.h>

void OpenWebsite(char* cpURL)
{
	
}

int main(void)
{
	LPCWSTR a = L"open";
	LPCWSTR b = L"https://www.youtube.com/watch?v=wVznsnM-Z-g&list=RDwVznsnM-Z-g&start_radio=1";
	ShellExecute(NULL, a, b, NULL, NULL, SW_SHOWNORMAL);
	return 0;
}