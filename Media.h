#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <string>

class Media {
private:
    std::string channelTitle;
    std::string owner;
    std::string mediaTitle;
    std::string category;
    std::string audioContent;
    std::string videoFile;
public:
    // Constructor: initializes all members in order.
    Media(const std::string &channelTitle, const std::string &owner,
          const std::string &mediaTitle, const std::string &category,
          const std::string &audioContent, const std::string &videoFile);

    // Getters for each member.
    const std::string& getChannelTitle() const;
    const std::string& getOwner() const;
    const std::string& getMediaTitle() const;
    const std::string& getCategory() const;
    const std::string& getAudioContent() const;
    const std::string& getVideoFile() const;

    void print(std::ostream &ost) const;
};

// Overloaded stream insertion operator that calls Media::print.
std::ostream& operator<<(std::ostream &ost, const Media &media);

#endif // MEDIA_H
