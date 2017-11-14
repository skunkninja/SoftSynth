#ifndef JUCE_AUDIO_CALL_BACK_H_INCLUDE
#define JUCE_AUDIO_CALL_BACK_H_INCLUDE

#include "JuceHeader.h"
#include "juce_audio_devices/juce_audio_devices.h"

class JUCE_API CJuceAudioCallBack :
    public AudioIODeviceCallback
{
public:
    CJuceAudioCallBack(void);
    virtual ~CJuceAudioCallBack(void);

    //void SetSoftSynth(CMidiLayer *softSynth_);
    /** Processes a block of incoming and outgoing audio data.

        The subclass's implementation should use the incoming audio for whatever
        purposes it needs to, and must fill all the output channels with the next
        block of output data before returning.

        The channel data is arranged with the same array indices as the channel name
        array returned by AudioIODevice::getOutputChannelNames(), but those channels
        that aren't specified in AudioIODevice::open() will have a null pointer for their
        associated channel, so remember to check for this.

        @param inputChannelData     a set of arrays containing the audio data for each
                                    incoming channel - this data is valid until the function
                                    returns. There will be one channel of data for each input
                                    channel that was enabled when the audio device was opened
                                    (see AudioIODevice::open())
        @param numInputChannels     the number of pointers to channel data in the
                                    inputChannelData array.
        @param outputChannelData    a set of arrays which need to be filled with the data
                                    that should be sent to each outgoing channel of the device.
                                    There will be one channel of data for each output channel
                                    that was enabled when the audio device was opened (see
                                    AudioIODevice::open())
                                    The initial contents of the array is undefined, so the
                                    callback function must fill all the channels with zeros if
                                    its output is silence. Failing to do this could cause quite
                                    an unpleasant noise!
        @param numOutputChannels    the number of pointers to channel data in the
                                    outputChannelData array.
        @param numSamples           the number of samples in each channel of the input and
                                    output arrays. The number of samples will depend on the
                                    audio device's buffer size and will usually remain constant,
                                    although this isn't guaranteed, so make sure your code can
                                    cope with reasonable changes in the buffer size from one
                                    callback to the next.
    */
    void audioDeviceIOCallback (const float** inputChannelData,
                                        int numInputChannels,
                                        float** outputChannelData,
                                        int numOutputChannels,
                                        int numSamples) override;

    /** Called to indicate that the device is about to start calling back.

        This will be called just before the audio callbacks begin, either when this
        callback has just been added to an audio device, or after the device has been
        restarted because of a sample-rate or block-size change.

        You can use this opportunity to find out the sample rate and block size
        that the device is going to use by calling the AudioIODevice::getCurrentSampleRate()
        and AudioIODevice::getCurrentBufferSizeSamples() on the supplied pointer.

        @param device       the audio IO device that will be used to drive the callback.
                            Note that if you're going to store this this pointer, it is
                            only valid until the next time that audioDeviceStopped is called.
    */
    void audioDeviceAboutToStart (AudioIODevice* device) override;

    /** Called to indicate that the device has stopped. */
    void audioDeviceStopped() override;
    
    void setPlayEnable(bool enable);
protected:
    //CMidiLayer *pSoftSynth;
	float sinVal[96];
	int leftIndex, rightIndex;
    bool playEnable;
};

#endif
