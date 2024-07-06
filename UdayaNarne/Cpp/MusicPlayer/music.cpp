#include <iostream>
#include <list>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class songDetails {
private:                            //Provides Encapsulation
    string songName;
    string artistName;
    int duration;
    int rating = 0;
    int subscribers;
    stack<songDetails> likedSongs;
    vector<songDetails> likedSongsVector;

    // Constructor
public:                                         //Those Details can only be accessed by some sort of medthods
    songDetails(string name, string artist) {
        songName = name;
        artistName = artist;
        subscribers = 0;
    }

    // Function to like a song
    void LikedSong(const songDetails& song) {
        likedSongs.push(song);
        likedSongsVector.push_back(song);
        rating++;
    }

    // Function to unlike a song
    void UnlikedSong() {
        if (!likedSongs.empty()) {
            songDetails k = likedSongs.top();
            likedSongs.pop();
            rating--;
            auto it = find(likedSongsVector.begin(), likedSongsVector.end(), k);
            if (it != likedSongsVector.end()) {
                likedSongsVector.erase(it);
            }
        }
    }
    //Print the details of the particular song
    void Details(songDetails &song1){
        cout << "Song Name: " << song1.songName << endl;
        cout << "Artist Name: " << song1.artistName << endl;
        song1.LikedSong(song1);
        cout << "Rating after liking: " << song1.rating << endl;
        song1.UnlikedSong();
        cout << "Rating after unliking: " << song1.rating << endl;
    }

    // Operator overloading for equality
    bool operator==(const songDetails& other) const {
        return (songName == other.songName && artistName == other.artistName);
    }
};

int main() {
    list<songDetails> availableSongs;

    songDetails song1("Heat Waves", "Glass Animals");
    availableSongs.push_back(song1);

    song1.LikedSong(song1);
    cout << "Song Name: " << song1.songName << endl;
    cout << "Artist Name: " << song1.artistName << endl;
    cout << "Rating after liking: " << song1.rating << endl;

    song1.UnlikedSong();
    cout << "Rating after unliking: " << song1.rating << endl;

    return 0;
}
