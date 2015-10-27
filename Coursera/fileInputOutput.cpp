//
// Created by Chongli Wang on 10/26/15.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    std::ifstream fin("Coursera/input.csv");
    std::ofstream fout("Coursera/output.csv");
    string row, cell;
    vector<vector<string>> data;
    size_t colN = 0, rowN = 0;
    bool firstRowRead = false;
    while (std::getline(fin, row)) {
        ++rowN;
        vector<string> rows;
        size_t pos = 0;
        while (row.find(',', pos) != string::npos) {
            if (!firstRowRead) ++colN;
            cell = row.substr(pos, row.find(',', pos) - pos);
            rows.push_back(cell);
            pos = row.find(',', pos) + 1;
        }
        rows.push_back(row.substr(pos));
        firstRowRead = true;
        data.push_back(rows);
    }
    fin.close();
    cout << ++colN << endl;
    cout << rowN << endl;
    for (auto rows: data) {
        for (int j = 0; j < rows.size() - 1; ++j)
            fout << rows[j] << ",";
        fout << rows.back() << endl;
    }
    fout.close();
    return 0;
}