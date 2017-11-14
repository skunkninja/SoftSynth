/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.3.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "AudioSetup.h"
#include "CustomMessage.h"
//[/Headers]

#include "MainComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainContentComponent::MainContentComponent ()
:juceMidiCallBack(this)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (textButton = new TextButton ("new button"));
    textButton->setButtonText (TRANS("Audio Setup"));
    textButton->addListener (this);

    addAndMakeVisible (m_HoldPlay = new TextButton ("new button2"));
    m_HoldPlay->setButtonText (TRANS("Hold To Play"));
    m_HoldPlay->addListener (this);


    //[UserPreSize]
    AudioDeviceManager::AudioDeviceSetup currentSetup;
    audioDeviceManager.initialise(2,2,NULL,true);
    audioDeviceManager.getAudioDeviceSetup(currentSetup);

    //Set current buffer size to 128, and current sample rate to 48k.
    currentSetup.bufferSize = 512;
    currentSetup.sampleRate = 48000.0;
    audioDeviceManager.setAudioDeviceSetup(currentSetup,true);

	audioDeviceManager.addAudioCallback(&juceAudioCallBack);
	audioDeviceManager.addMidiInputCallback(String::empty, &juceMidiCallBack);
    //[/UserPreSize]

    setSize (320, 480);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MainContentComponent::~MainContentComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	audioDeviceManager.removeAudioCallback(&juceAudioCallBack);
	audioDeviceManager.removeMidiInputCallback(String::empty, &juceMidiCallBack);
    //[/Destructor_pre]

    textButton = nullptr;
    m_HoldPlay = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainContentComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainContentComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    textButton->setBounds (8, 16, 120, 32);
    m_HoldPlay->setBounds (8, 56, 120, 32);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainContentComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton)
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
		CAudioSetup dlg(audioDeviceManager);

		if(DialogWindow::showModalDialog(L"Midi input device selection",
			&dlg,
			this,
			Colours::azure,true) == 1)
        {
        }
		//midioutDevice = audioDeviceManager.getDefaultMidiOutput();
        //[/UserButtonCode_textButton]
    }
    else if (buttonThatWasClicked == m_HoldPlay)
    {
        //[UserButtonCode_m_HoldPlay] -- add your button handler code here..
        //[/UserButtonCode_m_HoldPlay]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void MainContentComponent::buttonStateChanged (Button* buttonStateChanged)
{
    if (buttonStateChanged == m_HoldPlay)
    {
        juce::Button::ButtonState state = m_HoldPlay->getState();
        switch (state) {
            case juce::Button::buttonNormal:
                juceAudioCallBack.setPlayEnable(false);
                break;
            case juce::Button::buttonDown:
                juceAudioCallBack.setPlayEnable(true);
                break;
            case juce::Button::buttonOver:
                juceAudioCallBack.setPlayEnable(false);
                break;
        }
    }
}

void MainContentComponent::handleMessage(const Message& message)
{
    CCustomMessage *tmpMessage = (CCustomMessage *)&message;
    int type = tmpMessage->getType();
    
    switch (type) {
        case MSG_SOUND_ON:
            juceAudioCallBack.setPlayEnable(true);
            break;
        case MSG_SOUND_OFF:
            juceAudioCallBack.setPlayEnable(false);
            break;
        default:
            break;
    }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainContentComponent" componentName=""
                 parentClasses="public Component, public MessageListener" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="320" initialHeight="480">
  <BACKGROUND backgroundColour="ffffffff"/>
  <TEXTBUTTON name="new button" id="3a1af5155dc28d3f" memberName="textButton"
              virtualName="" explicitFocusOrder="0" pos="8 16 120 32" buttonText="Audio Setup"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button2" id="a10dd133b93ce124" memberName="m_HoldPlay"
              virtualName="" explicitFocusOrder="0" pos="8 56 120 32" buttonText="Hold To Play"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
