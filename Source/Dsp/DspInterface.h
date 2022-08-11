//
// Created by Lucas on 11/08/2022.
//

#ifndef ATMOSPHERE_DSP_INTERFACE_H
#define ATMOSPHERE_DSP_INTERFACE_H

#include <JuceHeader.h>

namespace atms {
    namespace dsp {
        class DspInterface {
        public:
            virtual void prepare (const juce::dsp::ProcessSpec&) = 0;
            virtual void process (const juce::dsp::ProcessContextReplacing<float>&) = 0;
            virtual void reset() = 0;

            virtual void setApvtsLayout(juce::AudioProcessorValueTreeState::ParameterLayout &layout) = 0;
        };
    }
}

#endif //ATMOSPHERE_DSP_INTERFACE_H
