#include "JuceMidiCallback.h"
#include "CustomMessage.h"

CJuceMidiCallback::CJuceMidiCallback(MessageListener *listener, CJuceAudioCallBack *audiocallback)
{
    localListener = listener;
	localaudiocallback = audiocallback;
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
			localaudiocallback->setPlayEnable(true);
        }
        else if(message.isNoteOff())
        {
            pMsg = new CCustomMessage(MSG_SOUND_OFF, 0, 0, 0, NULL);//
            localListener->postMessage(pMsg);
			localaudiocallback->setPlayEnable(false);
        }
    }
}

