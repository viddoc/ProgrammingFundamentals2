//Tommy Hudson Donation Sorter program
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

void selectionSort(int** ptrToElems, int size);
void displayDonations(int* donations, int size);
void displaySortedDonations(int** ptrToElems, int size);
int* getDonations(string fileName, int& numDonations);
int** createPtrArray(int* donations, int size);

const string FILENAME = "donations.txt";

int main()
{
	int numDonations = 0;
	int* donations = nullptr;
	//Create an array to hold the donations.
	try	
	{
		donations = getDonations(FILENAME, numDonations);
	}
	catch (const char* msg) 
	{ 
		cout << msg << endl; 
		exit(EXIT_FAILURE); 
	}

	//Create an array of pointers to ints.
	int** ptrDonations = createPtrArray(donations, numDonations);
	//Sort the donations.
	selectionSort(ptrDonations, numDonations);
	//Display the unsorted donations.
	cout << "\nDonations before being sorted\n";
	displayDonations(donations, numDonations);
	//Display the sorted donations.
	cout << "\nDonations after being sorted\n";
	displaySortedDonations(ptrDonations, numDonations);

	delete[] donations;
	delete[] ptrDonations;

	return 0;
}

void selectionSort(int** ptrToElems, int size)
{
	int startIndex, minIndex; // Index to start searching from and the index that contains the smallest number so far
	int* ptrMinElem; // Point to the address with the smallest value
	
	for (startIndex = 0; startIndex < size - 1; ++startIndex)
	{

		minIndex = startIndex;
		ptrMinElem = *(ptrToElems + startIndex);
		for (int index = startIndex + 1; index < size; ++index)
		{
			if (**(ptrToElems + index) < *ptrMinElem)
			{
				ptrMinElem = *(ptrToElems + index);
				minIndex = index;
			}

		} // end of inner for loop
		// swap the new min value with startIndex value
		*(ptrToElems + minIndex) = *(ptrToElems + startIndex);
		*(ptrToElems + startIndex) = ptrMinElem;
	} // end of outer for loop
}

void displayDonations(int* donations, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << *(donations + i) << endl;
	}
}

void displaySortedDonations(int** ptrToElems, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << **(ptrToElems + i) << endl;
	}
}

int* getDonations(string fileName, int& numDonations)
{
	//Open the file
	ifstream file(fileName);
	if (!file)
	{
		throw "Cannot open file " + fileName;
	}
	//Get the first integer which is the number of remaining integers
	file >> numDonations;
	//Create a dynamic array the size of numDonations
	int* arr = new int[numDonations];
	/*for (int i = ; i < numDonations; i++)
	{
		file >> *(arr + i);
	}*/
	int value;
	int i = 0;
	while (i < numDonations && file >> value)
	{
		*(arr + i) = value;
		++i;
	}
	file.close();
	return arr;
}

int** createPtrArray(int* donations, int size)
{
	int** ptrArr = new int* [size];

	for (int i = 0; i < size; ++i)
	{
		//The Value of ptrArr at i = The address of donations at i
		*(ptrArr + i) = donations + i;
	}
	return ptrArr;
}
