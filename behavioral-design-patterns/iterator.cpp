/* 
You are working on a music streaming application. The application has a playlist feature that allows users to create and 
manage playlists of _songs. Each playlist contains a collection of _songs. You need to implement an iterator for the playlist
collection that allows users to iterate over the _songs in a playlist.

Implement the Iterator design pattern to create an iterator object that can traverse the playlist collection and provide
access to its elements (_songs). The iterator should provide methods like hasNext() to check if there are more _songs in the 
playlist, and next() to retrieve the next song in the iteration.

Your task is to design the classes and implement the logic to handle the iteration over the playlist collection using the
Iterator pattern
*/

#include<iostream>
#include<memory>
#include<vector>

class Song {
    public: 
        std::string name, singer;

        Song(std::string name, std::string singer) {
            this->name = name, this->singer = singer;
        }
};

class PlaylistIterator {
    public: 
        virtual bool hasNext() const  = 0;
        virtual Song next() const = 0;
};

class Playlist {
    std::vector<Song> _songs;

    public: 
        void addSong(Song song) {
            _songs.push_back(song);
        }

        void removeSong(Song song) {
            auto itr = std::find(_songs.begin(), _songs.end(), song);
            if(itr != _songs.end()) {
                _songs.erase(itr);
            }
        }

        Song getSong(int index) const {
            return _songs[index];
        }

        std::shared_ptr<PlaylistIterator> getInorderIterator() {
            return std::shared_ptr<PlaylistIterator>(new Inorder(std::shared_ptr<Playlist>(this)));
        }

        std::shared_ptr<PlaylistIterator> getRandomIterator() {
            return std::shared_ptr<PlaylistIterator>(new Random(std::shared_ptr<Playlist>(this)));
        }

};

class Inorder: public PlaylistIterator {
        std::shared_ptr<Playlist> _playlist;

    public: 
        Inorder(std::shared_ptr<Playlist> playlist): _playlist(playlist) {}

        bool hasNext() const override {
            // logic here
            return true;
        }

        Song next() const override {
            // logic here
            return _playlist->getSong(0);
        }
};

class Random: public PlaylistIterator {
        std::shared_ptr<Playlist> _playlist;
    public: 
        Random(std::shared_ptr<Playlist> playlist): _playlist(playlist) {}

        bool hasNext() const override {
            return true;
        }

        Song next() const override {
            std::cout << "Random song generated";
            return _playlist->getSong(0);
        }
};

int main() {
    Playlist playlist;
    playlist.addSong(Song("A", "B"));
    playlist.addSong(Song("C", "D"));

    auto itr = playlist.getInorderIterator();
    itr->next();
}