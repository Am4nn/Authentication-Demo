#include <bits/stdc++.h>
#include <unordered_set>
#define endl '\n'
#define ll long long int
#define For(i, a, n) for (size_t i = a; i < n; i++)
using namespace std;

unordered_map<string, size_t> database;
hash<string> myHash;
const string salt = "myssaltfordemo";

bool store(string name, string pass)
{
    if (database.find(name) != database.end())
        return false;
    auto hashId = myHash(pass + salt);
    database[name] = hashId;
    return true;
}

bool authenticate(string name, string pass)
{
    auto hashId = myHash(pass + salt);
    auto user = database.find(name);
    if (user != database.end())
        return (user->second == hashId);
    return false;
}

bool changePassword(string name, string currentPassword, string newPassword)
{
    if (!authenticate(name, currentPassword))
        return false;
    auto hashId = myHash(newPassword + salt);
    database[name] = hashId;
    return true;
}

void run()
{
    int choice;
    string username, password;
    while (true)
    {
        cout << "\n\n1. Signup\n2. Login\n3. Change Password\n4. Show DataBase\n\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter UserName and Password\n";
            cin >> username >> password;
            if (store(username, password))
                cout << "Signup Completed !\n";
            else
                cout << "UserName Already Present !\n";
            break;
        }
        case 2:
        {
            cout << "Enter UserName and Password\n";
            cin >> username >> password;
            if (authenticate(username, password))
            {
                cout << "Correct UserName and Password ... Login Successful !!!\n";
            }
            else
            {
                cout << "Wrong UserName or Password ... Login Failed !!!\n";
            }
            break;
        }
        case 3:
        {
            cout << "Enter UserName and Current Password\n";
            cin >> username >> password;
            cout << "Enter New Password\n";
            string newPassword;
            cin >> newPassword;
            if (changePassword(username, password, newPassword))
                cout << "Password Changed Successfully !!!\n";
            else
                cout << "UserName or Current Password is Entered Wrong !\n";
            break;
        }
        case 4:
        {
            if (database.size() != 0)
            {
                cout << "DATABASE : \n";
                for (auto data : database)
                {
                    cout << data.first << " -> " << data.second << endl;
                }
                break;
            }
            cout << "DATABASE Is Empty !\n";
            break;
        }
        default:
            return;
        }
    }
}

int main()
{
    cout << "\n\nWelcome to an Authentication Demo";
    run();
    cout << "\nThanks for Using the Program, Hope you Liked it.\n";
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




aman -> hashId


16 16^16

*/
