#include <string>
#include "INotifier.h"

class SmsNotifier : INotifier {
  std::string number;
 public:
  SmsNotifier(const std::string &number);

  void Notify(const std::string &message) override;
  void SendSms(const std::string &message);
};