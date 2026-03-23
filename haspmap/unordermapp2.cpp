#include <bits/stdc++.h>
using namespace std;

struct hashPair {
    size_t operator()(const pair<int,int>& p) const {
        return hash<int>()(p.first) ^ hash<int>()(p.second);
    }
};

int main() {

    unordered_map<string,int> mp;
    unordered_map<int, vector<int>> mpVec;
    unordered_map<int, pair<int,int>> mpPair;
    unordered_map<pair<int,int>, int, hashPair> mpCustom;

    // INSERT
    mp["apple"] = 10;
    mp.insert({"banana", 20});
    mp.insert(make_pair("cherry", 30));
    mp.emplace("mango", 40);

    pair<string,int> p = {"grape", 50};
    mp.insert(p);

    unordered_map<string,int> temp = {{"x",1},{"y",2}};
    mp.insert(temp.begin(), temp.end());

    mp.insert({"z", 100}); // ✅ fixed

    // ACCESS
    cout << mp["apple"] << endl;
    cout << mp.at("banana") << endl;

    auto it1 = mp.find("cherry");
    if(it1 != mp.end()) cout << it1->second << endl;

    // SEARCH
    if(mp.find("mango") != mp.end()) cout << "Found\n";
    if(mp.count("grape")) cout << "Exists\n";

    // UPDATE
    mp["apple"] = 100;
    mp["apple"] += 10;

    // DELETE
    mp.erase("banana");

    auto it2 = mp.find("cherry");
    if(it2 != mp.end()) mp.erase(it2);

    // TRAVERSAL
    for(auto &p : mp) {
        cout << p.first << " " << p.second << endl;
    }

    for(auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    for(auto &[key, val] : mp) {
        cout << key << " " << val << endl;
    }

    // SIZE
    cout << mp.size() << endl;
    cout << mp.empty() << endl;

    // ADVANCED
    cout << mp.bucket_count() << endl;
    cout << mp.load_factor() << endl;

    mp.reserve(100);
    mp.rehash(200);

    // VECTOR + PAIR
    mpVec[1].push_back(10);
    mpPair[1] = {100, 200};

    // CUSTOM HASH
    mpCustom[{1,2}] = 500;
    cout << mpCustom[{1,2}] << endl;

    return 0;
}