#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } 
    else if (pid == 0) {
        printf("Child: PID = %d\n", getpid());
        sleep(2);
        printf("Child: Finished work\n");
    } 
    else {
        wait(NULL);
        printf("Parent: Child process completed. Parent PID = %d\n", getpid());
    }

    return 0;
}
