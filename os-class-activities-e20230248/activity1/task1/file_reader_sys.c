/* file_reader_sys.c */
#include <fcntl.h>
#include <unistd.h>

int main() {
    char buffer[256];
    // YOUR CODE HERE
    // 1. Open "output.txt" for 
    int fd = open("output.txt",O_RDONLY);
    // 2. Read content into buffer using read() in a loop
    ssize_t bytesRead;
    while((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
       // 3. Write the content to the terminal (fd 1) using write()
        write(1, buffer, bytesRead);
    }
    
    // 4. Close the file using close()
    close(fd);
    return 0;
}