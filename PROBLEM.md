# EventBus

## Context

You're designing a lightweight event bus system that allows parts of a system to subscribe to events and get notified when those events occur. Think of it as the minimal core of a pub/sub system or signal-slot mechanism.

## Problem

Implement a module called EventBus that allows different handlers (callbacks) to subscribe to specific event types, and notifies them when an event is published.
Requirements

    Event Definition

        Define an enum class EventType with at least three event types: Start, Stop, Data.

    Handler Subscription

        A handler is a std::function<void()> (just a basic callback for now).

        EventBus must allow subscription to a specific EventType.

    Publishing

        When you publish an event, all subscribed handlers for that EventType must be called.

    API

    class EventBus {
    public:
        void subscribe(EventType type, std::function<void()> handler);
        void publish(EventType type);
    };

    Concurrency Not Required (optional extension later)

        You don't need thread safety today.

## Example

bus.subscribe(EventType::Start, []() { std::cout << "Start triggered!\n"; });
bus.subscribe(EventType::Stop, []() { std::cout << "Stop triggered!\n"; });

bus.publish(EventType::Start); // Should print: Start triggered!
bus.publish(EventType::Stop);  // Should print: Stop triggered!

## Bonus

If you finish early:

    Support std::function<void(std::string)> for a payload with event (like a message).

    Or allow handlers to unsubscribe using a handler ID (advanced).

## Goal

This challenge tests:

    API design

    Use of STL containers (e.g. unordered_map<EventType, vector<function>>)

    Functional callbacks

    Clean encapsulation


