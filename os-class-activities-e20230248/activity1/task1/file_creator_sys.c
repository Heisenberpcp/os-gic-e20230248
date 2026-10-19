/* file_creator_sys.c */
#include <fcntl.h>    // open(), O_WRONLY, O_CREAT, O_TRUNC
#include <unistd.h>   // write(), close()
#include <string.h>   // strlen()

int main() {
    // YOUR CODE HERE
    // 1. Open/create "output.txt" using open()
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    // 2. Write "Hello from Operating Systems class!\n" using write()
    write(fd, "Hello from Operating Systems class!\n", 37);
    write(1,msg,37);
    // 3. Close the file using close()
    
    close(fd);
    // 4. Print "File created successfully!\n" to the terminal using write()
    write(1, "File created successfully!\n", 28);
    return 0;
}