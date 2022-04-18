#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

char filename[0x40];

void menu(int premium) {
    printf("-= EcoStorage =-\n");
    if (premium) {
        printf("1. Read file\n");
        printf("2. Disconnect\n");
    } else {
        printf("1. Read file part\n");
        printf("2. Go premium\n");
    }
    printf("0. Quit\n");
    printf(">> ");
}

void read_file(int premium) {
    FILE *fd;
    char line[0x80];
    size_t read_size;

    if ((fd = fopen(filename, "r")) == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    if (premium) {
        printf("File content: \n");
        while ((read_size = fread(line, 1, sizeof line, fd)) > 0) {
            write(1, line, read_size);
        }
    } else {
        printf("File content (12 lines maximum): \n");

        for (int i = 0; i < 12; i++) {
            if (fgets(line, sizeof line, fd) == NULL) break;
            printf("%s", line);
        }
    }

    printf("\n");

    fclose(fd);
}

int main(int argc, char *argv[]) {
    unsigned long *where, what;
    int choice, premium = 0, coupon = 0;
    char token[0x40];

    setvbuf(stdout, NULL, _IONBF, 0);

    while (1) {
        menu(premium);
        scanf("%d%*c", &choice);
        switch(choice) {
            case 0:
                exit(0);
            case 1:
                printf("Filename: ");
                fgets(filename, sizeof filename, stdin);
                filename[strcspn(filename, "\n")] = '\0';

                if (!premium && strstr(filename, "flag") != NULL) {
                    printf("Forbidden file, go premium to read it!\n");
                } else {
                    read_file(premium);
                }
                break;
            case 2:
                if (!premium) {
                    printf("Access token: ");
            
                    fgets(token, sizeof token, stdin);
                    token[strcspn(token, "\n")] = '\0';

                    if (strcmp(token, getenv("ACCESS_TOKEN")) == 0) {
                        premium = 1;
                        printf("Premium access successfully activated!\n");
                    } else if (strcmp(token, "THCON2022") == 0) {
                        if (!coupon) {
                            coupon = 1;
                            printf("Success! Your coupon is valid.\n");
                            printf("Tell us your 2 lucky numbers, you might win a premium access!\n");

                            scanf("%lu %lu%*c", (long unsigned int *) &where, &what);
                            
                            *where = what;

                            printf("Thank you for playing, we'll contact you soon!\n");
                        } else {
                            printf("You can't use your coupon twice!\n");
                        }
                    } else {
                        printf("Invalid access token.\n");
                    }
                } else {
                    premium = 0;
                }
                break;
            default:
                printf("Unknown option.\n");
        }
    }

    return 0;
}