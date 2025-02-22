#include <stdlib.h>
#include <time.h>

#include "game.h"

int main() {
    srand(time(NULL));
    categories_t categories = load_categories("words");
    game_t game;
    print_rules();
    initialize_game(&game, &categories);
    play_game(&game);
    return 0;
}
