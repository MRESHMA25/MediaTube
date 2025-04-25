#include "MediaPlayer.h"
#include "Media.h"

void AudioPlayer::play(std::ostream &ost, const Media &m) {
    ost << m.getAudioContent();
}

void VideoPlayer::play(std::ostream &ost, const Media &m) {
    // Output the audio content.
    AudioPlayer::play(ost, m);
    
    std::ifstream file(m.getVideoFile().c_str());
    if (!file) {
        ost << "\nError: Could not open video file: " << m.getVideoFile() << "\n";
        return;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        ost << "\n" << line;
    }
    file.close();
}
