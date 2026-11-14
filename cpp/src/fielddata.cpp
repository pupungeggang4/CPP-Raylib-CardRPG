#include "field.hpp"

std::unordered_map<std::string, int> FieldData::mapPlace = {
    {"HOME_TOWN", HOME_TOWN},
    {"PLAIN_1", PLAIN_1}, {"PLAIN_2", PLAIN_2}, {"PLAIN_3", PLAIN_3}, {"PLAIN_4", PLAIN_4}
};

std::unordered_map<int, std::string> FieldData::dataPath = {
    {HOME_TOWN, "data/field/home_town.dat"},
    {PLAIN_1, "data/field/plain_1.dat"},
    {PLAIN_2, "data/field/plain_2.dat"},
    {PLAIN_3, "data/field/plain_3.dat"},
    {PLAIN_4, "data/field/plain_4.dat"}
};

std::array<std::array<std::array<int, 6>, 100>, 100> FieldData::dataCell = {0};
std::array<std::array<std::array<int, 6>, 100>, 100> FieldData::dataWall = {0};
std::array<std::array<int, 100>, 100> FieldData::dataMonsterPool = {0};

void FieldData::loadFieldData() {
    std::ifstream file("data/field/monster_pool.dat");
    std::string line;

    int i = 0, j = 0;
    while(std::getline(file, line)) {
        j = 0;
        std::istringstream s(line);
        int num;
        while (s >> num) {
            dataMonsterPool[i][j] = num;
            j++;
        }
        i++;
    }

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
            int a, b, c, d, e; std::string f;
            s >> a;
            dataCell[i][j][0] = a;

            if (a == 1) {
                s >> b >> c >> d >> e >> f;
                dataCell[i][j][1] = b; dataCell[i][j][2] = c; dataCell[i][j][3] = d;
                dataCell[i][j][4] = e; dataCell[i][j][5] = mapPlace[f];
            } else {
                s >> b >> c;
                dataCell[i][j][1] = b; dataCell[i][j][2] = c; dataCell[i][j][3] = 0;
                dataCell[i][j][4] = 0; dataCell[i][j][5] = 0;
            }

            j += 1;
        }
    }
}
