/** 
 * Full Name: Dylan M. Ravel and Noslen Cruz-Muniz
 * Student ID: 2445987 and 2447745
 * Chapman Email: ravel@chapman.edu and cruzmuniz@chapman.edu
 * Course Number and Section: CPSC-350-03
 * Assignment or Exercise Number: PA5: Scare Games
*/

#include "TournamentTree.h"

// Default constructor
TournamentTree::TournamentTree() {
    
}

// overloaded constructor
TournamentTree::TournamentTree(TournamentNode* root) {
    this->root = root;
}

// overloaded constructor
TournamentTree::TournamentTree(std::vector<Monster> monsterBracket) {
    root = nullptr;
    this->monsterBracket = monsterBracket;

    // creates tree
    CreateTournamentTree(this->monsterBracket);
}

// overloaded constructor
TournamentTree::TournamentTree(std::string file) {
    this->root = nullptr;
    this->fileName = file;
    this->fileReader.open(this->fileName);

    // temp variables to read into vector
    std::string monsterName;
    int monsterScreamPower;
    
    while(this->fileReader >> monsterName >> monsterScreamPower) {
        // populates bracket
        this->monsterBracket.push_back(Monster(monsterName, monsterScreamPower));
    }

    // creates tree
    CreateTournamentTree(this->monsterBracket);
}

// default destructor
TournamentTree::~TournamentTree() {
    // closes the file reader
    this->fileReader.close();
}

// Creates a tournament tree
void TournamentTree::CreateTournamentTree(std::vector<Monster> monsterBracket) {
    // Ensure the size of monsterBracket is a power of 2 by adding temporary monsters
    int size = monsterBracket.size();
    int powerOfTwo = 1;

    while (powerOfTwo < size) {
        powerOfTwo *= 2;
    }

    while (monsterBracket.size() < powerOfTwo) {
        // creates temp monster
        monsterBracket.push_back(Monster("TEMP", 0));
    }

    this->monsterBracketSize = (2 * monsterBracket.size()) - 1;
    int tempCurrentSize = 0;
    int tempIndex = 0;

    // calls the helper method to help create it
    HelpCreateTournamentTree(this->root, tempCurrentSize, 0, monsterBracket, tempIndex);
}

// handle a single elimination using the helper method
Monster TournamentTree::SingleElimination() {
    HelpTournament(this->root);

    // return the monster
    return this->root->monster;
}

// handles double eliminations using the helper method
Monster TournamentTree::DoubleElimination() {
    for(int i = 0; i < this->monsterLosersBracket.size(); ++i) {
        // loop through the losers bracket
        if(this->monsterLosersBracket[i].GetName() == "TEMP" || this->monsterLosersBracket[i].GetName() == "") {
            // uses vector erase method to remove the entry in the vector
            this->monsterLosersBracket.erase(this->monsterLosersBracket.begin() + i);
            
            // go back one to check the index again
            --i;
        }
    }

    // calls the helper method for assistance
    HelpTournament(this->root);

    // returns the monster at the end
    return this->root->monster;
}

Monster TournamentTree::DoubleEliminationWinner() {
    // call single and double elimination
    this->finals.push_back(SingleElimination());
    this->finals.push_back(DoubleElimination());

    // choose winner and return accordingly
    if(this->finals[0].ScreamFight(this->finals[1])) {
        return this->finals[0];
    } else {
        return this->finals[1];
    }
}

// a helper method to help with saving the tree as a dot file
void TournamentTree::SaveTreeAsDotHelper(TournamentNode* node, std::ofstream& fileStream, int& nodeNumber) {
    // skip temp variables
    if (node == NULL || node->monster.GetName() == "TEMP") return;

    int currentNumber = nodeNumber++;
    fileStream << "    node" << currentNumber << " [label=\"" << node->monster.GetName()
         << " (Power: " << node->monster.GetScreamPower() << ")\"];\n";

    if (node->left && node->left->monster.GetName() != "TEMP") {
        int leftNumber = nodeNumber;
        SaveTreeAsDotHelper(node->left, fileStream, nodeNumber);
        fileStream << "    node" << currentNumber << " -> node" << leftNumber << ";\n";
    }

    if (node->right && node->right->monster.GetName() != "TEMP") {
        int rightNumber = nodeNumber;
        SaveTreeAsDotHelper(node->right, fileStream, nodeNumber);
        fileStream << "    node" << currentNumber << " -> node" << rightNumber << ";\n";
    }
}

// saving the tree as a dot file
void TournamentTree::SaveTreeAsDot(const std::string& filename, TournamentNode* rootNode) {
    std::ofstream fileStream(filename);
    if (!fileStream.is_open()) {
        std::cerr << "There was an error opening: " << filename << ". Please try again!" << std::endl;
        return;
    }

    fileStream << "digraph TournamentTree {\n";
    int nodeNumber = 0;
    SaveTreeAsDotHelper(rootNode, fileStream, nodeNumber);
    fileStream << "}\n";
    fileStream.close();
}

// a helper method to assist with creating the tree utilizing recursion
void TournamentTree::HelpCreateTournamentTree(TournamentNode*& rootNode, int& currentSize, int currentPowerLevel, std::vector<Monster>& monsterBracket, int& index) {
    int height = 0;
    
    // calculates the minimum height
    if (monsterBracket.size() <= 0) {
        height = -1; 
    } else {
        height = 0;
        int size = monsterBracket.size();
        while (size > 1) {
            size /= 2;
            height++;
        }
    }

    if(currentPowerLevel > height || currentSize >= this->monsterBracketSize) {
        // stop recursion when it has completed its task
        return;
    }

    if(rootNode == nullptr) {
        // Handles if the root is nullptr
        rootNode = new TournamentNode();
        rootNode->left = nullptr;
        rootNode->right = nullptr;
        rootNode->hasMonster = false;
        ++currentSize;
    }

    if(currentPowerLevel == height) {
        // if at the last power level and near the end of the bracket, assign monster to root
        if(index < monsterBracket.size()) {
            rootNode->monster = monsterBracket[index];
            rootNode->hasMonster = true;
            ++index;
        }
    } else {
        // recursively complete the right and left nodes for the rest of the tree
        HelpCreateTournamentTree(rootNode->left, currentSize, currentPowerLevel + 1, monsterBracket, index);
        HelpCreateTournamentTree(rootNode->right, currentSize, currentPowerLevel + 1, monsterBracket, index);
    }
}

void TournamentTree::HelpTournament(TournamentNode* rootNode) {
    if(rootNode->left == nullptr && rootNode->right == nullptr) {
        // if root node doesn't have any children return out of helper method
        return;
    }

    // recursively call on left node
    HelpTournament(rootNode->left);

    if(rootNode->right != nullptr) {
        // if right exists, recursively call on right node
        HelpTournament(rootNode->right);
    }

    if(rootNode->left && rootNode->right) {
        // if left and right exists, fight!
        Monster loser = rootNode->FightMonster();
        if (loser.GetName() != "TEMP") {
            this->monsterLosersBracket.push_back(loser);
        }
    }
}
