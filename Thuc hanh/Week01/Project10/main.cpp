#include"main.h"

void chuanhoa(string& path) {
    string temp = "";
    for (int i = 0; i < path.size(); i++)
    {
        if (path[i] != '"')
        {
            if (path[i] == '\\')
            {
                temp += '\\';
            }
            else
            {
                temp += path[i];
            }
        }
    }
    path = temp;
}

void FileInfo()
{
    string path;
    cout << "Path: ";
    getline(cin, path);

    if (path.empty())
    {
        cout << "Invalid path!" << endl;
        return;
    }
    chuanhoa(path);

    vector<string> result;
    int lastSlashIndex = path.find_last_of("\\");
    string folder, filename;
    if (lastSlashIndex != std::string::npos)
    {
        folder = path.substr(0, lastSlashIndex);
        filename = path.substr(lastSlashIndex + 1);
    }
    else 
    {
        filename = path;
    }

    int lastDotIndex = filename.find_last_of(".");
    string extension;
    if (lastDotIndex != std::string::npos && lastDotIndex != 0)
    {
        extension = filename.substr(lastDotIndex + 1);
    }
    cout << "Folder: " << folder << endl;
    cout << "Filename: " << filename << endl;
    cout << "Extension: " << extension << endl;

}

int main() 
{
	FileInfo();
}