#include "game.h"
#include "global.h"
#include "ui_service.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int get_random(int max) {
    int rnum = rand() % max;
    return rnum;
}
int select_category(categories_t *categories) {
    printf("Choose category (pls)\n");
    for (int i = 0; i < categories->categories_cnt; i++) {
        printf("%d %s\n", i, categories->category_words[i].category);
    }
    int x = 0;
    scanf("%d", &x);
    return x;
}

int select_level() {
    int x = 999;
    do {
        printf("Now choose lvl\n");
        printf("0. Easy\n");
        printf("1. Medium\n");
        printf("2. Hard (rock)\n");
        scanf("%d",&x);
        
    }
    while ((x != 0) && (x != 1) && (x != 2));
    if (x == 0) {
        printf("You chose easy level. You're sweety UwU\n");
    }
    else if (x == 1) {
        printf("You chose medium level. It must be fun\n");
    }
    else if (x == 2) {
        printf("You chose hard level. Let the fire burn\n");
    }
    return x;
}

void initialize_game(game_t *game, categories_t *categories) {
    int cat = select_category(categories);
    category_words_t cv = categories->category_words[cat];  
    char *category = cv.category;
    memmove(game->category, category, MAX_WORD_LEN);
    int level = select_level();
    game->level = level;
    words_level_t word_level = cv.words_lvls[level];
    char *word = word_level.words[get_random(word_level.words_cnt)];
    memmove(game->word, word, MAX_WORD_LEN);
    game->hangman_state = 0;
    game->tries_left = MAX_TRIES;
    for (size_t i = 0; i < strlen(word); i++) {
        game->guessed_word[i] = '_';
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        game->chosen_alphas[i] = '_';
    }
    
}

int alphabetidx(char *alphabet, char x) {
    for (size_t i = 0; i < strlen(alphabet); i++) {
        if (x == alphabet[i]) {
            return i;
        }
    }
    return -1;
}

int is_guess_repeated(game_t *game, char guess) {
    return game->chosen_alphas[alphabetidx("abcdefghijklmnopqrstuvwxyz", guess)] != '_';
}

void check_guess(game_t *game, char guess) {
    static char alphabet[ALPHABET_SIZE] = "abcdefghijklmnopqrstuvwxyz";

    char *nword = game->word;
    int is_in = 0;

    for (int i = 0; nword[i] != '\0'; i++) {
        if (nword[i] == guess) {
            game->guessed_word[i] = guess;
            int symb = alphabetidx(alphabet, nword[i]);
            game->chosen_alphas[symb] = 'V';
            is_in = 1;
        }
    }

    if (!is_in) {
        int symb = alphabetidx(alphabet, guess);
        game->chosen_alphas[symb] = 'X';
        game->hangman_state++;
    }
}

int is_game_won(game_t *game) {
    for (size_t i = 0; i < strlen(game->guessed_word); i++ ) {
        if (game->guessed_word[i] == '_') {
            return 0;
        }
    }
    return 1;
}

int letter_in_word(char letter, char *word) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] == letter) {
            return 1;
        }
    }
    return 0;
}

void play_game(game_t *game) {
    while (game->hangman_state != MAX_TRIES) {
        print_progress_bar(game->tries_left);
        print_game_state(game);
        printf("Choose your letter: ");
        char x;
        getchar();
        scanf("%c", &x);
        if (is_guess_repeated(game, x)) {
            printf("You have already guessed this letter, try a different one)\n");
            continue;
        }
        check_guess(game,x);
        if (!letter_in_word(x, game->word)) {
            game->tries_left--;
        }
        if (is_game_won(game)) {
            print_progress_bar(game->tries_left);
            print_game_state(game);
            printf("YOU WOOOON!!! URA!");
            return;
        }
    } 
    for (int i = 0; game->word[i] != '\0'; i++) {
        game->guessed_word[i] = game->word[i];
    }
    print_progress_bar(game->tries_left);
    print_game_state(game);
    printf("You lost. His death is your fault");
}
