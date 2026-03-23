#include <bits/stdc++.h>
using namespace std;

// 🔹 Custom hash for pair
struct hashPair {
    size_t operator()(const pair<int,int>& p) const {
        return hash<int>()(p.first) ^ hash<int>()(p.second);
    }
};

int main() {

    // 🔥 1. DECLARATION
    unordered_map<string,int> mp;
    unordered_map<int, vector<int>> mpVec;
    unordered_map<int, pair<int,int>> mpPair;
    unordered_map<pair<int,int>, int, hashPair> mpCustom;

    // 🔥 2. INSERT (ALL WAYS)
    mp["apple"] = 10;                             // []
    mp.insert({"banana", 20});                    // insert
    mp.insert(make_pair("cherry", 30));           // make_pair
    mp.emplace("mango", 40);                      // emplace

    pair<string,int> p = {"grape", 50};           // pair variable
    mp.insert(p);

    unordered_map<string,int> temp = {{"x",1},{"y",2}};
    mp.insert(temp.begin(), temp.end());          // range insert

    mp.insert(mp.begin(), {"z", 100});            // with hint

    // 🔥 3. ACCESS
    cout << mp["apple"] << endl;                  // []
    cout << mp.at("banana") << endl;              // at()

    auto it1 = mp.find("cherry");                 // iterator access
    if(it1 != mp.end()) cout << it1->second << endl;

    // 🔥 4. SEARCH
    if(mp.find("mango") != mp.end()) cout << "Found\n";
    if(mp.count("grape")) cout << "Exists\n";
    // if(mp.contains("apple")) cout << "C++20\n";

    // 🔥 5. UPDATE
    mp["apple"] = 100;
    mp["apple"] += 10;
    mp.insert({"apple", 500}); // won't update
    mp.emplace("apple", 600);  // won't update

    // 🔥 6. DELETE
    mp.erase("banana");                        // by key

    auto it2 = mp.find("cherry");              // by iterator
    if(it2 != mp.end()) mp.erase(it2);

    // erase range
    // mp.erase(mp.begin(), mp.end());

    // 🔥 7. TRAVERSAL

    cout << "\nRange loop:\n";
    for(auto &p : mp) {
        cout << p.first << " " << p.second << endl;
    }

    cout << "\nIterator:\n";
    for(auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    cout << "\nConst Iterator:\n";
    for(auto it = mp.cbegin(); it != mp.cend(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    cout << "\nStructured Binding:\n";
    for(auto &[key, val] : mp) {
        cout << key << " " << val << endl;
    }

    cout << "\nWhile Loop:\n";
    auto it3 = mp.begin();
    while(it3 != mp.end()) {
        cout << it3->first << " " << it3->second << endl;
        it3++;
    }

    // 🔥 8. SIZE / STATE
    cout << "\nSize: " << mp.size() << endl;
    cout << "Empty: " << mp.empty() << endl;
    cout << "Max size: " << mp.max_size() << endl;

    // 🔥 9. BUCKET / HASH (ADVANCED)
    cout << "\nBucket count: " << mp.bucket_count() << endl;
    cout << "Load factor: " << mp.load_factor() << endl;

    mp.reserve(100);
    mp.rehash(200);

    // 🔥 10. SWAP
    unordered_map<string,int> mp2;
    mp2["test"] = 999;
    mp.swap(mp2);

    // 🔥 11. CLEAR
    mp.clear();

    // 🔥 12. VECTOR + PAIR USAGE
    mpVec[1].push_back(10);
    mpVec[1].push_back(20);

    mpPair[1] = {100, 200};

    // 🔥 13. CUSTOM HASH (PAIR KEY)
    mpCustom[{1,2}] = 500;
    cout << "\nCustom key: " << mpCustom[{1,2}] << endl;

    return 0;
}