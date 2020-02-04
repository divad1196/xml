#ifndef NODE_H
#define NODE_H

#include <ostream>
#include <string>
#include <map>
#include <list>
#include <memory>

class Node;

struct InnerNode {
    InnerNode(std::string name);
    InnerNode(const InnerNode& inner);
    std::string m_name;
    std::map<std::string, std::string> m_attributes;
    std::list<Node> m_children;
    size_t rcount; // count of node having reference on it
};

typedef std::shared_ptr<Node> SharedNode;

class Node {
    public:
        Node(std::string name);
        Node(const Node& node);
        ~Node();

        std::ostream& render(std::ostream& stream) const;
        std::string render() const;

        void append(const Node& child);

        bool hasAttribute(std::string attr);
        void setAttribute(std::string attr, std::string value=""); // set or replace existing value
        void addAttribute(std::string attr, std::string value=""); // Set if not exists

        Node copy() const;
        Node rcopy() const;
    private:
        InnerNode* m_node;
};

std::ostream& operator<<(std::ostream& stream, Node node);

#endif // NODE_H