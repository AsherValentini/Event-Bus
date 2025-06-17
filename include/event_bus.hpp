#pragma once

#include <functional>
#include <unordered_map>
#include "event_types.hpp"

class EventBus {
  using Events = std::vector<std::function<void()>>;

public:
  void subscribe(EventType type, std::function<void()> handler) {
    eventBus_[type].push_back(handler);
  }
  void publish(EventType type) const {
    auto it = eventBus_.find(type);

    if (it != eventBus_.end()) {

      for (auto& handler : it->second) {
        handler();
      }
    }
  }

private:
  std::unordered_map<EventType, Events> eventBus_;
};