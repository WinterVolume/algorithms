#include <iostream>
#include <array>

using namespace std;

void insertionSort(array<int, 5> x)
{
    cout << "The unordered elements of the array are:"<< "\n"; 
    
	int arraySize = x.size();
    for(int i = 0; i < arraySize; i++)
    {
        cout << x[i] << "\n";
    }

    //Implement sort here
    for(int j = 1; j < arraySize; j++)
    {
        int key = x[j];
        int i =j-1;

        while(i >= 0 && x[i] > key)
        {
            x[i+1] = x[i];
            i=i-1;
        }
    
		x[i+1] = key;
    }

    cout << "The ordered elements of the array are:"<< "\n"; 
    for(int i = 0; i < arraySize; i++)
    {
        cout << x[i] << "\n";
    }
}

int main(){

    //Define the array
	array<int, 5> myInts;
	myInts = { 5,3,2,1,4 };
    insertionSort(myInts);
    return 0;    
}