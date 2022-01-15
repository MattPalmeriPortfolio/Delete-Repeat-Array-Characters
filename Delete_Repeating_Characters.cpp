#include <iostream>
//declare functions
bool promptContinue();
//prompts user to continue, returns TRUE if they choose yes and FALSE otherwise
void bubbleSort(char*& charArray, const int size);
//bubble sorts charArray[size] by ascii decimal value.
char* deleteRepeats(char*& charArray, int& size, const char letter);
//returns a new array with all repeats of letter removed. deletes the old array. changes size to match the size of the new array.

//main
int main()
{
	using namespace std;
	//initialize variables
	char* charList, letter;
	int size = 20;
	charList = new char[size] {'a', 'b', 'b', 'a', 'c', 'd', 'a', 'b', 'z', 'x', 'v', 'f', 'z', 'v', 'x', 'y', 'y', 'e', 'f', 'u'};
	bubbleSort(charList, size);
	//begin program loop
	for (int index = 0; index < size; index++)
		cout << charList[index] << " ";
	do
	{
		cout << "\nEnter a character to remove: ";
		cin >> letter;
		charList = deleteRepeats(charList, size, letter);
		for (int index = 0; index < size; index++)
			cout << charList[index] << " ";
		cout << endl;
	} while (promptContinue());
	cout << "Goodbye!\n";
	return 0;
}
//define functions
//uses <iostream>
bool promptContinue()
{
	char next;
	std::cout << "Would you like to continue? y/n: ";
	std::cin >> next;
	if (next == 'y' || next == 'Y')
		return true;
	else
		return false;
}

void bubbleSort(char*& charArray, const int size)
{
	char temp;
	for (int end = size; end > 0; end--)
		for (int j = 0; j < end - 1; j++)
		{
			if (charArray[j] > charArray[j + 1])
			{
				temp = charArray[j + 1];
				charArray[j + 1] = charArray[j];
				charArray[j] = temp;
			}
		}
	return;
}
//uses <iostream>
char* deleteRepeats(char*& charArray, int& size, const char letter)
{
	int startIndex, endIndex;
	for (startIndex = 0; charArray[startIndex] != letter && startIndex < size; startIndex++);
	if (startIndex >= size)
	{
		std::cout << "Letter not found.\n";
		return charArray;
	}
	for (endIndex = startIndex + 1; endIndex < size && charArray[endIndex] == letter; endIndex++);
	endIndex--; //return endIndex to last letter
	if (endIndex == startIndex)
	{
		std::cout << "Only one instance of " << letter << " was found.\n";
		return charArray;
	}
	const int newSize = size - (endIndex - startIndex);
	char* newArray = new char[newSize];
	for (int oldIndex = 0, newIndex = 0; oldIndex < size && newIndex < newSize; oldIndex++)
	{
		if (oldIndex < startIndex + 1 || oldIndex > endIndex)
		{
			newArray[newIndex] = charArray[oldIndex];
			newIndex++;
		}
	}
	size = newSize;
	delete[] charArray;
	return newArray;
}