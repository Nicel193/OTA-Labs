#include <iostream>

using namespace std;

int min(int array[], int arrayCount)
{
    int m = array[0];
    int index = 0;

    for (int i = 0; i < arrayCount; ++i)
    {
        if (array[i] < m)
        {
            m = array[i];
            index = i;
        }
    }

    return index;
}

int max(int array[], int arrayCount)
{
    int m = array[0];
    int index = 0;

    for (int i = 0; i < arrayCount; ++i)
    {
        if (array[i] > m)
        {
            m = array[i];
            index = i;
        }
    }

    return index;
}

double average(int array[], int arrayCount)
{
    int sum;

    for (int i = 0; i < arrayCount; ++i)
    {
        sum += array[i];
    }

    return (double)sum / (double)arrayCount;
}

int main()
{
    int keysValue[256];

    keysValue[3] = 0;

    int arrayCount = 0;

    while (true)
    {
        int n;

        cout << "lol";

        cin >> n;

        if (n > 0 && n < 256)
        {
            keysValue[arrayCount++] = n;

            cout << "Количество элементов: " << arrayCount << endl;
            cout << "Среднее Арифметическое: " << average(keysValue, arrayCount) << endl;
            cout << "Макс: " << keysValue[max(keysValue, arrayCount)] << " Мин:" << keysValue[min(keysValue, arrayCount)] << endl;

            if (keysValue[3] != 0)
                cout << "4-й элемент: " << keysValue[3] << endl;

            if (min(keysValue, arrayCount) > 0)
                cout << "Элемент перед минимальным элементом: " << keysValue[min(keysValue, arrayCount) - 1] << endl;
        }
        else
        {
            cout << "Неверное значение" << endl;
        }

        cout << "\n";
    }

    return 0;
}