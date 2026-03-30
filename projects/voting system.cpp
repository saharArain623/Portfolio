#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Candidate {
public:
    int id;
    string name;
    int votes;

    Candidate(int i, string n) : id(i), name(n), votes(0) {}
};

class Voter {
public:
    int id;
    string name;
    bool hasVoted;

    Voter(int i, string n) : id(i), name(n), hasVoted(false) {}
};

class VotingSystem {
private:
    vector<Candidate> candidates;
    vector<Voter> voters;

public:
    void addCandidate() {
        int id;
        string name;
        cout << "Enter Candidate ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Candidate Name: ";
        getline(cin, name);
        candidates.push_back(Candidate(id, name));
        cout << "Candidate added successfully!\n";
    }

    void addVoter() {
        int id;
        string name;
        cout << "Enter Voter ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Voter Name: ";
        getline(cin, name);
        voters.push_back(Voter(id, name));
        cout << "Voter registered successfully!\n";
    }

    void castVote() {
        if (candidates.empty()) {
            cout << "No candidates available. Cannot cast vote.\n";
            return;
        }
        if (voters.empty()) {
            cout << "No voters registered. Cannot cast vote.\n";
            return;
        }

        int voterId;
        cout << "Enter your Voter ID: ";
        cin >> voterId;

        // Find voter
        Voter* voterPtr = NULL; // <-- use NULL instead of nullptr
        for (size_t i = 0; i < voters.size(); i++) {
            if (voters[i].id == voterId) {
                voterPtr = &voters[i];
                break;
            }
        }

        if (voterPtr == NULL) {
            cout << "Voter not found!\n";
            return;
        }

        if (voterPtr->hasVoted) {
            cout << "You have already voted!\n";
            return;
        }

        cout << "\nCandidates List:\n";
        for (size_t i = 0; i < candidates.size(); i++) {
            cout << candidates[i].id << ". " << candidates[i].name << endl;
        }

        int candidateId;
        cout << "Enter Candidate ID to vote for: ";
        cin >> candidateId;

        // Find candidate
        Candidate* candidatePtr = NULL; // <-- use NULL instead of nullptr
        for (size_t i = 0; i < candidates.size(); i++) {
            if (candidates[i].id == candidateId) {
                candidatePtr = &candidates[i];
                break;
            }
        }

        if (candidatePtr == NULL) {
            cout << "Candidate not found!\n";
            return;
        }

        // Cast vote
        candidatePtr->votes++;
        voterPtr->hasVoted = true;

        cout << "Vote cast successfully for " << candidatePtr->name << "!\n";
    }

    void displayResults() {
        if (candidates.empty()) {
            cout << "No candidates available.\n";
            return;
        }

        cout << "\nElection Results:\n";
        for (size_t i = 0; i < candidates.size(); i++) {
            cout << candidates[i].name << " -> " << candidates[i].votes << " votes\n";
        }

        // Find winner
        Candidate* winner = &candidates[0];
        for (size_t i = 1; i < candidates.size(); i++) {
            if (candidates[i].votes > winner->votes) {
                winner = &candidates[i];
            }
        }

        cout << "\nWinner: " << winner->name << " with " << winner->votes << " votes!\n";
    }
};

int main() {
    VotingSystem system;
    int choice;

    do {
        cout << "\n--- Online Voting System ---\n";
        cout << "1. Add Candidate\n";
        cout << "2. Register Voter\n";
        cout << "3. Cast Vote\n";
        cout << "4. Display Results\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1: system.addCandidate(); break;
            case 2: system.addVoter(); break;
            case 3: system.castVote(); break;
            case 4: system.displayResults(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 5);

    return 0;
}
