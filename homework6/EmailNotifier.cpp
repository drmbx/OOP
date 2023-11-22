#include <iostream>
#include "EmailNotifier.h"

EmailNotifier::EmailNotifier(const std::string &email) :
	email{email} {}

void EmailNotifier::SendEmail(const std::string& message) {
  std::cout << "Send " << message << " e-mail "<< email << std::endl;
}

void EmailNotifier::Notify(const std::string &message) {
  SendEmail(message);
}