/*
	By Jenocn
	https://jenocn.github.io/
*/

#ifndef __MESSAGE_CENTER_H_H__
#define __MESSAGE_CENTER_H_H__

#include "MessageDispatcher.h"
#include "MessageListener.h"

namespace GCL {
namespace Pattern {

class MessageCenter {
public:
	template <typename T>
	static void AddListener(void* sender, std::function<void(T* message)> func);
	template <typename T>
	static void RemoveListener(void* sender);
	static void Send(MessagePtr message);
	static void Push(MessagePtr message);
	static void OnDispatch();
	static void Clear();
	static MessageDispatcher* GetCenterDispatcher();
	static MessageDispatcher* GetCustomDispatcher(const std::string& name);

private:
	static MessageDispatcher* _messageDispatcher;
	static std::unordered_map<std::string, std::shared_ptr<MessageDispatcher>> _customDispatcherMap;
};

template <typename T>
void MessageCenter::AddListener(void* sender, std::function<void(T* message)> func) {
	_messageDispatcher->AddListener<T>(sender, func);
}
template <typename T>
void MessageCenter::RemoveListener(void* sender) {
	_messageDispatcher->RemoveListener<T>(sender);
}

} // namespace Pattern
} // namespace GCL
#endif // !__MESSAGE_CENTER_H_H__
