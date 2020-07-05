/*
	By Jenocn
	https://jenocn.github.io/
*/

#ifndef __MESSAGE_LISTENER_H_H__
#define __MESSAGE_LISTENER_H_H__

#include "MessageBase.h"

namespace GCL {
namespace Pattern {

class IMessageListener {
public:
	virtual ~IMessageListener() {}

	virtual void Invoke(IMessage* message) = 0;
	virtual int GetMessageID() const = 0;
};

template <typename T>
class MessageListener : public IMessageListener {
public:
	MessageListener(std::function<void(T*)> func);
	virtual void Invoke(IMessage* message);
	virtual int GetMessageID() const;

private:
	std::function<void(T*)> _func;
};

template <typename T>
MessageListener<T>::MessageListener(std::function<void(T*)> func)
	: _func(func) {}

template <typename T>
void MessageListener<T>::Invoke(IMessage* message) {
	_func(static_cast<T*>(message));
}
template <typename T>
int MessageListener<T>::GetMessageID() const {
	return MessageBase<T>::GetClassType();
}

} // namespace Pattern
} // namespace GCL

#endif // !_MESSAGE_LISTENER_H_H__