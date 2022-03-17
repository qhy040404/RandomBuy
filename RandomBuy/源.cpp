#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	char TempPath[MAX_PATH] = { 0 };
	char AppPath[MAX_PATH] = { 0 };
	GetTempPathA(MAX_PATH, TempPath);
	GetCurrentDirectoryA(MAX_PATH, AppPath);
	string BatPath = TempPath;
	string TxtPath = AppPath;
	BatPath += "temp.bat";
	TxtPath += "\\save.txt";
	double input;
	double random;
	double sum = 0;
	cout << "今天搞了多少啊：";
	cin >> input;
	srand((unsigned)time(NULL));
	random = double(rand() % 100) / 100;
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << "存这么多吧：" << input * random;
	fstream save;
	save.open(TxtPath.c_str());
	save >> sum;
	save.close();
	cout << endl << "已经存了这么多了呢：" << sum + (input * random);
	ofstream bat;
	bat.open(BatPath.c_str());
	bat << "@echo off" << endl;
	bat << "del " << TxtPath.c_str() << endl;
	bat.close();
	system("%temp%\\temp.bat");
	system("timeout 1 >nul && del %temp%\\temp.bat");
	ofstream filesave;
	filesave.open(TxtPath.c_str());
	filesave << setprecision(2) << sum + (input * random);
	filesave.close();
	cout << endl << endl;
	system("@echo off && echo 按一下退出吧0.0 && pause >nul");
	return 0;
}