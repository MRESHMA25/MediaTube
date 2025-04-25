#include "Media.h"

// Constructor: Initializes all member variables.
Media::Media(const std::string &channelTitle, const std::string &owner,
             const std::string &mediaTitle, const std::string &category,
             const std::string &audioContent, const std::string &videoFile)
    : channelTitle(channelTitle), owner(owner), mediaTitle(mediaTitle),
      category(category), audioContent(audioContent), videoFile(videoFile)
{}

// Getter for channelTitle.
const std::string& Media::getChannelTitle() const {
    return channelTitle;
}

// Getter for owner.
const std::string& Media::getOwner() const {
    return owner;
}

// Getter for mediaTitle.
const std::string& Media::getMediaTitle() const {
    return mediaTitle;
}

// Getter for category.
const std::string& Media::getCategory() const {
    return category;
}

// Getter for audioContent.
const std::string& Media::getAudioContent() const {
    return audioContent;
}

// Getter for videoFile.
const std::string& Media::getVideoFile() const {
    return videoFile;
}

void Media::print(std::ostream &ost) const {
    ost << "Channel: " << channelTitle 
        << ", Owner: " << owner 
        << ", Category: " << category 
        << ", Media Title: " << mediaTitle;
}

// Overloaded stream insertion operator calls print.
std::ostream& operator<<(std::ostream &ost, const Media &media) {
    media.print(ost);
    return ost;
}
