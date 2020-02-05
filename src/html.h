#ifndef HTML_H
#define HTML_H

#include "node.h"
#include <string>

// Dev in process, design is not entirely defined yet

class HTMLBaseElement: public Node {
    void addClass(std::string cls);
    bool removeClass(std::string cls);
}

class Html: public HTMLBaseElement {

}

class Paragraph: public HTMLBaseElement {

}

class Div: public HTMLBaseElement {

}

class Span: public HTMLBaseElement {

}

class Ul: public HTMLBaseElement {

}

class Li: public HTMLBaseElement {

}




#endif // HTML_H