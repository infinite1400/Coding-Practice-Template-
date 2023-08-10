#include <bits/stdc++.h>
using namespace std;
void merge(int *arr, int l, int h, int mid)
{
    int lrange = mid - l + 1;
    int rrange = h - mid;
    int left[lrange];
    int right[rrange];
    for (int i = l; i <= mid; i++)
    {
        left[i - l] = arr[i];
    }
    for (int i = mid + 1; i <= h; i++)
    {
        right[i - mid - 1] = arr[i];
    }
    int i = 0, j = 0, k = l;
    while (lrange > i && rrange > j)
    {
        if (left[i] > right[j])
        {
            arr[k++] = right[j++];
        }
        else
        {
            arr[k++] = left[i++];
        }
    }
    while (lrange > i)
    {
        arr[k++] = left[i++];
    }
    while (rrange > j)
    {
        arr[k++] = right[j++];
    }
}
void mergesort(int arr[], int l, int h)
{
    if (h > l)
    {
        int mid = (l + h) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, h);
        merge(arr, l, h, mid);
    }
}
int main()
{
    // string str="00000012";
    // cout<<stol(str);
    int a=5;
    return 0;
}