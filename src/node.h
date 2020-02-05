#ifndef NODE_H
#define NODE_H

#include <ostream>
#include <string>
#include <map>
#include <list>

class Node;
class AttributeValue;

// typedef std::string AttributeKey;
// typedef std::string AttributeValue;
typedef std::pair<std::string, AttributeValue> AttributeBind;
namespace {
    struct InnerAttributeValue {
        InnerAttributeValue(std::string value);
        InnerAttributeValue(const InnerAttributeValue& inner);
        std::string m_value;
        size_t rcount; // count of attribute having reference on it
    };
    struct InnerNode {
        InnerNode(std::string name);
        InnerNode(const InnerNode& inner);
        std::string m_name;
        std::map<std::string, AttributeValue> m_attributes;
        std::list<Node> m_children;
        size_t rcount; // count of node having reference on it
    };
}
class AttributeValue {
    public:
        AttributeValue(std::string value);
        AttributeValue(const AttributeValue& attr);
        ~AttributeValue();
        void setValue(std::string value);
        std::string getValue() const;
    private:
        InnerAttributeValue* m_attribute;
};

class Node {
    public:
        Node(std::string name);
        Node(const Node& node);
        ~Node();

        std::ostream& render(std::ostream& stream) const;
        std::string render() const;

        void append(const Node& child);

        bool hasAttribute(std::string attr) const;
        void setAttribute(std::string attr, std::string value=""); // set or replace existing value
        void addAttribute(std::string attr, std::string value=""); // Set if not exists

        Node copy() const;
        Node rcopy() const;
    private:
        InnerNode* m_node;
};

std::ostream& operator<<(std::ostream& stream, Node node);

#endif // NODE_H