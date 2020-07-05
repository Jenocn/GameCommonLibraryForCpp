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
	void AddListener(void* sender, std::function<void(T*)> func);
	template <typename T>
	void RemoveListener(void* sender);
	void Send(MessagePtr message);
	void Push(MessagePtr message);
	void OnDispatch();
	void Clear();

private:
	std::list<MessagePtr>& _GetActiveQueue();
	std::list<MessagePtr>& _GetIdleQueue();

private:
	std::unordered_multimap<void*, IMessageListener*> _listenerMap;
	std::unordered_map<bool, std::list<MessagePtr>> _messageQueue;
	bool _activeQueueSign{ false };
};

template <typename T>
void MessageDispatcher::AddListener(void* sender, std::function<void(T*)> func) {
	if (func == nullptr) {
		return;
	}
	auto pair = _listenerMap.equal_range(sender);
	auto ite = pair.first;
	while (ite != pair.second) {
		if (ite->second->GetMessageID() == MessageBase<T>::GetClassType()) {
			return;
		}
		++ite;
	}

	auto listener = new MessageListener<T>(func);
	_listenerMap.emplace(sender, listener);
}

template <typename T>
void MessageDispatcher::RemoveListener(void* sender) {
	auto pair = _listenerMap.equal_range(sender);
	auto ite = pair.first;
	while (ite != pair.second) {
		if (ite->second->GetMessageID() == MessageBase<T>::GetClassType()) {
			delete ite->second;
			_listenerMap.erase(ite);
			return;
		}
		++ite;
	}
}

} // namespace Pattern
} // namespace GCL

#endif // !__MESSAGE_DISPATCHER_H_H__
