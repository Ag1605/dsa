#include <bits/stdc++.h>

using namespace std;

int main() {
    // Create an unordered_map
    unordered_map<string, int> map1;
    
    // 1. Insert elements
    map1["apple"] = 5;
    map1["banana"] = 3;
    map1["orange"] = 7;
    map1.insert({"mango", 4});
    
    cout << "=== Inserting Elements ===" << endl;
    for (auto& pair : map1) {
        cout << pair.first << " : " << pair.second << endl;
    }
    
    // 2. Access elements
    cout << "\n=== Accessing Elements ===" << endl;
    cout << "Value of 'apple': " << map1["apple"] << endl;
    cout << "Value of 'banana': " << map1.at("banana") << endl;
    
    // 3. Check if key exists
    cout << "\n=== Checking Key Existence ===" << endl;
    if (map1.find("orange") != map1.end()) {
        cout << "'orange' exists in map" << endl;
    }
    if (map1.count("grape") == 0) {
        cout << "'grape' does not exist in map" << endl;
    }
    
    // 4. Update elements
    cout << "\n=== Updating Elements ===" << endl;
    map1["apple"] = 10;
    cout << "Updated 'apple': " << map1["apple"] << endl;
    
    // 5. Delete elements
    cout << "\n=== Deleting Elements ===" << endl;
    map1.erase("banana");
    cout << "After erasing 'banana':" << endl;
    for (auto& pair : map1) {
        cout << pair.first << " : " << pair.second << endl;
    }
    
    // 6. Size and empty
    cout << "\n=== Size Information ===" << endl;
    cout << "Size: " << map1.size() << endl;
    cout << "Is empty: " << (map1.empty() ? "Yes" : "No") << endl;
    
    // 7. Clear all elements
    cout << "\n=== Clear Operation ===" << endl;
    map1.clear();
    cout << "After clearing, size: " << map1.size() << endl;
    
    // 8. Unordered_map with integer keys
    cout << "\n=== Integer Keys ===" << endl;
    unordered_map<int, string> map2;
    map2[1] = "one";
    map2[2] = "two";
    map2[3] = "three";
    
    for (auto& pair : map2) {
        cout << pair.first << " -> " << pair.second << endl;
    }
    
    // 9. Using find with iterator
    cout << "\n=== Using Find Iterator ===" << endl;
    auto it = map2.find(2);
    if (it != map2.end()) {
        cout << "Found: " << it->first << " : " << it->second << endl;
    }
    
 vector<pair<int,int>> v;

    // push methods
    v.push_back({1,10});
    v.push_back(make_pair(2,20));

    pair<int,int> p = {3,30};
    v.push_back(p);

    for(int i = 4; i <= 5; i++) {
        v.push_back({i, i*10});
    }

    v.emplace_back(6,60);

    // print methods
    cout << "Index loop:\n";
    for(int i = 0; i < v.size(); i++) {
        cout << v[i].first << " " << v[i].second << endl;
    }

    cout << "\nIterator:\n";
    for(auto it = v.begin(); it != v.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    cout << "\nRange loop:\n";
    for(auto &x : v) {
        cout << x.first << " " << x.second << endl;
    }

    

    return 0;
}
