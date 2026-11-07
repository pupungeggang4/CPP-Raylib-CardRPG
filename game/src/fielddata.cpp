#include "field.hpp"

std::unordered_map<int, std::string> FieldData::dataPath = {
    {HOME_TOWN, "data/home_town_0.txt"}
};

std::array<std::array<std::array<int, 6>, 100>, 100> FieldData::dataCell = {0};
std::array<std::array<std::array<int, 6>, 100>, 100> FieldData::dataWall = {0};

void FieldData::loadFieldData() {
    for (auto& value: FieldData::dataPath) {
        int i = value.first;
        std::ifstream file(value.second);
        if (!file.is_open()) {
            continue;
        }
        int j = 0;

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream s(line);
            int a, b, c, d, e, f;
            s >> a;
            dataCell[i][j][0] = a;

            if (a == 1) {
                s >> b >> c >> d >> e >> f;
                dataCell[i][j][1] = b; dataCell[i][j][2] = c; dataCell[i][j][3] = d;
                dataCell[i][j][4] = e; dataCell[i][j][5] = f;
            } else {
                s >> b >> c;
                dataCell[i][j][1] = b; dataCell[i][j][2] = c; dataCell[i][j][3] = 0;
                dataCell[i][j][4] = 0; dataCell[i][j][5] = 0;
            }

            j += 1;
        }
    }
}