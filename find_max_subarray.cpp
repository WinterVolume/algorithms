#include <iostream>
#include <vector>
#include <ctime>
#include <list>
#include <numeric>
#include <random>
#include <limits>

using namespace std;

void printArray(std::vector<int> &arr, int base_length)
{
	for (int i = 0; i <= base_length; i++)
	{

		cout << arr[i];
		if (i < base_length) 
		{
			cout << ",";
		}
	}
	cout << "\n" << endl;
}

int find_max_cross_subarray(vector<int> &x, int low, int mid, int high, int &start_indice, int &end_indice)
{
	int left_sum = std::numeric_limits<int>::min();
	int right_sum = std::numeric_limits<int>::min();
	int sum = 0;

	for (int i = mid; i >= low; i--)
	{
		sum = sum + x[i];
		if (sum > left_sum) 
		{
			left_sum = sum;
			start_indice = i;
		}
	}

	sum = 0;

	for (int j = mid+1; j<= high; j++)
	{
		sum = sum + x[j];
		if (sum > right_sum)
		{
			right_sum = sum;
			end_indice = j;
		}
	}

	return left_sum + right_sum;
}

int find_max_subarray(vector<int> &x, int low, int high, int &start_indice, int &end_indice)
{
	//Base case only one element
	if (high == low) 
	{
		return x[low];
	}

	else
	{
		//Get the midpoint
		int mid = (low + high) / 2;
		
		int left_sum = find_max_subarray(x, low, mid, start_indice, end_indice);
		int right_sum = find_max_subarray(x, mid+1, high, start_indice, end_indice);
		int cross_sum = find_max_cross_subarray(x, low, mid, high, start_indice, end_indice);

		//int sum_max_subarray = max(left_sum, right_sum, cross_sum);*/
		//return sum_max_subarray;

		if (left_sum >= right_sum && left_sum >= cross_sum) 
		{
			return left_sum;
		}
		else if (right_sum >= left_sum && right_sum >= cross_sum)
		{
			return right_sum;
		}
		else
		{
			return cross_sum;
		}
	}
}


int main() {

	//Define the array
	int base_length = 10;
	int start_indice;
	int end_indice;

	std::vector<int> base_vec(base_length);


	random_device rnd_device;
	// Specify the engine and distribution.
	mt19937 mersenne_engine{ rnd_device() };  // Generates random integers
	uniform_int_distribution<int> dist{ -25, 25 };

	auto gen = [&dist, &mersenne_engine]() {
		return dist(mersenne_engine);
	};

	std::generate(base_vec.begin(), base_vec.end(), gen);
	int r = base_vec.size() - 1;


	cout << "Print input vector \n" << endl;

	printArray(base_vec, r);

	int max_sub_val = find_max_subarray(base_vec, 0, base_length -1, start_indice, end_indice);

	cout << "Max sum of contiguos subarray = "<< max_sub_val << endl;
	
	//FIXME: Indice stuff is incorrect, can't be bothered finding a solution with passing by reference or via defining a custom return type ie tuple.
	//cout << "\nStart and end indices as follows: " << start_indice << ", " << end_indice << endl;

	return 0;
}