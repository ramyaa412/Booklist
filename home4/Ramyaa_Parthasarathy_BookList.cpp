/* Name : Ramyaa Parthasarathy
  Course:  Programming Finance
  Program : Book List
*/
#include<iostream>  //header files defined
#include<stdlib.h>
#include<iomanip>
using namespace std;

//Declaring the functions
void input();
void add(int &arraysize);
void insert(double list[], int &arraysize);
void insert_at(double list[], int &arraysize);
void delete_pos(double list[], int &arraysize);
void delete_num(double list[], int &arraysize);
void print(double list[], int &arraysize);
void sort_bubble(double *pointer, int &arraysize);
void sort_selection(double *pointer, int &arraysize);
void swap(double *pointer, int smaller, int pass);
void find_linear(double list[], int &arraysize);
void find_binary(double *pointer, int &arraysize);
const int maxvalue = 20; //define the length
int arraysize = 0, i = 0, pos;
double list[maxvalue] = { 0 }, *pointer = { 0 };

void main()
{
	input();	//call the menu function
}
void input()
{
	add(arraysize); //Have the user enter the ISBN numbers
	do 
	{
		int choice; 
		cout << "\nWelcome to the Book list program. \nWhat would you like to do?\n1. add an element to end of list\n2. add an element at a location\n3. find an element by ISBN number(linear search)\n4. find an element by ISBN number(binary search)\n5. delete an element at position\n6. delete an element by ISBN number\n7. sort the list(using selection sort)\n8. sort the list(using bubble sort)\n9. print the list\n10. exit \n\nyour choice-- - ";
		cin >> choice; //ask the user to provide their option
		
		if (choice == 10)
		{
			cout << "\n\n\t\tExiting the Program\n";
			exit(1);
		}
		else
		{
			switch (choice)
			{
			case 1: //inserting an element in the end of the list
				insert(list, arraysize); //fucntion call
				break;
			case 2:
				insert_at(list, arraysize); //inserting element at required position
				break;
			case 3:
				find_linear(list, arraysize); //linear search
				break;
			case 4:
				find_binary(pointer, arraysize); //binary search
				break;
			case 5:
				delete_pos(list, arraysize); //deleting a value depending on the position
				break;
			case 6:
				delete_num(list, arraysize); //deleting a value depending on the ISBN entered
				break;
			case 7:
				sort_selection(pointer, arraysize); //Selection sort using pointers
				break;
			case 8:
				sort_bubble(pointer, arraysize); //bubble sort using pointers
				break;
			case 9:
				print(list, arraysize); //printing the list
				break;
			default:
				cout << "\nInvalid Entry";
				break;
			}
		}
	} while (1);//always true
}

//Function definitions
void add(int &arraysize)  //initialisation of list
{

	cout << "\nEnter the number of values you want to enter : ";
	cin >> pos;
	if (pos >= maxvalue)  //Check if the value entered exceeds the list boundary
	{
		cout << "\nOut of bound\nBook list can only take upto 20 books";
		add(arraysize);
	}
	else if (pos < maxvalue)
	{
		for (int i = 0; i < pos; i++)
		{
			cout << "\nEnter ISBN number : ";
			cin >> list[i];
		}
		pointer = list; //copy the list in a pointer
		arraysize = pos;
		print(list, arraysize);//print the list
	}
}
	
void insert(double list[], int &arraysize)
{ 
	double new_element;
	if ((arraysize+1) == maxvalue)
		cout << "No place to enter more values"; //check is a new element can be added or not
	else
	{
		cout << "Enter ISBN number of book : "; //ask the user for input
		cin >> new_element;
		list[arraysize] = new_element; //place the element at the end of the array
		arraysize++; //increment the array size
		if (arraysize == maxvalue) //check if the array is now full and promt the user
		{
			cout << "The array is full now";
		}
		print(list, arraysize);//print the array
	}
	
}
void insert_at(double list[], int &arraysize)
{
	int newpos;
	double new_element;
	if ((arraysize+1) == maxvalue)   
	{
		cout << "\n List is full";   //check if the list is full and go back to menu
		input();
	}
	else
		if (arraysize == 0) //check if array is empty
	{
		cout << "\nArray is empty";
		add(arraysize); //go back to forming a list
	}
	else
	{
		cout << "\nEnter new element : ";
		cin >> new_element;
		cout << "\nEnter position : ";
		cin >> newpos;
		newpos = i+1;
		for (int i = arraysize; i > newpos; i--)  //move numbers to generate space in the location
			list[i] = list[i - 1];
		list[newpos+1] = new_element;
		arraysize++; //increment array size
		print(list, arraysize);
	}
	
}
void find_linear(double list[], int &arraysize) //linear search to find the book
{
	double element;
	cout << "\nEnter the ISBN to locate : ";
	cin >> element;
	pos = -1;
	for (i = 0; i < arraysize; i++) //for loop to search for the loop
		if (list[i] == element)
			 pos=i; //if the book is present
		
	
	if (pos != -1) //check if book was present or not
		cout << "\nThe book was Found at location" << i + 1 << endl;
	else
		cout << "\nInvalid Entry\nThe Book was Not found" << endl;
}
void find_binary(double *pointer, int &arraysize) //binary search
{
	sort_bubble(pointer, arraysize); //buuble sort is called to sort the array
	int element;
	cout << "\nEnter the ISBN to locate : ";
	cin >> element;
	int middle, low, high;
	low = 0; //assign the first term of list
	high = arraysize-1; //assign the last term
	while (low <= high) //condition is checked
	{
		middle = (low + high) / 2; //find the mid point
		if (element == *(pointer+middle)) //if value at mid point equal to required value
		{
			cout << "\nThe book with ISBN "<<element<<" found" << endl;
			cout << "\nThe book was found at the position " << middle+1<<endl;
			break;
		}
		else if (element < *(pointer+middle))  //if value smaller than value at mid point
		{
			high = middle - 1; 
		}
		else if (element > *(pointer+middle)) //if value is greater than value at mid point
		{
			low = middle + 1;
		}
		else
			cout << "\nInvalid Entry. ISBN does not exist" << endl;
				
	}
}
void swap(double *pointer, int smaller, int pass) //swapping operation
{
	double temp;
	temp = *(pointer + pass);
	*(pointer + pass) = *(pointer + smaller);
	*(pointer + smaller) = temp;
}
void sort_selection(double *pointer, int &arraysize) //selection sort
{
	double min;
	int index;
	for (int i = 0; i<arraysize - 1; i++)
	{
		min = *(pointer+i); //the first element is assigned the minimum value 
		index = i;
		for (int j = i + 1; j < arraysize; j++)
		{
			if (*(pointer + j) < min) //loop to check that minimum value to every other value and find the minimum value and its location
			{
				min = *(pointer + j);
				index = j;
			}
			swap(pointer, index, i); //calling the swap function
		}
	}
	cout << "\nThe sorted list is " << endl; //printing sorted list
	for (int i = 0; i < arraysize; i++)
	{
		cout <<i+1<<". "<<setprecision(10)<< *(pointer + i) << endl;
	}
}
void sort_bubble(double *pointer, int &arraysize)//bubble sort with early termination
{
	int flag = 1; //to optimize the bubble sort
	double temp;
	for (int i = 0; i < arraysize - 1 && flag; i++)
	{
		flag = 0;
		for (int j = 0; j < arraysize - i - 1; j++)
		{
			if (*(pointer + j) > *(pointer + j + 1)) //swapping
			{
				temp = *(pointer + j);
				*(pointer + j) = *(pointer + j + 1);
				*(pointer + j + 1) = temp;
				flag = 1; //swap occured
			}
		}
	}
	cout << "\nThe sorted list is " << endl;
	for (int i = 0; i < arraysize; i++)
	{
		cout << i+1 << ". " <<setprecision(10)<< *(pointer + i) << endl;
	}
}
void delete_pos(double list[], int &arraysize) //deleting the value at a given position
{
	int pos;
	if (arraysize == 0) //check if list is empty
	{
		cout << "\nList is empty. Deletion not possible";
		add(arraysize); //go back to adding a list
	}
	else
	{
		cout << "\nEnter the position in which you want the value to be deleted : ";
		cin >> pos;
		if (pos > arraysize) //if the position entered is greater than the array size
			cout << "\nInvalid Entry"<<endl;
		else
		{
			for (int i = pos; i < arraysize; i++) 
				list[i - 1] = list[i]; //moving the values up in the list in order to delete
			arraysize--; //decrease the array size
			print(list, arraysize);
		}
	}
	
}
void delete_num(double list[], int &arraysize) //delete number according to ISBN number
{
	double element;
	
	if (arraysize == 0)
	{
		cout << "\nList is empty. Deletion not possible"; //check if the list is empty and ask the user to form a list
		add(arraysize);
	}
	else 
	{
		cout << "\nEnter the ISBN number to be deleted : "; 
		cin >> element;
		pos = -1;
		for (int i = 0; i < arraysize; i++)
			if (list[i] == element) //if the element entered is in the list
			{
				pos = i; //assign the value of i to variable pos
				for (int i=pos; i < arraysize; i++)
					list[i] = list[i + 1]; //move the value ahead
				arraysize--; //decrement array size
				print(list, arraysize);
				break;
			}
	}
	if (pos == -1) //the element was not found
	{
		cout<<"Invalid input";
	}
	
}
void print(double list[], int &arraysize) //print the book list
{
	cout << "\nThe book list is: " << endl;
	if (arraysize == 0)
		cout << "\nNo list is generated. Please generate one";
	else
	{
		for (int i = 0; i < arraysize; i++)
			cout << i+1<< ". " << setprecision(10)<<list[i] << endl;
	}
}