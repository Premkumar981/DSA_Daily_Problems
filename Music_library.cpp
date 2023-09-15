#include <iostream>
#include <vector>
#include <algorithm>

class MusicLibrary {
public:
    MusicLibrary() {}

    void addSong(const std::string& songName, const std::string& artist) {
        songs.push_back(std::make_pair(songName, artist));
    }

    void displaySortedSongs() {
        std::sort(songs.begin(), songs.end(), [](const Song& a, const Song& b) {
            return a.second < b.second; // Sort by artist name
        });

        for (const auto& song : songs) {
            std::cout << song.first << " - " << song.second << std::endl;
        }
    }

private:
    using Song = std::pair<std::string, std::string>;
    std::vector<Song> songs;
};

int main() {
    int N;
    std::cout << "Enter the number of songs in the library: ";
    std::cin >> N;
    std::cin.ignore(); // Clear newline from the input buffer

    MusicLibrary library;

    for (int i = 0; i < N; i++) {
        std::string songName, artist;
        std::cout << "Enter song name: ";
        std::getline(std::cin, songName);
        std::cout << "Enter artist: ";
        std::getline(std::cin, artist);
        library.addSong(songName, artist);
    }

    std::cout << "Sorted songs:" << std::endl;
    library.displaySortedSongs();

    return 0;
}

