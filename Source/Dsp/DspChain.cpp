//
// Created by Lucas on 11/08/2022.
//

#include "DspChain.h"

atms::dsp::DspChain::DspChain() {
    this->spec = {};
}

atms::dsp::DspChain::~DspChain() {

}


void atms::dsp::DspChain::prepareChain(const juce::dsp::ProcessSpec &spec) {
    this->spec = spec;
    this->chain.prepare(spec);
}

void atms::dsp::DspChain::processChain(const juce::dsp::ProcessContextReplacing<float> &context) {
    this->chain.process(context);
}

void atms::dsp::DspChain::updateChainParameters(juce::AudioProcessorValueTreeState& apvts) {
    ChainSettings settings = this->getChainSettings(apvts);

    this->chain.get<Blur>().setParameters(settings.blurParameters, this->spec);
    this->chain.get<Reverb>().setParameters(settings.reverbParameters, this->spec);
}

juce::AudioProcessorValueTreeState::ParameterLayout atms::dsp::DspChain::getApvtsLayout() {
    juce::AudioProcessorValueTreeState::ParameterLayout layout;

    this->chain.get<Blur>().setApvtsLayout(layout);
    this->chain.get<Reverb>().setApvtsLayout(layout);
    return layout;
}

atms::dsp::DspChain::ChainSettings atms::dsp::DspChain::getChainSettings(juce::AudioProcessorValueTreeState& apvts) {
    ChainSettings settings;

    settings.blurParameters = this->chain.get<Blur>().getParameters(apvts);
    settings.reverbParameters = this->chain.get<Reverb>().getParameters(apvts);
    return settings;
}

void atms::dsp::DspChain::resetChain() {

}