#include <bits/stdc++.h>
#include <unordered_set>
#define endl '\n'
#define ll long long int
#define For(i, a, n) for (size_t i = a; i < n; i++)
using namespace std;

unordered_map<string, size_t> data1;
std::hash<std::string> myHash;
const string salt = "myssaltfordemo";

void store(string name, string pass)
{
    auto id = myHash(pass + salt);
    data1[name] = id;
}

bool authenticate(string name, string pass)
{
    auto id = myHash(pass + salt);
    auto val = data1.find(name);
    if (val != data1.end())
        return (val->second == id);
    return false;
}

int main()
{
    int cnt;
    string name, pass;
    while (true)
    {
        cout << "\n\n1. signup\n2. login\n3. showDataBase\n\n";
        cin >> cnt;
        switch (cnt)
        {
        case 1:
        {
            cout << "Enter UserName and Password\n";
            cin >> name >> pass;
            store(name, pass);
            cout << "Done\n";
            break;
        }
        case 2:
        {
            cout << "Enter UserName and Password\n";
            cin >> name >> pass;
            if (authenticate(name, pass))
            {
                cout << "Correct UserName and Password\n";
            }
            else
            {
                cout << "Wrong UserName or Password\n";
            }
            break;
        }
        case 3:
        {
            cout << "DATABASE : \n";
            for (auto x : data1)
            {
                cout << x.first << " -> " << x.second << endl;
            }
            break;
        }
        default:
            return 0;
        }
    }
    return 0;
}

/*

  Register
user : pass = abc123;
salt = "saltpromaxhihi"
delaytime 30sec
server : passID = hash(pass, salt); storeinDB(passID);

  Login
user : login(passlogin = abc123)
server : {
    passID = hash(passlogin, salt);
    originalpassID = retrievefromDB(user);
    if (passID === originalpassID) then login
    else pass wrong
}




aman -> 123


16 16^16

*/
