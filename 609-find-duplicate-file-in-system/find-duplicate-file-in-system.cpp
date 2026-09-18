class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> files;

        for (string path : paths) {
            stringstream ss(path);
            string directory;

            ss >> directory;

            string file;

            while (ss >> file) {
                int open = file.find('(');

                string name = file.substr(0, open);
                string content =
                    file.substr(open + 1,
                                file.size() - open - 2);

                string fullPath =
                    directory + "/" + name;

                files[content].push_back(fullPath);
            }
        }

        vector<vector<string>> result;

        for (auto& [content, pathsList] : files) {
            if (pathsList.size() > 1)
                result.push_back(pathsList);
        }

        return result;
    }
};