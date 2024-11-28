#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <string>
#include <chrono>

using namespace std;

bool isCompound(const string& word, const unordered_set<string>& ws) {
    for (int i = 1; i < word.size(); ++i) {
        string prefix = word.substr(0, i);  // First part
        string suffix = word.substr(i);     // Remaining part

        if (ws.count(prefix) && ws.count(suffix)) return true;

        if (ws.count(prefix) && ws.count(suffix) == 0) {
            if (isCompound(suffix, ws)) return true;
        }
    }
    return false;
}

int main() {
    vector<string> fileNames = {"Input_01.txt", "Input_02.txt"};
    unordered_set<string> ws;
    vector<string> words;

    // Start timing using chrono method 
    auto startTime = chrono::high_resolution_clock::now();

    // Read words from both files
    for (const string& fileName : fileNames) {
        ifstream inputFile(fileName);
        if (!inputFile) {
            cerr << "Error in opening the file: " << fileName << endl;
            return 1;
        }
        string word;
        while (inputFile >> word) {
            words.push_back(word);
            ws.insert(word); 
        }
    }

    string longestWord, secondLongestWord;

    for (const string& word : words) {
        ws.erase(word);  
        if (isCompound(word, ws)) {
            if (word.size() > longestWord.size()) {
                secondLongestWord = longestWord;
                longestWord = word;
            } else if (word.size() > secondLongestWord.size()) {
                secondLongestWord = word;
            }
        }
        ws.insert(word); 
    }

    // Stop timing
    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);

    // Output results
    cout << "The first Longest compounded word is: " << longestWord << endl;
    cout << "The second longest compounded word is: " << secondLongestWord << endl;
    cout << "The time taken to perform the task is: " << duration.count() << " milliseconds" << endl;

    return 0;
}
