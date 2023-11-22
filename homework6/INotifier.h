#pragma once

class INotifier {
  virtual void Notify(const std::string &message) = 0;
};