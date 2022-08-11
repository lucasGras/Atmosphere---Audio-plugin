//
// Created by Lucas on 11/08/2022.
//

#ifndef ATMOSPHERE_REVERB_PROCESSOR_H
#define ATMOSPHERE_REVERB_PROCESSOR_H

#include "../DspInterface.h"

namespace atms {
    namespace dsp {
        class ReverbProcessor: public DspInterface {
        public:
            struct Parameters {
                bool loop = false;
                float strength = 0.0f;
            };

            ReverbProcessor();
            ~ReverbProcessor();

            void prepare(const juce::dsp::ProcessSpec& spec) override;
            void process(const juce::dsp::ProcessContextReplacing<float>& context) override;
            void reset() override;

            void setApvtsLayout(juce::AudioProcessorValueTreeState::ParameterLayout &layout) override;

            Parameters getParameters(juce::AudioProcessorValueTreeState& apvts);
            void setParameters(Parameters parameters, juce::dsp::ProcessSpec spec);

        private:
            juce::dsp::Reverb processor;
        };
    }
}

#endif //ATMOSPHERE_REVERB_PROCESSOR_H
