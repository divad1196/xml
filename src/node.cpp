#include "node.h"
#include <sstream>

typedef std::pair<std::string, std::string> Attribute;

InnerNode::InnerNode(std::string name): m_name(name), rcount(1) {

}


InnerNode::InnerNode(const InnerNode& inner): m_name(inner.m_name), rcount(1) {

}

Node::Node(std::string name): m_node(new InnerNode(name)) {

}
Node::Node(const Node& node): m_node(node.m_node){
    ++(m_node->rcount);
}

Node::~Node() {
    --(m_node->rcount);
    if(m_node->rcount == 0) delete m_node;
}

void Node::append(const Node& child) {
    m_node->m_children.push_back(child);
}

bool Node::hasAttribute(std::string attr) {
    if (m_node->m_attributes.find(attr) != m_node->m_attributes.end()) return true;
    return false;
}


void Node::setAttribute(std::string attr, std::string value) {
    auto result = m_node->m_attributes.insert(Attribute(attr, value));
    if(result.second == false) {
        result.first->second = value;
    }
}

void Node::addAttribute(std::string attr, std::string value) {
    m_node->m_attributes.insert(Attribute(attr, value));
}

Node Node::copy() const{
    Node node(m_node->m_name);
    node.m_node->m_attributes = m_node->m_attributes;
    return node;
}

Node Node::rcopy() const{
    Node node = copy();
    for(const auto& child: m_node->m_children) {
        node.append(child.rcopy());
    }
}

std::ostream& Node::render(std::ostream& stream) const{
    stream << '<' << m_node->m_name;
    for(const auto& [attr, value]: m_node->m_attributes) {
        stream << ' ' << attr << "=\"" << value << '"';
    }
    stream << ">";
    for(const auto& node: m_node->m_children) {
        stream << '\n' << node;
    }
    stream << "\n</" << m_node->m_name << '>';

    return stream;
}

std::string Node::render() const{
    std::stringstream stream;
    render(stream);
    return stream.str();
}

std::ostream& operator<<(std::ostream& stream, Node node) {
    return node.render(stream);
}