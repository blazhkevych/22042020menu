#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include <algorithm>
using namespace std;
#define MENUTOP 4
#define MENULEFT 20
#define BACKGROUND 1
#define FOREGROUND 15
#define SELECTITEM 4

void gotorc(short r, short c) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, { c,r });
}
void Color(unsigned short Back, unsigned short Forg) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	unsigned short c = ((Back & 0x0F) << 4) + (Forg & 0x0F);
	SetConsoleTextAttribute(handle, c);
}
void paintmenu(const char** s, int sizem, int  pm) {
	system("cls");
	gotorc(MENUTOP, MENULEFT);
	Color(BACKGROUND, FOREGROUND);
	cout << "------Menu-------\n";
	for (size_t i = 0; i < sizem; i++)
	{
		gotorc(MENUTOP + i + 1, MENULEFT);
		cout << (i == pm ? Color(BACKGROUND, SELECTITEM), "=>" : "  ");
		cout << s[i] << endl;
		Color(BACKGROUND, FOREGROUND);
	}

}
int menu(const char** s, int sizem, int  pm = 0) {
	char c = 80;
	while (true)
	{
		if (c == 72 || c == 80) paintmenu(s, sizem, pm);
		c = _getch();
		switch (c)
		{
		case 27: //esc
			return -1;
		case 80: //down
			pm++;
			if (pm == sizem) pm = 0;
			break;
		case 72: //up
			if (pm == 0) pm = sizem;
			pm--;
			break;
		case 13: //enter
			return pm;
		}

	}

}
void Task1() {
	int a;
	cin >> a;
	cout << a << "Task1\n";
}
void Task2() {
	cout << "Task2\n";
}
void Task3() {
	cout << "Task3\n";
}
void Task4() {
	cout << "Task4\n";
}

int main() {
	Color(BACKGROUND, FOREGROUND);
	system("cls");
	const char* s[]{
		"Task 1",
		"Task 2",
		"Task 3",
		"Task 4",
	};
	int sizem = sizeof(s) / 4;
	int pm = 0;
	while (true)
	{
		pm = menu(s, sizem, pm);
		system("cls");
		switch (pm)
		{
		case -1: return 0;
		case 0:
			Task1();
			break;
		case 1:
			Task2();
			break;
		case 2:
			Task3();
			break;
		case 3:
			Task4();
			break;
		}
		Color(BACKGROUND, 2);
		cout << "done\n";
		_getch();
	}
}