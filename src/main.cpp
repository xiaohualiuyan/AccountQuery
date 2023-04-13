#include"accountQuery.h"
int main()
{
	AccountQuery A;
	while (true)
	{   cout << "**** Account Information Select*******";
		cout << "\n\t 1--->write record to file";
		cout << "\n\t 2--->read record to file";
		cout << "\n\t 3--->search record to file";
		cout << "\n\t 4--->delete record to file";
		cout << "\n\t 5--->updata record to file";
		cout << "\n\t 6--->Quit";
		cout << "\nEnter Your Choice:";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:A.WriteRec(); break;
		case 2:A.readRec(); break;
		case 3:A.searchRec(); break;
		case 4:A.deleteRec(); break;
		case 5:A.updataRec(); break;
		case 6:return 0; break;
		default:cout << "\nPlease Enter correct choice.\n"; break;
		}
	}
	return 0;
}