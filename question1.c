#include <stdio.h>
#define SENTENCE_SIZE 30
#define WORD_SIZE 10

int check_loop(int a, int b);
int check_key(char sentence[], int sentence_length, char word[],
int word_length);
int fill_char_array_in_input(char arr[], int length);

int main() {
    char sentence[SENTENCE_SIZE] = {0}; //array for the encrypted sentence
    char word[WORD_SIZE] = {0}; //array for the key word
    int sentence_size = 0;//length of sentence
    int word_size = 0;//length of word

    //fill the arrays with the inputs
    sentence_size = fill_char_array_in_input(sentence, SENTENCE_SIZE);
    word_size = fill_char_array_in_input(word, WORD_SIZE);

    //gets the key via the key_function
    int key = check_key(sentence, sentence_size, word,word_size);
    printf("%d\n", key); //print the key

    return 0;
}

int fill_char_array_in_input(char arr[], int length) {
    char input;
    int arr_size = 0;
    for (int i = 0; i < length; i++) { //word input
        if (scanf("%c", &input) == EOF) {
            break;
        }
        if (input == '\n') { //end of sentence
            break;
        }
        if (input == ' ') { //ignore spaces
            continue;
        }
        arr[arr_size] = input; //letter is valid
        arr_size++; //increase index and count
    }
    return arr_size;
}

int check_loop(int a, int b) {//checks looping of letters

    if (a > 'z' || a < 'a' || b > 'z' || b < 'a') { //a and b are small letters
        return 0;
    }
    if (a - b >= 0) { //no need for loop
        return a - b;
    }
    return a-b + 26 ; //need to loop edge cases
}

int check_key(char sentence[], int sentence_length, char word[],
    int word_length) {

    int count = 1; //assume the first word letter match the sentence
    for (int i = 0; i < sentence_length - word_length + 1; i++) {
        int key = check_loop(sentence[i], word[0]);//proposed encryption
        int sentence_index  = i + 1;
        int word_index = 1;
        while (check_loop(sentence[sentence_index], word[word_index])
            == key && sentence_index < sentence_length &&
            word_index < word_length) { //checks
            sentence_index++;
            word_index++;
            count++;
        }
        if (count == word_length) { //key found consecutive matches
            return key;
        }
        count = 1;//resets the count no match
    }
    return 0;
}




