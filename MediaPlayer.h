#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <iostream>
#include "Media.h"
#include <fstream>

class MediaPlayer {
public:
    // Pure virtual function to play a Media object.
    virtual void play(std::ostream &ost, const Media &m) = 0;
    
    // Virtual destructor.
    virtual ~MediaPlayer() {}
    
    // Overloaded << operator: plays the given Media using std::cout.
    MediaPlayer& operator<<(const Media &m) {
        play(std::cout, m);
        return *this;
    }
};

class AudioPlayer : public MediaPlayer {
public:
    // Overrides play to output Media audio content.
    virtual void play(std::ostream &ost, const Media &m);
};

class VideoPlayer : public AudioPlayer {
public:
    // Overrides play to output Media audio content and then display video file content.
    virtual void play(std::ostream &ost, const Media &m);
};

#endif // MEDIAPLAYER_H
