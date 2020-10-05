#include <iostream>
#include <math.h>
#include <conio.h> // для getch
#include <cstdlib> // system("pause");
#define N 30
using namespace std;

void meny() {
	cout << "0 - Выйти из программы" << endl;
	cout << "1 - Ввести несколько эл-ов с клавиатуры" << endl;
	cout << "2 - Добавить в массив n случайных чисел в промежутке от a до b" << endl;
	cout << "3 - Вывести массив на экран" << endl;
	cout << "4 - Поиск индекса элемента" << endl;
	cout << "5 - Добавление массив к массиву" << endl;
	cout << "6 - Объединение массивов" << endl;
	cout << "7 - Вставка элемента в массив" << endl;
	cout << "8 - Удаление нескольких подряд идущих элементов массива" << endl;
	cout << "9 - Поиск подпоследовательности" << endl;
}

int* initArray(int capacity)
{
	int* result = new int[capacity + 2]{ 0 };
	result += 2;
	*(result - 2) = capacity;
	return result;
}

void function_3(int* arr, int size) { // Вывести массив
	*(arr - 1) = size;
	for (int i = -2; i < size; i++)
	{
		cout << *(arr + i) << "  ";
	}
	system("pause");
}

void function_1(int*& arr, int& size, int M) { // Добавить несколько эл-ов с клавиатуры
	int a = 0;
	for (int i = 0; i < M; i++) {
		cout << "Введите число, которое необходимо добавить" << endl;
		cin >> a;
		*(arr + size) = a;
		size++;
	}
}
void function_2(int*& arr, int& size, int numb_rand, int a, int b) { // Добавить рандомные числа
	int new_size = size + numb_rand;
	while (size < new_size) {
		*(arr + size) = rand() % (b - a + 1) + a;
		size++;
	}
}

int function_4(int* arr, int size, int element) { // Поиск индекса элемента
	for (int i = 0; i < size; i++) {
		if (*(arr + i) == element) { return i; }
	}
	return -1;
}

void function_5(int*& arr, int& size, int* addArr, int addSize) { //Добавление массива к массиву
	int i = 0;
	int j = 0;
	for (i = size; i < size + addSize; i++) {
		*(arr + i) = *(addArr+j);
		j++;
	}
	size = size + addSize;
}

void function_6(int*& arr, int& size, int* addArr, int addSize) { //Объединение массивов
	int i = 0;
	int j = -1;
	int t = 0;
	int* arr_copy = new int[N] {0};
	for (i = 0; i < size; i++) {
		*(arr_copy + i) = *(arr + i);
	}

	if (addSize < size) {
		for (i = 0; i < size + addSize; i++) {
			if (i < 2 * addSize) {
				if (i % 2 == 0) { *(arr + i) = *(arr_copy+ i/2); cout << *(arr + i)  << "  "; }
				else {
					j++;
					*(arr + i) = *(addArr + j);
					cout << *(arr + i) << "  ";
				}
				t = i / 2;
			}
			else {
				t++;
				*(arr + i) = *(arr_copy + t);
				cout << *(arr + i) << "  ";
			}
		}
		system("pause");
	}
	if (addSize > size) {
		for (i = 0; i < size + addSize; i++) {
			if (i < 2 * size - 1) {
				if (i % 2 == 0) {
					*(arr + i) = *(arr_copy + i / 2);
					cout << *(arr + i) << "  ";
				}
				else {
					j++;
					t = i / 2;
					*(arr + i) = *(addArr + j);
					cout << *(arr + i) << "  ";
				}
			}
			else {
				t++;
				*(arr + i) = *(addArr + t);
				cout << *(arr + i) << "  ";
			}
		}
		system("pause");
	}
	size += addSize;
}

void function_7(int*& arr, int& size, int element, int index) { // Вставка элемента в массив
	int temp = 0;
	int* arr_copy = new int[N] {0};
	for (int i = 0; i < size; i++) {
		*(arr_copy + i) = *(arr + i);
	}
	temp = *(arr + index);
	*(arr+index) = element;
	size++;
	for (int i = index + 1; i < size; i++) {
		*(arr + i) = *(arr_copy + i - 1);
	}
}

int function_8(int*& arr, int& size, int startIndex, int count) { // Удаление нескольких подряд идущих элементов массива
	if (startIndex + count > size) { return -1; }
	else {
		int* arr_copy = new int[N] {0};
		for (int i = 0; i < size; i++) {
			*(arr_copy + i) = *(arr + i);
		}
		for (int i = startIndex; i < size - count; i++) {
			*(arr + i) = *(arr_copy + i + count);
		}
		size = size - count;
		return 0;
	}
}

/*int function_9(int* arr, int size, int* B, int size_B) { // Удаление нескольких подряд идущих элементов массива
	for (int j = 0; j < size_B; j++) {
		for (int i = 0; i < size; i++) {
			if (arr[i] == B[j]) {
				int temp = i;
				cout << i << " " << arr[i] << endl;

				cout << "arr[i + 1]=  " << arr[i + 1] << endl;
				cout << "B[j + 1]=  " << B[j + 1] << endl;
				if (arr[i + 1] == B[j + 1]) {
					while (arr[i + 1] = B[j + 1]) {
						if (i - temp + 1 == size_B) { return temp; }
						cout << "i - temp + 1" << "=  " << i - temp + 1 << "  " << arr[i] << endl;
						i++; j++;
					}
				}
				i = temp;
			}
		}
	}
	system("pause");
	return -1;
}*/

void check(int*& A, int& n, int x) {
	if (x == 1) {
		int a = 0;
		int M = 0;
		cout << "Сколько чисел Вы хотите добавить?" << endl;
		cin >> M;
		function_1(A, n, M);
	}
	if (x == 2) {
		int c = 0;
		cout << "Какое кол-во случайных чисел Вы хотите добавить?" << endl;
		cin >> c;
		int a = 0;
		int b = 0;
		cout << "В каком промежутке необходимо рандомить числа?" << endl;
		cin >> a >> b;
		function_2(A, n, c, a, b);
	}
	if (x == 3) {
		cout << "Массив:  ";
		function_3(A, n);
	}
	if (x == 4) {
		int element = 0;
		cout << "Индекс какого элемента Вы хотите узнать?" << endl;
		cin >> element;
		cout << function_4(A, n, element) << endl;
		system("pause");
	}
	if (x == 5) {
		int* addArr = new int[N] {0};
		int i = -1;
		int a = 0;
		cout << "Введите массив который необходимо добавить?" << endl;
		cout << "Введите -1000 когда заходите прекратить пополнение массива" << endl;
		while (1) {
			cin >> a;
			if (a != -1000) {
				i++;
				addArr[i] = a;
				//cout << addArr[i] << endl;
				//cout << i << endl;
			}
			else break;
		}
		cout << "Успешно!" << endl;
		int addSize = i + 1;
		/*for (i = 0; i < addSize; i++) {
			cout << addArr[i] << "  ";
		}*/
		function_5(A, n, addArr, addSize);
		delete[] addArr;
		system("pause");
	}
	if (x == 6) {
		int* addArr = new int[N] {0};
		int i = -1;
		int a = 0;
		cout << "Введите массив который необходимо добавить" << endl;
		cout << "Введите -1000 когда заходите прекратить пополнение массива" << endl;
		while (1) {
			cin >> a;
			if (a != -1000) {
				i++;
				addArr[i] = a;
			}
			else break;
		}
		int addSize = i + 1;
		for (i = 0; i < addSize; i++) {
			cout << addArr[i] << "  ";
		}
		system("pause");
		function_6(A, n, addArr, addSize);
	}
	if (x == 7) {
		int  element = 0;
		int index = 0;
		cout << "Какой элемент Вы хотите добавить?" << endl;
		cin >> element;
		cout << "Какой индекс должен иметь элемент?" << endl;
		cin >> index;
		function_7(A, n, element, index);
	}
	if (x == 8) {
		int startIndex = 0;
		int count = 0;
		cout << "Начиная с какого индекса надо удалить элементы?" << endl;
		cin >> startIndex;
		cout << "Сколько элементов надо удалить?" << endl;
		cin >> count;
		cout << function_8(A, n, startIndex, count) << endl;
	}
	/*if (x == 9) {
		int* B = new int[N] {0};
		int size_B = 0;
		int i = -1;
		int b = 0;
		cout << "Введите подпоследовательность, которую надо найти?" << endl;
		cout << "Введите -1000 когда заходите прекратить ввод" << endl;
		while (1) {
			cin >> b;
			if (b != -1000) {
				i++;
				B[i] = b;
			}
			else break;
		}
		size_B = i + 1;
		cout << function_9(A, n, B, size_B) << endl;
		system("pause");
	}*/
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int x = 1;
	int n = 0;
	int* A = initArray(N);
	while (x != 0) {
		system("cls");
		meny();
		cin >> x;
		check(A, n, x);
	}

	delete[] A;
	return 0;
}