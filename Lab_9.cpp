#include <iostream>
#include <time.h>
using namespace std;

struct Product
{
    Product()
    {
        this->Price = rand() % 100 + 1;
        this->Weight = rand() % 50 + 1;

        this->NumberPurchases = 0;
    }

    int Price;
    double Weight;

    int NumberPurchases;
};

int main()
{
    srand(time(NULL));

    int N, SumPrice = 0;
    double W, MaxWeight = 0.0f;

    cout << "Number of types of products: ";
    cin >> N;
    cout << "Capacity of the backpack: ";
    cin >> W;

    if (1 >= N || N > 256 || 1 >= W || W > 1024)
    {
        std::cout << "Incorrect value\n";
        system("pause");
        return 0;
    }

    Product *product = new Product[N]();

    int productCounter = 0;

    while (true)
    {
        MaxWeight += product[productCounter].Weight;

        if (MaxWeight >= W)
        {
            break;
        }

        SumPrice += product[productCounter].Price;

        product[productCounter].NumberPurchases++;

        productCounter++;

        if (productCounter == N)
        {
            productCounter = 0;
        }
    }

    cout << "Number of purchases of products:\n";
    for (int i = 0; i < N; i++)
    {
        if (product[i].NumberPurchases != 0)
        {
            cout << "Product " << i << ": x" << product[i].NumberPurchases << " Price: " << product[i].Price << "\n";
        }
    }

    cout << "Maximum price of all products in a backpack: " << SumPrice << "\n";

    system("pause");

    return 0;
}
