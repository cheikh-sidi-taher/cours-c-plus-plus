#include <iostream>
using namespace std;

double ReadTotalSales()
{
    double totalSales;
    cout << "Enter total sales: ";
    cin >> totalSales;
    return totalSales;
}

double getTotalCommission(double totalSales)
{
    if (totalSales > 1000000)
    {
        return totalSales * 0.1;
    }
    else if (totalSales >= 500000)
    {
        return totalSales * 0.02;
    }
    else if (totalSales >= 100000)
    {
        return totalSales * 0.03;
    }
    else if (totalSales >= 50000)
    {
        return totalSales * 0.05;
    }
    else
    {
        return 0.00;
    }
}

void PrintCommission(double commission)
{
    cout << "Commission: " << commission << endl;
}

int main()
{

    PrintCommission(getTotalCommission(ReadTotalSales()));
    return 0;
}
