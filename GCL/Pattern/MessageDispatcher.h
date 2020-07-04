/*
	By Jenocn
	https://jenocn.github.io/
*/

#ifndef __MESSAGE_DISPATCHER_H_H__
#define __MESSAGE_DISPATCHER_H_H__

#include "MessageListener.h"

namespace GCL {
namespace Pattern {

class MessageDispatcher {
public:
	template <typename T>
	void AddListener(void* sender, std::function<void(std::shared_ptr<T> message)> func);
	void RemoveListener(void* sender);
	void Send(MessagePtr message);
	void Push(MessagePtr message);
	void OnDispatch();
	void Clear();

private:
	std::list<MessagePtr>& _GetActiveQueue();
	std::list<MessagePtr>& _GetIdleQueue();

private:
	std::map<void*, IMessageListener*> _listenerMap;
	std::map<bool, std::list<MessagePtr>> _messageQueue;
	bool _activeQueueSign{false};
};

template <typename T>
void MessageDispatcher::AddListener(void* sender, std::function<void(std::shared_ptr<T> message)> func) {
	if (func == nullptr) {
		return;
	}
	if (_listenerMap.find(sender) != _listenerMap.end()) {
		return;
	}
	auto listener = new MessageListener<T>(func);
	_listenerMap.emplace(sender, listener);
}

} // namespace Pattern
} // namespace GCL

#endif // !__MESSAGE_DISPATCHER_H_H__
