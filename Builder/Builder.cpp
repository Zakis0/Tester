#include "Builder.h"

int Builder::compile(bool debug) {
    const std::string buildCommand = Constants::buildCommand;
    int compilationResult = system(buildCommand.c_str());
    if (debug) {
        std::cout << "Compilation ";
        std::cout << ((compilationResult == 0) ? "successful" : "failed") << std::endl;
    }
    return compilationResult;
}

int Builder::execute() {
    const std::string executionCommand = Constants::executionCommand;
    int executionResult = system(executionCommand.c_str());
    return executionResult;
}

int Builder::compileAndExecute() {
    int compilationResult = compile();
    if (compilationResult == 0) {
        int executionResult = execute();
        return executionResult;
    }
    return compilationResult;
}

std::string Builder::readOutput(const std::string& input) {
    int stdinPipe[2];
    int stdoutPipe[2];
    pid_t child_pid;

    if (pipe(stdinPipe) == -1 || pipe(stdoutPipe) == -1) {
        perror("pipe");
    }

    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
    }

    if (child_pid == 0) { // Child process
        close(stdinPipe[1]);   // Close the write end of the stdin pipe
        dup2(stdinPipe[0], STDIN_FILENO);  // Redirect stdin to the read end of the stdin pipe
        close(stdinPipe[0]);   // Close the original read end of the stdin pipe

        close(stdoutPipe[0]);  // Close the read end of the stdout pipe
        dup2(stdoutPipe[1], STDOUT_FILENO);  // Redirect stdout to the write end of the stdout pipe
        close(stdoutPipe[1]);  // Close the original write end of the stdout pipe

        // Execution of program
        execl(Constants::executionCommand.c_str(), Constants::executionCommand.c_str(), NULL);

        // If execl fails
        perror("execl");
    }
    else { // Parent process
        close(stdinPipe[0]);   // Close the read end of the stdin pipe
        close(stdoutPipe[1]);  // Close the write end of the stdout pipe

        write(stdinPipe[1], input.c_str(), input.size());  // Write to the write end of the stdin pipe
        close(stdinPipe[1]);   // Close the write end of the stdin pipe

        // Read from the read end of the stdout pipe and store it in a variable
        char buffer[MAX_OUTPUT_SIZE];
        std::string result;

        ssize_t bytesRead;
        while ((bytesRead = read(stdoutPipe[0], buffer, sizeof(buffer))) > 0) {
            result.append(buffer, bytesRead);
        }

        // Close the read end of the stdout pipe
        close(stdoutPipe[0]);

        // Wait for the child process to finish
        waitpid(child_pid, nullptr, 0);
        return result;
    }
    return "";
}
