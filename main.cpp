#include <iostream>
#include "Map.h"

int main() {
    Map<int, std::string> map;
    map.insert(1, "one");
    map.insert(2, "two");
    map.insert(3, "three");
    map.remove(2);
    map.insert(3, "four");

    for (int i = 0; i < map.end(); ++i) {
        std::cout << map.getByInd(i).getKey() << " ";
        std::cout << map.getByInd(i).getValue() << std::endl;
    }


    std::cout << "SECOND MAP" << std::endl;

    Map<std::string, int> stringMap;

    stringMap.insert("one", 1);
    stringMap.insert("two", 2);

    stringMap.remove("one");

    stringMap.insert("two", 10);

    for (int i = 0; i < stringMap.end(); ++i) {
        std::cout << stringMap.getByInd(i).getKey() << " ";
        std::cout << stringMap.getByInd(i).getValue() << std::endl;
    }

    return 0;
}
