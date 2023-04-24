/*
    Copyright(C) 2022 Tyler Crockett | Macdaddy4sure.com

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissionsand
    limitations under the License.
*/

#include <iostream>
#include <string>
#include <mysql.h>

using namespace std;

// Purpose: Search for a word in the SQL Dictionary and print to the screen

void WordTypeSearch();
void WordSearch();
string toLowerWord(string word);

int main()
{
    bool boolean = false;
    string input;
    string word;

    while (true)
    {
        system("cls");

        cout << endl;
        cout << "================= Main Menu =================" << endl;
        cout << "| 1. Word Search                            |" << endl;
        cout << "| 2. WordType Search                        |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << endl;
        cout << "Your Selection: ";
        getline(cin, input);

        if (input[0] == '1')
        {
            WordSearch();
        }
        if (input[0] == '2')
        {
            WordTypeSearch();
        }
    }
}

void WordSearch()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim228";
    string sql1;
    string input;
    string word;
    bool boolean = false;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        while (!boolean)
        {
            system("cls");

            cout << "word: ";
            getline(cin, input);

            if (input != "")
            {
                input = toLowerWord(input);

                sql1 = "SELECT * FROM entries;";
                mysql_query(conn, sql1.c_str());
                result = mysql_store_result(conn);

                while (row = mysql_fetch_row(result))
                {
                    word = toLowerWord(row[0]);

                    if (input == word)
                    {
                        cout << "word: " << row[0] << endl;
                        cout << "wordtype: " << row[1] << endl;
                        cout << "definition: " << row[2] << endl;
                        cout << endl;
                    }
                }
                cin.get();
            }
        }
    }
}

void WordTypeSearch()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string mysql_database = "dictionary";
    string mysql_username = "root";
    string mysql_password = "Anaheim228";
    string sql1;
    string input;
    string word;
    bool boolean = false;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        while (!boolean)
        {
            system("cls");

            cout << "word_type: ";
            getline(cin, input);

            if (input != "")
            {
                sql1 = "SELECT * FROM entries;";
                mysql_query(conn, sql1.c_str());
                result = mysql_store_result(conn);

                while (row = mysql_fetch_row(result))
                {
                    if (row[1] == "n.")
                    {
                        cout << "word: " << row[0] << endl;
                        cout << "definition: " << row[2] << endl;
                        cout << endl;
                    }

                    if (input == "adjective")
                    {
                        if (row[1] == "adj.")
                        {
                            cout << "word: " << row[0] << endl;
                            cout << "definition: " << row[2] << endl;
                            cout << endl;
                        }
                    }
                    if (input == "adverb")
                    {
                        if (row[1] == "adv.")
                        {
                            cout << "word: " << row[0] << endl;
                            cout << "definition: " << row[2] << endl;
                            cout << endl;
                        }
                    }
                    if (input == "preposition")
                    {
                        if (row[1] == "prep.")
                        {
                            cout << "word: " << row[0] << endl;
                            cout << "definition: " << row[2] << endl;
                            cout << endl;
                        }
                    }
                    if (input == "verb")
                    {
                        if (row[1] == "v." || row[1] == "v. i." || row[1] == "v. t.")
                        {
                            cout << "word: " << row[0] << endl;
                            cout << "definition: " << row[2] << endl;
                            cout << endl;
                        }
                    }
                }
            }
        }
    }
    else
    {

    }
}

string toLowerWord(string word)
{
    string temp;

    for (int x = 0; x <= word.length(); x++)
    {
        temp += tolower(word[x]);
    }

    return temp;
}