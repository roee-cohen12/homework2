#include <stdio.h>
#include <stdbool.h>
#define SHIP_SIZE 8
#define TOTAL_HEALTH 100
#define MAX_HEALTH 50
#define CRITICAL_HEALTH -1

int sum_array(int arr[], int length);
int input_for_ship(int ship[], int length);
int input_for_hits(bool ship[], int length);
int run_battle(int ships_health[], bool ship1_hits[], bool ship2_hits[], int length);

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

    int battle = run_battle(ships_health_values, ship1_hits, ship2_hits, SHIP_SIZE);


    return 0;
}

int run_battle(int ships_health[], bool ship1_hits[], bool ship2_hits[], int length) {
    int ship1_total_hits = 0;
    int ship2_total_hits = 0;
    for (int i = 0; i < length; i++) {
        if (ship1_hits[i]) {
            ship1_total_hits += ships_health[i];
        }
        if (ship1_total_hits >= TOTAL_HEALTH) {

        }
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

int sum_array(int arr[], int length) {//sums int array values
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += arr[i];
    }
    return sum;
}







