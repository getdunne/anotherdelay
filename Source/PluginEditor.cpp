#include "PluginProcessor.h"
#include "PluginEditor.h"

AnotherDelayAudioProcessorEditor::AnotherDelayAudioProcessorEditor (AnotherDelayAudioProcessor& p)
    : AudioProcessorEditor (&p)
    , processor (p)
    , delayTimeSlider(Slider::RotaryVerticalDrag, Slider::TextBoxBelow)
    , gainSlider(Slider::RotaryVerticalDrag, Slider::TextBoxBelow)
    , feedbackSlider(Slider::RotaryVerticalDrag, Slider::TextBoxBelow)
    , wetDrySlider(Slider::RotaryVerticalDrag, Slider::TextBoxBelow)
    , filterCutOffSlider(Slider::RotaryVerticalDrag, Slider::TextBoxBelow)
    , filterCutOffSliderHi(Slider::RotaryVerticalDrag, Slider::TextBoxBelow)
    , flutterFreqSlider(Slider::RotaryVerticalDrag, Slider::TextBoxBelow)
    , flutterDepthSlider(Slider::RotaryVerticalDrag, Slider::TextBoxBelow)
    , wowFreqSlider(Slider::RotaryVerticalDrag, Slider::TextBoxBelow)
    , wowDepthSlider(Slider::RotaryVerticalDrag, Slider::TextBoxBelow)
    , reverbEnabledButton("Enabled")
    , roomSizeSlider(Slider::RotaryVerticalDrag, Slider::TextBoxBelow)
    , dampingSlider(Slider::RotaryVerticalDrag, Slider::TextBoxBelow)
    , widthSlider(Slider::RotaryVerticalDrag, Slider::TextBoxBelow)
    , delayTimeLabel({}, "Delay Time")
    , gainLabel({}, "Gain (dB)")
    , feedbackLabel({}, "Feedback (dB)")
    , wetDryLabel({}, "Mix")
    , filterCutOffLabel({}, "Low Pass")
    , filterCutOffLabelHi({}, "High Pass")
    , flutterFreqLabel({}, "Flutter Freq")
    , flutterDepthLabel({}, "Flutter Depth")
    , wowFreqLabel({}, "Wow Freq")
    , wowDepthLabel({}, "Wow Depth")
    , roomSizeLabel({}, "Room Size")
    , dampingLabel({}, "Damping")
    , widthLabel({}, "Width")
    , delayTimeAttachment(p.getValueTreeState(), Parameters::delaytime.toString(), delayTimeSlider)
    , gainAttachment(p.getValueTreeState(), Parameters::gain.toString() , gainSlider)
    , feedbackAttachment(p.getValueTreeState(), Parameters::feedback.toString(), feedbackSlider)
    , wetDryAttachment(p.getValueTreeState(), Parameters::mix.toString(), wetDrySlider)
    , filterCutOffAttachment(p.getValueTreeState(), Parameters::lowpass.toString(), filterCutOffSlider)
    , filterCutOffHiAttachment(p.getValueTreeState(), Parameters::highpass.toString(), filterCutOffSliderHi)
    , flutterFreqAttachment(p.getValueTreeState(), Parameters::flutterfreq.toString(), flutterFreqSlider)
    , flutterDepthAttachment(p.getValueTreeState(), Parameters::flutterdepth.toString(), flutterDepthSlider)
    , wowFreqAttachment(p.getValueTreeState(), Parameters::wowfreq.toString(), wowFreqSlider)
    , wowDepthAttachment(p.getValueTreeState(), Parameters::wowdepth.toString(), wowDepthSlider)
    , reverbEnabledAttachment(p.getValueTreeState(), Parameters::reverbenabled.toString(), reverbEnabledButton)
    , roomSizeAttachment(p.getValueTreeState(), Parameters::roomsize.toString(), roomSizeSlider)
    , dampingAttachment(p.getValueTreeState(), Parameters::damping.toString(), dampingSlider)
    , widthAttachment(p.getValueTreeState(), Parameters::width.toString(), widthSlider)
{
	addAndMakeVisible(delayTimeSlider);
	delayTimeSlider.setRange(1, 4);

	addAndMakeVisible(delayTimeLabel);
	delayTimeLabel.setJustificationType(Justification::centred);
	delayTimeLabel.attachToComponent(&delayTimeSlider, false);

	addAndMakeVisible(gainSlider);
	gainSlider.setRange(0.0f, 1.0f);
	gainLabel.setJustificationType(Justification::centred);
	gainLabel.attachToComponent(&gainSlider, false);

	addAndMakeVisible(feedbackSlider);
	feedbackSlider.setRange(-45.0, -12.0);
	feedbackLabel.setJustificationType(Justification::centred);
	feedbackLabel.attachToComponent(&feedbackSlider, false);

	addAndMakeVisible(wetDrySlider);
	wetDrySlider.setRange(0.0f, 1.0f);
	wetDryLabel.setJustificationType(Justification::centred);
	wetDryLabel.attachToComponent(&wetDrySlider, false);

	addAndMakeVisible(filterCutOffSlider);
	filterCutOffSlider.setRange(400.0f, 21000.0f);
	filterCutOffSlider.setSkewFactorFromMidPoint(600);
	filterCutOffLabel.setJustificationType(Justification::centred);
	filterCutOffLabel.attachToComponent(&filterCutOffSlider, false);

	addAndMakeVisible(filterCutOffSliderHi);
	filterCutOffSliderHi.setRange(400.0f, 21000.0f);
	filterCutOffSliderHi.setSkewFactorFromMidPoint(600);
	filterCutOffLabelHi.setJustificationType(Justification::centred);
	filterCutOffLabelHi.attachToComponent(&filterCutOffSliderHi, false);

	addAndMakeVisible(flutterFreqSlider);
	flutterFreqSlider.setRange(2.5f, 5.0f);
	flutterFreqLabel.setJustificationType(Justification::centred);
	flutterFreqLabel.attachToComponent(&flutterFreqSlider, false);

	addAndMakeVisible(flutterDepthSlider);
	flutterDepthSlider.setRange(-0.2f, 0.2f);
	flutterDepthLabel.setJustificationType(Justification::centred);
	flutterDepthLabel.attachToComponent(&flutterDepthSlider, false);

	addAndMakeVisible(wowFreqSlider);
	wowFreqSlider.setRange(0.0f, 2.5f);
	wowFreqLabel.setJustificationType(Justification::centred);
	wowFreqLabel.attachToComponent(&wowFreqSlider, false);

	addAndMakeVisible(wowDepthSlider);
	wowDepthSlider.setRange(-0.2f, 0.2f);
	wowDepthLabel.setJustificationType(Justification::centred);
	wowDepthLabel.attachToComponent(&wowDepthSlider, false);

	addAndMakeVisible(roomSizeSlider);
	roomSizeSlider.setRange(0.f, 1.f);
	roomSizeLabel.setJustificationType(Justification::centred);
	roomSizeLabel.attachToComponent(&roomSizeSlider, false);

	addAndMakeVisible(dampingSlider);
	dampingSlider.setRange(0.f, 1.f);
	dampingLabel.setJustificationType(Justification::centred);
	dampingLabel.attachToComponent(&dampingSlider, false);

	addAndMakeVisible(widthSlider);
	widthSlider.setRange(0.f, 1.f);
	widthLabel.setJustificationType(Justification::centred);
	widthLabel.attachToComponent(&widthSlider, false);

	addAndMakeVisible(reverbEnabledButton);
	reverbEnabledButton.setClickingTogglesState(true);
    reverbEnabledButton.setToggleState(true, dontSendNotification);

    setSize(900, 300);
}

void AnotherDelayAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
	g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));

	g.setColour(Colours::silver);
    g.setFont(Font(Font::getDefaultSansSerifFontName(), 18.f, 3));
	//g.setFont(18.0f);

	g.drawRoundedRectangle(delayRectangle.toFloat(), 5, 1);
	g.drawRoundedRectangle(filterRectangle.toFloat(), 5, 1);
	g.drawRoundedRectangle(modRectangle.toFloat(), 5, 1);
	g.drawRoundedRectangle(reverbRectangle.toFloat(), 5, 1);

	g.setColour(Colours::darkgoldenrod);
	g.drawFittedText("Delay", delayRectangle.reduced(3), Justification::topRight, 1);
	g.drawFittedText("EQ", filterRectangle.reduced(3), Justification::topRight, 1);
	g.drawFittedText("Flutter & Wow", modRectangle.reduced(3), Justification::topRight, 1);
	g.drawFittedText("Reverb", reverbRectangle.reduced(3), Justification::topRight, 1);
	
}

void AnotherDelayAudioProcessorEditor::resized()
{
	delayRectangle = getLocalBounds().reduced(180, 5);
	delayRectangle.reduce(150, 5);
	delayRectangle.translate(-315, 0);

	filterRectangle = getLocalBounds().reduced(200, 5);
	filterRectangle.reduce(180, 5);
	filterRectangle.translate(-90, 0);

	modRectangle = getLocalBounds().reduced(180, 5);
	modRectangle.reduce(150, 5);
	modRectangle.translate(135, 0);

	reverbRectangle = getLocalBounds().reduced(200, 5);
	reverbRectangle.reduce(180, 5);
	reverbRectangle.translate(360, 0);
		
	gainSlider.setBounds(delayRectangle.reduced(82, 90).translated(-65, -45));
	delayTimeSlider.setBounds(delayRectangle.reduced(82, 90).translated(65, -45));
	feedbackSlider.setBounds(delayRectangle.reduced(82, 90).translated(-65, 85));
	wetDrySlider.setBounds(delayRectangle.reduced(82, 90).translated(65, 85));

	filterCutOffSlider.setBounds(filterRectangle.reduced(32, 89).translated(0, -45));
	filterCutOffSliderHi.setBounds(filterRectangle.reduced(32, 89).translated(0, 85));
	
	flutterFreqSlider.setBounds(modRectangle.reduced(82, 90).translated(-65, -45));
	flutterDepthSlider.setBounds(modRectangle.reduced(82, 90).translated(65, -45));
	wowFreqSlider.setBounds(modRectangle.reduced(82, 90).translated(-65, 85));
	wowDepthSlider.setBounds(modRectangle.reduced(82, 90).translated(65, 85));

	reverbEnabledButton.setBounds(reverbRectangle.reduced(25, 128).translated(0, -100));
	roomSizeSlider.setBounds(reverbRectangle.reduced(40, 99).translated(0, -20));
	dampingSlider.setBounds(reverbRectangle.reduced(40, 99).translated(-35, 95));
	widthSlider.setBounds(reverbRectangle.reduced(40, 99).translated(35, 95));
}
