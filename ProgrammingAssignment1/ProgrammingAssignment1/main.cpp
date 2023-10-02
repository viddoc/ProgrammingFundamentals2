/******************************
   Tommy Hudson
   09/18/2023
   main.cpp
   Program to read in a file containing the number of movies watched by students then
   calculate the average, median, and mode of those numbers.
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

// Function declarations
int* getMovies(int& numStudents, string fileName);
double calculateAverage(int* movies, int size);
double calculateMedian(int* movies, int size);
int* calculateMode(int* movies, int size, int& numModes);
void sort(int* movies, int size);
void swap(int* a, int* b);

int main()
{
	const string FILENAME = "moviecount.txt";
	//Number of students who watch movies.
	int numStudents = 0;
	//An array of integers to store counts of movies for each student.
	int* movieCounts = nullptr;	

	//Read in the movie data
	try 
	{
		movieCounts = getMovies(numStudents, FILENAME);
	}
	//If the file cannot be opened then catch the thrown exception
	catch (const char * message) 
	{ 
		cout << message << endl;
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
	//Sort the array.
	sort(movieCounts, numStudents);
	//Set decimal places to two for average and median.
	cout << setprecision(2) << fixed << showpoint;	
	//Output
	cout << "Total number of students who watched movies is " << numStudents << endl;
	cout << "The average number of movies watched by all students is " << calculateAverage(movieCounts, numStudents) << endl;
	cout << "The median number of movies watched by all students is " << calculateMedian(movieCounts, numStudents) << endl;
	//Variable for the number of modes in the list, there could be more than one.
	int numModes = 0;	
	//Array of modes is returned and stored in modes.
	int* modes = calculateMode(movieCounts, numStudents, numModes); 
	cout << "The number of modes is " << numModes << ".\n";
	//If there is one mode then output the one mode, if there are more then output each one.
	if (numModes == 1) 
	{
		cout << "The mode number of movies watched by all students is " << *(modes);	
	}
	else
	{
		cout << "The mode numbers of movies watched by all students is ";
		for (int i = 0; i < numModes; i++) 
		{ 
			cout << *(modes+i) << " ";
		}
	}
	
    return 0;
}
//Function to get the data from the text file and place it onto a dynamic array.
int* getMovies(int& numStudents, string fileName) 
{
	//Open the file
	ifstream file(fileName);
	if (!file)
	{
		throw "Cannot open file " + fileName;
	}
	//Get the first integer which is the number of remaining integers
	file >> numStudents;
	//Create a dynamic array the size of numDonations
	int* arr = new int[numStudents];
	int value;
	int i = 0;
	while (i < numStudents && file >> value)
	{
		*(arr + i) = value;
		++i;
	}
	file.close();
	return arr;

}
//Function to calculate and return the average of the data in the array.
double calculateAverage(int * movies, int size) 
{
	double sum=0;

	for (int i = 0; i < size; ++i)
	{
		sum += *(movies + i);
	}
	return (sum/size);
}
//Function to calculate and return the median of the data in the array.
double calculateMedian(int * movies, int size) 
{
	double median;
	//Using if statements to calculate median. If size is an even number it will use the if, if it is odd it will use the else.
	if ((size % 2) == 0)
	{
		median = (((*(movies + (size / 2))) + *(movies + ((size / 2) - 1))) / 2.0);
	}
	else
	{
		median = (*(movies + (size / (2))));
	}
	
	return median;
}
//Function to calculate the mode and return the mode.
int* calculateMode(int* movies, int size, int& numModes) 
{
	//Dynamic array to hold the numbers of the mode/modes with the same possible size of the array it is taking elements from.
	int* modeArr = new int[size];
	//Integer variable representing how many elements have the same number being checked.
	int currentCount = 0;
	//Integer variable representing the number of elements that hold the mode number.
	int maxCount = 0;
	//The current element of the array being tested.
	int currentElement = *(movies);
	//The next element that will be tested against the current element.
	int nextElement = *(movies+1);
	/*
	For-loop to compare each element of the array to the next element in the array. 
	The current element should be added to the mode array when it is determined to be the most often and the number of modes should be 1 whenever there is a single mode.
	If or when the current element matches the next element the current element count should be incremented.
	If the current element count matches the max element count then the number of modes should be incremented and the mode array should have that element added.
	If the current element count surpasses the mode element then the mode array should be cleared, then add the new mode, and the number of modes should be set to 1 again.
	*/
	for (int i = 1; i <= size; i++)
	{
		
		if (currentElement == nextElement)
		{
			currentCount++;
		}
		else
		{	
			if (currentCount > maxCount)
			{
				numModes = 0;
				*(modeArr + numModes) = currentElement;
				numModes++;
				maxCount = currentCount;
			}
			else if (currentCount == maxCount)
			{
				*(modeArr + numModes) = currentElement;
				numModes++;
			}
			currentCount = 0;
		}
		currentElement = *(movies + i);
		nextElement = *(movies + (i + 1));
	}
	return modeArr;
}
//Bubble sort function.
void sort(int* movies, int size) 
{
	int i, j;
	bool swapped;
	for (i = 0; i < size - 1; i++) 
	{
		swapped = false;
		for (j = 0; j < size - i - 1; j++) 
		{
			if (*(movies+j) > *(movies+(j + 1)))
			{
				swap(*(movies+j), *(movies + (j + 1)));
				swapped = true;
			}
		}
		// If no two elements were swapped by inner loop, then break
		if (swapped == false)
			break;
	}
}
//Swap function to be used in conjunction with the bubble sort function.
void swap(int* a, int* b) 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
