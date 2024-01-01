// Реализация пирамидальной сортировки на C++
#include <iostream>
#include "algorithm"

// Функция для создания динамического массива
int *create_arr(int n)
{
    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];

     return arr;

}

// Процедура для преобразования в двоичную кучу поддерева с корневым узлом i, что является
// индексом в arr[]. n - размер кучи

void heapify(int arr[], int n, int i)
{
    int largest = i;
// Инициализируем наибольший элемент как корень
    int l = 2*i + 1; // левый = 2*i + 1
    int r = 2*i + 2; // правый = 2*i + 2

    // Если левый дочерний элемент больше корня
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);

// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(arr, n, largest);
    }

    }

// Основная функция, выполняющая пирамидальную сортировку
void heapSort(int arr[], int n)
{
    // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i=n-1; i>=0; i--)
    {
        // Перемещаем текущий корень в конец
        std::swap(arr[0], arr[i]);

        // вызываем процедуру heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}

/* Вспомогательная функция для вывода на экран массива размера n*/
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

// Управляющая программа
int main()
{
    int one;

    std::cout << " Select the type of array! Enter 1 to create a dynamic array or 2 to create a static array   " << std::endl;
    std::cin >>one;

    if (one != 2) {
        int n;
        std::cout << "Size array: ";
        std::cin >> n;
        int *arr = create_arr(n);

        heapSort(arr, n);

        std::cout << "Sorted array:\n";
        printArray(arr, n);

        delete arr;

        system("Pause");

        return 0;
    }

                else {
                    int arr[] = {132, 11, 13, 5, 6, 7};
                    int n = sizeof(arr) / sizeof(arr[0]);

                    std::cout << "Sorted before" << std::endl;
                    for (int i = 0; i < 5; i++)
                        std::cout << arr[i] << ' ';
                    std::cout << std::endl;

                    heapSort(arr, n);

                    std::cout << "Sorted array is \n";
                    printArray(arr, n);
                }
                system("Pause");

                return 0;

    }