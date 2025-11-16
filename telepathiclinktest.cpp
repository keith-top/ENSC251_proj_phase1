#include "telepathiclinktest.hpp"
#include <stdexcept>

TelepathicLinkTest::TelepathicLinkTest(int signal, int cognitive, int empathic, int resistance)
    : signalStrength(signal), cognitiveLink(cognitive), 
      empathicOverlay(empathic), cognitiveResistance(resistance) {
    
    setSignalStrength(signal);
    setCognitiveLink(cognitive);
    setEmpathicOverlay(empathic);
    setCognitiveResistance(resistance);
    calculateTotal();
}

void TelepathicLinkTest::calculateTotal() {
    total = signalStrength + cognitiveLink + empathicOverlay + cognitiveResistance;
}

int TelepathicLinkTest::getSignalStrength() const { return signalStrength; }
int TelepathicLinkTest::getCognitiveLink() const { return cognitiveLink; }
int TelepathicLinkTest::getEmpathicOverlay() const { return empathicOverlay; }
int TelepathicLinkTest::getCognitiveResistance() const { return cognitiveResistance; }
int TelepathicLinkTest::getTotal() const { return total; }

void TelepathicLinkTest::setSignalStrength(int strength) {
    if (strength < 0 || strength > 10) {
        throw std::invalid_argument("Signal strength must be between 0 and 10");
    }
    signalStrength = strength;
    calculateTotal();
}

void TelepathicLinkTest::setCognitiveLink(int link) {
    if (link < 0 || link > 10) {
        throw std::invalid_argument("Cognitive link must be between 0 and 10");
    }
    cognitiveLink = link;
    calculateTotal();
}

void TelepathicLinkTest::setEmpathicOverlay(int overlay) {
    if (overlay < 0 || overlay > 10) {
        throw std::invalid_argument("Empathic overlay must be between 0 and 10");
    }
    empathicOverlay = overlay;
    calculateTotal();
}

void TelepathicLinkTest::setCognitiveResistance(int resistance) {
    if (resistance < 0 || resistance > 10) {
        throw std::invalid_argument("Cognitive resistance must be between 0 and 10");
    }
    cognitiveResistance = resistance;
    calculateTotal();
}