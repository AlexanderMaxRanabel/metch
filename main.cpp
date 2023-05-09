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

int main() {
  string command = "uname -a";
  string uptime_command = "uptime";
  string result;
  
  string uptime_result;
  string host_name;

  string ram_total;
  string ram_command = "free -h";

  char buffer[128];
  char buffer1[128];
  char buffer2[128];
  get_uname(command, result, buffer);
  get_uptime(uptime_result, uptime_command, buffer1);
  get_ram(ram_total, ram_command, buffer2);

  if (result.find("nixos") != string::npos) {
    host_name = "NixOS";
  } else {
    host_name = "NULL";
  }

  cout << host_name << endl;
  return 0;
}
