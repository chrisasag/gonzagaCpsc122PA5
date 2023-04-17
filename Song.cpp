#include "Song.h"

// TODO: finish this function
// This function convert string to lower case string
string convertToLowercase(string s) {
	int length = s.length();
	for (int i=0; i < length;i++){
		if(s.at(i) >= 'A' && s.at(i) <= 'Z'){
			s.at(i) += 32;
		}
	}
	return s;
}

// TODO: finish Song default value constructor
Song::Song() {
	title = "";
	artist = "";
	genre = "";
	rating = 1;
}

// TODO: finish Song explicit value constructor
// EVC: all string parameters are convert to lower case
Song::Song(string titleParam, string artistParam, string genreParam, int ratingParam) {
	title = convertToLowercase(titleParam);
	artist = convertToLowercase(artistParam);
	genre = convertToLowercase(genreParam);
	setRating(ratingParam);
}

string Song::getTitle() {
	return title;
}

void Song::setTitle(string newTitle) {
	title = convertToLowercase(newTitle);
}

string Song::getArtist() {
	return artist;
}

void Song::setArtist(string newArtist) {
	artist = convertToLowercase(newArtist);
}

string Song::getGenre() {
	return genre;
}

void Song::setGenre(string newGenre) {
	genre = convertToLowercase(newGenre);
}

int Song::getRating() {
	return rating;
}

void Song::setRating(int newRating) {
	if (newRating < MIN_RATING || newRating > MAX_RATING) {
		cout << "Rating must be in [" << MIN_RATING << ", " << MAX_RATING << "]" << endl;
	}
	if (newRating < MIN_RATING) {
		rating = MIN_RATING;
	}
	else if (newRating > MAX_RATING) {
		rating = MAX_RATING;
	}
	else {
		rating = newRating;
	}
}

// TODO: finish this function
// member function of Song, display object
void Song::displaySong() {
	cout << "Title: " << title << endl;
	cout << "Artist: " << artist << endl;
    cout << "Genre: " << genre << endl;
    cout << "Rating: " << rating << endl;
}

// TODO: finish this function
// This member function return attribute of song
string Song::getStringAttributeValue(string attribute) {
	if(attribute ==  "title"){
		return getTitle();
	} else if (attribute == "artist") {
        return getArtist();
    } else if (attribute == "genre") {
        return getGenre();
    } else if (attribute == "rating") {
		// change int type to string type to avoid extra boolean contral statement when sorting song library
        return to_string(getRating());
    } else {
        return "";
    }
}