// C++ program to demonstrate battle of Mesoketes

using namespace std;
#include <iostream>
#include <string>
#include <unordered_map>

class Wall
{
    private:
        std::unordered_map <std::string, int> wallHeight;
        int attack;

    public:
        Wall() {
            wallHeight = {
                { "north", 0 },
                { "south", 0 },
                { "west", 0 },
                { "east", 0 }
            };
        }

        int isWallAttacked(std::string wallSide, int attackedHeight) {
            return wallHeight[wallSide] < attackedHeight;
        }

        void reportAttack() {
            attack = attack + 1;
        }

        void updateWallHeightTemp(std::unordered_map <std::string, int> wallHeightTemp) {
            for (auto it : wallHeight) {

                if (it.first == "north" && wallHeightTemp["north"] > 0 ) {
                    wallHeight["north"] = wallHeightTemp["north"];
                } else if (it.first == "south" && wallHeightTemp["south"] > 0 ) {
                    wallHeight["south"] = wallHeightTemp["south"];
                } else if (it.first == "east" && wallHeightTemp["east"] > 0 ) {
                    wallHeight["east"] = wallHeightTemp["east"];
                } else if (it.first == "west" && wallHeightTemp["west"] > 0 ) {
                    wallHeight["west"] = wallHeightTemp["west"];
                }

            }
        }

        void printWall() {
            cunt << endl << endl << --------- WALL --------- << endl << endl;
            cout <<"NORTH : " << wallHeight["north"] << endl;
            cout <<"SOUTH : " << wallHeight["south"] << endl;
            cout <<"EAST : " << wallHeight["east"] << endl;
            cout <<"WEST : " << wallHeight["west"] << endl;
        }

        void printAttackCount() {
            cout << endl << "Count Attack : " << attack << endl;
        }

};

int main()
{
    Wall *wall = new Wall();
    bool ch;
    int attackedHeight, count = 0;
    std::string wallSide, tribe;

    std::unordered_map <std::string, int> wallHeightTemp;

    for (int days = 0; days < 3; days++)
    {
        wallHeightTemp = {
            { "north", 0 },
            { "south", 0 },
            { "west", 0 },
            { "east", 0 }
        };

        cout << endl << "DAY " << days+1 << endl;
        ch = 1;

        while(ch) {

            attackedHeight = 0;
            cout << "1. Continue Attacking : " << endl;
            cout << "0. Battle Finish for the day" << endl;
            cout << "Enter your choice : ";

            cin >> ch;

            if (!ch) {
                break;
            }

            cout << "Enter tribe, wallside, attack strength" << endl;
            cin >> tribe >> wallSide >> attackedHeight;

            if (wall->isWallAttacked(wallSide, attackedHeight)) {
                wallHeightTemp[wallSide] = attackedHeight;
                wall->reportAttack();
            }
        }

        wall->updateWallHeightTemp(wallHeightTemp);
    }

    wall->printWall();
    wall->printAttackCount();

    return 0;
}
