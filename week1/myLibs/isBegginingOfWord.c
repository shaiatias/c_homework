
#include <stdbool.h>
#include <elf.h>

bool isBegginingOfWord(char previous, char current){
    return (
            (previous == '\t' || previous == '\n' || previous == ' ' || previous == NULL) &&
            (current != '\t' && current != '\n' && current != ' ')
    );
}