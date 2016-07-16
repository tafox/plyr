#include <stdio.h>

void play_song(FILE *fp);

int main(int argc, char *argv[]) {
    FILE *fp = fopen(argv[1], "r");
    play_song(fp);
    return 0;
}

void play_song(FILE *fp) {
    char data[0x2000];
    fseek(fp, 0x2c, SEEK_SET);
    fread((void*) &data, sizeof(char), 0x2000, fp);
    for (int i = 0; i < 0x2c; i++) 
        putchar(data[i]);
    fclose(fp);
    return;
}
