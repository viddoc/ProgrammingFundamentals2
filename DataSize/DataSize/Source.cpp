//Tommy Hudson
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

template<class T> void displayLine(string title, T& data);
void displayLineForPtrChar(string title, char*& data);

int main()
{
	char aChar = 'A';
	short aShort = 2;
	int aInt = 4;
	long aLong = 6;
	long long aReallyLong = 8;
	float aCokeFloat = 10.25f;
	double trouble = 20.50;

	char* pChar = &aChar;
	short* pShort = &aShort;
	int* pInt = &aInt;
	long* pLong = &aLong;
	long long* pReallyLong = &aReallyLong;
	float* pCokeFloat = &aCokeFloat;
	double* pTrouble = &trouble;
	int** ppInt = &pInt;

	cout << "Data type sizes and addresses.\n\n";
	cout << setw(24) << "Data type\n" << setw(24) << "& variable name" << setw(6) << "Size"
		<< setw(18) << "Address" << setw(18) << "Value\n";

	displayLine("char aChar", aChar);
	displayLine("short aShort", aShort);
	displayLine("int aInt", aInt);
	displayLine("long aLong", aLong);
	displayLine("long long aReallyLong", aReallyLong);
	displayLine("float aCokeFloat", aCokeFloat);
	displayLine("double trouble", trouble);
	cout << endl;

	displayLineForPtrChar("char* pChar", pChar);
	displayLine("short* pShort", pShort);
	displayLine("int* pInt", pInt);
	displayLine("long* pLong", pLong);
	displayLine("long long* pReallyLong", pReallyLong);
	displayLine("float* pCokeFloat", pCokeFloat);
	displayLine("double* ptrouble", pTrouble);
	displayLine("int** ppInt", ppInt);

	return 0;
}

template<class T>
void displayLine(string title, T& data)
{
	cout << setw(24) << title << setw(6) << sizeof(data) << setw(18) << static_cast<void*>(&data) << setw(18) << data << endl;
}


void displayLineForPtrChar(string title, char*& data)
{
	cout << setw(24) << title << setw(6) << sizeof(data) << setw(18) << static_cast<void*>(&data) << setw(18) << static_cast<void*>(data) << endl;
}

