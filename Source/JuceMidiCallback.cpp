#include "JuceMidiCallback.h"


CJuceMidiCallback::CJuceMidiCallback(void)
{
}


CJuceMidiCallback::~CJuceMidiCallback(void)
{
}

void CJuceMidiCallback::handleIncomingMidiMessage(MidiInput* source, const MidiMessage& message)
{
    (void *)source;
    if(message.isSysEx())//sysex message.
    {
    }
    else
    {
        if(message.isNoteOn())
        {
        }
        else if(message.isNoteOff())
        {
        }
    }
}

