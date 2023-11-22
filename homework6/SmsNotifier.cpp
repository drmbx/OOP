#include <iostream>
#include "SmsNotifier.h"

SmsNotifier::SmsNotifier(const std::string &number) :
	number{number} {}

void SmsNotifier::SendSms(const std::string& message) {
  std::cout << "Send " << message << " to number "<< number << std::endl;
}

void SmsNotifier::Notify(const std::string &message) {
  SendSms(message);
}
