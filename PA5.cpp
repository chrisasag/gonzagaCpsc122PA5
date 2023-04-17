#include "PA5.h"

void displayMenu() {
	cout << endl << "Welcome to the CPSC 122 Music Manager!!" << endl;
	cout << "Please choose from the following options: " << endl;
	cout << "1) Display library" << endl;
	cout << "2) Load library" << endl;
	cout << "3) Store library" << endl;
	cout << "4) Sort library" << endl;
	cout << "5) Search library" << endl;
	cout << "6) Add song to library" << endl;
	cout << "7) Remove song from library" << endl;
	cout << "8) Edit song in library" << endl;
	cout << "9) Quit" << endl;
}

int getValidChoice() {
	int choice = -1;
	string temp;
	do {
		cout << "Choice: ";
		cin >> choice;
		if (choice < FIRST_OPTION || choice > LAST_OPTION) {
			cout << "That is not a valid option. Please try again." << endl;
		}
	} while (choice < FIRST_OPTION || choice > LAST_OPTION);
	getline(cin, temp); // flush the newline outta the buffer
	return choice;
}



void executeUserChoice(int choice, SongLibrary& lib) {

	string inPut1 = "", inPut2 = ""; 
	Song  foundSong;
	int foundIndex, removeIndex;
	bool found = false;
	string currTitle, currArtist, currGenre;
	int currRating, indexToedit;

	switch (choice) {
		case 1:
			lib.displayLibrary();
			cout << "number of songs in library: " << lib.getNumSongs() << endl;
			break;
		case 2:
			// TODO: call a helper member function, something like lib.loadLibrary();
			//get user input for input file name
			cout << "input file name: " << endl;
			getline(cin, inPut1);
			lib.performLoad(inPut1);	
			break;

		case 3: 
			// TODO: call a helper member function, something like lib.saveLibrary();
			//get user input for output file name
			cout << "what is your output file name: " << endl;
			getline(cin, inPut1);
			lib.performSave(inPut1);
			break;

		case 4:
			// TODO: call a helper member function, something like lib.sortLibrary();
			cout << "what attribute do you want to sort?(title, artist, genre or rating)" << endl;
			getline(cin, inPut1);
			lib.performSort(inPut1);
			break;
		case 5:
			// TODO: call a helper member function, something like lib.searchLibrary();
			cout << "What attribute do you want to search(title, artist, genre or rating): " << endl;
			getline(cin, inPut1);
			cout << "what do you want to search? " << endl;
			getline(cin, inPut2);
			found = lib.performSearch(inPut1, inPut2, &foundSong, &foundIndex);
			if(found){
				cout << "Song found at index: " << foundIndex << endl;
				foundSong.displaySong();
			}
			else{
				cout << "Song not found" << endl;
			}

			break;
		case 6:
		 	// TODO: call a helper member function, something like lib.addSongToLibrary();
			cout << "Enter the title of the song that you want to add: " << endl;
			getline(cin, currTitle);
			cout << "Enter the artist of the song that you want to add: " << endl;
			getline(cin, currArtist);
			cout << "Enter the genre of the song that you want to add: " << endl;
			getline(cin, currGenre);
			cout << "Enter the rating of the song that you want to add: " << endl;
			cin >> currRating;
			foundSong = Song(currTitle, currArtist, currGenre, currRating);
			lib.performAddSong(foundSong);
			cout << currTitle << " " << currArtist << " " << currGenre << " " << currRating << " " << endl;
		 	break;

		case 7:
			// TODO: call a helper member function, something like lib.removeSongFromLibrary();
			cout << "Tell me the index of the song you want to remove: " << endl;
			cin >> removeIndex;
			lib.performRemoveSong(removeIndex);
			break;

		case 8:
			// TODO: call a helper member function, something like lib.editSongInLibrary();
			cout << "Tell me the index of the song you want to edit: " << endl;
			cin >> indexToedit;
			cout << "What attribute of the song you want to change(title, artist, genre or rating)? " << endl;
			cin >> inPut1;
			cout << "What do you want to change?" << endl;
			cin >> inPut2;
			lib.performEditSong(indexToedit, inPut1, inPut2);
			break;
		default:
			cout << "Unrecognized menu choice" << endl;
			break;
	}
}

void runMusicManager() {
	SongLibrary lib;
	
	int choice = -1;
	do {
		displayMenu();
		choice = getValidChoice();
		if (choice != QUIT_OPTION) {
			executeUserChoice(choice, lib);
		}
	} while (choice != QUIT_OPTION);
	cout << "Thanks for you using the CPSC 122 Music Manager!!" << endl;
}
