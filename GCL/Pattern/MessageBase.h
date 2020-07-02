/*
	By Jenocn
	https://jenocn.github.io/
*/

#ifndef __MESSAGE_BASE_H_H__
#define __MESSAGE_BASE_H_H__

#include "../Base/ClassType.h"
#include <functional>
#include <list>
#include <map>
#include <memory>
#include <string>

namespace GCL {
namespace Pattern {

class IMessage {
public:
	virtual ~IMessage() {}
	virtual int GetMessageID() const = 0;
};

using MessagePtr = std::shared_ptr<IMessage>;

template <typename T>
class MessageBase : public GCL::Base::ClassType<T, IMessage>, public IMessage {
public:
	static std::shared_ptr<T> Create();
	virtual ~MessageBase() {}
	virtual int GetMessageID() const;
};

template <typename T>
std::shared_ptr<T> MessageBase<T>::Create() {
	return std::shared_ptr<T>(new T());
}

template <typename T>
int MessageBase<T>::GetMessageID() const {
	return MessageBase<T>::GetClassType();
}

} // namespace Pattern
} // namespace GCL

#endif // !__MESSAGE_BASE_H_H__