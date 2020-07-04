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
	static void AddListener(void* sender, std::function<void(std::shared_ptr<T> message)> func);
	static void RemoveListener(void* sender);
	static void Send(MessagePtr message);
	static void Push(MessagePtr message);
	static void OnDispatch();
	static void Clear();
	static MessageDispatcher* GetMessageDispatcher();

private:
	static MessageDispatcher* _messageDispatcher;
};

template <typename T>
void MessageCenter::AddListener(void* sender, std::function<void(std::shared_ptr<T> message)> func) {
	_messageDispatcher->AddListener<T>(sender, func);
}

} // namespace Pattern
} // namespace GCL
#endif // !__MESSAGE_CENTER_H_H__