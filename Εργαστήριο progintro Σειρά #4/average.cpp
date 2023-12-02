#include <cstdio>
using namespace std;

double Average(double arr[100], int n)
{
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return sum / n;
}

double ReadArray(double arr2d[100][100], int N, int M)
{
    double arrAvg[100];

    for (int i = 0; i < N; i++)
    {
        double arr[100];

        for (int j = 0; j < M; j++)
        {
            arr[j] = arr2d[i][j];
        }

        arrAvg[i] = Average(arr, M);
    }

    return Average(arrAvg, N);
}

int main()
{
    double arr2dRows[100][100], arr2dCols[100][100];
    int N, M;

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%lf", &arr2dRows[i][j]);
            arr2dCols[j][i] = arr2dRows[i][j];
        }
    }

    printf("%.3f\n", ReadArray(arr2dRows, N, M));
    printf("%.3f\n", ReadArray(arr2dCols, M, N));

    return 0;
}
