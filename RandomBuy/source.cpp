#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;
int main()
{
	char AppPath[MAX_PATH] = { 0 };
	GetCurrentDirectoryA(MAX_PATH, AppPath);
	string TxtPath = AppPath;
	TxtPath += "\\save.txt";
	double input;
	double random;
	double sum = 0;
	double withdraw = 0;
	cout << "������˶��ٰ���";
	cin >> input;
	while (1)
	{
		cout << endl << "ȫ�棨1��������ô�ģ�2����";
		char ch;
		ch = _getch();
		if (ch == 49)
		{
			withdraw = input;
			break;
		}
		else if (ch == 50)
		{
			srand((unsigned)time(NULL));
			random = double(rand() % 100) / 100;
			withdraw = input * random;
			__int64 temp = (__int64)(withdraw * 100);
			withdraw = temp / 100.0;
			cout << setiosflags(ios::fixed) << setprecision(2);
			cout << endl << "����ô��ɣ�" << withdraw;
			break;
		}
		else
		{
			cout << endl << "զϹjb������" << endl;
		}
	}
	fstream save;
	save.open(TxtPath.c_str());
	save >> sum;
	save.close();
	cout << endl << "�Ѿ�������ô�����أ�" << sum + withdraw;
	ofstream filesave;
	filesave.open(TxtPath.c_str());
	filesave << setiosflags(ios::fixed) << setprecision(2) << sum + withdraw;
	filesave.close();
	cout << endl << endl;
	system("@echo off && echo ��һ���˳���0.0 && pause >nul");
	return 0;
}