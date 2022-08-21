/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AtmosphereAudioProcessorEditor::AtmosphereAudioProcessorEditor (AtmosphereAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    juce::LookAndFeel::setDefaultLookAndFeel(&laf);

    this->slider.setSliderStyle(juce::Slider::SliderStyle::Rotary);
    this->slider.setRange(0.0f, 100.0f);
    this->slider.setValue(0.0f);
    this->slider.setTextBoxStyle(juce::Slider::NoTextBox, true, 100, 25);
    addAndMakeVisible(this->slider);


    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

AtmosphereAudioProcessorEditor::~AtmosphereAudioProcessorEditor()
{
}

//==============================================================================
void AtmosphereAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
}

void AtmosphereAudioProcessorEditor::resized()
{
    this->slider.setBounds(getWidth() / 2 - 100, getHeight() / 2 - 100, 200, 200);
}
