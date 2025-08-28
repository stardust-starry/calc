#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arithmetic.h>

int main(int argc, char *argv[])
{
    // Check for file deletion mode
    if (argc == 3 && strcmp(argv[1], "delete") == 0) {
        char *filename = argv[2];
        
        // Check if file exists before attempting deletion
        if (access(filename, F_OK) == 0) {
            if (unlink(filename) == 0) {
                printf("File '%s' deleted successfully.\n", filename);
                return 0;
            } else {
                perror("Error deleting file");
                return 1;
            }
        } else {
            printf("Error: File '%s' does not exist.\n", filename);
            return 1;
        }
    }
    
    // Original arithmetic calculator functionality
    if (argc != 3) {
        printf("Usage: %s <num1> <num2> OR %s delete <filename>\n", argv[0], argv[0]);
        return 1;
    }
    
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    printf("%d + %d = %d\n", a, b, add(a, b));
    printf("%d - %d = %d\n", a, b, sub(a, b));
    printf("%d * %d = %d\n", a, b, mul(a, b));
    printf("%d / %d = %d\n", a, b, dur(a, b));

    return 0;
}
