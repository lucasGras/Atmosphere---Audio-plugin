//
// Created by Lucas on 11/08/2022.
//

#ifndef ATMOSPHERE_DSPCHAIN_H
#define ATMOSPHERE_DSPCHAIN_H

#include "Processors/BlurProcessor.h"

namespace atms {
    namespace dsp {
        class DspChain {
        public:

            struct ChainSettings {
                BlurProcessor::Parameters blurParameters;
            };

            enum ChainProcessors {
                Blur,
            };

            DspChain();
            ~DspChain();

            void prepareChain(const juce::dsp::ProcessSpec& spec);
            void processChain(const juce::dsp::ProcessContextReplacing<float>& context);
            void resetChain();

            void updateChainParameters(ChainSettings parameters);
            juce::AudioProcessorValueTreeState::ParameterLayout getApvtsLayout();

        private:
            ChainSettings getChainSettings(juce::AudioProcessorValueTreeState& apvts);

        private:
            juce::dsp::ProcessorChain<BlurProcessor> chain;
        };
    }
}


#endif //ATMOSPHERE_DSPCHAIN_H
