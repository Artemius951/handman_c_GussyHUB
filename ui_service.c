#include "global.h"
#include <stdio.h>

void print_rules() {
    printf("Hangman is a simple word guessing game.\nPlayers try to figure out an unknown word by guessing letters.\nIf too many letters which do not appear in the word are guessed, the player is hanged (and loses).\nSetup the game by drawing a gallow and a underline for each letter in the unknown word.\nAs letters in the word are guessed, write them above the cooresponding underline.\nIf a letter not in the word is guess, draw a picture of a person on the gallow–one part for each incorrect letter guess.\nMost frequently, the person is drawn in 6 parts.\n");
}

void print_progress_bar(int tries_left) {
    switch (tries_left) {
        case (6):
            printf("Tries left: %d/%d.\n", tries_left, MAX_TRIES);
            printf("+------------+\n|            |\n|            |\n|            |\n|            |\n|     0      |\n|    /|\\     |\n|    / \\     |\n+------------+\n");
            break;
        case(5):
            printf("Tries left: %d/%d.\n", tries_left, MAX_TRIES);
            printf("+------------+\n|            |\n|            |\n|            |\n|            |\n|     0      |\n| |  /|\\     |\n|/|\\ / \\     |\n+------------+\n");
            break;
        case(4):
            printf("Tries left: %d/%d.\n", tries_left, MAX_TRIES);
            printf("+------------+\n|            |\n| |          |\n| |          |\n| |          |\n| |   0      |\n| |  /|\\     |\n|/|\\ / \\     |\n+------------+\n");
            break;
        case(3):
            printf("Tries left: %d/%d.\n", tries_left, MAX_TRIES);
            printf("+------------+\n| ____       |\n| |          |\n| |          |\n| |          |\n| |   0      |\n| |  /|\\     |\n|/|\\ / \\     |\n+------------+\n");
            break;
        case(2):
            printf("Tries left: %d/%d.\n", tries_left, MAX_TRIES);
            printf("+------------+\n| ________   |\n| |          |\n| |          |\n| |          |\n| |   0      |\n| |  /|\\     |\n|/|\\ / \\     |\n+------------+\n");
            break;
        case(1):
            printf("Tries left: %d/%d. Be careful!\n", tries_left, MAX_TRIES);
            printf("+------------+\n| ________   |\n| |       |  |\n| |          |\n| |          |\n| |   0      |\n| |  /|\\     |\n|/|\\ / \\     |\n+------------+\n");
            break;
        case(0):
            printf("Tries left: %d/%d. GG!\n", tries_left, MAX_TRIES);
            printf("+------------+\n| ________   |\n| |       |  |\n| |       0  |\n| |      /|\\ |\n| |      / \\ |\n| |          |\n|/|\\         |\n+------------+\n");
            break;
    }
}

void print_game_state(game_t *game) {
    printf("Category: %s\n", game->category);
    printf("Chosen letters:\n");
    for (char i = 'A'; i <= 'Z'; i++) {
        printf("%c ", i);
    }
    printf("\n");
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        printf("%c ", game->chosen_alphas[i]);
    }
    printf("\nWord: ");
    int i = 0;
    while (game->guessed_word[i] != '\0') {
        printf("%c ", game->guessed_word[i++]);
    }
    printf("\n");
}
