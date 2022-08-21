//
// Created by Lucas on 21/08/2022.
//

#ifndef ATMOSPHERE_LOOK_AND_FEEL_H
#define ATMOSPHERE_LOOK_AND_FEEL_H

#include <JuceHeader.h>

namespace atms {
    namespace style {
        class LookAndFeel: public juce::LookAndFeel_V4 {
            void drawRotarySlider (juce::Graphics&, int x, int y, int width, int height,
                                   float sliderPosProportional, float rotaryStartAngle,
                                   float rotaryEndAngle, juce::Slider&);
        };
    }
}


#endif //ATMOSPHERE_LOOK_AND_FEEL_H
