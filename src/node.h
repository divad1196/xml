#ifndef NODE_H
#define NODE_H

#include "attribute.h"
#include <ostream>
#include <string>
#include <map>
#include <list>

class Node;
namespace {
    struct InnerNode {
        InnerNode(std::string name);
        InnerNode(const InnerNode& inner);
        std::string m_name;
        std::map<std::string, AttributeValue> m_attributes;
        std::list<Node> m_children;
        size_t rcount; // count of node having reference on it
    };
}

class Node {
    public:
        Node(std::string name);
        Node(const Node& node);
        ~Node();
        void syncWith(const Node& node);
        bool isSyncWith(const Node& node);

        std::ostream& render(std::ostream& stream) const;
        std::string render() const;

        bool isChild(const Node& node) const;
        bool isDirectChild(const Node& node) const;
        void append(const Node& child);

        bool hasAttribute(std::string attr) const;
        void setAttribute(std::string attr, std::string value=""); // set or replace existing value
        void addAttribute(std::string attr, std::string value=""); // Set if not exists

        Node copy() const;
        Node rcopy() const;
    private:
        inline bool isSynchronized() const;
        bool m_isChild(const Node& node) const;
        InnerNode* m_node;
};

std::ostream& operator<<(std::ostream& stream, Node node);

#endif // NODE_H