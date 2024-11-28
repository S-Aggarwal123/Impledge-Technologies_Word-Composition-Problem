#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

unordered_map<string, bool> memoised_map;

bool isCompound(const string& word, const unordered_set<string>& ws) {
    if (memoised_map.find(word) != memoised_map.end()) {
        return memoised_map[word];
    }

    for (int i = 1; i < word.size(); ++i) {
        string prefix = word.substr(0, i);
        string suffix = word.substr(i);
        
        if (ws.count(prefix) && ws.count(suffix)) {
            return memoised_map[word] = true;
        }

        if (ws.count(prefix) && isCompound(suffix, ws)) {
            return memoised_map[word] = true;
        }
    }

    return memoised_map[word] = false;
}

int main() {
    vector<string> fileNames = {"Input_01.txt", "Input_02.txt"};
    unordered_set<string> ws;
    vector<string> words;

    auto start = high_resolution_clock::now();

    unordered_set<string> ws(words.begin(), words.end());

    string longestWord, secondLongestWord;

    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.size() < b.size();
    });

    for (const string& word : words) {
        if (isCompound(word, wordSet)) {
            if (word.size() > longestWord.size()) {
                secondLongestWord = longestWord;
                longestWord = word;
            } else if (word.size() > secondLongestWord.size()) {
                secondLongestWord = word;
            }
        }
    }

    // Output the results
    cout << "The longest compounded word is: " << longestWord << endl;
    cout << "The second longest compounded word is: " << secondLongestWord << endl;

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start); 

    // Output time taken for the process
    cout << "The time taken for the task is: " << duration.count() << " milliseconds" << endl;

    return 0;
}
