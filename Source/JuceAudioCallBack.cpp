#include "JuceAudioCallBack.h"


CJuceAudioCallBack::CJuceAudioCallBack(void)
{
}


CJuceAudioCallBack::~CJuceAudioCallBack(void)
{
}

void CJuceAudioCallBack::audioDeviceAboutToStart (AudioIODevice* device)
{
	(void *)device;
}

void CJuceAudioCallBack::audioDeviceStopped()
{
}

void CJuceAudioCallBack::audioDeviceIOCallback (const float** inputChannelData,
                                    int numInputChannels,
                                    float** outputChannelData,
                                    int numOutputChannels,
                                    int numSamples)
{
    inputChannelData = inputChannelData;
    numInputChannels += 0;
    float sampleval;
    for (int i = 0; i < numSamples; ++i)
    {
        for(int j = 0;j < numOutputChannels;j++)
        {
            if (outputChannelData[j] != 0)
            {
                sampleval = 0.0f;
                outputChannelData[j][i] = sampleval;
            }
        }
    }
}