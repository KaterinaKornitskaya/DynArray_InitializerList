// DynArray_InitializerList.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

/*
	Создать шаблонный класс, инкапсулирующий динамический массив. 
	Создать класс Point и адаптировать этот класс к созданному шаблону.
	Продемонстрировать создание и инициализацию объекта шаблонного класса 
	с помощью списка инициализации, состоящего из значений типа Point.
	Для этого использовать конструктор Initializer_list.
*/

class Point  // класс Point
{
	int x;
	int y;
public:
	Point() : x{0}, y{0} {}

	Point(int xP, int yP) : x{xP}, y{yP} {}  // конструктор с параметрами для установки значений
	
	// дружественная ф-ия - перегрузка оператора вывода << для вывода значений Point
	friend std::ostream& operator<<(std::ostream& os, Point& obj);
};

std::ostream& operator<<(std::ostream& os, Point& obj)
{
	os << "x: " << obj.x << " y: " << obj.y << std::endl;
	return os;
}

template <typename T> class DynArray  // шаблонный класс Динамический Массив
{
private:
	int length;  // размер массива
	T* data;     // указатель на динамический массив
public:
	DynArray() : length(0), data(nullptr) {}

	DynArray(int length) : length(length)
	{
		data = new T[length];  // выделение памяти под массив
	}

	// конструктор initializer_list
	DynArray(const std::initializer_list<T>& list) :   
		DynArray(list.size())
	{
		size_t i = 0;
		for (auto element : list)
		{
			data[i] = element;
			i++;
		}
	}
	~DynArray()
	{
		delete[] data;
	}

	// перегрузка оператора индексирования
	T& operator[](int index)
	{
		return data[index];
	}
	int getLength() const
	{
		return length;
	}
};

int main()
{
	// объект типа double
	DynArray<double> array{ 7.1, 6.2, 5.0, 4.1, 3 };
	for (int i = 0; i < 5; i++)
	{
		std::cout << array[i] << ' ';
	}
	std::cout << std::endl << std::endl;

	// объект пользовательского типа Point
	DynArray<Point> point_arr{Point(5,2), Point(7,4)};
	for (int i = 0; i < 2; i++)
	{
		std::cout << point_arr[i] << ' ';
	}

	return 0;
}
