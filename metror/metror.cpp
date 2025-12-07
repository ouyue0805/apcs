#include <iostream>
#include "json.hpp"
#include <string>
#include <vector> //裝東西的容器 vector</*要裝的東西(如果是int 裡面就是int)*/> /*宣告*/={資料;
#include <fstream>

using namespace std;
using json = nlohmann::json;

struct Events // 隕石撞擊物件
{
    int x;
    int y;
    int power;
    int powerLength;
};

void readMeteroData(string path, json &data)
{
    ifstream file(path); // 把檔案打開 讀進來
    if (!file.is_open())
    {
        cerr << "Error: Could not open file test.json" << endl;
    }

    try
    {
        // 運算子多載去做
        //  file >> data; // 讀到的資料丟給 data 承接 跟下面一樣
        data = json::parse(file); // 把檔案解碼的結果丟給 data
    }
    catch (const json::parse_error &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void to_json(json &j, const Events &e)
{
    j = json{{"x", e.x}, {"y", e.y}, {"power", e.power}, {"powerLength", e.powerLength}};
}

void from_json(const json &j, Events &e)
{
    // j.at("key") 會在 key 不存在時丟出例外
    // j["key"] 則會建立一個 null 物件，較不安全
    j.at("x").get_to(e.x);
    j.at("y").get_to(e.y);
    j.at("power").get_to(e.power);
    j.at("powerLength").get_to(e.powerLength);
}

int main()
{
    json data;
    // 創建物件 是很耗效能的 尤其是當你的物件很大的時候
    // call by value ->有複製的損耗 通常是 int struct
    // class 通常會 call by reference
    readMeteroData("./metero.json", data);
    vector<Events> events = data["events"];
    for (size_t i = 0; i < events.size(); i++)
    {
        cout << "x: " << events[i].x << " y: " << events[i].y << " power: " << events[i].power << endl;
    }

    int L, W;
    cin >> L;
    cin >> W;
    int Highmap[L][W];
    bool Dinosaurmap[L][W];
    int High;
    cin >> High;
    int Dinosaur;
    cin >> Dinosaur;
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < W; j++)
        {
            Highmap[i][j] = High;
        }
    }
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < W; j++)
        {
            Dinosaurmap[i][j] = false;
        }
    }
    for (int i = 0; i < Dinosaur; i++)
    {
        int a, b;
        cin >> a;
        cin >> b;
        Dinosaurmap[a][b] = true;
    }
    for (int i = 0; i < events.size(); i++)/*****/
    {
        if (Dinosaurmap[events[i].x][events[i].y] == true)
        {
            Dinosaurmap[events[i].x][events[i].y] = false;
        }
        else
        {
            for (int j = (events[i].x - (events[i].powerLength / 2)); j <= events[i].x + (events[i].powerLength / 2); j++)
            {
                for (int k = (events[i].y - (events[i].powerLength / 2)); k <= events[i].y + (events[i].powerLength / 2); k++)
                {
                    Highmap[j][k] -= events[i].power;
                }
            }
        }
    }
    int Highest = 0;
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (Highmap[i][j] > Highest)
            {
                Highest = Highmap[i][j];
            }
        }
    }
    int Lowest = High;
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (Highmap[i][j] < Lowest)
            {
                Lowest = Highmap[i][j];
            }
        }
    }
    unsigned int SoberDinosaur = 0;
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (Dinosaurmap[i][j] == true)
            {
                SoberDinosaur++;
            }
        }
    }
    cout << Highest << "\t" << Lowest << "\t" << SoberDinosaur << endl;
    return 0;
}
