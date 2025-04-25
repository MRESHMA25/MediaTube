#include "Channel.h"
#include <iostream>

Channel::Channel(const std::string &title, const std::string &owner)
    : title(title), owner(owner) {}
	
Channel::~Channel(){
    // Delete all Media objects stored in mediaArray.
    for (int i = 0; i < mediaArray.getSize(); i++) {
        delete mediaArray[i];
    }
}

bool Channel::equals(const std::string &title) const {
    return this->title == title;
}

Media* Channel::get(int index) const {
    if (index < 0 || index >= mediaArray.getSize()) {
        std::cerr << "Error: Index " << index << " out of bounds in Channel::get." << std::endl;
        exit(1);
    }
    return mediaArray[index];
}

int Channel::getSize() const {
    return mediaArray.getSize();
}

void Channel::print(std::ostream &ost) const {
    ost << "Channel Title: " << title << ", Owner: " << owner;
}

void Channel::printWithMedia(std::ostream &ost) const {
    print(ost);
    ost << std::endl;
    // Iterate over the Array and print each Media using its overloaded << operator.
    for (int i = 0; i < mediaArray.getSize(); i++) {
        ost << "  " << *(mediaArray[i]) << std::endl;
    }
}

void Channel::add(Media* mediaPtr) {
    // Uses the overloaded += operator of your Array class.
    mediaArray += mediaPtr;
}

std::ostream& operator<<(std::ostream &ost, const Channel &channel) {
    channel.print(ost);
    return ost;
}
