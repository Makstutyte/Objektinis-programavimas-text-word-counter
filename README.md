# Objektinis-programavimas-text-word-counter
Papildoma užduotis
Programa, kuri nuskaityto vartotojo nurodytą tekstinį failą (.txt) ir atspausdinanti tekste esančių žodžių pasikartojimo dažnį bei eilučių indeksus, kuriuose randamas pasikartojantis žodis. Programa taip pat išrenka tekste rastus URL adresus pateiktus tiek "pilnu" https://www.vu.lt/ tiek "sutrumpintu" pavidalu: www.vu.lt. 

## Įdiegimo instrukcija 
Norint paleisti programos kodą reikia:
1. Atsisiųsti programos kodą 
  <br />[releases](https://github.com/Makstutyte/Objektinis-programavimas-text-word-counter/releases)
2. Įsidiegti C++ compiler 
   <br />[GCC](https://gcc.gnu.org/)
3. Naudojant komandinę eilutę susirasti programos kodo buvimo vietą (directory) 
4. Sukompiliuoti programos kodą naudojant 
   <br /> `make` 
5. Paleisti programos kodą naudojant 
   <br /> `test` 
   
## Programos naudojimas 
Vartotojo veiksmų seka: 
1. Vartotojas įveda skaitomo failo pavadinimą formatu "pavadinimas.txt" 
2. Vartotojas pasirenka ar galutinis rezultatas bus atspausdinamas į ekraną, ar į atskirą .txt failą
    * Vartotojui pasirinkus rezultatų išsspausdinimą į atskirą .txt failą - nurodomas to failo pavadinimas

## Programoje naudojama
* Asociaciatyvus konteineris - std::multimap
* Sekos konteineris - std::vector
* Panaudotos koncepcijos - std::regex, std::make_pair
