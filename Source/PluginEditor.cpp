/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Pfmproject0AudioProcessorEditor::Pfmproject0AudioProcessorEditor (Pfmproject0AudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

Pfmproject0AudioProcessorEditor::~Pfmproject0AudioProcessorEditor()
{
    //processor.shouldPlaySound->beginChangeGesture();
    //processor.shouldPlaySound->setValueNotifyingHost(false);
    //processor.shouldPlaySound->endChangeGesture();
    
    Pfmproject0AudioProcessor::UpdateAutomatableParameter(processor.shouldPlaySound, false);
    
}

//==============================================================================
void Pfmproject0AudioProcessorEditor::paint (Graphics& g) 
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello Worlds", getLocalBounds(), Justification::centred, 1);
    
    getLocalBounds().reduced(4).removeFromBottom(3).expanded(2);
}

void Pfmproject0AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}


void Pfmproject0AudioProcessorEditor::mouseUp(const MouseEvent& e)
{
    //gets the current boolean value from the pointer, assigns inverse
    //sprocessor.shouldPlaySound->setValueNotifyingHost(!processor.shouldPlaySound->get());
}

void Pfmproject0AudioProcessorEditor::mouseDown(const MouseEvent& e)
{
    //processor.shouldPlaySound->beginChangeGesture();
    //processor.shouldPlaySound->setValueNotifyingHost(!processor.shouldPlaySound->get());
    //processor.shouldPlaySound->endChangeGesture();
    
    Pfmproject0AudioProcessor::UpdateAutomatableParameter(processor.shouldPlaySound,
                                                        !processor.shouldPlaySound->get());
    lastClickPos = e.getPosition();
}

void Pfmproject0AudioProcessorEditor::mouseDrag(const MouseEvent &e)
{
    auto clickPos = e.getPosition();
    
    //calculate how much mosue has moved
    //auto difY = jlimit(-1.0, 1.0, -(clickPos.y) / (static_cast<double>(getHeight())* 2));
    auto difY = jmap(double(clickPos.y), 0.0, (double)getHeight(), 1.0, 0.0);
    
    DBG ( "difY: " << difY);
    
    Pfmproject0AudioProcessor::UpdateAutomatableParameter(processor.bgColor, difY);
}
