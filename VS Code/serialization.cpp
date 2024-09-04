#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

struct Person {
    std::string name;
    int age;
};

void to_json(nlohmann::json& j, const Person& p) {
    j = nlohmann::json{{"name", p.name}, {"age", p.age}};
}

void from_json(const nlohmann::json& j, Person& p) {
    j.at("name").get_to(p.name);
    j.at("age").get_to(p.age);
}

void serialize(const Person& person, const std::string& filename) {
    nlohmann::json j = person;
    std::ofstream ofs(filename);
    if (ofs.is_open()) {
        ofs << j;
        ofs.close();
    } else {
        std::cerr << "Error opening file for writing.\n";
    }
}

Person deserialize(const std::string& filename) {
    nlohmann::json j;
    std::ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> j;
        ifs.close();
    } else {
        std::cerr << "Error opening file for reading.\n";
    }
    return j.get<Person>();
}

int main() {
    Person p1 = {"Bob", 25};
    std::string filename = "person.json";
    
    // Serialize
    serialize(p1, filename);
    
    // Deserialize
    Person p2 = deserialize(filename);
    
    std::cout << "Name: " << p2.name << ", Age: " << p2.age << '\n';
    return 0;
}
