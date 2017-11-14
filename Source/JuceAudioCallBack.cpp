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
    playEnable = false;
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

//处理录音数据/填充播放数据的回调函数
//每一帧中包含了若干个采样点。这个函数会在每一帧完成后调用。
//numSamples       - 这一帧中包含多少个采样点
//inputChannelData - 录音数据，这些数据是按通道保存的。比如说立体声(双通道)录音，
//                   则左通道在 inputChannelData[0]中,右通道在inputChannelData[1]中。
//                   左通道的第一个数据则是 inputChannelData[0][0]
//numInputChannels - 有多少个录音通道。
//outputChannelData- 要播放的数据。与录音数据结构一致，只需要按要求填充这个指针就可以得到正确的声音。
//numOutputChannels- 有多少个播放通道。

//一般而言，我们可以强行指定参数，则numSamples，numInputChannels，numOutputChannels是不会改变的。
//不过为了代码的通用性，建议在代码中加入判断。以免以后这三个值发生变化时代码无法正常工作。

void CJuceAudioCallBack::audioDeviceIOCallback (const float** inputChannelData,
                                    int numInputChannels,
                                    float** outputChannelData,
                                    int numOutputChannels,
                                    int numSamples)
{
    inputChannelData = inputChannelData;
    numInputChannels += 0;
    float sampleval;
    
    //从效率来说，一个通道一个通道的填比较好，不过这儿只是测试，就按采样来填。

    for (int i = 0; i < numSamples; ++i)
    {
        for(int j = 0;j < numOutputChannels;j++)
        {
            if(playEnable)
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
            else
            {
                outputChannelData[j][i] = 0.0f;
            }
        }
    }
}

void CJuceAudioCallBack::setPlayEnable(bool enable)
{
    playEnable = enable;
}
