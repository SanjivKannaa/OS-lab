#include <iostream>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int main() {
    int fd[2];
    pid_t pid;

    if (pipe(fd) == -1) {
        cerr << "Failed to create pipe\n";
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        cerr << "Failed to fork process\n";
        return 1;
    }

    if (pid == 0) {
        // Child process
        close(fd[0]); // Close reading end of pipe

        const int N = 10;
        char data[N+1];

        cout << "Enter " << N << " characters: ";
        cin.getline(data, N+1);

        write(fd[1], data, N); // Write data to pipe
        close(fd[1]); // Close writing end of pipe
    }
    else {
        // Parent process
        close(fd[1]); // Close writing end of pipe

        const int N = 10;
        char data[N+1];

        read(fd[0], data, N); // Read data from pipe
        close(fd[0]); // Close reading end of pipe

        int vowels = 0;
        for (int i = 0; i < N; i++) {
            if (data[i] == 'a' || data[i] == 'e' || data[i] == 'i' || data[i] == 'o' || data[i] == 'u' ||
                data[i] == 'A' || data[i] == 'E' || data[i] == 'I' || data[i] == 'O' || data[i] == 'U') {
                vowels++;
            }
        }

        cout << "Number of vowels: " << vowels << endl;
    }

    return 0;
}

