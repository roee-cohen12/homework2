#include <stdio.h>
#include <stdbool.h>
#define SHIP_SIZE 8
#define TOTAL_HEALTH 100
#define MAX_HEALTH 50
#define CRITICAL_HEALTH -1

int input_for_ship(int ship[], int length);
int input_for_hits(bool ship[], int length);
void run_battle(int ships_health[], bool ship1_hits[], bool ship2_hits[],
    int length);
bool mini_battle(int ships_health[], bool ship_hits[], int length);

int main() {
    //set ships for battle
    int ships_health_values[SHIP_SIZE] = {0};//each slot describes health factor
    bool ship1_hits[SHIP_SIZE] = {0};
    bool ship2_hits[SHIP_SIZE] = {0};

    //get the health values of the ships
    bool valid_inputs = input_for_ship(ships_health_values, SHIP_SIZE);
    if (!valid_inputs) {
        return 0; //there was en error in input
    }

    //get the hits history of the first ship
    bool valid_hits = input_for_hits(ship1_hits, SHIP_SIZE);
    if (!valid_hits) {
        return 0; //there was en error in input
    }

    //get the hits history of the second ship
    valid_hits = input_for_hits(ship2_hits, SHIP_SIZE);
    if (!valid_hits) {
        return 0; //there was en error in input
    }

    run_battle(ships_health_values, ship1_hits, ship2_hits, SHIP_SIZE);


    return 0;
}

bool mini_battle(int ships_health[], bool ship_hits[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (ships_health[i] == CRITICAL_HEALTH && ship_hits[i]) {
            return true;//ship is down
        }
        if (ship_hits[i]) {
            sum += ships_health[i];//ship hit on that index
        }
        if (sum >= TOTAL_HEALTH) {
            return true;//ship is down
        }
    }
    return false;//ship survived
}

void run_battle(int ships_health[], bool ship1_hits[], bool ship2_hits[],
    int length) {

    bool first_battle_outcome;
    bool second_battle_outcome;
    first_battle_outcome = mini_battle(ships_health, ship1_hits, length);
    second_battle_outcome = mini_battle(ships_health, ship2_hits, length);

    if (first_battle_outcome && second_battle_outcome) {
        //both ships lost
        printf("Both ships have lost the battle!\n");
    } else if (first_battle_outcome && !second_battle_outcome) {
        //ship1 lost, ship2 survived
        printf("Ship #2 has won the battle!\n");
    } else if (!first_battle_outcome && second_battle_outcome) {
        //ship2 lost, ship1 survived
        printf("Ship #1 has won the battle!\n");
    } else {
        //both ships survived
        printf("Both ships survived the battle!\n");
    }
}

int input_for_hits(bool ship[], int length) {//scan inputs for battleship
    static int ship_number = 1;
    if (ship_number == 1) {
        printf("Please enter first ship's hit marks:\n");//first run
    } else {
        printf("Please enter second ship's hit marks:\n");//second run
    }
    int hit_input;
    for (int i = 0; i < length; i++) {
        if (scanf("%d", &hit_input) != 1) { //checks value is an int
            printf("There was an error in input\n");
            return 0;
        }
        ship[i] = hit_input;//valid input
    }
    ship_number++;//update to print second ship on next run
    return 1;
}

int input_for_ship(int ship[], int length) {//scan inputs for battleship

    printf("Please enter ship's parts value:\n");
    int health_input;
    for (int i = 0; i < length; i++) {
        if (scanf("%d", &health_input) != 1) { //checks value is an int
            printf("There was an error in input\n");
            return 0;
        }
        if (health_input > MAX_HEALTH || health_input < CRITICAL_HEALTH ) {
            //health must be between -1 and 50
            printf("There was an error in input\n");
            return 0;
        }
        ship[i] = health_input;//valid input
    }
    return 1;
}







