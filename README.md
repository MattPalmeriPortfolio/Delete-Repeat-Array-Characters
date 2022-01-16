# Delete-Repeat-Array-Characters

Contents
---------------------
* File Contents
* Introduction
* Algorithm
* Requirements

## File Contents
	
	Delete_Repeating_Characters.cpp (program file containing code)

## Introduction
Book practice project from Problem Solving With C++ Chapter 9. Project 2.
A program that deletes the repeated characters specified in an array, and returns a new dynamic array fit to size. Demonstrates ability to work with dynamic arrays and clean data in c++.
Written using Microsoft Visual Studio. 

## Algorithm

	1. Start with a new dynamic array of chars, for simplicity, with an int var initialized to its size; create manually as program does not need input of values
		1a. run a bubble sort to sort the values in the array, using ascii decimal comparison
		1b. program will however take input of which char to delete, for ease of testing, so output array to screen and get input of which repeats to remove
	2. Return a new array with the repeats removed
		2a. find the first instance of the char in the array; this will be the startIndex
			2aa. if not found, output an error message and exit the function without changing anything
		2b. set endIndex to startIndex; from startIndex, iterate endIndex to end of array or until last repeat is found
			2ba. if only one instance of the char is found (startIndex == endIndex - 1) output an error message and exit the function without changing anything
		2c. newSize = old size - (# of instances of char - 1)
		2d. create new dynamic array of size newSize
		2e. ignoring the chars between (startIndex +  1) and endIndex, add the elements of oldArray to newArray
		2f. delete old array and return new array;
	3. Output new array - routine
	4. Prompt to continue - routine

## Requirements
No requirements or modules needed for running this program.
