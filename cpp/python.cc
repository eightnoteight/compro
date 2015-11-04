namespace python {
    namespace str {
        std::string& upper(std::string& w) {
            std::transform(w.begin(), w.end(), w.begin(), std::toupper);
            return w;
        }
        std::string upper(std::string w) {
            std::transform(w.begin(), w.end(), w.begin(), std::toupper);
            return w;
        }
        std::string& lower(std::string& w) {
            std::transform(w.begin(), w.end(), w.begin(), std::tolower);
            return w;
        }
        std::string lower(std::string w) {
            std::transform(w.begin(), w.end(), w.begin(), std::toupper);
            return w;
        }
        uint count(std::string src, char key) {
            uint cc = 0;
            for(char ch: srd) {
                if (ch == key) {
                    ++cc;
                }
            }
            return cc;
        }
        uint count(std::string& src, char key) {
            uint cc = 0;
            for(char ch: srd) {
                if (ch == key) {
                    ++cc;
                }
            }
            return cc;
        }
        uint count(std::string& src, string key) {
            uint cc = 0;
            for(char ch: srd) {
                if (ch == key) {
                    ++cc;
                }
            }
            return cc;
        }
    }
}
