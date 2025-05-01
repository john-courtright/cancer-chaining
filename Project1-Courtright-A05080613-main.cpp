// Driver File of Project 1: Cancer Diagnosis and Treatment Expert System
// Authors: Brittany Hale, John Courtright, Robert Jones
#include "Project1-Courtright-A05080613-backwardChain.h"
#include "Project1-Courtright-A05080613-forwardChain.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "This program will help diagnose cancer and provide a treatment plan." << endl;

    // BACKWARD CHAINING
    BackwardChain backwardChaining; // CONSTRUCTOR
    // Start Backward Chain process & bring its diagnosis result to main
    string diagnosis = backwardChaining.startBackwardChain();

    // Prepare Diagnosis string for Forward Chaining treatment plan
    if (diagnosis == "Basal Skin Cancer")
    {
        diagnosis = "Basal";
    }
    if (diagnosis == "Squamous Skin Cancer")
    {
        diagnosis = "Squamous";
    }
    if (diagnosis == "Breast Cancer")
    {
        diagnosis = "Breast";
    }
    if (diagnosis == "Lung Cancer")
    {
        diagnosis = "Lung";
    }
    if (diagnosis == "Pancreatic Cancer")
    {
        diagnosis = "Pancreatic";
    }
    if (diagnosis == "Colon or Rectal Cancer")
    {
        diagnosis = "Colon";
    }
    if (diagnosis == "Thyroid Cancer")
    {
        diagnosis = "Thyroid";
    }
    // diagnosis == "Leukemia" would not actually change diagnosis string

    // FORWARD CHAINING
    Treatment treatmentObject; // CONSTRUCTOR
    // Start Forward Chaining
    treatmentObject.process(diagnosis);
    string patientTreatment = treatmentObject.getTreatment();

    // Print Diagnosis and Treatment
    cout << "Diagnosis: " << diagnosis << endl;
    cout << "Treatment: " << patientTreatment << endl;
    cout << endl;

    return 0;
}