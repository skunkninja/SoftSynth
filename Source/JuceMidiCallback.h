#ifndef JUCE_MIDI_CALL_BACK_H_INCLUDE
#define JUCE_MIDI_CALL_BACK_H_INCLUDE

#include "JuceHeader.h"
#include "juce_audio_devices/juce_audio_devices.h"

enum
{
    MSG_SOUND_ON,
    MSG_SOUND_OFF,
};

class CJuceMidiCallback :
    public MidiInputCallback
{
public:
    CJuceMidiCallback(MessageListener *listener);
    ~CJuceMidiCallback(void);
    void handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message);
    //void SetSoftSynth(CMidiLayer *softSynth_);
protected:
    //CMidiLayer *pSoftSynth;
    
    MessageListener *localListener;
};

#endif
