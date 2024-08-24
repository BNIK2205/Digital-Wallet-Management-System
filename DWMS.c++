#include <bits/stdc++.h>
using namespace std;

struct User {
    int userID;
    int balance;
};

int findUserIndex(vector<User>& users, int userID) {
    for (int i = 0; i < users.size(); ++i) {
        if (users[i].userID == userID) {
            return i;
        }
    }
    return -1;
}

int main() {
    int N;
    cin >> N;
    
    vector<User> users(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> users[i].userID >> users[i].balance;
    }
    
    int T;
    cin >> T;
    
    vector<string> results(T);
    for (int i = 0; i < T; ++i) {
        int from_userID, to_userID, amount;
        cin >> from_userID >> to_userID >> amount;
        
        int fromIndex = findUserIndex(users, from_userID);
        int toIndex = findUserIndex(users, to_userID);
        
        if (fromIndex != -1 && toIndex != -1 && users[fromIndex].balance >= amount) {
            users[fromIndex].balance -= amount;
            users[toIndex].balance += amount;
            results[i] = "Success";
        } else {
            results[i] = "Failure";
        }
    }
    
    for (const string& result : results) {
        cout << result << endl;
    }
    
    cout << endl;
    
    sort(users.begin(), users.end(), [](const User& a, const User& b) {
        if (a.balance == b.balance) {
            return a.userID < b.userID;
        }
        return a.balance < b.balance;
    });
    
    for (const User& user : users) {
        cout << user.userID << " " << user.balance << endl;
    }
    
    return 0;
}
