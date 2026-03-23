#include <bits/stdc++.h>
using namespace std;

int main() {

    // DECLARATION
    map<string,int> mp;

    // INSERT
    mp["apple"] = 10;
    mp.insert({"banana", 20});
    mp.insert(make_pair("cherry", 30));
    mp.emplace("mango", 40);

    pair<string,int> p1 = {"grape", 50};
    mp.insert(p1);

    // loop insertion
    for(int i = 1; i <= 3; i++) {
        mp[to_string(i)] = i * 100;
    }

    // vector + loop
    vector<pair<string,int>> v = {{"x",1},{"y",2}};
    for(auto &p : v) {
        mp.insert(p);
    }

    // range insert
    mp.insert(v.begin(), v.end());

    // hint insert (only map)
    mp.insert(mp.begin(), {"z", 999});

    // ACCESS
    cout << mp["apple"] << endl;
    cout << mp.at("banana") << endl;

    auto it = mp.find("cherry");
    if(it != mp.end()) cout << it->second << endl;

    // SEARCH
    if(mp.find("mango") != mp.end()) cout << "Found mango\n";
    if(mp.count("grape")) cout << "Grape exists\n";

    // UPDATE
    mp["apple"] = 100;
    mp["apple"] += 10;

    // DELETE
    mp.erase("banana");

    auto it2 = mp.find("cherry");
    if(it2 != mp.end()) mp.erase(it2);

    // TRAVERSAL (ALL SAFE METHODS)

    cout << "\nRange loop:\n";
    for(auto &p : mp) {
        cout << p.first << " " << p.second << endl;
    }

    cout << "\nIterator:\n";
    for(auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    cout << "\nReverse Iterator:\n";
    for(auto it = mp.rbegin(); it != mp.rend(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    cout << "\nWhile Loop:\n";
    auto it3 = mp.begin();
    while(it3 != mp.end()) {
        cout << it3->first << " " << it3->second << endl;
        it3++;
    }

    // BOUNDS
    auto lb = mp.lower_bound("apple");
    if(lb != mp.end()) cout << "LB: " << lb->first << endl;

    auto ub = mp.upper_bound("apple");
    if(ub != mp.end()) cout << "UB: " << ub->first << endl;

    // SIZE
    cout << "\nSize: " << mp.size() << endl;
    cout << "Empty: " << mp.empty() << endl;

    // SWAP
    map<string,int> mp2;
    mp2["test"] = 999;
    mp.swap(mp2);

    // CLEAR
    mp.clear();

    // EXTRA
    map<int, vector<int>> mpVec;
    mpVec[1].push_back(10);

    map<int, pair<int,int>> mpPair;
    mpPair[1] = {100, 200};

    map<pair<int,int>, int> mpPairKey;
    mpPairKey[{1,2}] = 500;

    cout << "\nPair key: " << mpPairKey[{1,2}] << endl;

    return 0;
}