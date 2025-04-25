#include "MediaTube.h"
#include "Channel.h"
#include "Media.h"
#include "Search.h"
#include <iostream>


MediaTube::~MediaTube() {
    for (int i = 0; i < channels.getSize(); i++) {
        delete channels[i];
    }
}

void MediaTube::addChannel(Channel* channel) {
    channels += channel;
}

void MediaTube::addMedia(Media* media, const std::string& channelTitle) {
    bool found = false;
    // Iterate through channels to find the one with the matching title.
    for (int i = 0; i < channels.getSize(); i++) {
        if (channels[i]->equals(channelTitle)) {
            channels[i]->add(media);
            found = true;
            break;
        }
    }
    if (!found) {
        std::cerr << "Error: Channel with title '" << channelTitle << "' not found." << std::endl;
    }
}

const Array<Channel*>& MediaTube::getChannels() const {
    return channels;
}

Channel* MediaTube::getChannel(int index) const {
    if (index < 0 || index >= channels.getSize()) {
        std::cerr << "Error: Channel index " << index << " out of bounds." << std::endl;
        exit(1);
    }
    return channels[index];
}

Channel* MediaTube::getChannel(const std::string& title) const {
    for (int i = 0; i < channels.getSize(); i++) {
        if (channels[i]->equals(title)) {
            return channels[i];
        }
    }
    std::cerr << "Error: Channel with title '" << title << "' not found." << std::endl;
    exit(1);
}

void MediaTube::getMedia(const Search& search, Array<Media*>& outArray) const {
    // For every Channel in MediaTube.
    for (int i = 0; i < channels.getSize(); i++) {
        Channel* channel = channels[i];
        // For each Media in the Channel.
        for (int j = 0; j < channel->getSize(); j++) {
            Media* media = channel->get(j);
            if (search.matches(media)) {
                outArray += media;
            }
        }
    }
}
