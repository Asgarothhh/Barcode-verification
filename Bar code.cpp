#include <iostream>
#include <cmath>
#include <process.h>
using namespace std;

const int LENGTH = 14;
const int SIZE = 13;

class barCode
{
	private:
		char code[LENGTH];
		int barcode[SIZE];
	public:
		void read()
		{
			cout << "\nВведите штрих-код (ввод завершите символом '*'): ";
			cin.get(code, LENGTH, '*');
		}

		void converting()
		{
			for (int i = 0; i < SIZE; i++)
			{
				barcode[i] = code[i] - '0';
			}
		}

		bool review()
		{
			int count = 0;
			for (int i = 0; i < 13; i++)
			{
				if (code[i] == '\0') {
					count++;
				}
			}

			bool result = (count == 0) ? true : false;
			return result;
		}

		void add()
		{
				int Sr = 0, S1, Sh = 0, S, P, t;
				for (int i = 1; i < SIZE; i += 2)
				{
					Sr += barcode[i];
				}

				for (int i = 0; i < SIZE - 1; i += 2)
				{
					Sh += barcode[i];
				}

				S1 = Sr * 3;
				S = S1 + Sh;
				t = S % 10;
				P = 10 - t;

				barcode[SIZE - 1] = P;

				cout << "\nПолный возможный штрих-код: ";
				for (int i = 0; i < SIZE; i++)
					cout << barcode[i];
		}

		void verification()
		{
			int Sr=0, S1, Sh=0, S, P, t, firstNum, pozition;
			for (int i = 1; i < SIZE; i+=2)
			{
				Sr += barcode[i];
			}

			for (int i = 0; i < SIZE - 1; i += 2)
			{
				Sh += barcode[i];
			}

			S1 = Sr * 3;
			S = S1 + Sh;
			firstNum = S / 10;
			t = S % 10;
			P = 10 - t;
			
			if (P == barcode[SIZE - 1])
			{
				cout << "\nШтрих-код введён верно.";
			}
			else
			{
				char answer = 'a';
				cout << "\nНеверный штрих-код.";
				cout << "\nИсправить штрихкод (Y/N)? ";
				cin >> answer;
				switch (answer)
				{
					case 'Y':
					case 'y':
						cout << "\nВведите позицию элемента, который вы хотите изменить: ";
						cin >> pozition;
						if (pozition == SIZE - 1 || pozition > SIZE-1 || pozition < 0)
						{
							cout << "\nОшибка! Нельзя изменить контрольное число!";
							exit(1);
						}
						
						barcode[pozition] = 0;
						while (true)
						{
							Sr = 0; Sh = 0;
							for (int i = 1; i < SIZE; i += 2)
							{
								Sr += barcode[i];
							}

							for (int i = 0; i < SIZE - 1; i += 2)
							{
								Sh += barcode[i];
							}

							S1 = Sr * 3;
							S = S1 + Sh;
							firstNum = S / 10;
							t = S % 10;
							P = 10 - t;
							if (P == barcode[SIZE - 1])
								break;
							else
								barcode[pozition] += 1;
						}

						cout << "\nИсправленный штрихкод: ";
						for (int i = 0; i < SIZE; i++)
							cout << barcode[i];
						break;
					case 'N':
					case 'n':
						exit(1);
						break;
					default:
						cout << "\nНедопустимое значение! Попробуйте снова.";
						exit(1);
						break;
				}

			}
		}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	barCode cd;
	cd.read();
	if (cd.review()==true)
	{
		cout << "\nВсе символы штрих-кода введены.";
		cd.converting();
		cd.verification();
	}
	else
	{
		cout << "\nПри вводе штрих-кода был пропущен символ.";
		cd.converting();
		cd.add();
	}
	cout << endl;
	return 0;
}