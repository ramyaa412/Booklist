/*
  Program : Booklist_Parthasarathy.h
  Subject : Programmin Finance
  Program : Class-HW-6
			Class Declaration
  */


// preprocessor directive definition
#ifndef BOOKLISTPARTHASARATHY_H
#define BOOKLISTPARTHASARATHY_H

//Class declaration
class Booklist 
{
private: //access specifier
	int arraysize;
	int maxvalue;
public:
	Booklist(); //constructor protoype
	void insert(double[], int );
	void insert_at(double[], int,int);
	void delete_pos( double[], int);
	void delete_num(double[], int);
	void print( double[]);
	void sort_bubble(double[]);
	void sort_selection( double []);
	void swap(double[], int, int);
	int find_linear(double[],int);
	int find_binary(double[],int);
	int flag;
	int arrayval;
};

#endif // !BOOKLISTHEADER_H