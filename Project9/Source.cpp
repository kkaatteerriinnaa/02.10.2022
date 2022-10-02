#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

class Queue
{
	char* Wait;
	int MaxQueueLenght;
	int QueueLenght;
public:
	Queue(const char* buf);
	~Queue();
	bool IsEmpty();
	char Extract();
};

Queue::Queue(const char* buf)
{
	MaxQueueLenght = 6;
	Wait = new char[MaxQueueLenght];
	strcpy_s(Wait, 7, buf);
	QueueLenght = 6;
}

bool Queue::IsEmpty()
{
	return QueueLenght == 0;
}

char Queue::Extract()
{
	char temp = Wait[0];
	for (int i = 1; i < QueueLenght; i++)
		Wait[i - 1] = Wait[i];
	Wait[QueueLenght - 1] = temp;
	return temp;
}

Queue::~Queue()
{
	delete[]Wait;
}

int main()
{
	srand(time(0));
	HANDLE h;
	Queue Bar1("KF53RE");
	Queue Bar2("KF53RE");
	Queue Bar3("KF53RE");
	char B1c, B2c, B3c;
	int rand_spin; 
	while (true)
	{
		rand_spin = rand() % (15 - 30) + 15;
		for (int i = 0; i < rand_spin; i++)
		{
			char c;
			h = GetStdHandle(STD_OUTPUT_HANDLE);
			COORD a{ 0 , 0 };
			c = Bar1.Extract();
			SetConsoleTextAttribute(h, 7);
			SetConsoleCursorPosition(h, a);
			cout << c;
			B1c = c;
			Sleep(50);
		}
		rand_spin = rand() % (15 - 30) + 15;
		for (int i = 0; i < rand_spin; i++)
		{
			char c;
			h = GetStdHandle(STD_OUTPUT_HANDLE);
			COORD a{ 5 , 0 };
			c = Bar2.Extract();
			SetConsoleTextAttribute(h, 7);
			SetConsoleCursorPosition(h, a);
			cout << c;
			B2c = c;
			Sleep(50);
		}
		rand_spin = rand() % (15 - 30) + 15;
		for (int i = 0; i < rand_spin; i++)
		{
			char c;
			h = GetStdHandle(STD_OUTPUT_HANDLE);
			COORD a{ 10 , 0 };
			c = Bar3.Extract();
			SetConsoleTextAttribute(h, 7);
			SetConsoleCursorPosition(h, a);
			cout << c;
			B3c = c;
			Sleep(50);
		}
		cout << endl;
		if (B1c == B2c == B3c)
		{
			if (B1c == '5')
				cout << "You Win 1000$";
			else if (B1c == 'K')
				cout << "You Win 500$";
			else if (B1c == 'F')
				cout << "You Win 250$";
			else if (B1c == 'R')
				cout << "You Win 150$";
			else if (B1c == 'E')
				cout << "You Win 100$";
			else if (B1c == '3')
				cout << "You Win 50$";
		}
		else
			cout << "You Lose";
		cout << endl;
		system("pause");
		system("cls");
	}
}