// Implementation of the Backward Chain Class
// Authors: Brittany Hale, John Courtright
#include "Project1-Courtright-A05080613-backwardChain.h"
#include <stack>
#include <cstring>
#include <iostream>
#include <limits>
using namespace std;

// Constructor ~ Implemented by John
BackwardChain::BackwardChain()
{
  // Initialize Lists
  for (int i = 0; i < 13; i++)
    conclt[i] = "";
  for (int i = 0; i < 31; i++)
    varlt[i] = "";
  for (int i = 0; i < 72; i++)
    clvarlt[i] = "";
  for (int i = 0; i < 31; i++)
    varInt[i] = 'X';

  // Populate Conclusion List
  conclt[1] = "Cancer";
  conclt[2] = "LocalCancer";
  conclt[3] = "Skin Cancer";
  conclt[4] = "Basal Skin Cancer";
  conclt[5] = "Squamous Skin Cancer";
  conclt[6] = "PainCheck";
  conclt[7] = "Breast Cancer";
  conclt[8] = "Lung Cancer";
  conclt[9] = "Pancreatic Cancer";
  conclt[10] = "Colon or Rectal Cancer";
  conclt[11] = "Thyroid Cancer";
  conclt[12] = "Leukemia";

  // Populate Variable List
  varlt[1] = "Cancer";
  varlt[2] = "LocalCancer";
  varlt[3] = "Sores";
  varlt[4] = "Patches";
  varlt[5] = "Warts";
  varlt[6] = "NScars";
  varlt[7] = "Pain";
  varlt[8] = "PBreast";
  varlt[9] = "BreastSkin";
  varlt[10] = "BreastLump";
  varlt[11] = "Cough";
  varlt[12] = "BloodyCough";
  varlt[13] = "LungInfec";
  varlt[14] = "Clots";
  varlt[15] = "FreqHeadache";
  varlt[16] = "Diabetes";
  varlt[17] = "YellowSkin";
  varlt[18] = "AbPressure";
  varlt[19] = "BowelChange";
  varlt[20] = "BloodRectum";
  varlt[21] = "NeckLump";
  varlt[22] = "BreathSwallowIssue";
  varlt[23] = "VoiceChanges";
  varlt[24] = "ConstCough";
  varlt[25] = "BleedBruiseEasily";
  varlt[26] = "FeverChillsNightSweats";
  varlt[27] = "EnlargeLiverSpleen";
  varlt[28] = "SwolLymph";

  // Clause Variable List (updated by John)
  /* enter variables as they appear in the if clauses. a maximum
  of 3 variables per if statement. if no more variables hit return key. */
  clvarlt[1] = "Cancer";
  clvarlt[7] = "LocalCancer";
  clvarlt[13] = "LocalCancer";
  clvarlt[19] = "SkinCancer";
  clvarlt[20] = "Sores";
  clvarlt[21] = "Patches";
  clvarlt[22] = "Warts";
  clvarlt[23] = "NScars";
  clvarlt[25] = "SkinCancer";
  clvarlt[26] = "Sores";
  clvarlt[27] = "Patches";
  clvarlt[28] = "Warts";
  clvarlt[31] = "LocalCancer";
  clvarlt[37] = "Pain";
  clvarlt[38] = "PBreast";
  clvarlt[39] = "BreastSkin";
  clvarlt[40] = "BreastLump";
  clvarlt[43] = "Pain";
  clvarlt[44] = "Cough";
  clvarlt[45] = "BloodyCough";
  clvarlt[46] = "LungInfec";
  clvarlt[47] = "Clots";
  clvarlt[48] = "FreqHeadache";
  clvarlt[49] = "Pain";
  clvarlt[50] = "Diabetes";
  clvarlt[51] = "YellowSkin";
  clvarlt[52] = "Clots";
  clvarlt[55] = "Pain";
  clvarlt[56] = "AbPressure";
  clvarlt[57] = "BowelChange";
  clvarlt[58] = "BloodRectum";
  clvarlt[61] = "Pain";
  clvarlt[62] = "NeckLump";
  clvarlt[63] = "BreathSwallowIssue";
  clvarlt[64] = "VoiceChanges";
  clvarlt[65] = "ConstCough";
  clvarlt[67] = "Pain";
  clvarlt[68] = "BleedBruiseEasily";
  clvarlt[69] = "FeverChillsNightSweats";
  clvarlt[70] = "EnlargeLiverSpleen";
  clvarlt[71] = "SwolLymph";

  // Initialize Variables
  int Ri = 0;
  int Ci = 0;
  int conclusionPosition = 0;
  string var = "";

  //Backward Chaining System Initialized.
  return;
}

// Searches for a matching variable in the conclusion list
bool BackwardChain::search_conclusion_list(const string &var)
{
  /*
    This function finds the matching variable in the
    conclusion list & the corresponding rule number, Ri.
  */
  //Searching for var in Conclusion list...
  int conclusionPosition = 1;
  int i = 1;
  while (i <= 12 && strcmp(var.c_str(), conclt[i].c_str()) != 0) // Iterate up to and including the last element
  {
    // If the var (Stores conclusion from user) and current conclusion from conclt are different (not 0)
    i++; // Increment till we get to equal strings or not found
  }

  // If we found the var in the conclt (strcmp = 0)
  if (i <= 12 && strcmp(var.c_str(), conclt[i].c_str()) == 0) // Check if within bounds and strings are equal
  {
    conclusionPosition = i;
    finalConclusionPos = i;
    this->Ri = i * 10; // Assign rule number from index
    //cout << "Conclusion '" << var << "' found at position " << conclusionPosition << "." << endl;
    return true;
  }
  else
  {
    // No conclusion found in list
    //cout << "Conclusion '" << var << "' not found." << endl;
    return false;
  }
}

// Converts Rule # Ri to Clause # Ci
// Updated by Brittany Hale
int BackwardChain::rule_to_clause(int Ri)
{
  /*
    Rule #s are sequenced 10,20,30,40,50,...
    Each rule has 6 slots in the Clause Variable list.
    Formula:
  */
  //cout << "Ri is " << Ri << endl;
  int Ci = 6 * (Ri / 10 - 1) + 1;
  //cout << "Ci is " << Ci << endl;
  return Ci;
}

// void BackwardChain::update_clause_stack(int Ci) // For clause stack set for each rule
// {
//   for(i = 0; i < 6; i++){ // Ci to Ci + 5
//     if(clvarlt[Ci + i] != ""){ // If spot in Conclusion Var List is not empty
//       clauseStack.push(Ci + i); // Push Ci num into Clause Stack
//     }
//   }
// }

void BackwardChain::update_var_list(int Ci)
{
  // Push variables from Ci to Ci + 5 onto clauseStack
  for (int i = Ci; i < Ci + 6 && i < 73; i++)
  { // Ensure within bounds
    if (clvarlt[i] != "")
      clauseStack.push(i);
  }

  // Process each variable in the stack
  while (!clauseStack.empty())
  {
    int currentCi = clauseStack.top(); // Get top variable index
    clauseStack.pop();                 // Remove from stack

    string currentVar = clvarlt[currentCi]; // Get the variable name

    // Step 1: Check if current variable is also a conclusion
    if (search_conclusion_list(currentVar))
    {
      if (currentVar == "CANCER")
        suscancer++;
      if (currentVar == "LOCALC")
        localized++;
      if (localized > 2 || suscancer > 2)
      {
        Process(currentVar); // Recursively process this variable
      }
    }

    // Step 2: Check if the variable is already instantiated
    int varIndex = 0;
    for (int i = 1; i < 29; i++)
    {
      if (varlt[i] == currentVar)
      {
        varIndex = i;
        break;
      }
    }

    // If the variable is not instantiated, ask the user
    if (varInt[varIndex] == 'X')
    {                                // Assuming 'X' means uninitialized
      cout << getQuestion(varIndex); // Call helper function for prompts
      char userInput;
      cin >> userInput;
      cout << endl;

      // Validate input
      while (userInput != 'Y' && userInput != 'N' &&
             userInput != 'C' && userInput != 'S' && userInput != 'B')
      {
        cout << "Invalid input. Choose a valid character: ";
        cin >> userInput;
      }

      varInt[varIndex] = userInput; // Store the response
      //cout << "You set " << currentVar << " to: " << userInput << ".\n";
    }
  }
}

string BackwardChain::getQuestion(int varNum)
{
  switch (varNum)
  {
  case 1:
    return "Do you suspect cancer? (Y/N): ";
  case 2:
    return "Are the symptoms localized? (Y/N): ";
  case 3:
    return "Do you have sores? (Y/N): ";
  case 4:
    return "Do you have red patches? (Y/N): ";
  case 5:
    return "Do you have warts? (Y/N): ";
  case 6:
    return "Do you have new scars? (Y/N): ";
  case 7:
    return "Where are you experiencing pain? (C = Chest, S = Stomach, N = Neck, B = Bones): ";
  case 8:
    return "Do you have pain in the breast or nipple? (Y/N): ";
  case 9:
    return "Do you have red, irritated, or scaly skin on the breast? (Y/N): ";
  case 10:
    return "Do you have lumps in the breast, armpit, or collarbone? (Y/N): ";
  case 11:
    return "Do you have a cough or breathing issues? (Y/N): ";
  case 12:
    return "Have you coughed up blood? (Y/N): ";
  case 13:
    return "Have you had lung infections? (Y/N): ";
  case 14:
    return "Do you have blood clots? (Y/N): ";
  case 15:
    return "Do you experience frequent headaches? (Y/N): ";
  case 16:
    return "Do you have diabetes or experience diabetic symptoms? (Y/N): ";
  case 17:
    return "Do you have yellow skin? (Y/N): ";
  case 18:
    return "Is there pressure in your abdomen? (Y/N): ";
  case 19:
    return "Have you noticed bowel changes? (Y/N): ";
  case 20:
    return "Have you experienced blood from the rectum? (Y/N): ";
  case 21:
    return "Do you have neck swelling or a lump? (Y/N): ";
  case 22:
    return "Do you have breathing or swallowing issues? (Y/N): ";
  case 23:
    return "Has your voice changed? (Y/N): ";
  case 24:
    return "Do you have a constant cough? (Y/N): ";
  case 25:
    return "Do you bleed or bruise easily? (Y/N): ";
  case 26:
    return "Do you experience fever, chills, or night sweats? (Y/N): ";
  case 27:
    return "Do you have an enlarged liver or spleen? (Y/N): ";
  case 28:
    return "Do you have swollen lympth nodes? (Y/N): ";
  default:
    return "Enter 'Y' ";
  }
}

// Validates if a rule's 'if' conditions are met
void BackwardChain::validate_Ri(int Ri, string &conclusion)
{
  /*
    This function checks if the values of variables in the ‘if’ clauses of rule Ri
    match the values in the variable list & derived global variable list.

    If they do, it assigns the rule's conclusion to the 'conclusion' variable.
    Otherwise, it does nothing and returns.
  */
  int conclusionMet = 0;
  //cout << Ri << endl;
  switch (Ri)
  {
  case 10: // Rule 10
    if (varInt[1] == 'N')
    {
      //cout << "Conclusion: Cancer = NO\n";
      conclusionMet = 1;
    }
    break;

  case 20: // Rule 20
    if (varInt[2] == 'Y')
    {
      //cout << "Conclusion: Localized Cancers = YES\n";
      conclusionMet = 1;
    }
    break;

  case 30: // Rule 30
    if (varInt[2] == 'N')
    {
      //cout << "Conclusion: Skin Cancers = YES\n";
      conclusionMet = 1;
    }
    break;

  case 40: // Rule 40
    if (varInt[3] == 'Y' && varInt[4] == 'Y' && varInt[5] == 'N' && varInt[6] == 'Y')
    {
      //cout << "Conclusion: Basal Cell Skin Cancer = YES\n";
      conclusionMet = 1;
    }
    break;

  case 50: // Rule 50
    if (varInt[3] == 'Y' && varInt[4] == 'Y' && varInt[5] == 'Y')
    {
      //cout << "Conclusion: Squamous Cell Skin Cancer = YES\n";
      conclusionMet = 1;
    }
    break;

  case 60: // Rule 60
    if (varInt[2] == 'Y')
    {
      //cout << "Conclusion: CHECK PAIN\n";
      conclusionMet = 1;
    }
    break;

  case 70: // Rule 70
    if (varInt[7] == 'C' && varInt[8] == 'Y' && varInt[9] == 'Y' && varInt[10] == 'Y')
    {
      //cout << "Conclusion: Breast Cancer = YES\n";
      conclusionMet = 1;
    }
    break;

  case 80: // Rule 80
    if (varInt[7] == 'C' && varInt[11] == 'Y' && varInt[12] == 'Y' && varInt[13] == 'Y' && varInt[14] == 'Y' && varInt[15] == 'Y')
    {
      //cout << "Conclusion: Lung Cancer = YES\n";
      conclusionMet = 1;
    }
    break;

  case 90: // Rule 90
    if (varInt[7] == 'S' && varInt[16] == 'Y' && varInt[17] == 'Y' && varInt[14] == 'Y')
    {
      //cout << "Conclusion: Pancreatic Cancer = YES\n";
      conclusionMet = 1;
    }
    break;

  case 100: // Rule 100
    if (varInt[7] == 'S' && varInt[18] == 'Y' && varInt[19] == 'Y' && varInt[20] == 'Y')
    {
      //cout << "Conclusion: Colon or Rectal Cancer = YES\n";
      conclusionMet = 1;
    }
    break;

  case 110: // Rule 110
    if (varInt[7] == 'N' && varInt[21] == 'Y' && varInt[22] == 'Y' && varInt[23] == 'Y' && varInt[24] == 'Y')
    {
      //cout << "Conclusion: Thyroid Cancer = YES\n";
      conclusionMet = 1;
    }
    break;

  case 120: // Rule 120
    if (varInt[7] == 'B' && varInt[25] == 'Y' && varInt[26] == 'Y' && varInt[27] == 'Y' && varInt[28] == 'Y')
    {
      //cout << "Conclusion: Leukemia = YES\n";
      conclusionMet = 1;
    }
    break;

  default:
    cout << "Invalid rule number.\n";
  }

  if (conclusionMet == 1)
  {
    //Conclusion met successfully.
    diagnosis = conclt[finalConclusionPos];
  }
  else
  {
    //No conclusion met for the given rule.
    return;
  }
}

// Processes backward chaining recursively
void BackwardChain::Process(const string &var)
{
  /*
    Runs a loop that:
    1. Calls search_conclusion_list(variable) to find matching variable & rule Ri.
    2. Calls rule_to_clause(Ri) to convert Ri to clause Ci.
    3. Calls update_var_list(Ci) to instantiate variables (may trigger recursion).
    4. Calls validate_Ri(Ri, conclusion) to verify rule satisfaction.
    5. Saves conclusion in the derived global variable list.
    6. If values don't match, continues to the next conclusion.
  */

  search_conclusion_list(var); // Converts conclusion pos to rule index (Ri)
  Ci = rule_to_clause(Ri);
  update_var_list(Ci);
  validate_Ri(Ri, conclusion);
}

// Public Member Function that Starts Process
string BackwardChain::startBackwardChain()
{
  //cout << "Backward Chain Diagnosis Begin..." << endl;
  cout << "Here are the possible conclusions: " << endl;
  for (int i = 1; i < 13; i++)
  {
    if (i == 1 || i == 2 || i == 3 || i == 6) continue; // Skip these conclusions, not intuitievly useful
    cout << "CONCLUSION " << i << " " << conclt[i] << "\n";
  }

  bool valid = false;
  int userInput = 0;

  // Validate before calling Process
  while (!valid)
  {
    //cout << "Select a conclusion from the list by inputting the corresponding number: ";
    cout << "Please select a cancer type you want to check for by inputting the corresponding number: ";
    cin >> userInput;

    if (cin.fail())
    {
      cout << "Invalid input. Please enter a valid number from the list.\n";
      cin.clear();                                         // Clear error flags
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
      continue;
    }

    if (userInput >= 1 && userInput <= 12)
    {
      valid = true;
    }
    else
    {
      cout << "Invalid choice. Please enter a number between 1 and 12.\n";
      cin.clear(); // Just in case extra characters are left in the buffer
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }

  finalConclusionPos = userInput;
  string choice = conclt[userInput];
  cout << "You selected: " << choice << endl << endl;
  // Proceed with the backward chaining process using userInput
  Process(choice);
  printDiagnosis();
  cout << endl;
  return diagnosis;
}

// Public Member Function that Retreives Diagnosis Variable
// Implemented by John
void BackwardChain::printDiagnosis()
{

  if (diagnosis == "")
  {
    cout << "No diagnosis has been determined." << endl;
    return;
  }

  cout << "Your final diagnosis is " << diagnosis << "." << endl;
  return;
}