#include <vector>
#include <algorithm>
#include <iostream>


using std::cout;
using std::cin;
using std::vector;
using std::sort;

// Random number vector generator.Got these functions from Lab_06, these were given to us.
double randUniform()
{
	double r = double(rand()) / (RAND_MAX + 1.0);
	r = (double(rand()) + r) / (RAND_MAX + 1.0);
	r = (double(rand()) + r) / (RAND_MAX + 1.0);
	r = (double(rand()) + r) / (RAND_MAX + 1.0);
	return  r;
};


double randReal(double minReal, double maxReal)
{
	return minReal
		+ (maxReal - minReal) * randUniform();
};

vector<double> getNums(size_t listSize, double minNum, double maxNum)
{
	vector<double> theList;
	for (size_t i = 0; i < listSize; ++i)
	{
		theList.push_back(randReal(minNum, maxNum));
	}

	return theList;
};


//Sorting Functions

vector<double> merge(vector<double> left, vector<double> right, vector<double> pos)
{
	vector<double> value;
	int i = 0;
	int j = 0;
	int k = 0; //pos
	while (i < left.size() && j < right.size())
	{
		if (left.at(i) > right.at(j))
		{
			pos.push_back(left.at(i));
			i = i + 1;
		}
		else if (left.at(i) < right.at(j))
		{
			pos.push_back(right.at(j));
			j = j + 1;
		}
		k = k + 1;

	}
	while (i < left.size())
	{
		pos.push_back(left.at(i));
		k = k + 1;
		i = i + 1;
	}
	while (j < right.size())
	{
		pos.push_back(right.at(j));
		k = k + 1;
		j = j + 1;

	}
	return pos;
}
	


vector<double> mergeSort(vector<double> input)
{
	vector<double> left;
	vector<double> right;
	vector<double> pos;
	int mid;
	if (input.size() == 1)
	
		{
			return input;
		}
	mid = (input.size() + 1) / 2;
		

		for (int i = 0; i < mid; i++)
		{
			left.push_back(input.at(i));
		}

		for (int j = mid; j < input.size(); j++)
		{
			right.push_back(input.at(j));
		}

		left = mergeSort(left);
		right = mergeSort(right);
		return merge(left, right, pos);
	}

vector<double> insertion(vector<double> input)		
{
	int value;
	double temp;
	for (int i = 1; i < input.size(); i++)
	{
		value = i;
		while (value > 0 && input.at(value - 1) > input.at(value))
		{
			temp = input.at(value);
			input.at(value) = input.at(value-1);
			input.at(value-1) = temp;
			value--;
					
		}
	}
	
	return input;
}

vector<double> bubble (vector<double> input)  
{
	double temp;
	bool check=true;
	while (check)
	{
		for (int i = input.size(); i >= 0; i--)
		{
			for (int j = 0; j < i - 1; j++)
			{

				if (input.at(j) > input.at(j + 1))
				{
					temp = input.at(j);
					input.at(j) = input.at(j + 1);
					input.at(j + 1) = temp;
					check = false;
				}
			}
		}
	}
	return input;
	}

//vector<double> quickSort(vector<double> input)  //Just could not figure out how to do this one!!!!

vector<double> selection(vector<double> input)
{
	double min, temp;
	int pos;
for (int i = 0; i < input.size(); i++)
{
	for (int j = i; j < input.size(); j++)
	{
		if (j == i)
		{
			min= input.at(i);
			pos = i;
		}
			
		
		if (min > input.at(j))
		{
			min = input.at(j);
			pos = j;
		}
	}
	temp = input.at(i);
	input.at(i) = min;
	input.at(pos) = temp;
 }
return input;

}


