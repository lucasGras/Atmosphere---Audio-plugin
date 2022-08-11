//
// Created by Lucas on 11/08/2022.
//

#include "BlurProcessor.h"

atms::dsp::BlurProcessor::BlurProcessor() {

}

atms::dsp::BlurProcessor::~BlurProcessor() {

}

void atms::dsp::BlurProcessor::prepare(const juce::dsp::ProcessSpec &spec) {
    this->processor.prepare(spec);
}

void atms::dsp::BlurProcessor::process(const juce::dsp::ProcessContextReplacing<float> &context) {
    this->processor.process(context);
}

void atms::dsp::BlurProcessor::reset() {
    this->processor.reset();
}

void atms::dsp::BlurProcessor::setApvtsLayout(juce::AudioProcessorValueTreeState::ParameterLayout &layout) {
    auto lowPassFilterRange = juce::NormalisableRange<float>(
    200.0f,
    20000.0f,
    1.0f
    );
    layout.add(std::make_unique<juce::AudioParameterFloat>(
        "BlurLowPassFilter",
        "BlurLowPassFilter",
        lowPassFilterRange,
        20000.0f
    ));
}

atms::dsp::BlurProcessor::Parameters
atms::dsp::BlurProcessor::getParameters(juce::AudioProcessorValueTreeState &apvts) {
    Parameters parameters;

    parameters.filterFrequency = apvts.getRawParameterValue("BlurLowPassFilter")->load();
    return parameters;
}

void atms::dsp::BlurProcessor::setParameters(atms::dsp::BlurProcessor::Parameters parameters, juce::dsp::ProcessSpec spec) {
    // TODO Add Q equalization param
    this->processor.state = juce::dsp::IIR::Coefficients<float>::makeLowPass(
    spec.sampleRate,
    parameters.filterFrequency
    );
}
