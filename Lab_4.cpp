#include <iostream>

using namespace std;

int GetMaxValue(int array[], int arraySize)
{
    int max = array[0];

    for (int i = 0; i < arraySize - 1; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    return max;
}

int *CountSort(int array[], int arraySize)
{
    int maxValue = (GetMaxValue(array, arraySize) + 1);
    int newArray[maxValue];

    for (int i = 0; i < maxValue; i++)
    {
        newArray[i] = 0;
    }

    for (int i = 0; i < arraySize; i++)
    {
        newArray[array[i]]++;
    }

    int index;

    for (int i = 0; i < maxValue; i++)
    {
        if (newArray[i] != 0)
        {
            while (newArray[i] != 0)
            {
                array[index++] = i;
                newArray[i]--;
            }
        }
    }

    return array;
}

int SearchBinary(int arr[], int right, int key)
{
    int mid = 0;
    int left = 0;

    if (key > right)
        return -1;

    while (true)
    {
        mid = (left + right) / 2;

        if (key > arr[mid])
            left = mid;

        if (key < arr[mid])
            right = mid;

        if (key == arr[mid])
            return mid;

        if (left == right) // если границы сомкнулись
            return -1;
    }
}

int main()
{
    int n, m, findValue;

    cout << "Сколько значений хотите ввести?" << endl;
    cin >> n;
    cout << "Сколько значений хотите найти" << endl;
    cin >> m;

    int arr[n];
    cout << "Введите значения:" << endl;

    for (int i = 0; i <= n - 1; i++)
    {
        cin >> arr[i];
    }

    CountSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << " : " << arr[i];
    }

    cout << endl;
    cout << "Введите значения, которое хотите найти: " << endl;

    for (int i = 0; i <= m; i++)
    {
        cin >> findValue;

        int index = SearchBinary(arr, n, findValue);

        if (index != -1)
        {
            cout << "Указанное число находится в ячейке с индексом: " << index << endl;
        }
        else
        {
            cout << "В массиве нет числа: " << findValue << endl;
        }
    }
}