/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Style/LookAndFeel.h"

//==============================================================================
/**
*/
class AtmosphereAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    AtmosphereAudioProcessorEditor (AtmosphereAudioProcessor&);
    ~AtmosphereAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AtmosphereAudioProcessor& audioProcessor;

    // Custom GUI
    atms::style::LookAndFeel laf;
    juce::Slider slider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AtmosphereAudioProcessorEditor)
};
