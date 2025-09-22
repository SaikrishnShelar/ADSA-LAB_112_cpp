
//count the no.of inversion 
#include<iostream>
#include<vector>
using namespace std;

void combine(vector<int>& arr, int start, int end, int mid, int& invert)
{
    int s = start, m = mid;
    vector<int> temp;

    while (s < mid && m <= end)
    {
        if (arr[s] <= arr[m])
        {
            temp.push_back(arr[s]);
            s++;
        }
        else
        {
            temp.push_back(arr[m]);
            m++;
            invert += (mid - s); // Count inversions
        }
    }

    while (s < mid)
    {
        temp.push_back(arr[s]);
        s++;
    }

    while (m <= end)
    {
        temp.push_back(arr[m]);
        m++;
    }

    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[i - start];
    }
}

void divide(vector<int>& arr, int start, int end, int& invert)
{
    if (start >= end) return;

    int mid = (start + end) / 2;

    divide(arr, start, mid, invert);      // Left
    divide(arr, mid + 1, end, invert);    // Right
    combine(arr, start, end, mid + 1, invert); // Merge
}

int main()
{
    vector<int> arr = {2, 4, 1, 3, 5};
    int invert = 0;
    divide(arr, 0, arr.size() - 1, invert);

    cout << "Final sorted array: ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    cout << "\nTotal inversions: " << invert << endl;
    return 0;
}
