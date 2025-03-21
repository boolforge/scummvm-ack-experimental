/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef ACK_SOUND_H
#define ACK_SOUND_H

#include "common/scummsys.h"
#include "common/str.h"
#include "audio/mixer.h"
#include "audio/audiostream.h"

namespace Ack {

class AckEngine;

/**
 * Sound manager for ACK engine
 * Handles sound effects and music playback
 */
class Sound {
private:
    AckEngine *_vm;
    Audio::Mixer *_mixer;
    
    // Sound handles for different channels
    Audio::SoundHandle _soundHandles[4];
    
    // Music state
    bool _musicPlaying;
    int _currentMusic;
    
public:
    Sound(AckEngine *vm);
    ~Sound();
    
    // Sound playback
    void playSound(const Common::String &name, byte channel);
    void stopSound(byte channel);
    
    // Music playback
    void playMusic(int musicId);
    void stopMusic();
    bool isMusicPlaying() const { return _musicPlaying; }
    
    // Volume control
    void setVolume(byte volume);
    
    // Resource management
    bool loadSound(int soundId);
    void unloadSound(int soundId);
};

} // End of namespace Ack

#endif // ACK_SOUND_H
