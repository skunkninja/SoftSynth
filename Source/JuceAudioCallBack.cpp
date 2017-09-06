#include "JuceAudioCallBack.h"
#include "DSP_Instruction.h"

CJuceAudioCallBack::CJuceAudioCallBack(void)
{
	int i;
	for (i = 0; i < numElementsInArray(sinVal); i++)
	{
		sinVal[i] = sin(i*3.1415926 * 4 / numElementsInArray(sinVal));
	}
	leftIndex = rightIndex = 0;
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
				int *pval = nullptr;
				switch (j)
				{
				case 0:
					pval = &leftIndex;
					sampleval = sinVal[*pval];
					break;
				case 1:
					pval = &rightIndex;
					sampleval = sinVal[*pval/2];
					break;
				default:
					break;
				}

				if (pval == nullptr)
				{
					break;
				}
				(*pval)++;
				
				*pval = DSP_LOOP(*pval, 0, numElementsInArray(sinVal));
                outputChannelData[j][i] = sampleval;
            }
        }
    }
}