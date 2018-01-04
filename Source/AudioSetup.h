/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.2.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "juce_audio_devices/juce_audio_devices.h"
#include "juce_audio_utils/juce_audio_utils.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class CAudioSetup  : public Component,
                     public ComboBox::Listener
{
public:
    //==============================================================================
    CAudioSetup (AudioDeviceManager& deviceManager_);
    ~CAudioSetup();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    AudioDeviceManager& deviceManager;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<GroupComponent> groupComponent2;
    ScopedPointer<GroupComponent> groupComponent;
    ScopedPointer<AudioDeviceSelectorComponent> component;
    ScopedPointer<Label> label;
    ScopedPointer<ComboBox> comboBox;
    ScopedPointer<Label> label2;
    ScopedPointer<ComboBox> comboBox2;
    ScopedPointer<Label> label3;
    ScopedPointer<ComboBox> comboBox3;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CAudioSetup)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
