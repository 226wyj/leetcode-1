/* reference from: https://www.cnblogs.com/grandyang/p/6944331.html */
class FileSystem {
    private:
        unordered_map<string, set<string>> dirs;
        unordered_map<string, string> files;

    public:
        FileSystem() {
            dirs["/"];
        }

        vector<string> ls(string path) {
            // it's a file: return a list w/ only this file name
            /* if (files.find(path) != files.end()) { */
            if (files.count(path)) {
                int idx = path.find_last_of('/');
                return {path.substr(idx + 1)};
            // it has some sub-diectories
            } else {
                auto t = dirs[path];
                return vector<string>(t.begin(), t.end());
            }
        }

        void mkdir(string path) {
            istringstream is(path);
            string t = "", dir = "";
            /* ssize_t */
            /* getline(char ** restrict linep, size_t * restrict linecapp, FILE * restrict stream); */
            while (getline(is, t, '/')) {
                if (t.empty())
                    continue;
                if (dir.empty())
                    dir += "/";
                dirs[dir].insert(t);
                if (dir.size() > 1)
                    dir += "/";
                dir += t;
            }
        }

        void addContentToFile(string filePath, string content) {
            int idx = filePath.find_last_of('/');
            string dir = filePath.substr(0, idx);
            string file = filePath.substr(idx + 1);
            if (dir.empty())
                dir = "/";
            /* if (dirs.find(dir) == dirs.end()) */
            if (!dirs.count(dir))
                mkdir(dir);
            dirs[dir].insert(file);
            files[filePath].append(content);
        }

        string readContentFromFile(string filePath) {
            return files[filePath];
        }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
