// Implementation of the Forward Chain Class
// Author: Robert Jones
#include <string>
#include <iostream>

using namespace std;

class Treatment
{
    private:
        string clauseVL[271][9];
        string variableList[23][2];
        string ruleList[31][9];
        string treatmentResult;
        int globalConclusionsCounter;
        string globalConclusions[31];
        string treatment;

    public:
        //Constructor
        Treatment();

        void initializeCVL();
        void initializeVarList();
        void initializeRuleList();
        void search_cvl(string var);
        void clause_to_rule (int var);
        void update_VL(int var);
        void validate_Ri(int var);
        void process(string var);
        void printGlobalConclusions();
        void modifyTreatmentString();
        string getTreatment();
};
