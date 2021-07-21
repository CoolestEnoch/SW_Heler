#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <Windows.h>
using namespace std;

char sw_process[][233]
{
	 "FNPLicensingService64.exe", "FNPLicensingService.exe", "SWVisualize.BoostService.exe", "SWVisualize.Queue.Server.exe", "sldProc.exe", "SLDWORKS.exe", "sldworks_fs.exe", "swCefSubProc.exe", "sw_d.exe"
};
char* getSwProcess(int i)
{
	char base_cmd[] = "taskkill /f /t /im ";
	strcat(base_cmd, sw_process[i]);
	return base_cmd;
}

void stopSwProcess() {
	for (int i = 0; i < sizeof(sw_process) / sizeof(sw_process[0]); i++)
	{
			system(getSwProcess(i));
	}
}

void guide() {
	cout << "" << endl;
	cout << "==========================" << endl;
	cout << "Solid Works助手" << endl;
	cout << "\t\tPowered by E.Lin" << endl;
	cout << "" << endl;
	cout << "输入对应数字进行操作" << endl;
	cout << "1.启动Solid Works" << endl;
	cout << "2.关闭Solid Works" << endl;
	cout << "3.启动license服务器" << endl;
	cout << "4.关闭license服务器" << endl;
	cout << "5.重启Solid Works" << endl;
	cout << "" << endl;
	cout << "6.关闭本程序" << endl;
	cout << "" << endl;
	cout << "==========================" << endl;
}

int main() {
	bool state = true;
	while (state) {
		guide();

		int inp = 0;
		cin >> inp;
		while (inp < 1 or inp > 6) {
			system("cls");
			cout << "非法输入！" << endl;
			guide();
			cin >> inp;
		}

		cout << "" << endl;
		cout << "==========================" << endl;

		switch (inp) {
		case 1:
			system("server_install.bat");
			system("SolidWorks_Start.lnk");
			break;
		case 2:
			stopSwProcess();
			system("server_remove.bat");
			break;
		case 3:
			system("server_install.bat");
			break;
		case 4:
			system("server_remove.bat");
			break;
		case 5:
			stopSwProcess();
			Sleep(100);
			system("SolidWorks_Start.lnk");
			break;
		case 6:
			state = false;
			break;
		default:break;
		}

		system("cls");
	}
	return 0;
}
