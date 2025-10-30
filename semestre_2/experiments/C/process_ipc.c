#include <stdio.h>
#include <windows.h>

typedef struct _ProcessData {
  HANDLE hStdinWrite;
  HANDLE hStdoutRead;
  PROCESS_INFORMATION piProcInfo;
} ProcessData;

void closeProcess(ProcessData* pData) {
  if (pData->hStdinWrite) {
    CloseHandle(pData->hStdinWrite);
    pData->hStdinWrite = NULL;
  }
  if (pData->hStdoutRead) {
    CloseHandle(pData->hStdoutRead);
    pData->hStdoutRead = NULL;
  }
  if (pData->piProcInfo.hProcess) {
    TerminateProcess(pData->piProcInfo.hProcess, 0);
    CloseHandle(pData->piProcInfo.hProcess);
    pData->piProcInfo.hProcess = NULL;
  }
  if (pData->piProcInfo.hThread) {
    CloseHandle(pData->piProcInfo.hThread);
    pData->piProcInfo.hThread = NULL;
  }
}

char* readChild(HANDLE hCldStdoutRead) {
  static char buffer[4096];
  DWORD read;
  Sleep(200); // Give child a moment to respond
  if (PeekNamedPipe(hCldStdoutRead, NULL, 0, NULL, &read, NULL) && read > 0) {
    if (ReadFile(hCldStdoutRead, buffer, sizeof(buffer) - 1, &read, NULL) && read > 0) {
      buffer[read] = '\0';
      return buffer;
    }
  }
  return "";
}


void writeChild(HANDLE hCldStdinWrite, const char* input) {
  DWORD written;
  WriteFile(hCldStdinWrite, input, (DWORD) strlen(input), &written, NULL);
}

int main() {
  // Handles for pipes
  HANDLE hCldStdoutRead, hCldStdoutWrite, hCldStdinRead, hCldStdinWrite;
  SECURITY_ATTRIBUTES secAttr = {sizeof(SECURITY_ATTRIBUTES), NULL, TRUE};

  // Create a pipe for the child's STDOUT
  if (!CreatePipe(&hCldStdoutRead, &hCldStdoutWrite, &secAttr, 0)) {
    fprintf(stderr, "Stdout pipe creation failed\n");
    return 1;
  }

  // Ensure the read handle to the pipe for STDOUT is not inherited
  SetHandleInformation(hCldStdoutRead, HANDLE_FLAG_INHERIT, 0);

  // Create a pipe for the child's STDIN
  if (!CreatePipe(&hCldStdinRead, &hCldStdinWrite, &secAttr, 0)) {
    fprintf(stderr, "Stdin pipe creation failed\n");
    return 1;
  }

  // Ensure the write handle to the pipe for STDIN is not inherited
  SetHandleInformation(hCldStdinWrite, HANDLE_FLAG_INHERIT, 0);

  // Set up STARTUPINFO structure
  STARTUPINFOA siStartInfo        = {0};
  PROCESS_INFORMATION piProcInfo  = {0};
  siStartInfo.cb                  = sizeof(STARTUPINFOA);
  siStartInfo.hStdError           = hCldStdoutWrite;
  siStartInfo.hStdOutput          = hCldStdoutWrite;
  siStartInfo.hStdInput           = hCldStdinRead;
  siStartInfo.dwFlags            |= STARTF_USESTDHANDLES;

  // Create the child process (e.g., a simple cmd.exe that echoes input)
  char cmdLine[] = "cmd.exe /Q /K"; // /Q disables echo, /K keeps shell open after command

  BOOL success = CreateProcessA(
    NULL, cmdLine, NULL, NULL,
    TRUE, // Inherit handles
    0, NULL, NULL, &siStartInfo, &piProcInfo
  );

  if (!success) {
    fprintf(stderr, "Process creation failed\n");
    return 1;
  }

  // The parent doesn't need these handles
  CloseHandle(hCldStdoutWrite);
  CloseHandle(hCldStdinRead);

  // Write command to child's stdin
  const char* input = "echo Hello from parent\r\n";
  writeChild(hCldStdinWrite, input);

  // Read child's stdout (non-blocking for demo)
  char* output = readChild(hCldStdoutRead);
  printf("Child output: %s", output);

  ProcessData pData = {0};
  pData.hStdinWrite = hCldStdinWrite;
  pData.hStdoutRead = hCldStdoutRead;
  pData.piProcInfo  = piProcInfo;

  closeProcess(&pData);

  return 0;
}
