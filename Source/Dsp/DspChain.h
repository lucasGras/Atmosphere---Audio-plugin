//
// Created by Lucas on 11/08/2022.
//

#ifndef ATMOSPHERE_DSP_CHAIN_H
#define ATMOSPHERE_DSP_CHAIN_H

#include "Processors/BlurProcessor.h"
#include "Processors/ReverbProcessor.h"

namespace atms {
    namespace dsp {
        class DspChain {
        public:

            struct ChainSettings {
                BlurProcessor::Parameters blurParameters;
                ReverbProcessor::Parameters reverbParameters;
            };

            enum ChainProcessors {
                Blur,
                Reverb
            };

            DspChain();
            ~DspChain();

            void prepareChain(const juce::dsp::ProcessSpec& spec);
            void processChain(const juce::dsp::ProcessContextReplacing<float>& context);
            void resetChain();

            void updateChainParameters(juce::AudioProcessorValueTreeState &apvts);
            juce::AudioProcessorValueTreeState::ParameterLayout getApvtsLayout();

        private:
            ChainSettings getChainSettings(juce::AudioProcessorValueTreeState& apvts);

        private:
            juce::dsp::ProcessorChain<BlurProcessor, ReverbProcessor> chain;
            juce::dsp::ProcessSpec spec;
        };
    }
}


#endif //ATMOSPHERE_DSP_CHAIN_H
