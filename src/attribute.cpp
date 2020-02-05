
#include "attribute.h"

//==================================================================================
// Attributes

InnerAttributeValue::InnerAttributeValue(std::string value): m_value(value), rcount(1) {

}


InnerAttributeValue::InnerAttributeValue(const InnerAttributeValue& inner): m_value(inner.m_value), rcount(1) {

}


AttributeValue::AttributeValue(std::string value): m_attribute(new InnerAttributeValue(value)) {

}

AttributeValue::AttributeValue(const AttributeValue& attr): m_attribute(attr.m_attribute){
    ++(m_attribute->rcount);
}

AttributeValue::~AttributeValue() {
    --(m_attribute->rcount);
    if(m_attribute->rcount == 0) delete m_attribute;
}


void AttributeValue::syncWith(const AttributeValue& attr) {
    --(m_attribute->rcount);
    if(m_attribute->rcount == 0) delete m_attribute;
    m_attribute = attr.m_attribute;
    ++(m_attribute->rcount);
}

bool AttributeValue::isSyncWith(const AttributeValue& attr) {
    return m_attribute == attr.m_attribute;
}


void AttributeValue::setValue(std::string value) {
    m_attribute->m_value = value;
}


std::string AttributeValue::getValue() const {
    return m_attribute->m_value;
}