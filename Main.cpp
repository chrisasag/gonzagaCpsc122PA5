#include "PA5.h"

/*
 Name:Haohan Liu
 Class: CPSC 122, Spring 2023
 Programming Assignment 5
 Description: This program reads song data from a file and save them in an dynamically allocated array. Each song
 have four features: title, artist, genre and rating. The user can remove, add, edit each song in the song library.
 This program also allow user to sort songs by their feactures, display the song library and store them in a file.

 Notes:I use software development method to solve this project, and I use code-compile-test method to finish functions step by step.
I learned that it is necessary to use member functions to access private attributes in a class. 
Additionally, when switching from using getline to infile >>, it is important to release any buffer that might have been used. 
Another important practice is to set any pointers to NULL after deleting the only element in an array, such as the song array.
*/
int main() {
	runMusicManager();

	return 0;
}
