#include<iostream>
using namespace std;

void FractionalKnapsack(double profit[], double weight[], int n, double capacity)
{
    double ratio[100];
    double x[100] = {0};

    for(int i = 0; i < n; i++)
        ratio[i] = profit[i] / weight[i];

    // Sort objects in decreasing order of profit/weight ratio

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(ratio[j] < ratio[j + 1])
            {
                double temp = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp;

                temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;

                temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;
            }
        }
    }

    double totalProfit = 0;

    for(int i = 0; i < n; i++)
    {
        if(weight[i] <= capacity)
        {
            x[i] = 1;
            totalProfit += profit[i];
            capacity -= weight[i];
        }
        else
        {
            x[i] = capacity / weight[i];
            totalProfit += profit[i] * x[i];
            capacity = 0;
            break;
        }
    }

    cout << "Selected fractions in ratio-sorted order: ";

    for(int i = 0; i < n; i++)
        cout << x[i] << " ";

    cout << "\nMaximum profit = " << totalProfit << endl;
}

int main()
{
    int n;
    double capacity;

    cout << "Enter number of objects: ";
    cin >> n;

    if(n <= 0 || n > 100)
    {
        cout << "Invalid number of objects";
        return 0;
    }

    double profit[100], weight[100];

    cout << "Enter profit and weight of each object:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> profit[i] >> weight[i];

        if(weight[i] <= 0)
        {
            cout << "Weights must be positive";
            return 0;
        }
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    if(capacity < 0)
    {
        cout << "Invalid capacity";
        return 0;
    }

    FractionalKnapsack(profit, weight, n, capacity);

    return 0;
}