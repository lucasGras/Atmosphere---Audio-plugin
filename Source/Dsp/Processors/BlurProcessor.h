//
// Created by Lucas on 11/08/2022.
//

#ifndef ATMOSPHERE_BLUR_PROCESSOR_H
#define ATMOSPHERE_BLUR_PROCESSOR_H

#include "../DspInterface.h"

namespace atms {
    namespace dsp {
        class BlurProcessor: public DspInterface {
        public:
            struct Parameters {
                float lowPassFilterCutoff = 20000.0f;
            };

            BlurProcessor();
            ~BlurProcessor();

            void prepare(const juce::dsp::ProcessSpec& spec) override;
            void process(const juce::dsp::ProcessContextReplacing<float>& context) override;
            void reset() override;

            void setApvtsLayout(juce::AudioProcessorValueTreeState::ParameterLayout &layout) override;

            Parameters getParameters(juce::AudioProcessorValueTreeState& apvts);

        private:
            juce::dsp::ProcessorDuplicator<
                juce::dsp::IIR::Filter<float>,
                juce::dsp::IIR::Coefficients<float>
            > processor;
        };
    }
}


#endif //ATMOSPHERE_BLUR_PROCESSOR_H
