#include "game.h"
#include <string.h>
#include <stdbool.h>
int get_random(int max) {
    int rand = random(max);
    return rand;
}
int select_category(categories_t *categories) {
    printf("Choose category (pls)");
    for (int i = 0; i < categories->categories_cnt; i++) {
        printf("%d %s", i+1, categories->category_words[i]);
    }
    int x = 0;
    scanf("%d", &x);
    return x-1;
}

int select_level() {
    int x = 999;
    do {
        printf("Now choose lvl");
        printf("0. Easy");
        printf("1. Medium");
        printf("2. Hard (rock)");
        scanf("%d",&x);
    }
    while (x != 0 || x != 1 || x != 2);
    if (x == 0) {
        printf("You chose easy level. You're sweety UwU");
    }
    else if (x == 1) {
        printf("You chose medium level. It must be fun");
    }
    else if (x == 2) {
        printf("You chose hard level. Let the fire burn");
    }
    return x;
}

void initialize_game(game_t *game, categories_t *categories) {
    int cat = select_category(categories);
    category_words_t cv = categories->category_words[cat];  
    char category[MAX_WORD_LEN] = cv.category;
    int level = select_level();
    words_level_t wordl = cv.words_lvls[level];
    char word = wordl.words[get_random(wordl.words_cnt)];
    int hangman_state = 0;
    int tries_left = MAX_TRIES;
    char guessed_word[MAX_WORD_LEN]; 
    for (int i = 0; i < strlen(word); i++) {
        guessed_word[i] = '_';
    }
    char chosen_alphas[ALPHABET_SIZE];
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        chosen_alphas[i] = '_';
    }
}

int alphabetidx(char *alphabet, char x) {
    for (int i = 0; i < strlen(alphabet); i++) {
        if (x == alphabet[i]) {
            return i;
        }
    }
}

void check_guess(game_t *game, char guess) {
    char alphabet[ALPHABET_SIZE] = "abcdefghijklmnopqrstuvwxyz";

    char *nword = game->word;
    for (int i = 0; i < strlen(nword);i++) {
        if (guess == nword[i]) {
            game->guessed_word[i] = guess;
            int symb = alphabetidx(*alphabet,guess);
            game->chosen_alphas[symb] = 'V';
        }
        else {
            int symb = alphabetidx(*alphabet,guess);
            game->chosen_alphas[symb] = 'X';
            game->hangman_state++;
        }
    }
}

int is_game_won(game_t *game) {
    for (int i = 0; i < strlen(game->guessed_word); i++ ) {
        if (game->guessed_word == '_') {
            return 0;
        }
    }
    return 1;
}

void play_game(game_t *game) {
    while (game->hangman_state != MAX_TRIES) {
        printf("Choose your letter");
        char x;
        scanf("%c", &x);
        check_guess(game,x);
        if (is_game_won(game)) {
            printf("YOU WOOOON!!! URA!");
            return;
        }
    } 
    printf("You lost. His death is your fault");
}
