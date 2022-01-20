#include <iostream>
#include <array>
#include <vector>
//#include <algorithm>
#include <ctime>
#include <iostream>
#include <list>
#include <numeric>
#include <random>


using namespace std;

void printArray(std::vector<int> &arr, int base_length) 
{
	for (int i = 0; i <= base_length; i++)
	{
		cout << arr[i] << endl;
	}

	cout << "\n" << endl;
}


//Add return new sorted array perhaps, at lowest level needs a vector of two components so need to get that going in the recursive step.
void mergeArray(vector<int> &x, int start, int midpoint, int end)
{
	//create extra storage vector for storage
	std::vector<int> aux(x.size());


	int length_left = midpoint +1 - start;
	int length_right = end - midpoint;

	//Create left and right vectors
	std::vector<int> left(length_left +1);
	std::vector<int> right(length_right +1);

	

	for (int i = 0; i < length_left; i++)
	{
		left[i] = x[start + i];

	}

	for (int j = 0; j < length_right ; j++)
	{
			right[j] = x[midpoint +1 + j];
	}

	left[length_left] = 1000;
	right[length_right] = 1000;

	int i = 0;
	int j = 0;

	for (int k = start; k <= end; k++) 
	{
		if (left[i] <= right[j]) 
		{
			aux[k] = left[i];
			i= i + 1;

		}
		else
		{
			aux[k] = right[j];
			j = j + 1;
		}
		

	}

	cout << "Sorted \n" << endl;
	printArray(aux, aux.size() -1);

	// Copy the vector

	for (int i = start; i <= end; i++) {
		x[i] = aux[i];
	}

	cout << "Back into og array \n" << endl;
	printArray(x, x.size() -1);

}
//
//
void mergeSort(vector<int> &x, int start, int end)
{
	if (start < end) 
	{
		int midpoint = (start + end) / 2;
		mergeSort(x, start, midpoint);
		mergeSort(x, midpoint +1, end);
		mergeArray(x, start, midpoint, end);
	}
}


int main() {

	//Define the array
	int base_length = 20;

	std::vector<int> base_vec(base_length);


	random_device rnd_device;
	// Specify the engine and distribution.
	mt19937 mersenne_engine{ rnd_device() };  // Generates random integers
	uniform_int_distribution<int> dist{ 1, 50 };

	auto gen = [&dist, &mersenne_engine]() {
		return dist(mersenne_engine);
	};
	
	std::generate(base_vec.begin(), base_vec.end(), gen);

	//std::vector<int> v(10); 
	//std::iota(std::begin(v), std::end(v), 0); 

	int p = 0;
	int r = base_vec.size() -1;
	/*int q = (p + r) / 2;*/

	cout << "Print input vector \n" << endl;
			
	printArray(base_vec, r);

	mergeSort(base_vec, p, r);


	cout << "\n Print sorted vector" << endl;

	printArray(base_vec, r);


	

	//mergeArray(myInts);
	return 0;
}