#include "Serializer.hpp"

int main() {
    Data obj;
    obj.name = "Matti";
    obj.age = 50;

    uintptr_t serialized = Serializer::serialize(&obj);

    Data* deserialized = Serializer::deserialize(serialized);

    if (deserialized != nullptr) {
        std::cout << "Deserialized Data: Name " << deserialized->name << ", Age " << deserialized->age << std::endl;
		std::cout << "Obj Data: Name " << obj.name << ", Age " << obj.age << std::endl;

        if (deserialized->name == obj.name && deserialized->age == obj.age) {
            std::cout << "Serialization and Deserialization successful." << std::endl;

        } else {
            std::cout << "Serialization or Deserialization failed. Values don't match." << std::endl;
        }

        if (deserialized == &obj) {
            std::cout << "Pointers match!" << std::endl;
        } else {
            std::cout << "Pointers don't match!" << std::endl;
        }
    } else {
        std::cout << "Deserialization failed." << std::endl;
    }

    return 0;
}