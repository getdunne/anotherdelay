#pragma once

#include "JuceHeader.h"
#include "PluginProcessor.h"

class AnotherDelayAudioProcessorEditor : public AudioProcessorEditor
{
public:
    AnotherDelayAudioProcessorEditor (AnotherDelayAudioProcessor&);
    virtual ~AnotherDelayAudioProcessorEditor() = default;

    void paint (Graphics&) override;
    void resized() override;
	bool getReverbToggleState() { return reverbEnabledButton.getToggleState(); };

private:
    AnotherDelayAudioProcessor& processor;

	Slider delayTimeSlider;
	Slider gainSlider;
	Slider feedbackSlider;
	Slider wetDrySlider;
	Slider filterCutOffSlider;
	Slider filterCutOffSliderHi;
	Slider flutterFreqSlider;
	Slider flutterDepthSlider;
	Slider wowFreqSlider;
	Slider wowDepthSlider;
	
	TextButton reverbEnabledButton;
	Slider roomSizeSlider;
	Slider dampingSlider;
	Slider widthSlider;

	Label delayTimeLabel;
	Label gainLabel;
	Label feedbackLabel;
	Label wetDryLabel;
	Label filterCutOffLabel;
	Label filterCutOffLabelHi;
	Label flutterFreqLabel;
	Label flutterDepthLabel;
	Label wowFreqLabel;
	Label wowDepthLabel;
	Label roomSizeLabel;
	Label dampingLabel;
	Label widthLabel;

	AudioProcessorValueTreeState::SliderAttachment delayTimeAttachment;
	AudioProcessorValueTreeState::SliderAttachment gainAttachment;
	AudioProcessorValueTreeState::SliderAttachment feedbackAttachment;
	AudioProcessorValueTreeState::SliderAttachment wetDryAttachment;
	AudioProcessorValueTreeState::SliderAttachment filterCutOffAttachment;
	AudioProcessorValueTreeState::SliderAttachment filterCutOffHiAttachment;
	AudioProcessorValueTreeState::SliderAttachment flutterFreqAttachment;
	AudioProcessorValueTreeState::SliderAttachment flutterDepthAttachment;
	AudioProcessorValueTreeState::SliderAttachment wowFreqAttachment;
	AudioProcessorValueTreeState::SliderAttachment wowDepthAttachment;
	
	AudioProcessorValueTreeState::ButtonAttachment reverbEnabledAttachment;
	AudioProcessorValueTreeState::SliderAttachment roomSizeAttachment;
	AudioProcessorValueTreeState::SliderAttachment dampingAttachment;
	AudioProcessorValueTreeState::SliderAttachment widthAttachment;

	juce::Rectangle<int> delayRectangle;
	juce::Rectangle<int> filterRectangle;
	juce::Rectangle<int> modRectangle;
	juce::Rectangle<int> reverbRectangle;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AnotherDelayAudioProcessorEditor)
};
