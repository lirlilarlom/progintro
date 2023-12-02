#include <iostream>
#include <climits>
using namespace std;

int MinMax(int arr2d[100][100], int N, int M, bool isMin)
{
    int arr[100];
    int result = isMin ? INT_MAX : INT_MIN;

    for (int j = 0; j < M; j++)
    {
        arr[j] = arr2d[0][j];

        for (int i = 1; i < N; i++)
        {
            if ((isMin && arr[j] < arr2d[i][j]) || (!isMin && arr[j] > arr2d[i][j])) arr[j] = arr2d[i][j];
        }

        if ((isMin && result > arr[j]) || (!isMin && result < arr[j])) result = arr[j];
    }

    return result;
}

int main()
{
    int N, M, arr2d[100][100], arr2dT[100][100];
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr2d[i][j];
            arr2dT[j][i] = arr2d[i][j];
        }
    }

    cout << MinMax(arr2d, N, M, true) << endl
         << MinMax(arr2dT, M, N, false) << endl;

    return 0;
}
