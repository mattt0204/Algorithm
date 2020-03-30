

int main()
{
    int arr[] = {1, 52, 48};
    int N = 3;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (arr[i] + arr[j] == 100)
            {
                return 1;
            }
        }
    }
    return 0;
}
// n^2