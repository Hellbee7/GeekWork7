#include <iostream>
using namespace std;


/*void qsort(int* Array, int size)
{
    int first = 999;
    int mid = 0;
    int last = 0;
    for (int i = 0; i < size; i++)
    {
        if (Array[i] > last)
        {
            last = Array[i];
        }
        if (Array[i] < first)
        {
            first = Array[i];
        }
        
    }
    mid = (first + last) / 2;

    cout << first << " " << mid  << " "<<  last << endl;
}
*/

void sort(int* Array, int size)
{
    int buffer = 0;
    int bucket[3][10];
    int counter = 0;
    int counter2 = 0;
    int counter3 = 0;
    int arraycounter = 0;

    for (int i = 0; i < size; i++)
    {
        if (Array[i] <= 3)
        {
            bucket[0][counter] = Array[i];
            counter += 1;
        }
        else if (Array[i] <= 6 && Array[i]>3)
        {
            bucket[1][counter2] = Array[i];
            counter2 += 1;
        }
        else
        {
            bucket[2][counter3] = Array[i];
            counter3 += 1;
        }
    }
 
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (bucket[i][j] > bucket[i][j+1] && j < 4 && bucket[i][j] >= 0 && bucket[i][j+1] >= 0)
            {
                buffer = bucket[i][j];
                bucket[i][j] = bucket[i][j + 1];
                bucket[i][j + 1] = buffer;
            }
            
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (bucket[i][j] >= 0 && bucket[i][j] < 20)
            {
                arraycounter += 1;
            }
        }
    }

   int *newBucket = new int[arraycounter];
   counter = 0;
   cout << "Processed: ";
   for (int i = 0; i < sizeof(bucket)/sizeof(int); i++)
   {
       if (bucket[0][i] >= 0 && bucket[0][i] < 20)
       {
           newBucket[counter] = bucket[0][i];
           cout << newBucket[counter] << " ";
           counter += 1;
       }
   }
}

int main()
{
    int Array[]{0, 2, 8, 3, 4, 6, 5, 9, 8, 2, 7, 3};

    cout << "Original: ";
    for (int i = 0; i < 11; i++)
    {
        cout << Array[i] << " ";
    }
    cout << endl;
    int sizeofArray = sizeof(Array) / sizeof(int);
    sort(Array, sizeofArray);
    //qsort(Array, sizeofArray);
 
    return 0;
}