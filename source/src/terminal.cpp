#include <string>
#include <unordered_map>
#include <vector>
#include <functional>
#include "CPU.h"

using command = std::function<void(const std::vector<std::string>& args)>;


std::unordered_map<std::string, command> comandos;


extern CPU core0;


void initCommands() {

}


void terminalThread(int argc, char** argv) {


}