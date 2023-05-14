#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int get_uname(string command, string result, char* buffer) {
  FILE* pipe = popen(command.c_str(), "r");

  if (!pipe) {
    cerr << "Failed to Execute" << endl;
    return 1;
  }

  while (fgets(buffer, sizeof(buffer), pipe)) {
    result += buffer;
  }
  pclose(pipe);
  return 0;
}

int get_uptime(string uptime_result, string uptime_command, char* buffer1) {
  FILE* upipe = popen(uptime_command.c_str(), "r");

  if (!upipe) {
    cerr << "Failed to Execute" << endl;
    return 1;
  }

  while(fgets(buffer1, sizeof(buffer1), upipe)) {
    uptime_result += buffer1;
  }
  pclose(upipe);
  return 0;
}

int get_ram(string ram_total, string ram_command, char* buffer2) {
  FILE* rpipe = popen(ram_command.c_str(), "r");

  if (!rpipe) {
    cerr << "Failed to Execute" << endl;
    return 1;
  }

  while(fgets(buffer2, sizeof(buffer2), rpipe)) {
    ram_total += buffer2;
  }

  pclose(rpipe);
  return 0;
}

int get_kernel(string kernel_result, string kernel_command, char* buffer3) {
  FILE* kpipe = popen(kernel_command.c_str(), "r");
  
  if (!kpipe) {
    cerr << "Failed to execute" << endl;
    return 1;
  } 

  while(fgets(buffer3, sizeof(buffer3), kpipe)) {
    kernel_result += buffer3;
  }
  pclose(kpipe);
  return 0;
}

int get_logo(string logo_result, string logo_command, char* buffer4) {
  FILE* lpipe = popen(logo_command.c_str(), "r");
  
  if (!lpipe) {
    cerr << "Failed to execute" << endl;
    return 1;
  }

  while(fgets(buffer4, sizeof(buffer4), lpipe)) {
    logo_result += buffer4;
  }
  pclose(lpipe);
  return 0;
}

int main() {
  string command = "uname -a";
  string uptime_command = "uptime";
  string result;
  
  string uptime_result;
  string host_name;

  string ram_total;
  string ram_command = "free -h";

  string kernel_result;
  string kernel_command = "uname -r";

  string logo_command = "neofetch --logo";
  string logo_result;

  char buffer[128];
  char buffer1[128];
  char buffer2[128];
  char buffer3[128];
  char buffer4[128];
  get_uname(command, result, buffer);
  get_uptime(uptime_result, uptime_command, buffer1);
  get_ram(ram_total, ram_command, buffer2);
  get_kernel(kernel_result, kernel_command, buffer3);
  get_logo(logo_result, logo_command, buffer4);

  if (result.find("nixos") != string::npos) {
    host_name = "NixOS";
  } else {
    host_name = "NULL";
  }

  cout << host_name << endl;
  return 0;
}
