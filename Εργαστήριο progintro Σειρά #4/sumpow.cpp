#include <iostream>
#include <cmath>
using namespace std;

int CheckSum(int num, int arrPow[10])
{
    int sumPow = 0;

    do
    {
        sumPow += arrPow[num % 10];
        num /= 10;
    }
    while (num != 0);

    return sumPow;
}

int main()
{
    int N, arrPow[10]{};
    cin >> N;

    for (int i = 0; i < 10; i++)
    {
        arrPow[i] = pow(i, N);
    }

    for (int num = 0; num < 100'000'000; num++)
    {
        if (CheckSum(num, arrPow) == num) cout << num << endl;
    }   

    return 0;
}
