#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

unsigned int lagA = 55, lagB = 24;

void GenerateRandomValues(int N, int *Nums);
int MaxConsecutiveOnes(int N, int *Nums);
void WritingToFile(int N, int *Nums);

int main()
{
    int N = 0;
    int *Nums = new int[N];

    cout << "Enter the number of generated values: ";
    cin >> N;

    if (1 >= N || N > 256)
    {
        std::cout << "Incorrect value: " << N << "\n";
        system("pause");
        return 0;
    }

    GenerateRandomValues(N, Nums);

    WritingToFile(N, Nums);

    cout << "Test max consecutive ones: " << MaxConsecutiveOnes(N, Nums) << "\n";

    system("pause");
}

void GenerateRandomValues(int N, int *Nums)
{
    srand(time(NULL));
    int *Arr = new int[max(lagA, lagB)];

    for (int i = 0; i < max(lagA, lagB); i++)
    {
        Arr[i] = rand();
    }

    for (int i = N; i > 0; i--)
    {
        int Res;

        if (Arr[max(lagA, lagB) - lagA] >= Arr[max(lagA, lagB) - lagB])
        {
            Res = Arr[max(lagA, lagB) - lagA] - Arr[max(lagA, lagB) - lagB];
        }
        else
        {
            Res = Arr[max(lagA, lagB) - lagB] - Arr[max(lagA, lagB) - lagA];
        }

        for (int i = 0; i < max(lagA, lagB); i++)
        {
            Arr[i] = rand();
        }

        Nums[i] = Res;
    }
}

int MaxConsecutiveOnes(int N, int *Nums)
{
    int maxValue = 0;

    for (int i = 0; i < N; i++)
    {
        int count = 0;

        while (Nums[i] != 0)
        {
            Nums[i] = (Nums[i] & (Nums[i] << 1));

            count++;
        }

        if (count > maxValue)
        {
            maxValue = count;
        }
    }

    return maxValue;
}

void WritingToFile(int N, int *Nums)
{
    std::ofstream out;
    out.open("E:\\Projects\\C++\\OTA Labs\\CharacteristicSequence.txt");

    if (out.is_open())
    {
        out << "Characteristic sequence:\n";

        for (int i = 1; i < N; i++)
        {
            out << i << " : Value: " << Nums[i] << "\n";
        }
    }
    else
    {
        std::cout << "Open (out)file error\n";
    }

    out.close();
}