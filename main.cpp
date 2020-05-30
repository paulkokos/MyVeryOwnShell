#include <dirent.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const vector<string> commandList = {
        "dir",
        "exit",
        "copy",
        "find",
        "tree"
};
void recognitionCommand(const vector<string>& commandsVector);
vector<string> splitCommand(string command,char delimiter);
void exitCommand();

void introduction();

//void commandEvaluation(int command);

void dir_command() {
    DIR * d;
    struct dirent *dir;
    d = opendir(".");
    if (d)
    {
        while ((dir = readdir(d)) != nullptr)
        {
            cout << "\n" <<dir->d_name;
        }
    }
    closedir(d);
}

string dir_inline(){
    string file_path = __FILE__;
    string dir_path = file_path.substr(0, file_path.rfind('\\'));
    return dir_path;
}
int main()
{
    int status;
    string command;
    bool isValid = true;
    string survey_fname;
    introduction();
    do {
        cin.clear();
        cout << dir_inline();
        cout << "\\>";
        getline(cin,command);
        vector<string> commands = splitCommand(command,' ');
        recognitionCommand(commands);
        cout << "\n";
    } while (isValid);

    return 0;
}

void introduction() {
    //Raw string literal
    const char *const introString = R"(
*************************************
* International Hellenic University *
* Operating Systems Exercise        *
* Student: Pavlos Kokozidis         *
* AEM: 3774                         *
*************************************)";
    cout << introString << "\n\n\n\n";
}
void recognitionCommand(const vector<string>& commandsVector) {

    try {
        if (commandsVector[0] == commandList[0]) {
            dir_command();
            return;
        } else if (commandsVector[0] == commandList[1]) {
            exitCommand();
            return;
        } else if (commandsVector[0] == commandList[2]) {
            //findCommand(commandsVector[1],commandsVector[2]);
            return;
        } else if (commandsVector[0] == commandList[3]) {
            //copyCommand(commandsVector[1],commandsVector[2]);
            return;
        } else if (commandsVector[0] == commandList[4]) {
            //treeCommand();
            return;
        } else {
            cout << "Invalid Command";
        }
    } catch (exception & e) {
        cout << "Standard exception: " << e.what() << endl;
    }
}

vector<string> splitCommand(string command,char delimiter){
    string wordCommand;
    int numberOfSplitedStrings;
    command+=delimiter;
    int lengthOfCommand = command.size();

    vector<string> subStringList;
    try {
        for (auto i : command) {
            if (i != delimiter) {
                wordCommand += i;
            } else {
                if ((int) wordCommand.size() != 0) {
                    subStringList.push_back(wordCommand);
                }
                wordCommand = "";
            }
        }
        return subStringList;
    } catch (exception &e) {
        cout << "Standard exception: " <<e.what() << endl;
    }
}

void exitCommand() {
    string answer;
    cout << "Are you sure you want to exit the program? [yes/No]";
    try {
        std::cin.ignore(EOF);
        getline(cin, answer);
        transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
        if (answer == "YES") {
            exitCommand();
        } else if (answer == "NO") {
            //Do nothing
        } else {
            cout << "Invalid answer !";
            answer = "";
        }
        cin.clear();
    } catch (exception& e ) {
        cout << e.what() << '\n';
    }
}