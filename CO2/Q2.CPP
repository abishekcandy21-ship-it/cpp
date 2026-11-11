#include <iostream>
using namespace std;

int& highestMark(int marks[], int n)
{
    int highestIndex = 0;

    for (int i = 1; i < n; i++)
    {
        if (marks[i] > marks[highestIndex])
        {
            highestIndex = i;
        }
    }

    return marks[highestIndex];
}

// Demonstrates an unsafe function.
// Do not call or use its returned reference.
int& dangerousFunction()
{
    int localValue = 50;
    return localValue;
}

int main()
{
    int marks[] = {75, 88, 92, 81, 85};
    int n = 5;

    cout << "Original marks: ";

    for (int i = 0; i < n; i++)
    {
        cout << marks[i] << " ";
    }

    cout << endl;

    highestMark(marks, n) += 2;

    cout << "After moderation: ";

    for (int i = 0; i < n; i++)
    {
        cout << marks[i] << " ";
    }

    cout << endl;

    cout << "Highest mark: "
         << highestMark(marks, n) << endl;

    return 0;
}