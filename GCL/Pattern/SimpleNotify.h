/*
	By Jenocn
	https://jenocn.github.io/
*/

#pragma once

#include <functional>
#include <unordered_map>

namespace GCL {
namespace Pattern {

template <typename TMessage>
class SimpleNotify {
public:
	using MessageFunc = std::function<void(const TMessage&)>;

	bool AddListener(void* sender, MessageFunc func) {
		auto ite = _listeners.find(sender);
		if (ite == _listeners.end()) {
			_listeners.emplace(sender, func);
			return true;
		}
		return false;
	}
	bool RemoveListener(void* sender) {
		auto ite = _listeners.find(sender);
		if (ite != _listeners.end()) {
			_listeners.erase(ite);
			return true;
		}
		return false;
	}
	void Send(const TMessage& msg) {
		for (auto& item : _listeners) {
			item.second(msg);
		}
	}

private:
	std::unordered_map<void*, MessageFunc> _listeners;
};

} // namespace Pattern
} // namespace GCL