#include <iostream>
#include <map>
#include <string>

using namespace std;

class SimpleDB {
private:
    map<string, string> db;
public:
    void insert(const string& key, const string& value) {
        db[key] = value;
    }

    bool remove(const string& key) {
        return db.erase(key);
    }

    string search(const string& key) {
        auto it = db.find(key);
        if (it != db.end()) {
            return it->second;
        }
        return "Clé non trouvée";
    }

    void displayDB() {
        for (const auto& pair : db) {
            cout << pair.first << " : " << pair.second << endl;
        }
    }
};

int main() {
    SimpleDB db;

    db.insert("1", "John Doe");
    db.insert("2", "Jane Smith");

    cout << "Après insertion :" << endl;
    db.displayDB();

    db.remove("1");

    cout << "Après suppression :" << endl;
    db.displayDB();

    cout << "Recherche pour '2' :" << endl;
    cout << db.search("2") << endl;

    return 0;
}
