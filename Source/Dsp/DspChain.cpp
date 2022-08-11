//
// Created by Lucas on 11/08/2022.
//

#include "DspChain.h"

atms::dsp::DspChain::DspChain() {

}

atms::dsp::DspChain::~DspChain() {

}


void atms::dsp::DspChain::prepareChain(const juce::dsp::ProcessSpec &spec) {
    this->chain.prepare(spec);
}

void atms::dsp::DspChain::processChain(const juce::dsp::ProcessContextReplacing<float> &context) {
    this->chain.process(context);
}

void atms::dsp::DspChain::updateChainParameters(atms::dsp::DspChain::ChainSettings parameters) {

}

juce::AudioProcessorValueTreeState::ParameterLayout atms::dsp::DspChain::getApvtsLayout() {
    juce::AudioProcessorValueTreeState::ParameterLayout layout;

    this->chain.get<Blur>().setApvtsLayout(layout);

    return layout;
}

atms::dsp::DspChain::ChainSettings atms::dsp::DspChain::getChainSettings(juce::AudioProcessorValueTreeState& apvts) {
    ChainSettings settings;

    settings.blurParameters = this->chain.get<Blur>().getParameters(apvts);
    return settings;
}

void atms::dsp::DspChain::resetChain() {

}