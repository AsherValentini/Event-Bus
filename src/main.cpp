#include <iostream>
#include <memory>

#include "event_bus.hpp"

int main() {
  auto bus = std::make_unique<EventBus>();

  bus->subscribe(EventType::START, []() { std::cout << "[EventBus] Event started \n"; });
  bus->subscribe(EventType::START, []() { std::cout << "[EventBus] Logging started \n"; });
  bus->subscribe(EventType::DATA, []() { std::cout << "[EventBus] Event running \n"; });
  bus->subscribe(EventType::STOP, []() { std::cout << "[EventBus] Event stopped \n"; });
  bus->subscribe(EventType::STOP, []() { std::cout << "[EventBus] Logging stopped \n"; });

  bus->publish(EventType::START);
  bus->publish(EventType::DATA);
  bus->publish(EventType::STOP);

  return 0;
}

