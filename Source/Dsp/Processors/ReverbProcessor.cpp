//
// Created by Lucas on 11/08/2022.
//

#include "ReverbProcessor.h"

atms::dsp::ReverbProcessor::ReverbProcessor() {

}

atms::dsp::ReverbProcessor::~ReverbProcessor() {

}

void atms::dsp::ReverbProcessor::prepare(const juce::dsp::ProcessSpec &spec) {
    this->processor.prepare(spec);
}

void atms::dsp::ReverbProcessor::process(const juce::dsp::ProcessContextReplacing<float> &context) {
    this->processor.process(context);
}

void atms::dsp::ReverbProcessor::reset() {
    this->processor.reset();
}


void atms::dsp::ReverbProcessor::setApvtsLayout(juce::AudioProcessorValueTreeState::ParameterLayout &layout) {
    auto reverbStrengthRange = juce::NormalisableRange<float>(0.0f, 100.0f, 0.2f);

    layout.add(std::make_unique<juce::AudioParameterBool>(
        "RevLoop",
        "RevLoop",
        false
    ));
    layout.add(std::make_unique<juce::AudioParameterFloat>(
        "RevStrength",
        "RevStrength",
        reverbStrengthRange,
        0.0f
    ));
}

atms::dsp::ReverbProcessor::Parameters
atms::dsp::ReverbProcessor::getParameters(juce::AudioProcessorValueTreeState &apvts) {
    Parameters parameters;

    parameters.loop = apvts.getRawParameterValue("RevLoop")->load();
    parameters.strength = apvts.getRawParameterValue("RevStrength")->load();
    return parameters;
}

/**
 * Atms Loop parameter affect juce::dsp::Reverb::Parameters::freezeMode
 * Atms strenght [0; 100] parameter affect:
 * - juce roomSize [0; 1] +
 * - juce wetLevel [0; 1] ++
 * - juce dryLevel [0; 1] --
 * @param parameters
 * @param spec
 */
void atms::dsp::ReverbProcessor::setParameters(atms::dsp::ReverbProcessor::Parameters parameters,
                                               juce::dsp::ProcessSpec spec) {
    juce::dsp::Reverb::Parameters baseReverbParameters = {};

    (void)spec;
    baseReverbParameters.freezeMode = parameters.loop ? 1.0f : 0.0f;
    baseReverbParameters.dryLevel = -parameters.strength / 100;
    baseReverbParameters.wetLevel = parameters.strength;
    baseReverbParameters.roomSize = 0.1f + ((parameters.strength - 10) / 100);
    this->processor.setParameters(baseReverbParameters);
}