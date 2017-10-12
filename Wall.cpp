// C++ program to demonstrate battle of Mesoketes

using namespace std;
#include <iostream>
#include <string>
#include <unordered_map>

/**
 * Represents the Battle class having walls and attack count
 *
 * @author Aarti Pawar <aartiashokpawar@gmail.com>
 */
class Wall
{
    private:

        /**
         * Class variables
         */
        std::unordered_map <std::string, int> wallHeight;
        int attack;

    public:

        /**
         * Constructor - to initialize class variables
         */
        Wall() {
            wallHeight = {
                { "north", 0 },
                { "south", 0 },
                { "west", 0 },
                { "east", 0 }
            };

            attack = 0;
        }

        /**
         * Checks if wall is attacked ie if wall height is less than the attacked strength
         *
         * @param  wallSide        wall side
         * @param  attackedHeight  attacked strength
         *
         * @return                 True, if wall is attacked
         */
        int isWallAttacked(std::string wallSide, int attackedHeight) {
            return wallHeight[wallSide] < attackedHeight;
        }

        /**
         * Increments 'attack' class variable by 1 when successful attack is made
         */
        void reportAttack() {
            attack = attack + 1;
        }

        /**
         * Updates the height of all the sides of the wall after battle finishes on that day
         *
         * @param wallHeightTemp   Map to store four wall sides height
         */
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

        /**
         * Prints all wall side height
         */
        void printWall() {
            cunt << endl << endl << --------- WALL --------- << endl << endl;
            cout <<"NORTH : " << wallHeight["north"] << endl;
            cout <<"SOUTH : " << wallHeight["south"] << endl;
            cout <<"EAST : " << wallHeight["east"] << endl;
            cout <<"WEST : " << wallHeight["west"] << endl;
        }

        /**
         * Prints successful attack count
         */
        void printAttackCount() {
            cout << endl << "Successful Attack Count: " << attack << endl;
        }

};

/**
 * main function - an entry point
 *
 * @return  integer  Returns 0, if suucessful
 */
int main()
{
    Wall *wall = new Wall();
    bool ch;
    int attackedHeight, count = 0;
    std::string wallSide, tribe;

    std::unordered_map <std::string, int> wallHeightTemp;

    // Assumption - Three days of battle
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

        // Each day attacks
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

            // Check if the wall side attack is successful
            if (wall->isWallAttacked(wallSide, attackedHeight)) {
                wallHeightTemp[wallSide] = attackedHeight;
                wall->reportAttack();
            }
        }

        // Update all the attacked wall sides
        wall->updateWallHeightTemp(wallHeightTemp);
    }

    // Print Wall sides strength and successful attack count
    wall->printWall();
    wall->printAttackCount();

    return 0;
}
