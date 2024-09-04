#include <bits/stdc++.h>
using namespace std;

/*
# Algorithm for merger sort
function mergeSort(array)
    if length(array) ≤ 1
        return array
    middle = length(array) / 2
    left = mergeSort(array[0...middle-1])
    right = mergeSort(array[middle...length(array)-1])
    return merge(left, right)

function merge(left, right)
    result = []
    while left and right are not empty
        if left[0] ≤ right[0]
            append left[0] to result
            remove left[0] from left
        else
            append right[0] to result
            remove right[0] from right
    append any remaining elements in left or right to result
    return result
*/

void merge(vector<int> &a, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftA(n1);
    vector<int> rightA(n2);

    for (int i = 0; i < n1; i++)
        leftA[i] = a[left + i];
    for (int i = 0; i < n2; i++)
        rightA[i] = a[mid + i + 1];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (leftA[i] <= rightA[j])
        {
            a[k] = leftA[i];
            ++i;
        }
        else
        {
            a[k] = rightA[j];
            ++j;
        }
        ++k;
    }
    while (i < n1)
    {
        a[k] = leftA[i];
        ++i;
        ++k;
    }
    while (j < n2)
    {
        a[k] = rightA[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int> &a, int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, mid, right);
}

int main()
{
    std::vector<int> array = {38, 27, 43, 3, 9, 82, 10, -1, 2, 3, 43, 21};

    std::cout << "Unsorted array: ";
    for (int num : array)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    mergeSort(array, 0, array.size() - 1);

    std::cout << "Sorted array: ";
    for (int num : array)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
