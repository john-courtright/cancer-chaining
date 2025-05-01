// Implementation of the Forward Chain Class
// Author: Robert Jones
#include "Project1-Courtright-A05080613-forwardChain.h"

Treatment::Treatment()
{
    initializeCVL();
    initializeVarList();
    initializeRuleList();
    globalConclusionsCounter = 0;
}

// Initializes the clause variable list into a 2D array. Empty strings represent the spaces. If not empty, clause variables will be accessible with indexs [clauseIndex][0-7]
void Treatment::initializeCVL()
{
  clauseVL[1][0] = "Cancer=Basal"; clauseVL[1][1] = "Centralized=YES"; clauseVL[1][2]= "Excisable=YES"; clauseVL[1][3] = "";
        clauseVL[1][4] = ""; clauseVL[1][5] = ""; clauseVL[1][6] = ""; clauseVL[1][7] = ""; clauseVL[1][8] = "";
    clauseVL[10][0] = "Cancer=Basal"; clauseVL[10][1] = "Centralized=YES"; clauseVL[10][2]= "Excisable=NO"; clauseVL[10][3] = "";
        clauseVL[10][4] = ""; clauseVL[10][5] = ""; clauseVL[10][6] = ""; clauseVL[10][7] = ""; clauseVL[10][8] = "";
    clauseVL[19][0] = "Cancer=Basal"; clauseVL[19][1] = "Centralized=NO"; clauseVL[19][2] = ""; clauseVL[19][3] = ""; clauseVL[19][4] = ""; clauseVL[19][5] = "";
        clauseVL[19][6] = ""; clauseVL[19][7] = ""; clauseVL[19][8] = "";
    clauseVL[28][0] = "Cancer=Squamous"; clauseVL[28][1] = "Centralized=YES"; clauseVL[28][2] = "Excisable=YES"; clauseVL[28][3] = ""; clauseVL[28][4] = "";
        clauseVL[28][5] = ""; clauseVL[28][6] = ""; clauseVL[28][7] = ""; clauseVL[28][8] = "";
    clauseVL[37][0] = "Cancer=Squamous"; clauseVL[37][1] = "Centralized=YES"; clauseVL[37][2] = "Excisable=NO"; clauseVL[37][3] = ""; clauseVL[37][4] = "";
        clauseVL[37][5] = ""; clauseVL[37][6] = ""; clauseVL[37][7] = ""; clauseVL[37][8] = "";
    clauseVL[46][0] = "Cancer=Squamous"; clauseVL[46][1] = "Centralized=NO"; clauseVL[46][2] = "Weak=YES"; clauseVL[46][3] = ""; clauseVL[46][4] = "";
        clauseVL[46][5] = ""; clauseVL[46][6] = ""; clauseVL[46][7] = ""; clauseVL[46][8] = "";
    clauseVL[55][0] = "Cancer=Squamous"; clauseVL[55][1] = "Centralized=NO"; clauseVL[55][2] = "Weak=NO"; clauseVL[55][3] = ""; clauseVL[55][4] = "";
        clauseVL[55][5] = ""; clauseVL[55][6] = ""; clauseVL[55][7] = ""; clauseVL[55][8] = "";
    clauseVL[64][0] = "Cancer=Breast"; clauseVL[64][1] = "Centralized=NO"; clauseVL[64][2] = "Late=YES"; clauseVL[64][3] = ""; clauseVL[64][4] = "";
        clauseVL[64][5] = ""; clauseVL[64][6] = ""; clauseVL[64][7] = ""; clauseVL[64][8] = "";
    clauseVL[73][0]= "Cancer=Breast"; clauseVL[73][1] = "Centralized=NO"; clauseVL[73][2] = "Late=NO"; clauseVL[73][3] = "Large=YES"; clauseVL[73][4] = "";
        clauseVL[73][5] = ""; clauseVL[73][6] = ""; clauseVL[73][7] = ""; clauseVL[73][8] = "";
    clauseVL[82][0]= "Cancer=Breast"; clauseVL[82][1] = "Centralized=NO"; clauseVL[82][2] = "Late=NO"; clauseVL[82][3] = "Large=NO"; clauseVL[82][4] = "";
        clauseVL[82][5] = ""; clauseVL[82][6] = ""; clauseVL[82][7] = ""; clauseVL[82][8] = "";
    clauseVL[91][0]= "Cancer=Breast"; clauseVL[91][1] = "Centralized=YES"; clauseVL[91][2] = "Excisable=YES"; clauseVL[91][3] = ""; clauseVL[91][4] = "";
        clauseVL[91][5] = ""; clauseVL[91][6] = ""; clauseVL[91][7] = ""; clauseVL[91][8] = "";
    clauseVL[100][0]= "Cancer=Breast"; clauseVL[100][1] = "Centralized=YES"; clauseVL[100][2] = "Excisable=NO"; clauseVL[100][3] = ""; clauseVL[100][4] = "";
        clauseVL[100][5] = ""; clauseVL[100][6] = ""; clauseVL[100][7] = ""; clauseVL[100][8] = "";
    clauseVL[109][0] = "Cancer=Colon"; clauseVL[109][1] = "Early=YES"; clauseVL[109][2] = "Excisable=YES"; clauseVL[109][3] = ""; clauseVL[109][4] = "";
        clauseVL[109][5] = ""; clauseVL[109][6] = ""; clauseVL[109][7] = ""; clauseVL[109][8] = "";
    clauseVL[118][0] = "Cancer=Colon"; clauseVL[118][1] = "Early=YES"; clauseVL[118][2] = "Excisable=NO"; clauseVL[118][3] = ""; clauseVL[118][4] = "";
        clauseVL[118][5] = ""; clauseVL[118][6] = ""; clauseVL[118][7] = ""; clauseVL[118][8] = "";
    clauseVL[127][0] = "Cancer=Colon"; clauseVL[127][1] = "Early=NO"; clauseVL[127][2] = ""; clauseVL[127][3] = ""; clauseVL[127][4] = "";
        clauseVL[127][5] = ""; clauseVL[127][6] = ""; clauseVL[127][7] = ""; clauseVL[127][8] = "";
    clauseVL[136][0] = "Cancer=Leukemia"; clauseVL[136][1] = "Acute=YES"; clauseVL[136][2] = "Myeloid=YES"; clauseVL[136][3] = ""; clauseVL[136][4] = "";
        clauseVL[136][5] = ""; clauseVL[136][6] = ""; clauseVL[136][7] = ""; clauseVL[136][8] = "";
        //Myeloid=NO is the same as Lymphoid=YES
    clauseVL[145][0] = "Cancer=Leukemia"; clauseVL[145][1] = "Acute=YES"; clauseVL[145][2] = "Myeloid=NO"; clauseVL[145][3] = ""; clauseVL[145][4] = "";
        clauseVL[145][5] = ""; clauseVL[145][6] = ""; clauseVL[145][7] = ""; clauseVL[145][8] = "";
    clauseVL[154][0] = "Cancer=Leukemia"; clauseVL[154][1] = "Chronic=YES"; clauseVL[154][2] = "Myeloid=YES"; clauseVL[154][3] = ""; clauseVL[154][4] = "";
        clauseVL[154][5] = ""; clauseVL[154][6] = ""; clauseVL[154][7] = ""; clauseVL[154][8] = "";
    clauseVL[163][0] = "Cancer=Leukemia"; clauseVL[163][1] = "Chronic=YES"; clauseVL[163][2] = "Myeloid=NO"; clauseVL[163][3] = "Urgent=YES"; clauseVL[163][4] = "";
        clauseVL[163][5] = ""; clauseVL[163][6] = ""; clauseVL[163][7] = ""; clauseVL[163][8] = "";
    clauseVL[172][0] = "Cancer=Leukemia"; clauseVL[172][1] = "Chronic=YES"; clauseVL[172][2] ="Myeloid=NO"; clauseVL[172][3] = "Urgent=NO"; clauseVL[172][4] = "";
        clauseVL[172][5] = ""; clauseVL[172][6] = ""; clauseVL[172][7] = ""; clauseVL[172][8] = "";
    clauseVL[181][0] = "Cancer=Lung"; clauseVL[181][1] = "Small=NO"; clauseVL[181][2] = "Early=YES"; clauseVL[181][3] = ""; clauseVL[181][4] = "";
        clauseVL[181][5] = ""; clauseVL[181][6] = ""; clauseVL[181][7] = ""; clauseVL[181][8] = "";
    clauseVL[190][0] = "Cancer=Lung"; clauseVL[190][1] = "Small=NO"; clauseVL[190][2] = "Early=NO"; clauseVL[190][3] = ""; clauseVL[190][4] = "";
        clauseVL[190][5] = ""; clauseVL[190][6] = ""; clauseVL[190][7] = ""; clauseVL[190][8] = "";
    clauseVL[199][0] = "Cancer=Lung"; clauseVL[199][1] = "Small=YES"; clauseVL[199][2] = "Excisable=YES"; clauseVL[199][3] = ""; clauseVL[199][4] = "";
        clauseVL[199][5] = ""; clauseVL[199][6] = ""; clauseVL[199][7] = ""; clauseVL[199][8] = "";
    clauseVL[208][0] = "Cancer=Lung"; clauseVL[208][1] = "Small=YES"; clauseVL[208][2] = "Excisable=NO"; clauseVL[208][3] = ""; clauseVL[208][4] = "";
        clauseVL[208][5] = ""; clauseVL[208][6] = ""; clauseVL[208][7] = ""; clauseVL[208][8] = "";
    clauseVL[217][0] = "Cancer=Pancreatic"; clauseVL[217][1] = "Excisable=YES"; clauseVL[217][2] = "Risk=YES"; clauseVL[217][3] = ""; clauseVL[217][4] = "";
        clauseVL[217][5] = ""; clauseVL[217][6] = ""; clauseVL[217][7] = ""; clauseVL[217][8] = "";
    clauseVL[226][0] = "Cancer=Pancreatic"; clauseVL[226][1] = "Excisable=YES"; clauseVL[226][2] = "Risk=NO"; clauseVL[226][3] = ""; clauseVL[226][4] = "";
        clauseVL[226][5] = ""; clauseVL[226][6] = ""; clauseVL[226][7] = ""; clauseVL[226][8] = "";
    clauseVL[235][0] = "Cancer=Pancreatic"; clauseVL[235][1] = "Excisable=NO"; clauseVL[235][2] = ""; clauseVL[235][3] = ""; clauseVL[235][4] = "";
        clauseVL[235][5] = ""; clauseVL[235][6] = ""; clauseVL[235][7] = ""; clauseVL[235][8] = "";
    clauseVL[244][0] = "Cancer=Thyroid"; clauseVL[244][1] = "Covered=YES"; clauseVL[244][2] = "Centralized=NO"; clauseVL[244][3] = ""; clauseVL[244][4] = "";
        clauseVL[244][5] = ""; clauseVL[244][6] = ""; clauseVL[244][7] = ""; clauseVL[244][8] = "";
    clauseVL[253][0] = "Cancer=Thyroid"; clauseVL[253][1] = "Covered=YES"; clauseVL[253][2] = "Centralized=YES"; clauseVL[253][3] = ""; clauseVL[253][4] = "";
        clauseVL[253][5] = ""; clauseVL[253][6] = ""; clauseVL[253][7] = ""; clauseVL[253][8] = "";
    clauseVL[262][0] = "Cancer=Thyroid"; clauseVL[262][1] = "Covered=NO"; clauseVL[262][2] = ""; clauseVL[262][3] = ""; clauseVL[262][4] = "";
        clauseVL[262][5] = ""; clauseVL[262][6] = ""; clauseVL[262][7] = ""; clauseVL[262][8] = "";
}

void Treatment::initializeVarList()
{
    variableList[0][0] = "Cancer"; variableList[0][1] = "";
    variableList[1][0] = "Basal"; variableList[1][1] = "";
    variableList[2][0] = "Centralized"; variableList[2][1] = "";
    variableList[3][0] = "Excisable"; variableList[3][1] = "";
    variableList[4][0] = "Squamous"; variableList[4][1] = "";
    variableList[5][0] = "Weak"; variableList[5][1] = "";
    variableList[6][0] = "Breast"; variableList[6][1] = "";
    variableList[7][0] = "Late"; variableList[7][1] = "";
    variableList[8][0] = "Large"; variableList[8][1] = "";
    variableList[9][0] = "Colon"; variableList[9][1] = "";
    variableList[10][0] = "Early"; variableList[10][1] = "";
    variableList[11][0] = "Leukemia"; variableList[11][1] = "";
    variableList[12][0] = "Acute"; variableList[12][1] = "";
    variableList[13][0] = "Myeloid"; variableList[13][1] = "";
    variableList[14][0] = "Lymphoid"; variableList[14][1] = "";
    variableList[15][0] = "Chronic"; variableList[15][1] = "";
    variableList[16][0] = "Urgent"; variableList[16][1] = "";
    variableList[17][0] = "Lung"; variableList[17][1] = "";
    variableList[18][0] = "Small"; variableList[18][1] = "";
    variableList[19][0] = "Pancreatic"; variableList[19][1] = "";
    variableList[20][0] = "Risk"; variableList[20][1] = "";
    variableList[21][0] = "Thyroid"; variableList[21][1] = "";
    variableList[22][0] = "Covered"; variableList[22][1] = "";
}

void Treatment::initializeRuleList()
{
    
    ruleList[1][0] = "Cancer=Basal"; ruleList[1][1] = "Centralized=YES"; ruleList[1][2]= "Excisable=YES"; ruleList[1][3] = "";
        ruleList[1][4] = ""; ruleList[1][5] = ""; ruleList[1][6] = ""; ruleList[1][7] = ""; ruleList[1][8] = "Treatment=Targeted Radiation";
    ruleList[2][0] = "Cancer=Basal"; ruleList[2][1] = "Centralized=YES"; ruleList[2][2]= "Excisable=NO"; ruleList[2][3] = "";
        ruleList[2][4] = ""; ruleList[2][5] = ""; ruleList[2][6] = ""; ruleList[2][7] = ""; ruleList[2][8] = "Treatment=Surgical Removal";
    ruleList[3][0] = "Cancer=Basal"; ruleList[3][1] = "Centralized=NO"; ruleList[3][2] = ""; ruleList[3][3] = ""; ruleList[3][4] = ""; ruleList[3][5] = "";
        ruleList[3][6] = ""; ruleList[3][7] = ""; ruleList[3][8] = "Treatment=Immunotherapy";
    ruleList[4][0] = "Cancer=Squamous"; ruleList[4][1] = "Centralized=YES"; ruleList[4][2] = "Excisable=YES"; ruleList[4][3] = ""; ruleList[4][4] = "";
        ruleList[4][5] = ""; ruleList[4][6] = ""; ruleList[4][7] = ""; ruleList[4][8] = "Treatment=Surgical Removal";
    ruleList[5][0] = "Cancer=Squamous"; ruleList[5][1] = "Centralized=YES"; ruleList[5][2] = "Excisable=NO"; ruleList[5][3] = ""; ruleList[5][4] = "";
        ruleList[5][5] = ""; ruleList[5][6] = ""; ruleList[5][7] = ""; ruleList[5][8] = "Treatment=Targeted Radiation";
    ruleList[6][0] = "Cancer=Squamous"; ruleList[6][1] = "Centralized=NO"; ruleList[6][2] = "Weak=YES"; ruleList[6][3] = ""; ruleList[6][4] = "";
        ruleList[6][5] = ""; ruleList[6][6] = ""; ruleList[6][7] = ""; ruleList[6][8] = "Treatment=Chemotherapy";
    ruleList[7][0] = "Cancer=Squamous"; ruleList[7][1] = "Centralized=NO"; ruleList[7][2] = "Weak=NO"; ruleList[7][3] = ""; ruleList[7][4] = "";
        ruleList[7][5] = ""; ruleList[7][6] = ""; ruleList[7][7] = ""; ruleList[7][8] = "Treatment=Immunotherapy";
    ruleList[8][0] = "Cancer=Breast"; ruleList[8][1] = "Centralized=NO"; ruleList[8][2] = "Late=YES"; ruleList[8][3] = ""; ruleList[8][4] = "";
        ruleList[8][5] = ""; ruleList[8][6] = ""; ruleList[8][7] = ""; ruleList[8][8] = "Treatment=Systemic Therapy";
    ruleList[9][0]= "Cancer=Breast"; ruleList[9][1] = "Centralized=NO"; ruleList[9][2] = "Late=NO"; ruleList[9][3] = "Large=YES"; ruleList[9][4] = "";
        ruleList[9][5] = ""; ruleList[9][6] = ""; ruleList[9][7] = ""; ruleList[9][8] = "Treatment=Systemic Therapy then Surgical Removal";
    ruleList[10][0]= "Cancer=Breast"; ruleList[10][1] = "Centralized=NO"; ruleList[10][2] = "Late=NO"; ruleList[10][3] = "Large=NO"; ruleList[10][4] = "";
        ruleList[10][5] = ""; ruleList[10][6] = ""; ruleList[10][7] = ""; ruleList[10][8] = "Treatment=Surgical Removal";
    ruleList[11][0]= "Cancer=Breast"; ruleList[11][1] = "Centralized=YES"; ruleList[11][2] = "Excisable=YES"; ruleList[11][3] = ""; ruleList[11][4] = "";
        ruleList[11][5] = ""; ruleList[11][6] = ""; ruleList[11][7] = ""; ruleList[11][8] = "Treatment=Surgical Removal";
    ruleList[12][0]= "Cancer=Breast"; ruleList[12][1] = "Centralized=YES"; ruleList[12][2] = "Excisable=NO"; ruleList[12][3] = ""; ruleList[12][4] = "";
        ruleList[12][5] = ""; ruleList[12][6] = ""; ruleList[12][7] = ""; ruleList[12][8] = "Treatment=Targeted Radiation";
    ruleList[13][0] = "Cancer=Colon"; ruleList[13][1] = "Early=YES"; ruleList[13][2] = "Excisable=YES"; ruleList[13][3] = ""; ruleList[13][4] = "";
        ruleList[13][5] = ""; ruleList[13][6] = ""; ruleList[13][7] = ""; ruleList[13][8] = "Treatment=Colonoscopy";
    ruleList[14][0] = "Cancer=Colon"; ruleList[14][1] = "Early=YES"; ruleList[14][2] = "Excisable=NO"; ruleList[14][3] = ""; ruleList[14][4] = "";
        ruleList[14][5] = ""; ruleList[14][6] = ""; ruleList[14][7] = ""; ruleList[14][8] = "Treatment=Colectomy";
    ruleList[15][0] = "Cancer=Colon"; ruleList[15][1] = "Early=NO"; ruleList[15][2] = ""; ruleList[15][3] = ""; ruleList[15][4] = "";
        ruleList[15][5] = ""; ruleList[15][6] = ""; ruleList[15][7] = ""; ruleList[15][8] = "Treatment=Colectomy";
    ruleList[16][0] = "Cancer=Leukemia"; ruleList[16][1] = "Acute=YES"; ruleList[16][2] = "Myeloid=YES"; ruleList[16][3] = ""; ruleList[16][4] = "";
        ruleList[16][5] = ""; ruleList[16][6] = ""; ruleList[16][7] = ""; ruleList[16][8] = "Treatment=ATRA Drug Therapy";
        //Myeloid=NO is the same as Lymphoid=YES
    ruleList[17][0] = "Cancer=Leukemia"; ruleList[17][1] = "Acute=YES"; ruleList[17][2] = "Myeloid=NO"; ruleList[17][3] = ""; ruleList[17][4] = "";
        ruleList[17][5] = ""; ruleList[17][6] = ""; ruleList[17][7] = ""; ruleList[17][8] = "Treatment=Chemotherapy";
    ruleList[18][0] = "Cancer=Leukemia"; ruleList[18][1] = "Chronic=YES"; ruleList[18][2] = "Myeloid=YES"; ruleList[18][3] = ""; ruleList[18][4] = "";
        ruleList[18][5] = ""; ruleList[18][6] = ""; ruleList[18][7] = ""; ruleList[18][8] = "Treatment=TKI Inhibitor";
    ruleList[19][0] = "Cancer=Leukemia"; ruleList[19][1] = "Chronic=YES"; ruleList[19][2] = "Myeloid=NO"; ruleList[19][3] = "Urgent=YES"; ruleList[19][4] = "";
        ruleList[19][5] = ""; ruleList[19][6] = ""; ruleList[19][7] = ""; ruleList[19][8] = "Treatment=Targeted Drugs, Chemoterapy, or Immunotherapy";
    ruleList[20][0] = "Cancer=Leukemia"; ruleList[20][1] = "Chronic=YES"; ruleList[20][2] ="Myeloid=NO"; ruleList[20][3] = "Urgent=NO"; ruleList[20][4] = "";
        ruleList[20][5] = ""; ruleList[20][6] = ""; ruleList[20][7] = ""; ruleList[20][8] = "Treatment=Low-Dose Radiation or Surgical Removal";
    ruleList[21][0] = "Cancer=Lung"; ruleList[21][1] = "Small=NO"; ruleList[21][2] = "Early=YES"; ruleList[21][3] = ""; ruleList[21][4] = "";
        ruleList[21][5] = ""; ruleList[21][6] = ""; ruleList[21][7] = ""; ruleList[21][8] = "Treatment=Surgical Removal or Targeted Therapy then Removal";
    ruleList[22][0] = "Cancer=Lung"; ruleList[22][1] = "Small=NO"; ruleList[22][2] = "Early=NO"; ruleList[22][3] = ""; ruleList[22][4] = "";
        ruleList[22][5] = ""; ruleList[22][6] = ""; ruleList[22][7] = ""; ruleList[22][8] = "Treatment=Radiation, Chemo, or Immunotherapy";
    ruleList[23][0] = "Cancer=Lung"; ruleList[23][1] = "Small=YES"; ruleList[23][2] = "Excisable=YES"; ruleList[23][3] = ""; ruleList[23][4] = "";
        ruleList[23][5] = ""; ruleList[23][6] = ""; ruleList[23][7] = ""; ruleList[23][8] = "Treatment=Surgical Removal then Chemotherapy";
    ruleList[24][0] = "Cancer=Lung"; ruleList[24][1] = "Small=YES"; ruleList[24][2] = "Excisable=NO"; ruleList[24][3] = ""; ruleList[24][4] = "";
        ruleList[24][5] = ""; ruleList[24][6] = ""; ruleList[24][7] = ""; ruleList[24][8] = "Treatment=Chemoraditation";
    ruleList[25][0] = "Cancer=Pancreatic"; ruleList[25][1] = "Excisable=YES"; ruleList[25][2] = "Risk=YES"; ruleList[25][3] = ""; ruleList[25][4] = "";
        ruleList[25][5] = ""; ruleList[25][6] = ""; ruleList[25][7] = ""; ruleList[25][8] = "Treatment=Chemo or Raditation Therapy then consider Surgery";
    ruleList[26][0] = "Cancer=Pancreatic"; ruleList[26][1] = "Excisable=YES"; ruleList[26][2] = "Risk=NO"; ruleList[26][3] = ""; ruleList[26][4] = "";
        ruleList[26][5] = ""; ruleList[26][6] = ""; ruleList[26][7] = ""; ruleList[26][8] = "Treatment=Surgical Removal";
    ruleList[27][0] = "Cancer=Pancreatic"; ruleList[27][1] = "Excisable=NO"; ruleList[27][2] = ""; ruleList[27][3] = ""; ruleList[27][4] = "";
        ruleList[27][5] = ""; ruleList[27][6] = ""; ruleList[27][7] = ""; ruleList[27][8] = "Treatment=Chemotherapy";
    ruleList[28][0] = "Cancer=Thyroid"; ruleList[28][1] = "Covered=YES"; ruleList[28][2] = "Centralized=NO"; ruleList[28][3] = ""; ruleList[28][4] = "";
        ruleList[28][5] = ""; ruleList[28][6] = ""; ruleList[28][7] = ""; ruleList[28][8] = "Treatment=Radical Neck Dissection";
    ruleList[29][0] = "Cancer=Thyroid"; ruleList[29][1] = "Covered=YES"; ruleList[29][2] = "Centralized=YES"; ruleList[29][3] = ""; ruleList[29][4] = "";
        ruleList[29][5] = ""; ruleList[29][6] = ""; ruleList[29][7] = ""; ruleList[29][8] = "Treatment=Thyroidectomy";
    ruleList[30][0] = "Cancer=Thyroid"; ruleList[30][1] = "Covered=NO"; ruleList[30][2] = ""; ruleList[30][3] = ""; ruleList[30][4] = "";
        ruleList[30][5] = ""; ruleList[30][6] = ""; ruleList[30][7] = ""; ruleList[30][8] = "Treatment=Lobectomy";
    /*ruleList[31][0] = "Basal=NO"; ruleList[31][1] = "Squamous=NO"; ruleList[31][2] = "Breast=NO"; ruleList[31][3] = "Colon=NO"; ruleList[31][4] = "Leukemia=NO";
        ruleList[31][5] = "Lung=NO"; ruleList[31][6] = "Pancreatic=NO"; ruleList[31][7] = "Thyroid=NO"; ruleList[31][8] = "Treatment=None";*/
    }


void Treatment::search_cvl(string variable)
{
    for (int CI = 1; CI < 271; CI++)
    {
        if(clauseVL[CI][0]== variable)
        {
            update_VL(CI);
            clause_to_rule(CI);
        }
    }
    return;
}

void Treatment::clause_to_rule(int clauseNumber)
{
    int RI = ((clauseNumber/9)+1);
    validate_Ri(RI);

    return;
}

void Treatment::update_VL(int clauseNumber)
{
    string preModVar;
    string postModVar;

    for (int i = 1; i < 8; i++)
    {
        if (clauseVL[clauseNumber][i] != "")
        {
            preModVar = clauseVL[clauseNumber][i];
            std::size_t seperator = preModVar.find("=");
            postModVar = preModVar.substr(0, seperator);
            
            string userInput;

            if(postModVar == "Basal")
            {
                if(variableList[1][1] == "")
                {
                    do{
                        cout<< "Patient has Basal Cell Carcinoma? (YES/NO) ";
                        cin >> userInput;
                    }while(userInput != "YES" && userInput != "NO");
                    variableList[1][1] = userInput;
                    globalConclusions[globalConclusionsCounter]=(variableList[1][0] + "=" + variableList[1][1]);
                    globalConclusionsCounter++;
                }
            }

            if(postModVar == "Centralized")
            {
                if(variableList[2][1] == "")
                {
                    do{
                        cout<< "Is it Centralized? (YES/NO) ";
                        cin >> userInput;
                    }while(userInput != "YES" && userInput != "NO");
                    variableList[2][1] = userInput;
                    globalConclusions[globalConclusionsCounter]=(variableList[2][0] + "=" + variableList[2][1]);
                    globalConclusionsCounter++;
                }
            }

            if(postModVar == "Excisable")
            {
                if(variableList[3][1] == "")
                {
                    do{
                        cout<< "Is it Excisable? (YES/NO) ";
                        cin >> userInput;
                    }while(userInput != "YES" && userInput != "NO");
                    variableList[3][1] = userInput;
                    globalConclusions[globalConclusionsCounter]=(variableList[3][0] + "=" + variableList[3][1]);
                    globalConclusionsCounter++;
                }
            }
            if(postModVar == "Squamous")
            {
                if(variableList[4][1] == "")
                {
                    do{
                        cout<< "Patient has squamous cell carcinoma? (YES/NO) ";
                        cin >> userInput;
                    }while(userInput != "YES" && userInput != "NO");
                    variableList[4][1] = userInput;
                    globalConclusions[globalConclusionsCounter]=(variableList[4][0] + "=" + variableList[4][1]);
                    globalConclusionsCounter++;
                }
            }
            if(postModVar == "Weak")
            {
                if(variableList[5][1] == "")
                {
                    do{
                        cout<< "Is the patient experiencing weakness? (YES/NO) ";
                        cin >> userInput;
                    }while(userInput != "YES" && userInput != "NO");
                    variableList[5][1] = userInput;
                    globalConclusions[globalConclusionsCounter]=(variableList[5][0] + "=" + variableList[5][1]);
                    globalConclusionsCounter++;
                }
            }
            if(postModVar == "Breast")
            {
                if(variableList[6][1] == "")
                {
                    do{
                        cout<< "Patient has Breast cancer? (YES/NO) ";
                        cin >> userInput;
                    }while(userInput != "YES" && userInput != "NO");
                    variableList[6][1] = userInput;
                    globalConclusions[globalConclusionsCounter]=(variableList[6][0] + "=" + variableList[6][1]);
                    globalConclusionsCounter++;
                }
            }
            if(postModVar == "Late")
            {
                if(variableList[7][1] == "")
                {
                    do{
                        cout<< "Is it Late stage? (YES/NO) ";
                        cin >> userInput;
                    }while(userInput != "YES" && userInput != "NO");
                    variableList[7][1] = userInput;
                    globalConclusions[globalConclusionsCounter]=(variableList[7][0] + "=" + variableList[7][1]);
                    globalConclusionsCounter++;
                }
            }
            if(postModVar == "Large")
            {
                if(variableList[8][1] == "")
                {
                    do{
                        cout<< "Is it Large? (YES/NO) ";
                        cin >> userInput;
                    }while(userInput != "YES" && userInput != "NO");
                    variableList[8][1] = userInput;
                    globalConclusions[globalConclusionsCounter]=(variableList[8][0] + "=" + variableList[8][1]);
                    globalConclusionsCounter++;
                }
            }
            if(postModVar == "Colon")
            {
                if(variableList[9][1] == "")
                {
                    do{
                        cout<< "Patient has Colon cancer? (YES/NO) ";
                        cin >> userInput;
                    }while(userInput != "YES" && userInput != "NO");
                    variableList[9][1] = userInput;
                    globalConclusions[globalConclusionsCounter]=(variableList[9][0] + "=" + variableList[9][1]);
                    globalConclusionsCounter++;
                }
            }
            if(postModVar == "Early")
            {
                if(variableList[10][1] == "")
                {
                    do{
                        cout<< "Was the cancer caught early? (YES/NO) ";
                        cin >> userInput;
                    }while(userInput != "YES" && userInput != "NO");
                    variableList[10][1] = userInput;
                    globalConclusions[globalConclusionsCounter]=(variableList[10][0] + "=" + variableList[10][1]);
                    globalConclusionsCounter++;
                }
            }
            if(postModVar == "Leukemia")
            {
                if(variableList[11][1] == "")
                {
                    do{
                        cout<< "Patient has Leukemia? (YES/NO) ";
                        cin >> userInput;
                    }while(userInput != "YES" && userInput != "NO");
                    variableList[11][1] = userInput;
                    globalConclusions[globalConclusionsCounter]=(variableList[11][0] + "=" + variableList[11][1]);
                    globalConclusionsCounter++;
                }
            }
            if(postModVar == "Acute")
            {
                if(variableList[12][1] == "")
                {
                    do{
                        cout<< "Is it Acute Leukemia? (YES/NO) ";
                        cin >> userInput;
                    }while(userInput != "YES" && userInput != "NO");
                    variableList[12][1] = userInput;
                    globalConclusions[globalConclusionsCounter]=(variableList[12][0] + "=" + variableList[12][1]);
                    globalConclusionsCounter++;
                }
            }
            if(postModVar == "Myeloid")
            {
                if(variableList[13][1] == "")
                {
                    do{
                        cout<< "Did it start in Myeloid cells? (YES/NO) ";
                        cin >> userInput;
                    }while(userInput != "YES" && userInput != "NO");
                    variableList[13][1] = userInput;
                    globalConclusions[globalConclusionsCounter]=(variableList[13][0] + "=" + variableList[13][1]);
                    globalConclusionsCounter++;
                }
            }
            if(postModVar == "Lymphoid")
            {
                if(variableList[14][1] == "")
                {
                    do{
                        cout<< "Did it start in Lymphoid cells? (YES/NO) ";
                        cin >> userInput;
                    }while(userInput != "YES" && userInput != "NO");
                    variableList[14][1] = userInput;
                    globalConclusions[globalConclusionsCounter]=(variableList[14][0] + "=" + variableList[14][1]);
                    globalConclusionsCounter++;
                }
            }
            if(postModVar == "Chronic")
            {
                if(variableList[15][1] == "")
                {
                    do{
                        cout<< "Is it Chronic Leukemia? (YES/NO) ";
                        cin >> userInput;
                    }while(userInput != "YES" && userInput != "NO");
                    variableList[15][1] = userInput;
                    globalConclusions[globalConclusionsCounter]=(variableList[15][0] + "=" + variableList[15][1]);
                    globalConclusionsCounter++;
                }
            }
            if(postModVar == "Urgent")
            {
                if(variableList[16][1] == "")
                {
                    do{
                        cout<< "Is treatment needed urgently? (YES/NO) ";
                        cin >> userInput;
                    }while(userInput != "YES" && userInput != "NO");
                    variableList[16][1] = userInput;
                    globalConclusions[globalConclusionsCounter]=(variableList[16][0] + "=" + variableList[16][1]);
                    globalConclusionsCounter++;
                }
            }
            if(postModVar == "Lung")
            {
                if(variableList[17][1] == "")
                {
                    do{
                        cout<< "Patient has lung cancer? (YES/NO) ";
                        cin >> userInput;
                    }while(userInput != "YES" && userInput != "NO");
                    variableList[17][1] = userInput;
                    globalConclusions[globalConclusionsCounter]=(variableList[17][0] + "=" + variableList[17][1]);
                    globalConclusionsCounter++;
                }
            }
            if(postModVar == "Small")
            {
                if(variableList[18][1] == "")
                {
                    do{
                        cout<< "Are the tumors small? (YES/NO) ";
                        cin >> userInput;
                    }while(userInput != "YES" && userInput != "NO");
                    variableList[18][1] = userInput;
                    globalConclusions[globalConclusionsCounter]=(variableList[18][0] + "=" + variableList[18][1]);
                    globalConclusionsCounter++;
                }
            }
            if(postModVar == "Pancreatic")
            {
                if(variableList[19][1] == "")
                {
                    do{
                        cout<< "Patient has pancreatic cancer? (YES/NO) ";
                        cin >> userInput;
                    }while(userInput != "YES" && userInput != "NO");
                    variableList[19][1] = userInput;
                    globalConclusions[globalConclusionsCounter]=(variableList[19][0] + "=" + variableList[19][1]);
                    globalConclusionsCounter++;
                }
            }
            if(postModVar == "Risk")
            {
                if(variableList[20][1] == "")
                {
                    do{
                        cout<< "Is the patient high risk? (YES/NO) ";
                        cin >> userInput;
                    }while(userInput != "YES" && userInput != "NO");
                    variableList[20][1] = userInput;
                    globalConclusions[globalConclusionsCounter]=(variableList[20][0] + "=" + variableList[20][1]);
                    globalConclusionsCounter++;
                }
            }
            if(postModVar == "Thyroid")
            {
                if(variableList[21][1] == "")
                {
                    do{
                        cout<< "Patient has Thyroid Cancer? (YES/NO) ";
                        cin >> userInput;
                    }while(userInput != "YES" && userInput != "NO");
                    variableList[21][1] = userInput;
                    globalConclusions[globalConclusionsCounter]=(variableList[21][0] + "=" + variableList[21][1]);
                    globalConclusionsCounter++;
                }
            }
            if(postModVar == "Covered")
            {
                if(variableList[22][1] == "")
                {
                    do{
                        cout<< "Do the tumors cover the entire thyroid? (YES/NO) ";
                        cin >> userInput;
                    }while(userInput != "YES" && userInput != "NO");
                    variableList[22][1] = userInput;
                    globalConclusions[globalConclusionsCounter]=(variableList[22][0] + "=" + variableList[22][1]);
                    globalConclusionsCounter++;
                }
         }
        }
    }
}

void Treatment::validate_Ri(int ruleNumber)
{
    bool indexValidated = true;
    string variable;
    string value;

    for (int i=0; i <8; i++)
    {
        string ruleCondition = ruleList[ruleNumber][i];
        bool varPresent = false;
        if (ruleCondition != "")
        {
            std::size_t seperator = ruleCondition.find("=");
            variable = ruleCondition.substr(0, seperator);
            value = ruleCondition.substr(seperator + 1);

            for(int j=0; j<23; j++)
            {
                if(variableList[j][0] == variable)
                {
                    varPresent=true;
                    if (variableList[j][1] != value) {
                        indexValidated = false;
                        break;
                    }
                }
            }

            if (varPresent == false)
            {
                indexValidated = false;
                break;
            }
            if(indexValidated == false)
            {
                break;
            }
        }
    }

    if (indexValidated == true)
    {
        string conclusion = ruleList[ruleNumber][8];
        globalConclusions[globalConclusionsCounter] = conclusion;
        modifyTreatmentString();
        globalConclusionsCounter++;
        printGlobalConclusions();

        return;
    }
}

void Treatment::process(string patientDiagnosis)
{
    variableList[0][1] = patientDiagnosis;
    string searchCriteria = "Cancer=" + patientDiagnosis;
    globalConclusions[globalConclusionsCounter] = searchCriteria;
    globalConclusionsCounter++;
    search_cvl(searchCriteria);
    return;
}

void Treatment::printGlobalConclusions()
{
    cout << endl;
    for(int i = 0; i <= globalConclusionsCounter; i++)
    {
        if (globalConclusions[i] != "")
        {
            cout << globalConclusions[i] << endl;
            globalConclusions[i] = "";
        }
    }
    cout << endl;
    return;
}

void Treatment::modifyTreatmentString()
{
    string postModTreatment = globalConclusions[globalConclusionsCounter];
    std::size_t seperator = postModTreatment.find("=");
    treatment = postModTreatment.substr(seperator+1);
    return;

}

string Treatment::getTreatment()
{
    cout << endl;
    return treatment;
}
