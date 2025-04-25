#ifndef MEDIATUBE_H
#define MEDIATUBE_H

#include <iostream>
#include <string>
#include "Array.h"
#include "Channel.h"
#include "Media.h"
#include "Search.h"

class MediaTube {
private:
    Array<Channel*> channels;
public:
	~MediaTube();
    // Adds a Channel pointer to the MediaTube.
    void addChannel(Channel* channel);

    // Adds a Media pointer to the Channel with the given title.
    // If the Channel does not exist, outputs an error message.
    void addMedia(Media* media, const std::string& channelTitle);

    // Returns a const reference to the Array of Channels.
    const Array<Channel*>& getChannels() const;

    // Returns the Channel pointer at the given index.
    // If the index is invalid, outputs an error message and exits.
    Channel* getChannel(int index) const;

    // Returns the Channel pointer with the given title.
    // If not found, outputs an error message and exits.
    Channel* getChannel(const std::string& title) const;

    // Populates outArray with all Media pointers from every Channel that match the Search criteria.
    void getMedia(const Search& search, Array<Media*>& outArray) const;
};

#endif // MEDIATUBE_H
