#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int k;
    extern char *optarg;
    extern int optind;

    printf("Current Optiond : %d\n", optind);
    while ((k = getopt(argc, argv, "phn:")) != -1)
    {
        switch (k)
        {
        case 'p':
            printf("Welcome Linux System Programming!\n");
            break;

        case 'n':
            printf("Nice to meet %s\n", optarg);
            break;

        case 'h':
            printf("possible option : p, n\n");
            break;

        default:
            printf("possible option is n,p,h\n");
            break;
        }

        printf("Next Optind : %d\n", optind);
    }
}