#include <iostream>
using namespace std;

int subset[100]; // To store subset
int n, target;
int setArr[100];

// Function to find subsets
void sumOfSubsets(int i, int sum, int remaining)
{
    if (sum == target)
    {
        // Print the subset
        cout << "Subset: ";
        for (int j = 0; j < i; j++)
        {
            cout << subset[j] << " ";
        }
        cout << endl;
        return;
    }

    if (i >= n || sum > target || sum + remaining < target)
    {
        return;
    }

    // Include current element
    subset[i] = setArr[i];
    sumOfSubsets(i + 1, sum + setArr[i], remaining - setArr[i]);

    // Exclude current element
    sumOfSubsets(i + 1, sum, remaining - setArr[i]);
}

int main()
{
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> setArr[i];
        total += setArr[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    sumOfSubsets(0, 0, total);

    return 0;
}