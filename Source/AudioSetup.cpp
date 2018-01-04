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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "AudioSetup.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
CAudioSetup::CAudioSetup (AudioDeviceManager& deviceManager_)
    : deviceManager(deviceManager_)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (groupComponent2 = new GroupComponent ("new group",
                                                             TRANS("Tone generator setup")));

    addAndMakeVisible (groupComponent = new GroupComponent ("new group",
                                                            TRANS("Audio device setup")));

    addAndMakeVisible (component = new AudioDeviceSelectorComponent (deviceManager, 0, 2, 0, 2, true, true, true, false));
    component->setName ("new component");

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Tone generator buffer size:")));
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (Label::textColourId, Colours::white);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (comboBox = new ComboBox ("new combo box"));
    comboBox->setEditableText (false);
    comboBox->setJustificationType (Justification::centredLeft);
    comboBox->setTextWhenNothingSelected (String());
    comboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox->addItem (TRANS("256"), 1);
    comboBox->addItem (TRANS("512"), 2);
    comboBox->addItem (TRANS("1024"), 3);
    comboBox->addListener (this);

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("Thread number:")));
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (comboBox2 = new ComboBox ("new combo box"));
    comboBox2->setEditableText (false);
    comboBox2->setJustificationType (Justification::centredLeft);
    comboBox2->setTextWhenNothingSelected (String());
    comboBox2->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox2->addItem (TRANS("1"), 1);
    comboBox2->addItem (TRANS("2"), 2);
    comboBox2->addItem (TRANS("3"), 3);
    comboBox2->addItem (TRANS("4"), 4);
    comboBox2->addListener (this);

    addAndMakeVisible (label3 = new Label ("new label",
                                           TRANS("Tone generator numbers per thread:")));
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (comboBox3 = new ComboBox ("new combo box"));
    comboBox3->setEditableText (false);
    comboBox3->setJustificationType (Justification::centredLeft);
    comboBox3->setTextWhenNothingSelected (String());
    comboBox3->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox3->addItem (TRANS("32"), 1);
    comboBox3->addItem (TRANS("64"), 2);
    comboBox3->addItem (TRANS("128"), 3);
    comboBox3->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 600);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

CAudioSetup::~CAudioSetup()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    groupComponent2 = nullptr;
    groupComponent = nullptr;
    component = nullptr;
    label = nullptr;
    comboBox = nullptr;
    label2 = nullptr;
    comboBox2 = nullptr;
    label3 = nullptr;
    comboBox3 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void CAudioSetup::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff001836));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void CAudioSetup::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    groupComponent2->setBounds (8, 504, 576, 88);
    groupComponent->setBounds (8, 0, 576, 504);
    component->setBounds (16, 16, 560, 480);
    label->setBounds (16, 520, 184, 24);
    comboBox->setBounds (208, 520, 88, 24);
    label2->setBounds (368, 520, 112, 24);
    comboBox2->setBounds (488, 520, 64, 24);
    label3->setBounds (240, 552, 240, 24);
    comboBox3->setBounds (488, 552, 64, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void CAudioSetup::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBox)
    {
        //[UserComboBoxCode_comboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox]
    }
    else if (comboBoxThatHasChanged == comboBox2)
    {
        //[UserComboBoxCode_comboBox2] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox2]
    }
    else if (comboBoxThatHasChanged == comboBox3)
    {
        //[UserComboBoxCode_comboBox3] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox3]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="CAudioSetup" componentName=""
                 parentClasses="public Component" constructorParams="AudioDeviceManager&amp; deviceManager_"
                 variableInitialisers="deviceManager(deviceManager_)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="600" initialHeight="600">
  <BACKGROUND backgroundColour="ff001836"/>
  <GROUPCOMPONENT name="new group" id="542e7422abe0aec9" memberName="groupComponent2"
                  virtualName="" explicitFocusOrder="0" pos="8 504 576 88" title="Tone generator setup"/>
  <GROUPCOMPONENT name="new group" id="1222bd71541cf06c" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="8 0 576 504" title="Audio device setup"/>
  <GENERICCOMPONENT name="new component" id="29e3f1f9451b331e" memberName="component"
                    virtualName="AudioDeviceSelectorComponent" explicitFocusOrder="0"
                    pos="16 16 560 480" class="Component" params="deviceManager, 0, 2, 0, 2, true, false, true, false"/>
  <LABEL name="new label" id="5cd9a1d9edd1faf4" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="16 520 184 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Tone generator buffer size:"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" kerning="0" bold="0" italic="0"
         justification="33"/>
  <COMBOBOX name="new combo box" id="b05cbf188f7829b6" memberName="comboBox"
            virtualName="" explicitFocusOrder="0" pos="208 520 88 24" editable="0"
            layout="33" items="256&#10;512&#10;1024" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="cafc622874d86d1" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="368 520 112 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Thread number:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="7d6c8153f5c57891" memberName="comboBox2"
            virtualName="" explicitFocusOrder="0" pos="488 520 64 24" editable="0"
            layout="33" items="1&#10;2&#10;3&#10;4" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="7c1bebf3130d00af" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="240 552 240 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Tone generator numbers per thread:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="13fcce3e8814443d" memberName="comboBox3"
            virtualName="" explicitFocusOrder="0" pos="488 552 64 24" editable="0"
            layout="33" items="32&#10;64&#10;128" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
