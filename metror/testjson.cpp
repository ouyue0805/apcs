#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

struct Address
{
    string street;
    string city;
};
// 泛型 運算子重載
// overload 告訴 json 遇到 Address 物件時該怎麼處理
// call by reference 傳進來的物件會直接被修改 而不是複製一份
void from_json(const json &j, Address &addr)
{
    j.at("street").get_to(addr.street);
    j.at("city").get_to(addr.city);
}
int main()
{
    ifstream file("test.json"); // 把檔案打開 讀進來
    if (!file.is_open())
    {
        cerr << "Error: Could not open file test.json" << endl;
        return 1;
    }

    json data;

    try
    {
        // file >> data; // 讀到的資料丟給 data 承接
        data = json::parse(file); // 把檔案解碼的結果丟給 data
    }
    catch (const json::parse_error &e)
    {
        std::cerr << e.what() << '\n';
    }

    string name = data["name"];
    cout << "name: " << name << endl;
    int age = data["age"];
    cout << "age: " << age << endl;
    bool is_student = data["is_student"];
    cout << "is_student: " << is_student << endl;
    vector<string> skills = data["skills"];
    // ["C++", "Python", "JavaScript"]
    for (const string skill : skills)
    {
        cout << skill << endl;
    }
    // 泛型 template 
    Address address = data["address"].get<Address>();
    cout<<"city: " << address.city << " street: "<< address.street<<endl;
    // bool dinasoreMap[10][10];
    // int deepMap[10][10];
    // 檢查隕石撞擊的座標是否有直接撞擊恐龍 如果有恐龍就移除 true -> false
    // 如果沒有代表要修改deepMap 根據隕石的參數去修改
    // 經過幾次的隨機模擬 輸出deepMap 最高 最低點座標

    return 0;
}