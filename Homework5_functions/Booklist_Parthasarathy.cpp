//
//  booklist_Parthasarathy.cpp
//  
// Class Definition
//
//

#include<iostream>
#include<iomanip>
#include "booklistparthasarathy.h"
using namespace std;


Booklist::Booklist()
{
	arraysize = 0;
	flag = 0;
	maxvalue = 20;
}

void Booklist::insert(double list[], int new_element)
{
	arraysize++;
	//Checking to see that the max size of 20 has not been exceeded
	if (arraysize <= maxvalue)
	{
		list[arraysize - 1] = new_element; //Adding element to the end
		print(list);
	}
	else
	{
		cout << "\n Out of Bounds\n Book List can only take upto 20 books";
	}
	flag = 0;
	arrayval = arraysize;
}
void Booklist::insert_at(double list[], int new_element, int position)
{
	int i = 0;
	//double new_element;
	if ((arraysize + 1) == maxvalue)
	{
		cout << "\n List is full";   //check if the list is full and go back to menu
	}
	else if (position > arraysize + 1)
		cout << "Position you want to enter exceeds the number of values in the array";
	else
	{

		arraysize++;
		if (arraysize <= maxvalue)
		{
			for (int i = arraysize - 1; i >= position; i--)
			{

				list[i] = list[i - 1]; //Shifting the elements to right 

			}
			list[position - 1] = new_element; //Adding the new element

									  //print
			print(list);
		}

	}
	flag = 0;
	arrayval = arraysize;
}
int Booklist::find_linear(double list[], int search_element) //linear search to find the book
{
	
	for (int i = 0; i < arraysize; i++) //for loop to search for the loop
	{
		if (list[i] == search_element)
			return i; //if the book is present
	}
	return -1; // if not present
}
int Booklist::find_binary(double list[], int search_element) //binary search
{
	int middle, low, high;
	low = 0; //assign the first term of list
	high = arraysize - 1; //assign the last term
	while (low <= high) //condition is checked
	{
		middle = (low + high) / 2; //find the mid point
		if (search_element == list[middle]) //if value at mid point equal to required value
		{
			return middle;
		}
		else if (search_element < *(list + middle))  //if value smaller than value at mid point
		{
			high = middle - 1;
		}
		else
		{
			low = middle + 1;
		}
		return -1;
	}
	
}
void Booklist::swap(double list[], int smaller, int pass) //swapping operation
{
	double temp = 0;
	temp = *(list + pass);
	*(list + pass) = *(list + smaller);
	*(list + smaller) = temp;
}
void Booklist::sort_selection(double list[]) //selection sort
{
	double min;
	double temp;
	int index;
	for (int i = 0; i<arraysize; i++)
	{
		min = *(list + i); //the first element is assigned the minimum value 
		index = i;
		for (int j = i + 1; j < arraysize; j++)
		{
			if (*(list + j) < min) //loop to check that minimum value to every other value and find the minimum value and its location
			{
				min = *(list + j);
				index = j;
			}
			swap(list, index, i); //calling the swap function
		}
	}
	flag = 1;
	print(list);
}
void Booklist::sort_bubble( double list[])//bubble sort with early termination
{
	int temp=0; //to optimize the bubble sort
	//double temp;
	for (int i = 0; i < arraysize - 1; i++)
	{
		for (int j = 0; j < arraysize - i - 1; j++)
		{
			if (*(list + j) > *(list + j + 1)) //swapping
			{
				temp = *(list + j);
				*(list + j) = *(list + j + 1);
				*(list + j + 1) = temp;
				
			}
		}
	}
	flag = 1; //swap occured
	print(list);
}
void Booklist::delete_pos(double list[], int pos) //deleting the value at a given position
{
	
	if (arraysize == 0) //check if list is empty
	{
		cout << "\nList is empty. Deletion not possible";
	}
	else if (pos > arraysize) //if the position entered is greater than the array size
			cout << "\nInvalid Entry" << endl;
	else
	{
		for (int i = pos; i < arraysize; i++)
				list[i - 1] = list[i]; //moving the values up in the list in order to delete
			
		}
	arraysize--; //decrease the array size
	print(list);
}

void Booklist::delete_num(double list[], int element) //delete number according to ISBN number
{
	int pos = 0;
	if (arraysize == 0)
	{
		cout << "\nList is empty. Deletion not possible"; //check if the list is empty and ask the user to form a list
	}
	else
	{
		pos = -1;
		for (int i = 0; i < arraysize; i++)
			if (list[i] == element) //if the element entered is in the list
			{
				pos = i; //assign the value of i to variable pos
				for (int i = pos; i < arraysize; i++)
					list[i] = list[i + 1]; //move the value ahead
				arraysize--; //decrement array size
				print( list);
				break;
			}
	}
	if (pos == -1) //the element was not found
	{
		cout << "Invalid Input";
	}

}
void Booklist::print(double list[]) //print the book list
{
	cout << "\nThe book list is: " << endl;
	if (arraysize == 0)
		cout << "\nNo list is generated. Please generate one";
	else
	{
		for (int i = 0; i < arraysize; i++)
			cout << i + 1 << ". " << setprecision(10) << list[i] << endl;
	}
}