#include "Command.h"

Command::Command(Camera* c) : camera(c){}

Command::Command(Camera* c, tinyxml2::XMLDocument* doc, tinyxml2::XMLNode* node) : camera(c), docOut(doc), nodeOut(node){}