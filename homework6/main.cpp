#include <iostream>
#include <vector>
#include "SmsNotifier.h"
#include "EmailNotifier.h"

int main() {
  SmsNotifier sms{"+7-923-228-38-72"};
  EmailNotifier email{"m.filippov@g.nsu.ru"};
  std::vector<INotifier> notifiers;
  notifiers.push_back(sms);


  sms.Notify("I know lessons in C++");
  email.Notify("And want the lesson one");
  return 0;
}
