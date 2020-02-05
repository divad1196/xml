#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <string>

class AttributeValue;
typedef std::pair<std::string, AttributeValue> AttributeBind;

namespace {
    struct InnerAttributeValue {
        InnerAttributeValue(std::string value);
        InnerAttributeValue(const InnerAttributeValue& inner);
        std::string m_value;
        size_t rcount; // count of attribute having reference on it
    };
}

class AttributeValue {
    public:
        AttributeValue(std::string value);
        AttributeValue(const AttributeValue& attr);
        ~AttributeValue();
        void syncWith(const AttributeValue& attr);
        bool isSyncWith(const AttributeValue& attr);


        void setValue(std::string value);
        std::string getValue() const;
    private:
        InnerAttributeValue* m_attribute;
};

// class Attribute: public std::pair<std::string, AttributeValue> {

// };

#endif // ATTRIBUTE_H