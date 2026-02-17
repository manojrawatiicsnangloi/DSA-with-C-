#include <iostream>
#include <list>
#include <string>

struct Song {
    int id;
    std::string title;
    std::string artist;
    int duration; // in seconds

    Song(int i, std::string t, std::string a, int d)
        : id(i), title(t), artist(a), duration(d) {}
};

int main() {
    std::list<Song> playlist;
    // Add songs
    playlist.push_back(Song(101, "Shape of You", "Ed Sheeran", 240));
    playlist.push_back(Song(102, "Blinding Lights", "The Weeknd", 200));
    playlist.push_back(Song(103, "Levitating", "Dua Lipa", 220));

    // Insert a song at the beginning
    playlist.push_front(Song(100, "Bad Guy", "Billie Eilish", 194));

    // Remove a song (by id)
    playlist.remove_if([](Song s){ return s.id == 102; }); // removes "Blinding Lights"

    // Display playlist
    for (const auto& song : playlist) {
        std::cout << song.id << " - " 
                  << song.title << " by " 
                  << song.artist 
                  << " (" << song.duration << "s)" 
                  << std::endl;
    }

    return 0;
}
