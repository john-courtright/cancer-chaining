// Class definition of BackwardChain
// Authors: Brittany Hale, John Courtright
#include <string>
#include <stack>
using namespace std;

class BackwardChain
{
private:
    // Data Members
    string conclt[14];  // Conclusion List
    string varlt[30];   // Variable List
    string clvarlt[73]; // Clause Variable List
    char varInt[30];    // Holds values of variables

    /* Stack stuff by Britt */
    stack<int> ruleStack;   // Stack for rule #s
    stack<int> clauseStack; // Stack for clause #s, stores slause #s for each rule at once.

    string var;       // Stored Variable
    string diagnosis; // Final Diagnosis
    string conclusion;
    int Ri = 0, Ci = 0; // Clause and Rule Num
    int conclusionPosition = 0;
    int finalConclusionPos = 0;
    int localized = 0;
    int suscancer = 0;

    // Private Function Prototypes
    bool search_conclusion_list(const string &var);
    int rule_to_clause(int Ri);
    void update_var_list(int Ci);
    void validate_Ri(int Ri, string &conclusion);
    void Process(const string &var);
    string getQuestion(int varNum);

public:
    // Constructor
    BackwardChain();

    // Public Function Prototypes
    string startBackwardChain(); // Entry point in main
    void printDiagnosis();     // Prints final diagnosis
};