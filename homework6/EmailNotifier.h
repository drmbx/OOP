#include <string>
#include "INotifier.h"

class EmailNotifier : INotifier {
  std::string email;
 public:
  EmailNotifier(const std::string& email);

  void Notify(const std::string &message) override;
  void SendEmail(const std::string &message);
};
