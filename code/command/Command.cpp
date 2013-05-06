#include "Command.h"


Command::Command(Camera* c) : camera(c){}


Command::Command(Camera* c, tinyxml2::XMLNode* node) : camera(c), nodeOut(node){}