#include <iostream>

int main()
{
    int arr[150][150], array[22500]{}, N, sum = 0, sumDiag1 = 0, sumDiag2 = 0;
    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> arr[i][j];
            array[arr[i][j]]++;
        }
    }
    
    for (int i = 0; i < N; i++)
    {
        sum += arr[0][i];
        sumDiag1 += arr[i][i];
        sumDiag2 += arr[N - 1 - i][i];
    }

    if (sumDiag1 != sum || sumDiag2 != sum)
    {
        std::cout << "no" << std::endl;
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        int currentSumX = 0, currentSumY = 0;

        for (int j = 0; j < N; j++)
        {
            currentSumX += arr[i][j];
            currentSumY += arr[j][i];
        }

        if (currentSumX != sum || currentSumY != sum)
        {
            std::cout << "no" << std::endl;
            return 0;
        }
    }

    for (int i = 0; i < N * N - 1; i++)
    {
        if (array[i] != 1)
        {
            std::cout << "no" << std::endl;
            return 0;
        }
    }

    std::cout << "yes" << std::endl;
}
