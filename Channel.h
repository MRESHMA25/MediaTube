#ifndef CHANNEL_H
#define CHANNEL_H

#include <iostream>
#include <string>
#include "Array.h"
#include "Media.h"

class Channel {
private:
    Array<Media*> mediaArray;
    std::string title;
    std::string owner;
public:
    // Constructor
    Channel(const std::string &title, const std::string &owner);
	
	// Destructor: deletes all Media objects stored in this channel.
    ~Channel();

    // equals: returns true if the given title matches the channel's title.
    bool equals(const std::string &title) const;

    // get: returns the Media* at the given index.
    // If index is out-of-bounds, prints an error message and exits.
    Media* get(int index) const;

    // getSize: returns the number of Media items in this Channel.
    int getSize() const;

    void print(std::ostream &ost) const;

    void printWithMedia(std::ostream &ost) const;

    void add(Media* mediaPtr);
};

// Overloaded stream insertion operator to print Channel details.
std::ostream& operator<<(std::ostream &ost, const Channel &channel);

#endif // CHANNEL_H
