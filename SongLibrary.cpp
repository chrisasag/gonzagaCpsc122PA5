#include "SongLibrary.h"

SongLibrary::SongLibrary() {
	// initialize to empty list
	numSongs = 0;
	songs = NULL; 
}

// TODO: finish SongLibrary destructor
// SongLibrary destructor, deallocate songs array, set songs pointer to null, set numSongs to zero
SongLibrary::~SongLibrary() {
	delete [] songs;
	songs = NULL;
	numSongs = 0;
}

int SongLibrary::getNumSongs() {
	return numSongs;
}

void SongLibrary::setNumSongs(int newNumSongs) {
	numSongs = newNumSongs;
}

Song * SongLibrary::getSongsArray() {
	return songs;
}

void SongLibrary::setSongsArray(Song * newSongsArr) {
	if (songs != NULL) {
		delete [] songs;
	}
	songs = newSongsArr;
}

// TODO: finish this function
// display all the songs that stored in the songs array
void SongLibrary::displayLibrary() {
	for(int i=0; i< numSongs; i++){
		cout << "Song No." << i << endl;
		songs[i].displaySong();
		cout << endl << endl;
	}
}

// TODO: finish this function
// This member function read songs from a txt file then store all the songs in a dynamically allocated array
void SongLibrary::performLoad(string filename) {

	//deallocate any existing song array
	delete[] songs;
	songs = NULL;
	numSongs = 0;

	//open the file to read:
	ifstream infile;
	infile.open(filename);

	if(!infile.is_open()){
		cout << "Can not open the input file" << endl;
	}
	
	string line;// to release buffer  

	string currtitle = "", currartist = "", currgenre = "";
	int currrating = 0;

	while(!infile.eof()){ 
		getline(infile, currtitle);
		getline(infile, currartist);
		getline(infile, currgenre);
		infile >> currrating;
		getline(infile, line);//release the buffer
		infile.ignore();
		infile.ignore();

		//new song object
		Song currSong(currtitle, currartist, currgenre, currrating);
		//call the add function to add song to array
		performAddSong(currSong);
		
	}
	infile.close();
	
}

// TODO: finish this function
// this member function save curr songlibrary to an txt file
void SongLibrary::performSave(string filename) {
	ofstream outfile(filename);
	for(int i=0; i < numSongs; i++){
		outfile << songs[i].getTitle() << endl;
        outfile << songs[i].getArtist() << endl;
        outfile << songs[i].getGenre() << endl;
        outfile << songs[i].getRating() << endl;
        outfile << endl;
	}
	outfile.close();
}

// TODO: finish this function
// This member function sort the existing song library by arrtibutes 
void SongLibrary::performSort(string attribute) {

	//check if the arrtribute is valid
	if(attribute!= "title" && attribute != "artist" && attribute != "genre" && attribute != "rating"){
		cout << "Invalid attribute to sort" << endl;
	}

	//sorting alogrithm from stackoverflow
	string song1="", song2 = "";
	int mInindex = 0;
	for(int i=0;i<numSongs-1;i++){
		mInindex = i;
		for(int j=i+1;j<numSongs;j++){
			song1 = songs[j].getStringAttributeValue(attribute);
			song2 = songs[mInindex].getStringAttributeValue(attribute);
			if(convertToLowercase(song1) < convertToLowercase(song2)){
				mInindex = j;
			}
		}

		//swap mini song to the front
		Song currsong;
		currsong = songs[i];
		songs[i] = songs[mInindex];
		songs[mInindex] = currsong;
	}
	
}

// TODO: finish this function
// This member function searches the song library for a song with the given attribute value pair.
// If a matching song is found, the function returns true and sets the foundSong pointer to the matching Song object,
// If no matching song is found, the function returns false and sets the index pointer to -1.
bool SongLibrary::performSearch(string searchAttribute, string searchAttributeValue, Song * foundSong, int * index) {
	string currValue = "";
	for (int i = 0; i < numSongs; i++) {
        currValue = songs[i].getStringAttributeValue(searchAttribute);
        if (currValue == searchAttributeValue) {
            *foundSong = songs[i];
            *index = i;
            return true;
        }
    }
    *index = -1;
    return false;
	
}

// TODO: finish this function
// this Songlibrary function dynamically allocates a new array, copy every element in the old array to the new array
// then deallocate the old array and add the new song to the end of the end array
void SongLibrary::performAddSong(Song newSong) {

	//dynamically allocate a new array that is larger than the previous array
	Song * newSongs = new Song[numSongs + 1];

	//copy all the songs to the newSongs array
	for(int i=0; i<numSongs; i++){
		newSongs[i] = songs[i];
	}

	//add the new song to the end of the newSong array
	newSongs[numSongs] = newSong;

	//deallocate the old song array
	delete[] songs;

	songs = newSongs;

	//update number of songs
	numSongs ++;
}

// TODO: finish this function
// This member function remove a song from the song library and update the number of songs 
void SongLibrary::performRemoveSong(int indexToRemove) {
	//check if its a valid index to remove
	if(indexToRemove < 0 || indexToRemove >= numSongs){
		cout << "invalid index" << endl;
		return;
	}

	//dynamically allocate a new array with smaller size
	Song *newSongs = new Song[numSongs-1];

	//copy songs from old array to the new array
	int i,j;
	for(i=0, j=0;i < numSongs;i++){
		if(i != indexToRemove){
			newSongs[j] = songs[i];
			j++;
		}
	}

	//deallocate the old array
	delete [] songs;

	//very important! set the song pointer to null after the only song in songlibrary deleted
	if(numSongs <= 1){
		songs = NULL;
	}
	else{
		//update pointer to new array
		songs = newSongs;}

	//number of songs -1
	numSongs --;
}

// TODO: finish this function
//This member function find the song by index and call setter function of song class to edit
void SongLibrary::performEditSong(int indexToEdit, string attribute, string newAttributeValue) {	
	if(indexToEdit < 0 || indexToEdit >= numSongs){
		cout << "Invalid index." << endl;
		return;
	}

	int newrating;
	if(attribute == "title"){
		songs[indexToEdit].setTitle(newAttributeValue);
    } 
	else if (attribute == "artist") {
        songs[indexToEdit].setArtist(newAttributeValue);
    } 
	else if (attribute == "genre") {
       	songs[indexToEdit].setGenre(newAttributeValue);
    } 
	else if (attribute == "rating") {
		newrating = stoi(newAttributeValue);//convert string to int
		songs[indexToEdit].setRating(newrating);
	}
	else{
		cout << "Invalid attribute" << endl;
		return;
	}

	cout << "Song edit successfully" << endl;

}
