#include <iostream>
#include <algorithm>
using namespace std;

struct Item
{
    int weight, value;
};

bool cmp(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, cmp);

    double total = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (W >= arr[i].weight)
        {
            total += arr[i].value;
            W -= arr[i].weight;
        }
        else
        {
            total += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }
    return total;
}

int main()
{
    Item arr[] = {{12, 100}, {18, 120}, {10, 60}};
    int W = 20;
    int n = 3;

    cout << "Maximum Profit: " << fractionalKnapsack(W, arr, n);
    return 0;
}