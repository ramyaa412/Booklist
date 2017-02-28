//
//  Main_Parthasarathy.cpp

#include<iostream>
using namespace std;
#include "BooklistParthasarathy.h"
#include "Main_Parthasarathy.h"

int main()
{
	Booklist book;
	double list[20];
	int choice = 0;
	int position=0;
	double new_element = 0;
	double search_element=0;
	int pos = 0;
	int element = 0;
	
	do
	{
		cout << "\nWelcome to the Book numberlist program. \nWhat would you like to do?\n1. add an element to end of list\n2. add an element at a location\n3. find an element by ISBN number(linear search)\n4. find an element by ISBN number(binary search)\n5. delete an element at position\n6. delete an element by ISBN number\n7. sort the list(using selection sort)\n8. sort the list(using bubble sort)\n9. print the list\n10. exit \n\nyour choice-- - ";
		cin >> choice; //ask the user to provide their option

			switch (choice)
			{
			case 1: //inserting an element in the end of the list
			{
				int a = 0;
				cout << "\nEnter the ISBN of the book you want to add : ";
				cin >> new_element;
				a = book.find_linear(list, new_element); //function call
				if (a != -1)
				{
					cout << "\n The book with this ISBN already exists";
				}
				else
				{
					book.insert(list, new_element);
				}
				break;
			}
			case 2:
			{
				int a = 0;
				cout << "\nEnter the new element you want to insert : ";
				cin >> new_element;
				cout << "\nEnter the position you want to add this element : ";
				cin >> position;
				a = book.find_linear(list, new_element);
				if (a = !- 1)
					cout << "\n The book with this ISBN already exists.";
				else
					book.insert_at(list,new_element,position); //inserting element at required position
				break;
			}
			case 3:
			{
				int i = 0;
				cout << "\n Enter the element you want to search : ";
				cin >> search_element;
				//Getting the position as a return value from the function.
				i = book.find_linear(list, search_element);
				//Displaying the search result
				if (i == -1)
					cout << "\n Invalid Entry\nThe book was not found\n";
				else
					cout << "\n The ISBN you requested is found at position : " << i + 1;
				break;
			}
			case 4:
			{
				int i = 0;
				//Checking the sort flag to verify that the list is sorted/not
				if (book.flag != 1)
				{
					cout << "\n The list is not sorted. To use binary search, sort the list first\n";
				}

				//if it is sorted already,
				else
				{
					cout << "\n Enter the element you want to search : ";
					cin >> search_element;
					i = book.find_binary(list, search_element);
					//Displaying the result
					if (i == -1)
						cout << "\nInvalid Entry\n The ISBN does not exist";
					else
						cout << "\n The ISBN you requested is found at position : " << i + 1;
				}

				break;

			}
		
			case 5:
			{
				//Check to verify that the list is not empty
				if (book.arrayval == 0)
				{
					cout << "\n There are no elements present to delete \n";
				}
				//If it's not empty,
				else
				{
					cout << "\n Enter the position you want to delete :";
					cin >> pos;
					book.delete_pos(list, pos);
				}
				break;
			}
	
			case 6:
			{
				//Check to verify that the list is not empty
				if (book.arrayval == 0)
				{
					cout << "\n There are no elements present to delete \n";
				}
				//If it's not empty,
				else
				{
					cout << "\n Enter the ISBN you want to delete : ";
					cin >> element;
					book.delete_num(list, element);

				}
				break;

			}
			case 7:
				book.sort_selection(list); //Selection sort using pointers
				break;
			case 8:
				book.sort_bubble(list); //bubble sort using pointers
				break;
			case 9:
				book.print(list); //printing the list
				break;
			case 10:
				cout << "\n\n\t\tExiting the Program\n";
				exit(1);
			default:
				cout << "\nInvalid Entry";
				break;
			}
		} while (1);//always true


	return 0;
}