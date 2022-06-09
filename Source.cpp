#include <iostream>
#include <conio.h>

using namespace std;

const int MAXSIZE = 20;

class QUEUE
{
private:
	char* arr;
	int front;
	int rear;
public:
	QUEUE()
	{
		arr = new char[MAXSIZE];
		front = -1;
		rear = -1;
	}

	void MAKENULL()
	{
		front = -1;
		rear = -1;
	}

	bool EMPTY()
	{
		if (rear == -1 && front == -1)
			return true;
		return false;
	}

	void ENQUEUE(char c)
	{
		if ((rear + 1) % MAXSIZE == front)
			cout << "Queue is full" << endl;
		else
		{
			if (front == -1)
				front = 0;
			rear = (rear + 1) % MAXSIZE;
			arr[rear] = c;
		}

	}

	void DEQUEUE()
	{
		if (EMPTY())
			cout << "Queue is empty" << endl;
		else if (front == rear)
		{
			rear = -1;
			front = -1;
		}
		else
		{
			front = (front + 1) % MAXSIZE;
		}
	}

	char FRONT()
	{
		if (EMPTY())
		{
			cout << "Queue is empty" << endl;
		}
		else
			return arr[front];
	}

	void PRINT()
	{
		if (EMPTY())
			cout << "Queue is empty" << endl;
		else
		{
			if (front <= rear)
			{
				for (int i = front; i <= rear; i++)
				{
					cout << arr[i];
				}
				cout << endl;
			}
			else
			{
				for (int i = front; i < MAXSIZE; i++)
				{
					cout << arr[i];
				}

				for (int i = 0; i < rear; i++)
				{
					cout << arr[i];
				}
				cout << endl;
			}
		}

	}
};

int main()
{
	QUEUE Q;

	char c;

	Q.MAKENULL();

	c = ' ';

	while (c != '=') {
		c = _getch();
		Q.ENQUEUE(c);
		Q.PRINT();
	}

	Q.DEQUEUE();

	Q.DEQUEUE();

	Q.ENQUEUE('<');

	while (!Q.EMPTY()) {

		printf("%c, ", Q.FRONT());

		Q.DEQUEUE();

	}

	printf("\n");

	return 0;
}
