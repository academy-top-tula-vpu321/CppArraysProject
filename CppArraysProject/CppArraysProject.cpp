#include <iostream>

int ArrayMin(int array[], int size)
{
    int minIndex{};
    for (int i = 1; i < size; i++)
        if (array[minIndex] > array[i])
            minIndex = i;
    return minIndex;
}

void ArrayPrint(int array[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";
}

void ArrayInitRand(int array[], int size, int begin = 0, int end = 99)
{
    for (int i = 0; i < size; i++)
        array[i] = begin + rand() % (end - begin + 1);
}

void ArrayShiftLeft(int array[], int size, int steps)
{
    steps %= size;

    for (int s = 0; s < steps; s++)
    {
        int pocket = array[0];
        for (int i = 1; i < size; i++)
            array[i - 1] = array[i];
        array[size - 1] = pocket;
    }
}

void ArrayShiftRight(int array[], int size, int steps)
{
    steps %= size;
    for (int s = 0; s < steps; s++)
    {
        int pocket = array[size - 1];
        for (int i = size - 1; i > 0; i--)
            array[i] = array[i - 1];
        array[0] = pocket;
    }
}

int main()
{
    const int size{ 10 };
    int array[size]{};

    //array[4] = 100;

    ArrayPrint(array, size);

    srand(time(nullptr));

    int begin = 20;
    int end = 100;

    ArrayInitRand(array, size);
    ArrayPrint(array, size);
    ArrayShiftRight(array, size, 33);
    ArrayPrint(array, size);

    /*int minIndex = ArrayMin(array, size);

    std::cout << "Min index: " << minIndex
        << " Min value: " << array[minIndex] << "\n";
    */

    const int rows{ 4 };
    const int columns{ 5 };

    int matrix[rows][columns];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            matrix[i][j] = (i + 1) * 10 + (j + 1);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            std::cout << matrix[i][j] << "\t";
        std::cout << "\n";
    }
        

}
