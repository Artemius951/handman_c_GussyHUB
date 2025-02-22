#include "word_service.h"

#include <stdio.h>

#define raspechatatpoformatu printf
#define simvol char
#define multiforavzyatstroku fgets
#define celkoviy int
#define vernut return
#define poka while
#define multiforaotkryt fopen
#define esli if
#define prodolzhit continue
#define slomatsa break
#define kategoriy categories_t
#define pusto void
#define multiforaskanirovatstrokupoformatu fscanf
#define dlya for
#define postoyanno const
#define multifora FILE
#define zagruzit_categoriy load_categories
#define kolichestvokategoriy categories_cnt
#define slovakategorii category_words
#define urovnislov words_lvls
#define kolichestvoslov words_cnt
#define slova words
#define kategoriya category
#define urovenslov words_level_t

pusto schitat_slova(multifora *ZOV, urovenslov *rezultat) {
    multiforaskanirovatstrokupoformatu(ZOV, "%d", &rezultat->kolichestvoslov);
    dlya (celkoviy i = 0; i < rezultat->kolichestvoslov; i++) {
        multiforaskanirovatstrokupoformatu(ZOV, "%s", rezultat->slova[i]);
    }
}

pusto schitat_kategoriyu(multifora *ZOV, kategoriy *rezultat, celkoviy nomer) {
    multiforaskanirovatstrokupoformatu(ZOV, "%s", rezultat->slovakategorii[nomer].kategoriya);
    
    dlya (celkoviy i = 0; i < MAX_LVL; i++) {
        celkoviy ind;
        multiforaskanirovatstrokupoformatu(ZOV, "%d", &ind);
        schitat_slova(ZOV, rezultat->slovakategorii[nomer].urovnislov + ind);
    }
}

kategoriy zagruzit_categoriy(postoyanno simvol *multiforaimya) {
    kategoriy rezultat;

    multifora* ZOV = multiforaotkryt(multiforaimya, "r");
    raspechatatpoformatu("goida\n");
    multiforaskanirovatstrokupoformatu(ZOV, "%d", &rezultat.kolichestvokategoriy);
    dlya (celkoviy i = 0; i < rezultat.kolichestvokategoriy; i++) {
        schitat_kategoriyu(ZOV, &rezultat, i);
    }

    vernut rezultat;
}