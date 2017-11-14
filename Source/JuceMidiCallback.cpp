#include "JuceMidiCallback.h"
#include "CustomMessage.h"

CJuceMidiCallback::CJuceMidiCallback(MessageListener *listener)
{
    localListener = listener;
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
        Message *pMsg;
        if(message.isNoteOn())
        {

            pMsg = new CCustomMessage(MSG_SOUND_ON, 0, 0, 0, NULL);//
            localListener->postMessage(pMsg);
        }
        else if(message.isNoteOff())
        {
            pMsg = new CCustomMessage(MSG_SOUND_OFF, 0, 0, 0, NULL);//
            localListener->postMessage(pMsg);
        }
    }
}

