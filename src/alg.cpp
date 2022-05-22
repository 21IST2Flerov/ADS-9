// Copyright 2021 NNTU-CS
#include  <cstdlib>
#include  "bst.h"

bool search(const char& sym, const std::string& string);
std::string searchRoot(const char* filename) {
    std::string mid_of_alphabet = "fghijklmnopqrstuFGHIJKLMNOPQRSTU";
    std::string word = "";
    std::ifstream fin(filename);
    if (!fin) {
        std::cout << "File error!" << std::endl;
        return word;
    }
    std::string temp;
    while (getline(fin, temp)) {
        std::stringstream words(temp);
        while (words >> word) {
            std::transform(word.begin(), word.end(), word.begin(), tolower);
            for (int i = 0; i < mid_of_alphabet.size(); ++i) {
                if (word[0] == mid_of_alphabet[i]) {
                    fin.close();
                    return word;
                }
            }
        }
    }
    fin.close();
    return word;
}
bool search(const char& sym, const std::string& string) {
    for (int i = 0; i < string.size(); ++i) {
        if (sym == string[i]) {
            return true;
        }
    }
    return false;
}
BST<std::string> createTree(const char* filename) {
    // поместите сюда свой код
    std::string root_val = searchRoot(filename);
    BST<std::string> tree;
    tree.add(root_val);
    tree.root->count--;
    std::ifstream fin(filename);
    if (!fin) {
        std::cout << "File error!" << std::endl;
        return tree;
    }
    std::string word = "";
    std::string temp_string;
    std::string english_alphabet = "abcdefghijklmnopqrstuvwxyz";
    english_alphabet += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while (getline(fin, temp_string)) {
        for (int i = 0; i < temp_string.size(); ++i) {
            word += temp_string[i];
            if (!(search(temp_string[i], english_alphabet))) {
                word.resize(word.size() - 1);
                if (!(word.empty())) {
                    std::transform(word.begin(), word.end(), word.begin(), tolower);
                    tree.add(word);
                    word = "";
                }
            }
        }
        if (search(word[word.size() - 1], english_alphabet)) {
            std::transform(word.begin(), word.end(), word.begin(), tolower);
            tree.add(word);
            word = "";
        }
    }
    fin.close();
    return tree;
}
